/*
 Список багов в исходном решении
 
 1. Некомпилируемость из-за проблем с константностью в main. Сообщение об этой ошибке в большинстве компиляторов довольно громоздкое и запутанное. Чтобы обнаружить источник проблемы, достаточно найти ссылку на строчку исходного кода:
 
 /place/home/coursera/domains_bad_wa.cpp:44:3: note: in instantiation of function template specialization 'std::__y1::sort<const std::__y1::basic_string<char, std::__y1::char_traits<char>, std::__y1::allocator<char> > *>' requested here
 sort(begin(banned_domains), end(banned_domains));
 ^
 
 2. Беззнаковые счётчики в IsSubdomain. Легко находится компилятором и вылезает в виде ворнингов с описанием вида «выражение i >= 0 выполняется всегда, так как i беззнаковое» («comparison of unsigned expression >= 0 is always true»). Если пропустить ворнинги, то проблема проявится на юнит-тесте IsSubdomain(s, s). Он же поможет обнаружить и следующую проблему.
 3. Некорректная работа IsSubdomain при вызове от двух одинаковых строк. Как правило, легко находится юнит-тестом из предыдущего пункта. С другой стороны, у опытного разработчика таких проблем и вовсе не должно возникать: достаточно, написав выражение i < 0 && domain[j] == '.', попробовать доказать, что индекс jвсегда неотрицателен, а когда это не удастся, придумать контрпример — это и будет упомянутый ранее юнит-тест.
 4. Считывание лишней пустой строки в ReadDomains. Найти эту ошибку помог бы почти любой юнит-тест на эту функцию, но его написание было осложнено тем, что входной поток нельзя было переопределить и всегда использовался cin.
 5. Перепутанные "Good" и "Bad". Не допустить эту ошибку помогла бы грамотная декомпозиция программы. Функция (метод) с названием вида «является ли данный домен поддоменом одного из доменов набора» возвращала бы понятный bool, а затем при выводе понадобилось бы лишний раз подумать: если данный домен является поддоменом, это "Good" или "Bad"?
 6. Забаненные домены перевёрнуты, а обычные нет. Эта ошибка возникла из-за фатального семантического недостатка архитектуры кода. А именно, сущность «домен» в разные моменты жизни является либо обычной записью домена, либо перевёрнутой. Такой неоднозначности стоит максимально избегать: лучше написать кастомный компаратор, сравнивающий домены с конца, чем переворачивать домены ради упрощения кода. Эту проблему, как и предыдущую, помогли бы обнаружить юнит-тесты на функции (методы), на которые стоило бы разбить main.
 7. Передача в IsSubdomain перевёрнутых доменов вместо обычных. Такие проблемы на стыке двух участков кода (функция ожидала обычных доменов, а основной алгоритм оперировал перевёрнутыми) довольно типичны для командных проектов и обнаруживаются тестами. Впрочем, ошибка из этого пункта той же природы, что и из предыдущего.
 8. Их можно было избежать, если выполнить декомпозицию программы:
*/

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

template<typename It>
class Range {
public:
    Range(It begin, It end) : begin_(begin), end_(end) {}
    It begin() const { return begin_; }
    It end() const { return end_; }
    
private:
    It begin_;
    It end_;
};

pair<string_view, optional<string_view>> SplitTwoStrict(string_view s, string_view delimiter = " ") {
    const size_t pos = s.find(delimiter);
    if (pos == s.npos) {
        return {s, nullopt};
    } else {
        return {s.substr(0, pos), s.substr(pos + delimiter.length())};
    }
}

vector<string_view> Split(string_view s, string_view delimiter = " ") {
    vector<string_view> parts;
    if (s.empty()) {
        return parts;
    }
    while (true) {
        const auto [lhs, rhs_opt] = SplitTwoStrict(s, delimiter);
        parts.push_back(lhs);
        if (!rhs_opt) {
            break;
        }
        s = *rhs_opt;
    }
    return parts;
}


class Domain {
public:
    explicit Domain(string_view text) {
        vector<string_view> parts = Split(text, ".");
        parts_reversed_.assign(rbegin(parts), rend(parts));
    }
    
    size_t GetPartCount() const {
        return parts_reversed_.size();
    }
    
    auto GetReversedParts() const {
        return Range(begin(parts_reversed_), end(parts_reversed_));
    }
    
private:
    vector<string> parts_reversed_;
};

// domain is subdomain of itself
bool IsSubdomain(const Domain& subdomain, const Domain& domain) {
    const auto subdomain_reversed_parts = subdomain.GetReversedParts();
    const auto domain_reversed_parts = domain.GetReversedParts();
    return
    subdomain.GetPartCount() >= domain.GetPartCount()
    && equal(begin(domain_reversed_parts), end(domain_reversed_parts),
             begin(subdomain_reversed_parts));
}

bool IsSubOrSuperDomain(const Domain& lhs, const Domain& rhs) {
    return lhs.GetPartCount() >= rhs.GetPartCount()
    ? IsSubdomain(lhs, rhs)
    : IsSubdomain(rhs, lhs);
}


class DomainChecker {
public:
    template <typename InputIt>
    DomainChecker(InputIt domains_begin, InputIt domains_end) {
        sorted_domains_.reserve(distance(domains_begin, domains_end));
        for (const Domain& domain : Range(domains_begin, domains_end)) {
            sorted_domains_.push_back(&domain);
        }
        sort(begin(sorted_domains_), end(sorted_domains_), IsDomainLess);
        sorted_domains_ = AbsorbSubdomains(move(sorted_domains_));
    }
    
    // Check if candidate is subdomain of some domain
    bool IsSubdomain(const Domain& candidate) const {
        const auto it = upper_bound(
                                    begin(sorted_domains_), end(sorted_domains_),
                                    &candidate, IsDomainLess);
        if (it == begin(sorted_domains_)) {
            return false;
        }
        return ::IsSubdomain(candidate, **prev(it));
    }
    
private:
    vector<const Domain*> sorted_domains_;
    
    static bool IsDomainLess(const Domain* lhs, const Domain* rhs) {
        const auto lhs_reversed_parts = lhs->GetReversedParts();
        const auto rhs_reversed_parts = rhs->GetReversedParts();
        return lexicographical_compare(
                                       begin(lhs_reversed_parts), end(lhs_reversed_parts),
                                       begin(rhs_reversed_parts), end(rhs_reversed_parts)
                                       );
    }
    
    static vector<const Domain*> AbsorbSubdomains(vector<const Domain*> domains) {
        domains.erase(
                      unique(begin(domains), end(domains),
                             [](const Domain* lhs, const Domain* rhs) {
                                 return IsSubOrSuperDomain(*lhs, *rhs);
                             }),
                      end(domains)
                      );
        return domains;
    }
};


vector<Domain> ReadDomains(istream& in_stream = cin) {
    vector<Domain> domains;
    
    size_t count;
    in_stream >> count;
    domains.reserve(count);
    
    for (size_t i = 0; i < count; ++i) {
        string domain_text;
        in_stream >> domain_text;
        domains.emplace_back(domain_text);
    }
    return domains;
}

vector<bool> CheckDomains(const vector<Domain>& banned_domains, const vector<Domain>& domains_to_check) {
    const DomainChecker checker(begin(banned_domains), end(banned_domains));
    
    vector<bool> check_results;
    check_results.reserve(domains_to_check.size());
    for (const Domain& domain_to_check : domains_to_check) {
        check_results.push_back(!checker.IsSubdomain(domain_to_check));
    }
    
    return check_results;
}

void PrintCheckResults(const vector<bool>& check_results, ostream& out_stream = cout) {
    for (const bool check_result : check_results) {
        out_stream << (check_result ? "Good" : "Bad") << "\n";
    }
}

int main() {
    const vector<Domain> banned_domains = ReadDomains();
    const vector<Domain> domains_to_check = ReadDomains();
    PrintCheckResults(CheckDomains(banned_domains, domains_to_check));
    return 0;
}

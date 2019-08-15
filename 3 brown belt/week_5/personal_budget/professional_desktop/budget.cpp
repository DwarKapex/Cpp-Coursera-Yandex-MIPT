#include "test_runner.h"

#include <iostream>
#include <optional>
#include <cstdint>
#include <ctime>
#include <string>
#include <tuple>
#include <numeric>

using namespace std;

//===========================================================================================
struct Date{
    
    Date() = default;
    Date(int year, int month, int day);
    
    time_t AsTimestamp() const ;
    friend bool operator==(const Date&, const Date&);
    friend istream& operator >> (istream&, Date&);
    friend ostream& operator << (ostream&, const Date&);
    
    int year_ = 2000, month_ = 1, day_ = 1;
};




Date::Date(int year, int month, int day):
year_(year),
month_(month),
day_(day)
{}

time_t Date::AsTimestamp() const {
    std::tm t;
    t.tm_sec   = 0;
    t.tm_min   = 0;
    t.tm_hour  = 0;
    t.tm_mday  = day_;
    t.tm_mon   = month_ - 1;
    t.tm_year  = year_ - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
}

bool operator==(const Date& first, const Date& second) {
    return make_tuple(first.year_, first.month_, first.day_) ==
    make_tuple(second.year_, second.month_, second.day_);
}

istream& operator>>(istream& input, Date& date){
    input >> date.year_;
    input.ignore(1);
    input >> date.month_;
    input.ignore(1);
    input >> date.day_;
    return input;
}

ostream& operator << (ostream& output, const Date& date){
    output << date.year_ << '-' << date.month_ << '-' << date.day_;
    return output;
}


int ComputeDaysDiff(const Date& date_to, const Date& date_from) {
    const time_t timestamp_to = date_to.AsTimestamp();
    const time_t timestamp_from = date_from.AsTimestamp();
    static const int SECONDS_IN_DAY = 60 * 60 * 24;
    return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

//===========================================================================================
enum QueryRequest{
    EARN,
    SPEND,
    PAY_TAX,
    COMPUTE_INCOME
};

struct Query{
    
    
    QueryRequest request_;
    Date date_from, date_to;
    optional<uint32_t> value_=nullopt;
    
    friend istream& operator >> (istream& input, Query& q){
        string query_request;
        input >> query_request >> q.date_from >> q.date_to;
        if (query_request == "Earn"){
            q.request_ = QueryRequest::EARN;
            input >> *q.value_;
        }
        else if (query_request == "Spend"){
            q.request_ = QueryRequest::SPEND;
            input >> *q.value_;
        }
        else if (query_request == "PayTax"){
            q.request_ = QueryRequest::PAY_TAX;
            input >> *q.value_;
        }
        else{
            q.request_ = QueryRequest::COMPUTE_INCOME;
        }
        return input;
    }
    
    friend ostream& operator << (ostream& output, const Query& q){
        if (q.request_ == QueryRequest::EARN)
            output << "Earn " << q.date_from << ' ' << q.date_to << ' ' << *q.value_;
        else if (q.request_ == QueryRequest::SPEND)
            output << "Spend " << q.date_from << ' ' << q.date_to << ' ' << *q.value_;
        else if (q.request_ == QueryRequest::PAY_TAX)
            output << "PayTax " << q.date_from << ' ' << q.date_to << ' ';
        else{
            output << "ComputeIncome " << q.date_from << ' ' << q.date_to << ' ' << *q.value_;
        }
        return output;
    }
    
    friend bool operator==(const Query& first, const Query& second){
        return make_tuple(first.request_, first.date_from, first.date_to, *first.value_) == make_tuple(second.request_, second.date_from, second.date_to, *second.value_);
    }
};



class PersonalBudget{
public:
    PersonalBudget() = default;
    PersonalBudget& Earn(const Date& from, const Date& to, double value);
    PersonalBudget& Spend(const Date& from, const Date& to, double value);
    PersonalBudget& PayTax(const Date& from, const Date& to, int persentage);
    double ComputeIncome(const Date& from, const Date& to);
    optional<double> ProcessRequest(const Query& request);
    
private:
    
    int daysFrom2000(const Date& date) const {
        return ComputeDaysDiff(date, {});
    }
    
    static constexpr int days_in_XXI_century = 36600;
    vector<double> earn=vector<double>(days_in_XXI_century, 0.0);
    vector<double> spend=vector<double>(days_in_XXI_century, 0.0);
    static constexpr Date begin_XXI_century = {};
};

PersonalBudget& PersonalBudget::Earn(const Date& date_from, const Date& date_to, double value){
    uint32_t days_count = ComputeDaysDiff(date_to, date_from)+1;
    int start_day = ComputeDaysDiff(date_from, begin_XXI_century),
    end_day = start_day+days_count;
    const auto amountPerDay = value/days_count;
    for (int i = start_day; i < end_day; ++i)
        earn[i] += amountPerDay;
    
    return *this;
}

PersonalBudget& PersonalBudget::Spend(const Date& date_from, const Date& date_to, double value){
    uint32_t days_count = ComputeDaysDiff(date_to, date_from)+1;
    int start_day = ComputeDaysDiff(date_from, begin_XXI_century),
    end_day = start_day+days_count;
    const auto amountPerDay = value/days_count;
    for (int i = start_day; i < end_day; ++i)
        spend[i] += amountPerDay;
    
    return *this;
}


PersonalBudget& PersonalBudget::PayTax(const Date& date_from, const Date& date_to, int persentage){
    const double afterTax = (100.0 - persentage) / 100.0;
    int start_day = ComputeDaysDiff(date_from, begin_XXI_century),
    end_day = ComputeDaysDiff(date_to, begin_XXI_century);
    for (int i = start_day; i <= end_day; ++i){
        earn[i] *= afterTax;
    }
    return *this;
}

double PersonalBudget::ComputeIncome(const Date& date_from, const Date& date_to){
    int start_day = ComputeDaysDiff(date_from, begin_XXI_century),
        end_day = ComputeDaysDiff(date_to, begin_XXI_century);
    double total_earn = accumulate(earn.begin()+start_day, earn.begin()+end_day+1, 0.0);
    double total_spend = accumulate(spend.begin()+start_day, spend.begin()+end_day+1, 0.0);
    return total_earn-total_spend;
}

optional<double> PersonalBudget::ProcessRequest(const Query& request){
    switch (request.request_){
        case QueryRequest::EARN:
            Earn(request.date_from, request.date_to, *request.value_);
            break;
        case QueryRequest::SPEND:
            Spend(request.date_from, request.date_to, *request.value_);
            break;
        case QueryRequest::PAY_TAX:
            PayTax(request.date_from, request.date_to, *request.value_);
            break;
        case QueryRequest::COMPUTE_INCOME:
            return ComputeIncome(request.date_from, request.date_to);
    }
    return nullopt;
}


void TestDateInput(){
    {
        Date d;
        stringstream ss;
        ss << "2000-5-12";
        ss >> d;
        ASSERT_EQUAL(d, Date(2000,5,12));
    }
    {
        Date a{2000,1,5}, b {2000,1,5};
        ASSERT_EQUAL(ComputeDaysDiff(a, b), 0);
    }
    {
        Date a{2000,1,1}, b{2000,1,1};
        ASSERT_EQUAL(ComputeDaysDiff(b, a), 0);
    }
    
}

void TestQueryInput(){
    {
        Query q;
        stringstream ss;
        ss << "Earn 2000-1-1 2000-5-4 50";
        ss >> q;
        ss << q;
        ASSERT_EQUAL(ss.str(), "Earn 2000-1-1 2000-5-4 50");
    }
    {
        Query q;
        stringstream ss;
        ss << "Spend 2000-1-1 2000-5-4 50";
        ss >> q;
        ss << q;
        ASSERT_EQUAL(ss.str(), "Spend 2000-1-1 2000-5-4 50");
    }

    {
        Query q;
        stringstream ss;
        ss << "PayTax 2000-1-1 2000-5-4 50";
        ss >> q;
        ss << q;
        ASSERT_EQUAL(ss.str(), "PayTax 2000-1-1 2000-5-4 50");
    }
    {
        Query q;
        stringstream ss;
        ss << "ComputeIncome 2000-1-1 2000-5-4";
        ss >> q;
        ss << q;
        ASSERT_EQUAL(ss.str(), "ComputeIncome 2000-1-1 2000-5-4");
    }

}

void TestBudget(){
    {
        PersonalBudget bd;
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 0);
        bd.Earn({2000,1,1}, {2000,1,5}, 20);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 20.0);
        bd.PayTax({2000,1,1}, {2000,1,2}, 13);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 18.96);
        bd.Earn({2000,1,2}, {2000,1,2}, 10);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 28.96);
        bd.PayTax({2000,1,2}, {2000,1,2}, 13);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 27.2076);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2000,1,1}), 3.48);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,2}, {2000,1,2}), 11.7276);
    }
    {
        PersonalBudget bd;
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 0);
        bd.Earn({2000,1,1}, {2000,1,5}, 20);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 20.0);
        bd.PayTax({2000,1,1}, {2000,1,2}, 13);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 18.96);
        bd.Spend({2000,12,30}, {2001,01,02}, 14);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 8.46);
        bd.PayTax({2000,12,30}, {2000,12,30}, 13);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 8.46);
    }
    {
        PersonalBudget bd;
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 0.0);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 0.0);
        bd.PayTax({2000,1,1}, {2000,1,2}, 13);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), 0.0);
        bd.Spend({2000,12,30}, {2001,01,02}, 12);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), -9.0);
        bd.PayTax({2000,12,30}, {2000,12,30}, 13);
        ASSERT_EQUAL(bd.ComputeIncome({2000,1,1}, {2001,1,1}), -9.0);
    }

}

int main() {
    TestRunner tr;
    //RUN_TEST(tr, TestDateInput);
    //RUN_TEST(tr, TestQueryInput);
    //RUN_TEST(tr, TestBudget);
    
    
    PersonalBudget bd;
    int Q = 0;
    cin >> Q;
    Query request;
    cout.precision(20);
    while (Q-- >0){
        cin >> request;
        auto result = bd.ProcessRequest(request);
        if (result)
            cout << *result << '\n';
    }
    
    return 0;
}

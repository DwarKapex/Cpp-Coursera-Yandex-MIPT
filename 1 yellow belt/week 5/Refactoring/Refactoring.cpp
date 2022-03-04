#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
    Person(const string& type, const string& name) :
    m_type(type), m_name(name) {}
    
    virtual ~Person() = default;
    
    virtual void Walk(const string& destination) {
        cout << Log() << " walks to: " << destination << endl;
    }
    
    string Log() const {
        return (m_type + ": " + m_name);
    }
    
    void DoAction(const string& action) const {
        cout << m_type << ": " << m_name << " " << action << endl;
    }
    
    string name() const { return m_name; };
    string type() const { return m_type; };
    
private:
    const string m_type;
    const string m_name;
};


class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) :
    Person("Student", name), FavouriteSong(favouriteSong) {}
    
    void Learn() {
        DoAction("learns");
    }
    
    void Walk(const string& destination) override {
        Person::Walk(destination);
        SingSong();
    }
    
    void SingSong() {
        DoAction("sings a song: " + FavouriteSong);
    }
    
private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) :
    Person("Teacher", name), Subject(subject) {}
    
    void Teach() {
        DoAction("teaches: " + Subject);
    }
    
private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) :
    Person("Policeman", name) {}
    
    void Check(const Person& p) {
        DoAction("checks " + p.type() + ". "
                 + p.type() + "'s name is: " + p.name());
    }
};

void VisitPlaces(Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}
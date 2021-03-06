//
// Created by SebDixon on 23/06/21.
//

#ifndef UNTITLED_INHERIT_H
#define UNTITLED_INHERIT_H

#include <string>
#include <iostream>

enum Sex{
    MALE,
    FEMALE,
};

class Person  {
private:
    std::string m_name{};
    int m_age{};
    Sex m_sex{};
public:
    explicit Person(const std::string &name = "", int age = 0, Sex sex = MALE)
    : m_name{name}, m_age{age}, m_sex{sex} {
        std::cout << "base class constructor called first\n";
    }

    const std::string& get_name() const {
        return m_name;
    }

    int get_age() const {
        return m_age;
    }

    Sex get_sex() const {
        return m_sex;
    }
};

class Athlete : public Person {
private:
    std::string m_sport{};
    double m_weight{};
public:
    // call base class constructor of choice to initialise base class variables
    Athlete(const std::string &name, int age, Sex sex,
            const std::string &sport, double weight)
    : Person{name, age, sex}, m_sport{sport}, m_weight{weight} {
        std::cout << "child class constructor called next\n";
    }

    std::string get_sport() const {
        return m_sport;
    }

    double get_weight() const {
        return m_weight;
    }
};

class ParaAthlete : public Athlete {
private:
    std::string m_disability{};
public:
    ParaAthlete(const std::string &name, int age, Sex sex,
                const std::string &sport, double weight, std::string dis)
                : Athlete(name, age, sex, sport, weight), m_disability{dis} {}
};

class Base {
private:
    int m_private;
protected:
    int m_protect;
public:
    int m_public;

    Base(int priv, int protec, int pub)
    : m_private{priv}, m_protect{protec}, m_public{pub} {}

    int get_private() const {
        return m_private;
    }

    int get_protected() const {
        return m_protect;
    }

    int get_public() const {
        return m_public;
    }

    void identify() {
        std::cout << "I am Base class\n";
    }

    void chain() {
        std::cout << "Base class call\n";
    }

};

class Derived : public Base {
public:
    Derived(int priv, int protec, int pub) : Base(priv, protec, pub) {}

    void view_members() {
        std::cout << get_private() << '\n'; // private member accessed using getter function
        std::cout << m_protect << '\n'; // protected member directly accessed given public inheritance
        std::cout << m_public << '\n'; // public member always directly accessible
    }

    void identify() {   // overrides base class member function
        std::cout << "I am Derived class\n";
    }

    void chain() {
        Base::chain();  // call to base class member function to add functionality
        std::cout << "Derived class call\n";
    }
};

class PrivateDerived : private Base {
public:
    PrivateDerived(int priv, int protec, int pub) : Base(priv, protec, pub) {}

    void view_members() {
        std::cout << get_private() << '\n'; // all non-private member functions now private
        std::cout << get_protected() << '\n'; // protected member inside Base now private member variable
        std::cout << get_public() << '\n'; // public member inside Base now private member variable
    }

};

class Parent{
private:
    int m_value;
public:
    Parent(int val) : m_value{val} {}

    Parent(const Parent& pt) : Parent(pt.m_value) {}

    friend std::ostream& operator<<(std::ostream& out, const Parent &pt) {
        out << pt.m_value;
        return out;
    }
protected:
    void print() {
        std::cout << m_value;
    }
};

class Child : private Parent{
public:
    Child(int val) : Parent(val) {}

    Child(const Parent& pt) : Parent(pt) {}

    friend std::ostream& operator<<(std::ostream& out, const Child &ch) {
        out << static_cast<const Parent&>(ch);  // overridden operator using static cast
        return out;
    }

    using Parent::print;
    // using keyword changes access specifier of inherited member variable to current access region
};

class Father{
private:
    std::string m_name{};
public:
    explicit Father(std::string name = "Father") : m_name{name} {}

    Father(const Father &father) {
        m_name = father.m_name;
    }

    std::string get_father() {
        return m_name;
    }
};

class Mother{
private:
    std::string m_name{};
public:
    explicit Mother(std::string name = "Mother") : m_name{name} {}

    Mother(const Mother& mother) {
        m_name = mother.m_name;
    }

    std::string get_mother() {
        return m_name;
    }
};

class Son : public Father, public Mother {  // multiple inheritance, avoid unless best solution
private:
    std::string m_name{};
public:
    Son(std::string name) : m_name{name} {}

    Son(std::string name, std::string father, std::string mother)
    : m_name{name}, Father{father}, Mother{mother} {}

    Son(std::string name, const Father &father, const Mother &mother)
    : m_name{name}, Father{father}, Mother{mother} {}

    std::string get_son() {
        return m_name;
    }
};



#endif //UNTITLED_INHERIT_H

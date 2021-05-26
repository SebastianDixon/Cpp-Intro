#include <iostream>
#include <vector>

class DateClass{    // similar to struct, blueprint for objects
    int day{};  // class members are private by default, public keyword overwrites this
    int month{};    // private members can be only be accessed by other members
    int year{};

public:// class members are private by default, public keyword overwrites this
    void printDate(){   // member functions which are normally common operations for the class data
        std::cout << day << "/" << month << "/" << year << '\n';
    }

    void set(int d, int m, int y){  // public members can be accessed by anyone
        day = d;    // set() can access private member day, given it is a member of the same class
        month = m;
        year = y;
    }

    void copy(const DateClass &d){  // access to private members allowed through public function
        day = d.day;
        month = d.month;
        year = d.year;
    };
};

void objectcreation(){
    DateClass bday{};    // member object initialisation
    bday.set(22, 7, 2002);
    bday.printDate();   // the member function takes the class object passed to it

    DateClass invitationDate{};
    invitationDate.copy(bday);
    invitationDate.printDate();
}

class Calc{
public:
    using datatype = int;   // a local alias namespace can be used, faster change of data type later

    std::vector<datatype> op_history{};

    datatype add(datatype x, datatype y){
        datatype result{x + y};
        op_history.push_back(result);
        return result;
    }
};

void addnums(){
    Calc operation{};
    operation.add(5, 6);
    operation.add(3, 9);

    for (Calc::datatype iterator : operation.op_history) {
        std::cout << iterator << " ";
    }
}

int main(){
    objectcreation();
    return 0;
}
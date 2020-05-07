#include <iostream>
#include <string>

using namespace std;

class Meat
{
    protected:
    double protein;
    double price;

    string animal;

    public:
    Meat(){}

    Meat(double protein, double price, string animal)
    {
        this->protein = protein;
        this->price = price;
        this->animal = animal;
    }

    ~Meat(){}

    friend void externalFunction(Meat & meatStats);

    void meatStats()
    {
        cout << protein << price << animal << endl;
    }
};

void externalFunction(Meat &meatStats)
{
    cout << "External function accessed" << endl;
}


class Steak: public Meat
{
    private:
    enum cooked {rare=1, mediumrare, medium, welldone};
    string animal = "Cow";

    public:
    Steak(){}

    Steak(double protein, double price)
    {
        this-> protein = protein;
        this-> price = price;
    }

    ~Steak(){}

    void howDone(string val)
    {
        if (val == "rare")
        {
            cooked choice {rare};
        }
        else if (val == "mediumrare")
        {
            cooked choice {mediumrare};
        }
        else if (val == "medium")
        {
            cooked choice {medium};
        }
        else if (val == "welldone")
        {
            cooked choice {welldone};
        }
        else
        {
            string choice;
            cout << "choose from rare, mediumrare, medium, welldone: ";
            cin >> choice;
            howDone(choice);
        }

    }


};


int main()
{
    cout << "choose from rare, mediumrare, medium, welldone" << endl;

    Meat jerky{4.0, 2.0, "Cow"};
    jerky.meatStats();

    Steak sebsSteak{25.0, 50.0};
    sebsSteak.howDone("rare");

    externalFunction(jerky);

    return 0;
}

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Person {

public:

    string name;
    string surname;

    Person() {
        //  cout << "Object Person has created" << endl;
    }

    Person(string name_, string surname_) : name{ name_ }, surname{ surname_ } {
        // cout << "Object Person has created" << endl;
    }
    Person(const Person& obj) {
        name = obj.name;
        surname = obj.surname;
    }

    ~Person() {

    };

    void seePerson() {
        cout << "Your name and surname:" << endl;
        cout << name << " " << surname << endl;
    }



};
class Flat {
public:

    vector<vector<string>> flat;

    Flat() {
        //   cout << "Object Flat has created" << endl;
    }

    Flat(const Flat& obj) {
        flat = obj.flat;
    }

    ~Flat() {

    };

    void addPerson(Person person) {

        vector<string> person_ = { person.name, person.surname };
        flat.push_back(person_);

    }

    void seePeople() {
        cout << "Your Flat:" << endl;
        for (vector<string> person : flat) {
            for (string per : person) {
                cout << per << " ";
            }
            cout << endl;
        }
    }

};
class House {

    vector<vector<vector<string>>> house;

public:

    House() {
        //  cout << "Object House has created" << endl;
    }

    House(const House& obj) {
        house = obj.house;
    }

    ~House() {

    };

    void addFlat(Flat ourFlat) {
        house.push_back(ourFlat.flat);
    }

    void seeHouse() {
        int i = 1;
        cout << "Your House:" << endl;
        for (vector<vector<string>> flat : house) {
            cout << "Flat" << i << ":" << endl;
            i++;
            for (vector<string> person : flat) {
                for (string per : person) {
                    cout << per << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

};


int main()
{

    Person p1("Roman", "Kryvenko");
    Person p2("Sergui", "Romanchuk");

    Flat fl1;
    fl1.addPerson(p1);
    fl1.addPerson(p2);

    Person p1_("Pavlo", "Datsenko");

    Flat fl2;
    fl2.addPerson(p1_);

    Person p1_1("Maria", "Polishuk");
    Person p2_1("Mykola", "Shevchenko");

    Flat fl3;
    fl3.addPerson(p1_1);
    fl3.addPerson(p2_1);

    House OurHouse;
    OurHouse.addFlat(fl1);
    OurHouse.addFlat(fl2);
    OurHouse.addFlat(fl3);

    OurHouse.seeHouse();

}

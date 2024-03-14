#include <iostream> 
#include <string> 
#include <list> 
#include <fstream>
#include <vector>

using namespace std;

class telBook {


    list<list<string>> tel_book;

    list<string> person;

    string name;
    string telW;
    string telH;
    string info;

public:

    //   telBook(string name_, string telW_, string telH_, string info_) :
    //       name{ name_ }, telW{ telW_ }, telH{ telH_ }, info{ info_ } {
    //
    //   };

    void addSubscriber() {
        string name_;
        string telW_;
        string telH_;
        string info_;
        cout << "Enter info about Subscriber.." << endl;
        cout << "Name: ";
        cin >> name_;
        cout << "Work telephone: ";
        cin >> telW_;
        cout << "Home telephone: ";
        cin >> telH_;
        cout << "Additional info: ";
        cin >> info_;
        cout << "Subsctibes has successfuly added!" << endl;
        name = name_;
        telH = telH_;
        telW = telW_;
        info = info_;

        person.push_back(name);
        person.push_back(telW);
        person.push_back(telH);
        person.push_back(info);

        tel_book.push_front(person);
        person.clear();
    }

    void printBook() {
        cout << endl;
        cout << "Your telephone book: " << endl;
        int i = 1;
        for (list<string> per : tel_book) {
            cout << i << ". ";
            for (string el : per) {
                cout << el << " ";
            }
            cout << endl;
            i++;
        }
    }
    void saveToFile(const string& filename)  const {
        ofstream file(filename);
        if (file.is_open()) {
            int i = 1;
            for (list<string> per : tel_book) {
                for (string el : per) {
                    file << i << ". " << el << " " << endl;
                    i++;
                }
            }
            cout << "File was successfuly saved" << endl;
        }
    };
    void loadFile(const string& filename) const {
        ifstream file(filename);
        if (file.is_open()) {
            int i = 1;
            for (list<string> per : tel_book) {
                for (string el : per) {
                    file >> i >> el;
                    i++;
                }
            }
            cout << "File was successfuly loaded" << endl;
        }
    }
    list<string> findSub(string name_) {
        for (list<string> per : tel_book) {
            for (string el : per) {
                if (el == name) {
                    return per;
                }
            }
        }
    }
    void deleteSub(string name_) {
        for (list<string> per : tel_book) {
            for (string el : per) {
                if (el == name_) {
                    per.clear();
                }
            }
        }
    }

};

int main()
{
    telBook sub;
    sub.addSubscriber();
    //   sub.addSubscriber(); 
    sub.printBook();
    string a;
    cin >> a;
    for (string el : sub.findSub(a)) {
        cout << el << " ";
    }

}
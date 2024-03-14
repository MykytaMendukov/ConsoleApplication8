#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

class Reservoir {

    string name;
    float width, height, length;

    float volume;
    float square;
    string type;

public:

    Reservoir() : name("Indefined name"), width(1.), height(1.), length(1.) {

    }

    explicit Reservoir(const string name_, float width_, float height_, float length_) : name{ name_ }, width{ width_ }, height{ height_ }, length{ length_ } {

    };

    Reservoir(const Reservoir& obj) {
        name = obj.name;
        width = obj.width;
        height = obj.height;
        length = obj.length;
    }

    ~Reservoir() {

    }

    friend ostream& operator << (ostream& out, Reservoir& obj);

    bool operator > (Reservoir& obj) {
        return this->findSquare() > obj.findSquare();
    }


    float findVolume() {
        volume = width * height * length;

        return volume;
    }

    float findSquare() {
        square = width * length;

        return square;

    }

    void determineTheType() {
        if (square < 62000) {
            type = "Pool";
        }
        else if (square >= 62000 || square < 39000000) {
            type = "lake";
        }
        else if (square >= 39000000) {
            type = "Sea";
        }
    }

    void displayInfo() const {
        cout << "Your reservoir" << endl;
        cout << "Name: " << name << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Length: " << length << endl;
    }

};


ostream& operator << (ostream& out, Reservoir& obj) {

    out << "Your reservoir" << endl;
    out << "Name: " << obj.name << endl;
    out << "Width: " << obj.width << endl;
    out << "Height: " << obj.height << endl;
    out << "Length: " << obj.length << endl;
    out << "Volume: " << obj.findVolume() << endl;
    out << "Square: " << obj.findSquare() << endl;

    return out;

}

class Reservoirs {

    vector<Reservoir> resArray;

public:

    void addItem(Reservoir& res) {
        resArray.push_back(res);
    }

    void removeItem(int index) {
        if (index >= 0 && index < resArray.size()) {
            resArray.erase(resArray.begin() + index);
        }
        else {
            cout << "Error!" << endl;
        }
    }

    void saveToTextFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const Reservoir& reservoir : resArray) {
                reservoir.displayInfo();
            }
            file.close();
            cout << "Success" << endl;
        }
        else {
            cout << "Error!" << endl;
        }
    }

    void saveToBinaryFile(const string& filename) const {
        ofstream outFile(filename, std::ios::binary);
        if (outFile.is_open()) {
            for (const Reservoir& reservoir : resArray) {
                outFile.write(reinterpret_cast<const char*>(&reservoir), sizeof(Reservoir));
            }
            outFile.close();
            cout << "Succes" << endl;
        }
        else {
            cerr << "Error!" << endl;
        }
    }

    void displayItems() {
        int i = 1;
        cout << "All reservoirs:" << endl;
        for (const Reservoir& reservoir : resArray) {
            cout << i << "." << endl;
            reservoir.displayInfo();
            i++;
        }
    }

};

int main()
{
    Reservoirs res;

    Reservoir r1("Lake", 100, 200, 16);
    Reservoir r2("Pool", 50, 100, 40);

    cout << r1 << endl;
    cout << r2 << endl;

    res.addItem(r1);
    res.addItem(r2);

    res.displayItems();

    res.saveToTextFile("reservoid.text");
    res.saveToBinaryFile("reservoir.dat");

}

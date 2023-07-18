#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler {
private:
    string file_name;
    ifstream infile;
    ofstream outfile;

public:
    FileHandler(const string& filename) : file_name(filename) {}

    bool openFileForReading() {
        infile.open(file_name);
        return infile.is_open();
    }

    bool openFileForWriting() {
        outfile.open(file_name);
        return outfile.is_open();
    }

    void closeFile() {
        if (infile.is_open())
            infile.close();
        if (outfile.is_open())
            outfile.close();
    }

    string readLine() {
        string line;
        getline(infile, line);
        return line;
    }

    void writeLine(const string& line) {
        outfile << line << endl;
    }
};

int main() {
    FileHandler file("Sayilar.txt");

    if (file.openFileForWriting()) {
        file.writeLine("Hello, World!");
        file.writeLine("This is a test.");
        file.closeFile();
    } else {
        cout << "Failed to open the file for writing." << endl;
    }

    if (file.openFileForReading()) {
        string line;
        while ((line = file.readLine()) != "") {
            cout << line << endl;
        }
        file.closeFile();
    } else {
        cout << "Failed to open the file for reading." << endl;
    }

    return 0;
}

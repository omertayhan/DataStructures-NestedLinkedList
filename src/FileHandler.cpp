#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler
{
private:
    string file_name;
    ifstream infile;
    ofstream outfile;

public:
    FileHandler(const string &filename) : file_name(filename) {}

    bool openFileForReading()
    {
        infile.open(file_name);
        return infile.is_open();
    }

    bool openFileForWriting()
    {
        outfile.open(file_name);
        return outfile.is_open();
    }

    void closeFile()
    {
        if (infile.is_open())
            infile.close();
        if (outfile.is_open())
            outfile.close();
    }

    string readLine()
    {
        string line;
        getline(infile, line);
        return line;
    }

    void writeLine(const string &line)
    {
        outfile << line << endl;
    }
};
#include "FileHandler.hpp"
using namespace std;

FileHandler::FileHandler(const string &filename) : file_name(filename) {}

bool FileHandler::openFileForReading()
{
    infile.open(file_name);
    return infile.is_open();
}

void FileHandler::closeFile()
{
    if (infile.is_open())
        infile.close();
}

vector<int> FileHandler::readIntegersFromLine(const string &line, vector<int> &tens, vector<int> &ones)
{
    vector<int> numbers;
    istringstream iss(line);
    int num;
    while (iss >> num)
    {
        numbers.push_back(num);
        tens.push_back(num / 10);
        ones.push_back(num % 10);
    }
    return numbers;
}

void FileHandler::processFileAndDisplayArrays()
{
    if (openFileForReading())
    {
        vector<vector<int>> arrays;
        vector<vector<int>> arraysTens;
        vector<vector<int>> arraysOnes;
        string line;

        // Read each line and store numbers in separate arrays
        while (getline(infile, line))
        {
            vector<int> numbers;
            vector<int> tens;
            vector<int> ones;
            numbers = readIntegersFromLine(line, tens, ones);
            arrays.push_back(numbers);
            arraysTens.push_back(tens);
            arraysOnes.push_back(ones);
        }

        closeFile();

        // Display the content of each array
        cout << "Numbers: " << endl;
        for (const auto &arr : arrays)
        {
            for (int num : arr)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        cout << "Tens: " << endl;
        for (const auto &arr : arraysTens)
        {
            for (int num : arr)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        cout << "Ones: " << endl;
        for (const auto &arr : arraysOnes)
        {
            for (int num : arr)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cerr << "Failed to open the file for reading." << endl;
    }
}

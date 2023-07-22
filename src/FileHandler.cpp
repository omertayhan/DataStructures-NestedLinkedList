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
ifstream &FileHandler::getInfile()
{
    return infile;
}
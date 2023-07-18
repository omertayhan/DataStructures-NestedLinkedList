#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class FileHandler
{
private:
    std::string file_name;
    std::ifstream infile;

public:
    FileHandler(const std::string &filename);

    bool openFileForReading();
    void closeFile();
    std::vector<int> readIntegersFromLine(const std::string &line, std::vector<int>& tens, std::vector<int>& ones);
    void processFileAndDisplayArrays();
};

#endif /* FILEHANDLER_HPP */

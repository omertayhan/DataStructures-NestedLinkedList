/** 
* @file Filehandler.hpp
* @description File Handler for txt
* @course VERİ YAPILARI 1. Öğretim B
* @assignment 1.ÖDEV
* @date 22.7.23
* @author ÖMER TUFAN AYHAN tufan.ayhan@ogr.sakarya.edu.tr, Doğan Alperen Memur dogan.memur@ogr.sakarya.edu.tr 
*/
#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class FileHandler
{
private:
    std::string file_name;
    std::ifstream infile;

public:
    FileHandler(const std::string &filename);

    bool openFileForReading();
    void closeFile();
    std::ifstream &getInfile();
};

#endif /* FILEHANDLER_HPP */

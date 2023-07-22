/** 
* @file Filehandler.cpp
* @description File Handler for txt
* @course VERİ YAPILARI 1. Öğretim B
* @assignment 1.ÖDEV
* @date 22.7.23
* @author ÖMER TUFAN AYHAN tufan.ayhan@ogr.sakarya.edu.tr
*/
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
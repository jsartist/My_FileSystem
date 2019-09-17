#pragma once
#ifndef __FILESYSTEM__
#define __FILESYSTEM__
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#pragma warning(disable:4996)
using namespace std;

class FileSystem {
private:
 string address;
 ofstream os;
 ifstream is;
public:
 FileSystem(string address) : address(address) {
  
 }
 void FileManu();
 void FileAccess(int k);
 void in();
 void ou();
 int start();
};

#endif
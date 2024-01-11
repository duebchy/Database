

#ifndef DATABASE_INCLUDES_H
#define DATABASE_INCLUDES_H

#endif //DATABASE_INCLUDES_H

#include <iostream>
#include <fstream>
#include "string"
#include "map"
#include "filesystem"
#include "iterator"
#include "algorithm"
#include "sstream"
#include "vector"



using namespace std;

using Data = map<string, string>;



map<string, int> COMMANDS = {
        {"/get", 1},
        {"/help", 2},
        {"/add", 3},
        {"/edit", 4},
        {"/delete", 5},
        {"/stop", 6},
        {"/show", 7}
};

const string bin_path = "C:/Users/vdovi/CLionProjects/DataBase/data/binlog.txt";

string binCommand;



string command;




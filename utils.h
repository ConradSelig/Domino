#ifndef UTILS_H
#define UTILS_H

#include<string>

#include "pugixml.hpp"

using namespace std;

string getCurrentDateTime(char mode='a', bool include_year=true);
void increment_version(pugi::xml_node vi, string mode);

#endif

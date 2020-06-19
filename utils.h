#ifndef UTILS_H
#define UTILS_H

#include<string>
#include<vector>

using namespace std;

string getCurrentDateTime();
void create_blank_file(string file_name);
vector<string> split(string input, char token);

#endif

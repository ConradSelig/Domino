#include<ctime>
#include<string>
#include<fstream>

#include "utils.h"

using namespace std;

string getCurrentDateTime() {
    // get the current time
    time_t curr_time = time(0);
    tm* now = localtime(&curr_time);

    char stripped_time[100];
    
    strftime(stripped_time, sizeof(stripped_time), "%a %b %d %H:%M:%S %Y", now);

    string time(stripped_time);

    return time;
}


void create_blank_file(string file_name) {
    ofstream (file_name.c_str());
    return;
}

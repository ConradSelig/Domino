#include<ctime>
#include<string>
#include<iostream>

#include "utils.h"

using namespace std;

/* 
 * modes
 *      a: "all", gives both date and time
 *      d: "date", gives only date
 *      t: "time", gives only time
*/ 
string getCurrentDateTime(char mode, bool include_year) {
    // get the current time
    time_t curr_time = time(0);
    tm* now = localtime(&curr_time);

    char stripped_time[100];
    string format;
    
    switch(mode) {
            case 'd': format = "%a %b %d"; break;
            case 't': format = "%H:%M:%S"; break;
            default: format = "%a %b %d %Y %H:%M:%S";
    }

    if(include_year) {
        format += ", %Y";
    }

    strftime(stripped_time, sizeof(stripped_time), format.c_str(), now);

    string time(stripped_time);

    return time;
}

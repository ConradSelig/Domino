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


/* 
 * modes:
 *      'mark': mark (full integer increases)
 *      'major': full version ([0-9]\..)
 *      'minor': partial version (.\.[0-9])
 */
void increment_version(pugi::xml_node vi, string mode) {
    // variable for storing the mark
    int mark;
    
    // variables for storing the major and minor versions
    string tmp;
    size_t pos = 0;
    int major;
    int minor;

    // collecting the mark from the old node
    mark = vi.attribute("mark").as_int();

    // collecting the major and minor version from the old node
    tmp = vi.attribute("version").value();
    pos = tmp.find(".");
    major = atoi(tmp.substr(0, pos).c_str());
    tmp.erase(0, pos + 1);
    minor = atoi(tmp.c_str());


    // incrimenting one of the values based off of the given mode
    if (mode == "mark") {
        mark++;
    } else if (mode == "major") {
        major++;
    } else if (mode == "minor") {
        minor++;
    } else {
        return;
    }

    vi.attribute("mark").set_value(mark);
    vi.attribute("version").set_value((to_string(major) + "." + to_string(minor)).c_str());

    return;
}

// Native includes
#include<iostream>
#include<string>
#include<fstream>

// project header files
#include "utils.h"
#include "pugixml.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    // ===== variables =====
    // name for the metadata_file
    string metadata_file_name = "metadata.xml"; 
    string tmp;

    // If command line arguments are given, use those instead of the defaults
    if(argc != 0) {
        // "metadata.xml" = argv[0];
    }

    // load metadata file
    pugi::xml_document metadata_file;
    pugi::xml_parse_result metadata = metadata_file.load_file("metadata.xml");

    // check that the file did load
    if(metadata_file) {
        cout << "XML FILE [" << metadata_file_name << "] WAS LOADED" << endl;
    } else {
        cout << "XML FILE [" << metadata_file_name << "] COULD NOT BE LOADED." << endl;
        cout << "CLOSING PROGRAM" << endl;
        return 1;
    }

    // output welcome message
    cout << endl << "Welcome back Mr.Selig." << endl;
    cout << "Your last login was on " << metadata_file.child("last_login").child_value() << "." << endl;

    pugi::xml_node vi = metadata_file.child("version_info");

    // save metadata file
    tmp = getCurrentDateTime('d', true) + " at " + getCurrentDateTime('t', false);
    metadata_file.child("last_login").last_child().set_value(tmp.c_str());
    cout << endl << "Saving metadata: " << ((metadata_file.save_file("metadata.xml") == 1) ? "Done." : "FAILED") << endl;

    return 0;
}

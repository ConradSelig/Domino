// Native includes
#include<iostream>
#include<string>
#include<fstream>

// local build includes
#include "yaml-cpp/yaml.h"

// project header files
#include "utils.h"

using namespace std;

int main(int argc, char *argv[]) {

    // ===== variables =====
    // name for the metadata_file
    const string metadata_file_name = "metadata.yaml"; 

    // If command line arguments are given, use those instead of the defaults
    if(argc != 0) {

    }

    // Load the metadata yaml file
    YAML::Node metadata = YAML::LoadFile(metadata_file_name);

    // output welcome message
    cout << "Welcome back." << endl;
    cout << "Recovering data from " << metadata["lastRunDate"].as<string>() << endl;

    // system is closing, set the lastRunDate in the metadata file
    metadata["lastRunDate"] = getCurrentDateTime();

    // save the metadata file
    ofstream fout(metadata_file_name);
    fout << metadata;
    
    return 0;
}

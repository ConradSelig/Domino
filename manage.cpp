// Native includes
#include<iostream>
#include<string>
#include<fstream>

// local build includes
#include "yaml-cpp/yaml.h"

// project header files
#include "utils.h"
#include "argengine.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    // ===== variables =====
    // name for the metadata_file
    string metadata_file_name = "metadata.yaml";
    const string &mfn = metadata_file_name; 
    string next_yaml_file;
    const string &nyf = next_yaml_file;

    // initialize the argument parser
    juzzlin::Argengine argengine(argc, argv);

    // add the custom metadata file to the arguments list
    argengine.addOption({"--metadata-file"}, [&] (string value) {
        metadata_file_name = value;                
    });
    
    // actually parse the arguments
    argengine.parse();

    // Load the metadata yaml file
    YAML::Node metadata = YAML::LoadFile(mfn);

    // Open the version yaml file
    next_yaml_file = "version.yaml";
    YAML::Node version = YAML::LoadFile(nyf);

    // output loading messages
    cout << "Recovering data from " << metadata["lastRunDate"].as<string>() 
            << endl;

    cout << endl;
    cout << "Currently running \"" << version["codename"] << "\". (Mark " 
            << version["mark"] << "; Version " << version["version"] << ")" 
            << endl;

    // output welcome messages
    cout << endl;
    for(int i = 0; i < 80; i++) cout << "=";
    cout << endl;
    cout << "Welcome back Mr.Selig." << endl;

    // system is closing, set the lastRunDate in the metadata file
    metadata["lastRunDate"] = getCurrentDateTime();

    // save the metadata file
    ofstream fout(metadata_file_name);
    fout << metadata;
    
    return 0;
}

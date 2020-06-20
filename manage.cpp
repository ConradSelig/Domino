// Native includes
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>

// local build includes
#include "yaml-cpp/yaml.h"

// project header files
#include "utils.h"
#include "argengine.hpp"
#include "yaml_extension.h"

using namespace std;

int main(int argc, char *argv[]) {

    // ===== variables =====
    // name for the metadata_file
    string metadata_file_name = "metadata.yaml";
    const string &mfn = metadata_file_name; 
    string next_yaml_file;
    const string &nyf = next_yaml_file;

    string node_value;
    const string &nv = node_value;

    vector<string> tokens;

    YAML::Node metadata;
    YAML::Node version;

    // initialize the argument parser
    juzzlin::Argengine argengine(argc, argv);

    // add the custom metadata file to the arguments list
    argengine.addOption({"--metadata-file"}, [&] (string value) {
        metadata_file_name = value;                
    });
    
    // actually parse the arguments
    argengine.parse();

    // Load the metadata yaml file
    try {
        metadata = YAML::LoadFile(mfn);
    } catch (YAML::BadFile) {
        create_blank_file(metadata_file_name);
        metadata = YAML::LoadFile(mfn);
        metadata["lastRunDate"] = YAML::Null;
        metadata["userName"] = YAML::Null;
        metadata["prefix"] = YAML::Null;
    }
    
    // Open the version yaml file
    next_yaml_file = "version.yaml";
    try {
        version = YAML::LoadFile(nyf);
    } catch (YAML::BadFile) {
        cout << "No version file found. Aborting." << endl;
        return -1;
    }

    // ensure that metadata keys exist
    metadata = ensure_key(metadata, "lastRunDate");
    metadata = ensure_key(metadata, "userName");
    metadata = ensure_key(metadata, "prefix");

    // ensure that the last run date is not Null
    if(metadata["lastRunDate"].IsNull()) {
        metadata["lastRunDate"] = "unknown";
    }

    // output loading messages
    cout << "Recovering data from " << metadata["lastRunDate"].as<string>() 
            << endl;

    cout << endl;
    cout << "Currently running \"" << version["codename"] << "\". (Mark " 
            << version["mark"] << "; Version " << version["version"] << ")" 
            << endl;

    // output split line
    cout << endl;
    for(int i = 0; i < 40; i++) cout << "=";
    cout << endl << endl;
    
    // output welcome back message
    try {
        node_value = metadata["userName"].as<string>();
        if (!YAML::IsNullString(nv)) { 
            cout << "Welcome back ";
            if(check_key(metadata, "prefix") && node_value.find(' ') != string::npos) {
                tokens = split(node_value, ' ');
                cout << metadata["prefix"] << tokens[tokens.size() - 1] << "." << endl;
            } else {
                cout << metadata["userName"] << "." << endl;
            }
        } else {
            cout << "Welcome back." << endl;
        }
    } catch (YAML::BadConversion) {
        cout << "Welcome back." << endl;
    }

    // system is closing, set the lastRunDate in the metadata file
    metadata["lastRunDate"] = getCurrentDateTime();

    // save the metadata file
    ofstream fout(metadata_file_name);
    fout << metadata;
    
    return 0;
}

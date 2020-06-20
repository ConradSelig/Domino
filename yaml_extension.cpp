#include<string>
#include<iostream>

#include "yaml-cpp/yaml.h"

using namespace std;

bool check_key(YAML::Node &node, string key) {
    
    try {
        if (!node[key] || 
            node[key].IsNull() || 
            !node[key].IsDefined()) {
            return false;
        }
    } catch (YAML::BadConversion) {
        return false;
    }

    return true;
}


YAML::Node ensure_key(YAML::Node node, string key) {
    
    if (!check_key(node, key)) {
        node[key] = YAML::Null;
    }

    return node;
}

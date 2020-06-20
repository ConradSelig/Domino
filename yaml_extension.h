#ifndef YAML_EXTENSION_H
#define YAML_EXTENSION_H

#include<string>

using namespace std;

bool check_key(YAML::Node &node, string key);
YAML::Node ensure_key(YAML::Node node, string key);

#endif

#include<string>
#include<vector>
#include<experimental/filesystem>

namespace fs = std::experimental::filesystem::v1;
using namespace std;

vector<string> list_dir(string path){
   
    vector<string> files;

    for (const auto & entry : fs::directory_iterator(path)) {
        files.push_back(entry.path());
    }

    return files;

}


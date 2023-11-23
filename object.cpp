#include "object.h"
#include <iostream>

Object::Object(std::string file_name){
    std::ifstream fs;
    fs.open(file_name);
    std::string key;
    std::string string_value;
    getline(fs, string_value);
    description["brief"] = string_value;
    while ((fs >> key >> string_value) && ((key != "0") && (string_value != "0"))){
        description[key] = string_value;
    }
    int int_value;
    getline(fs, string_value);
    while (fs >> key >> int_value){
        stats[key] = int_value;
        //std::cout << "key:_" << key << "_\n";
        //std::cout << "key:_" << int_value << "_\n";
    }
    fs.close();
}

int Object::get_stat(std::string stat){
    return stats[stat];
}

std::string Object::get_description(std::string desc){
    return description[desc];
}

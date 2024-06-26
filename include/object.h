#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <string>
#include <fstream>

class Object{
    friend class Shop;
    protected:
        std::string file_name;
        std::map<std::string, int> stats;
        std::map<std::string, std::string> description;
        Object(std::string& file_name);
    public:
        int GetStat(std::string stat);
        std::string GetDescription(std::string desc);
};

#endif //OBJECT_H

#include <map>
#include <string>
#include <fstream>

class Object{
    friend class Shop;
    protected:
        std::string file_name;
        std::map<std::string, int> stats;
        std::map<std::string, std::string> description;
        Object(std::string file_name);
    public:
        int get_stat(std::string stat);
        std::string get_description(std::string desc);
};

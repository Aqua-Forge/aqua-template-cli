#include "Helpers.hpp"


bool startsWith (std::string str, std::string substr)
{
    return str.rfind(substr, 0) == 0;
}


std::vector<std::string> split(std::string const &str, const char delimiter)
{
    std::vector<std::string> out;
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delimiter))
    {
        out.push_back(s);
    }
    return out;
}


std::vector<std::string> listdir(std::string path)
{
    std::vector<std::string> content;
    for (const auto & entry : fs::directory_iterator(path))
    {
        auto vs = split(entry.path(), '/');
        content.push_back(vs.back());
    }
    return content;
}

#include "Helpers.hpp"


bool helpers::startsWith (std::string str, std::string substr)
{
    return str.rfind(substr, 0) == 0;
}


std::vector<std::string> helpers::split(std::string const &str, const char delimiter)
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


std::vector<std::string> helpers::listdir(std::string path)
{
    std::vector<std::string> content;
    for (const auto & entry : fs::directory_iterator(path))
    {
        auto vs = helpers::split(entry.path(), '/');
        content.push_back(vs.back());
    }
    return content;
}


void helpers::copy(std::string src, std::string dst)
{
    fs::copy(src, dst, fs::copy_options::overwrite_existing | fs::copy_options::recursive);
}

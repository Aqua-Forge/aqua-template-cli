#include "Parameters.hpp"


Parameters::Parameters()
{
    this->parameters['h'] = {
        'h',                                             // Flag
        "help",                                          // Flag Name
        "Display this help",                             // Description
        false,                                           // Has Value
        "",                                              // Value
    };

    this->parameters['n'] = {
        'n',                                              // Flag
        "name",                                           // Flag Name
        "Specifies the project name",                     // Description
        true,                                             // Has Value
        "",                                               // Value
    };

    this->parameters['l'] = {
        'l',                                              // Flag
        "language",                                       // Flag Name
        "Specifies the template's programming language",  // Description
        true,                                             // Has Value
        "",                                               // Value
    };

    this->parameters['d'] = {
        'd',                                              // Flag
        "display",                                        // Flag Name
        "Displays all available languages.",              // Description
        false,                                            // Has Value
        "",                                               // Value
    };
}


Parameter Parameters::findByName(std::string flagName)
{
    std::map<char, Parameter>::iterator it;
    for (it = this->parameters.begin(); it != this->parameters.end(); ++it)
    {
        if (it->second.flagName == flagName)
        {
            return it->second;
        }
    }
    std::string exc = std::string("Unknown parameter `") + flagName + std::string("`.");
    throw std::runtime_error(exc).what();
}


Parameter Parameters::findByFlag(char flag)
{
    if (this->parameters.count(flag))
    {
        return this->parameters[flag];
    }
    else
    {
        std::string exc = std::string("Unknown parameter `");
        exc.push_back(flag);
        exc += "`.";
        throw std::runtime_error(exc).what();
    }
}


std::vector<Parameter> Parameters::getAll()
{
    std::vector<Parameter> params;
    std::map<char, Parameter>::iterator it;
    for(it = this->parameters.begin(); it != this->parameters.end(); ++it)
    {
        params.push_back(it->second);
    }
    return params;
}


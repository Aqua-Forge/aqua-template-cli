#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <map>


/**
 * @brief ADT of a command line parameter
 */
struct Parameter {
    char flag;
    const char *flagName;
    const char *description;
    bool hasValue;
    std::string value = "";
};

class Parameters
{
public:
    Parameters();
    Parameter findByName(std::string flagName);
    Parameter findByFlag(char flag);
    void displayHelp();

private:
    std::map<char, Parameter> parameters;
};

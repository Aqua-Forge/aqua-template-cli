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

/**
 * @brief Implements an encapsulator for the Parameters ADT
 * 
 */
class Parameters
{
public:
    /**
     * @brief Initializates all existent Parameters (command line arguments)
     * 
     */
    Parameters();

    /**
     * @brief Find a parameter by its flag name
     * 
     * @param flagName 
     * @return Parameter 
     */
    Parameter findByName(std::string flagName);

    /**
     * @brief Find a parameter by its flag abbreviation
     * 
     * @param flag 
     * @return Parameter 
     */
    Parameter findByFlag(char flag);

    /**
     * @brief Return all possible parameters
     * 
     * @return std::vector<Parameter> 
     */
    std::vector<Parameter> getAll();

private:
    std::map<char, Parameter> parameters;
};

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "Parameters.hpp"
#include "Helpers.hpp"


class Generator
{
public:
    Generator(std::vector<Parameter> params);

    /**
     * @brief Prints the help informations about aqua-template CLI.
     * 
     */
    void displayHelp();

    /**
     * @brief Prints header with Copyrights.
     * 
     */
    void displayHeader();


    /**
     * @brief Verifies if the specified language is available for template generating.
     * 
     * @param lang 
     * @return true 
     * @return false 
     */
    bool checkLanguage(std::string lang);


    /**
     * @brief Sets the generator configurations, like project name and language.
     * 
     */
    void setConfigs();

private:
    std::vector<Parameter> parameters;
    bool fgHelp = false;
    bool fgLanguages = false;
    std::map<std::string, std::string> configs = {
        {"project_name", ""},
        {"project_lang", ""}
    };
};





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
    /**
     * @brief Construct a new Generator object
     * 
     * @param params 
     */
    Generator(std::vector<Parameter> params);

    /**
     * @brief Prints header with Copyrights.
     * 
     */
    void displayHeader();

    /**
     * @brief Prints the help informations about aqua-template CLI.
     * 
     */
    void displayHelp();

    /**
     * @brief Prints the available languages for project template generation.
     * 
     */
    void displayLanguages();

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

    /**
     * @brief Asks for user to input the project name.
     * 
     */
    void askProjectName();

    /**
     * @brief Asks for user to input the project language.
     * 
     */
    void askProjectLang();

    /**
     * @brief Runs the generator with the arguments passed.
     * 
     */
    void run();

private:
    std::vector<Parameter> parameters;
    std::vector<Parameter> fullParameters;
    bool fgHelp = false;
    bool fgLanguages = false;
    std::map<std::string, std::string> configs = {
        {"project_name", ""},
        {"project_lang", ""}
    };
};





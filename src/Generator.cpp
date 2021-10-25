#include "Generator.hpp"


Generator::Generator(std::vector<Parameter> params) : parameters(params)
{
    try
    {
        this->setConfigs();
        Parameters fullParams;
        this->fullParameters = fullParams.getAll();
    }
    catch(const char* err)
    {
        std::cerr << "Error: ";
        std::cerr << err << '\n';
        exit(1);
    }
}


void Generator::displayHeader()
{
    std::cout << "Copyright (c) 2021 Aqua Forge" << std::endl;
    std::cout << "Aqua-Template - Project Template Generator v1.0" << std::endl;
}


void Generator::displayHelp()
{
    this->displayHeader();
    std::cout << "Usage:" << std::endl;
    std::cout << "\taqua-template [-a value | --arg=value]" << std::endl;

    std::cout << "Arguments:" << std::endl;

    std::vector<Parameter>::iterator it = this->fullParameters.begin();
    for (; it != this->fullParameters.end(); ++it)
    {
        std::cout << "\t-"
                  << it->flag
                  << " | --"
                  << it->flagName
                  << " : "
                  << it->description
                  << std::endl;
    }
}


void Generator::displayLanguages()
{
    std::cout << "Available template languages:" << std::endl;
    std::vector<std::string> langs = helpers::listdir("templates");
    for (std::vector<std::string>::iterator it = langs.begin(); it != langs.end(); ++it)
    {
        std::cout << "\t- " << *it << std::endl;
    }
}


bool Generator::checkLanguage(std::string lang)
{
    std::vector<std::string> availLanguages = helpers::listdir("templates");
    return std::find(availLanguages.begin(), availLanguages.end(), lang) != availLanguages.end();
}


void Generator::setConfigs()
{
    std::vector<Parameter>::iterator it;
    for (it = this->parameters.begin(); it != this->parameters.end(); ++it)
    {
        switch (it->flag)
        {
        case 'h':
            this->fgHelp = true;
            break;

        case 'l':
            if (this->checkLanguage(it->value))
            {
                this->configs["project_lang"] = it->value;
            }
            else
                throw "Invalid language! Send the flag `-d` to list the available languages.";
            break;

        case 'n':
            this->configs["project_name"] = it->value;
            break;

        case 'd':
            this->fgLanguages = true;
            break;

        default:
            break;
        }
    }
}


void Generator::askProjectName()
{
    std::string projectName;
    std::cout << "Please enter the project name: ";
    std::getline(std::cin, projectName);
    this->configs["project_name"] = projectName;
}


void Generator::askProjectLang()
{
    this->displayLanguages();
    std::string projectName;
    std::cout << "Please enter the programming language: ";
    std::getline(std::cin, projectName);

    if (this->checkLanguage(projectName))
    {
        this->configs["project_lang"] = projectName;
    }
    else
    {
        throw "Invalid language! Send the flag `-d` to list the available languages.";
    }
}


void Generator::run()
{
    try
    {
        if (this->fgHelp)
        {
            this->displayHelp();
        }
        else if (this->fgLanguages)
        {
            this->displayHeader();
            this->displayLanguages();
        }
        else
        {
            if (this->configs["project_name"] == "")
            {
                this->askProjectName();
            }

            if (this->configs["project_lang"] == "")
            {
                this->askProjectLang();
            }
        }
    }
    catch(const char* err)
    {
        std::cerr << err << '\n';
        exit(1);
    }
    
}

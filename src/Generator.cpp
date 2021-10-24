#include "Generator.hpp"


Generator::Generator(std::vector<Parameter> params) : parameters(params)
{
    try
    {
        this->setConfigs();
    }
    catch(const char* err)
    {
        std::cerr << "Error: ";
        std::cerr << err << '\n';
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
    std::cout << "usage:" << std::endl;

    std::vector<Parameter>::iterator it = this->parameters.begin();
    for (; it != this->parameters.end(); ++it)
    {
        std::cout << "\t -"
                  << it->flag
                  << " | --"
                  << it->flagName
                  << " : "
                  << it->description
                  << std::endl;
    }
}


bool Generator::checkLanguage(std::string lang)
{
    std::vector<std::string> availLanguages = listdir("templates");
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

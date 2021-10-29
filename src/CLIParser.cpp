#include "CLIParser.hpp"


CLIParser::CLIParser(int size_, char **args_) : size(size_), args(args_) {}


CLIParser::CLIParser() {}


void CLIParser::setSize(int size_)
{
    this->size = size_;
}


void CLIParser::setArgs(char** args_)
{
    this->args = args_;
}


void CLIParser::parse()
{
    // Add all valid arguments to this->CLIParams
    for (int i = 1; i < this->size; ++i)
    {
        std::string arg = std::string(this->args[i]);

        // Receiving a "--flagname" parameter.
        if (helpers::startsWith(arg, std::string("--")))
        {
            arg.erase(0, 2);
            try
            {
                std::vector<std::string> argAndValue = helpers::split(arg, '=');
                Parameter param = this->parameters.findByName(argAndValue[0]);

                if (param.hasValue)
                {
                    if (argAndValue.size() <= 1)
                        throw "Invalid syntax. Please use the format: --flagname=value";
                    param.value = argAndValue[1];
                }

                this->CLIParams.push_back(param);
            }
            catch(const char* err)
            {
                std::cerr << "Error: ";
                std::cerr << err << '\n';
                exit(1);
            }
        }

        // Receiving a "-f(lag)" parameter.
        else if (helpers::startsWith(arg, std::string("-")))
        {
            arg.erase(0,1);
            try
            {
                Parameter param = this->parameters.findByFlag(arg.at(0));
                if (param.hasValue)
                {
                    if (i == this->size - 1)
                        throw "Invalid syntax. Please use the format: -f value";
                    param.value = std::string(this->args[++i]);
                }
                this->CLIParams.push_back(param);
            }
            catch(const char* err)
            {
                std::cerr << "Error: ";
                std::cerr << err << '\n';
                exit(1);
            }
        }

        else
        {
            std::cout << "Error: ";
            std::cerr << "Invalid syntax. Type `aqua-template -h` for usage." << std::endl;
            exit(1);
        }
    }
}


std::vector<Parameter> CLIParser::getParameters()
{
    return this->CLIParams;
}

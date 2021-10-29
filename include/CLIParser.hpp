#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Helpers.hpp"
#include "Parameters.hpp"

/**
 * @brief Parses the command line arguments.
 * 
 */
class CLIParser
{
    public:
        /**
         * @brief Construct a new CLIParser object
         * 
         * @param size argc
         * @param args argv
         */
        CLIParser(int size, char **args);

        /**
         * @brief Construct a new CLIParser object
         * 
         */
        CLIParser();

        /**
         * @brief Parses the arguments
         * 
         */
        void parse();

        /**
         * @brief Set the number of arguments
         * 
         * @param size 
         */
        void setSize(int size);

        /**
         * @brief Set the CLI Arguments
         * 
         * @param args 
         */
        void setArgs(char **args);

        /**
         * @brief Return the parsed parameters
         * 
         * @return std::vector<Parameter> 
         */
        std::vector<Parameter> getParameters();

    private:
        Parameters parameters;
        std::vector<Parameter> CLIParams;
        int size;
        char **args;
};

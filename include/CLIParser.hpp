#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Helpers.hpp"
#include "Parameters.hpp"


class CLIParser
{
    public:
        CLIParser(int size, char **args);

        std::vector<Parameter> getParameters();

    private:
        Parameters parameters;
        std::vector<Parameter> CLIParams;
};

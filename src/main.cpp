#include "CLIParser.hpp"
#include "Generator.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    CLIParser parser(argc, argv);
    Generator generator(parser.getParameters());
    generator.run();

    return 0;
}

#include <iostream>

#include "InputParser.hpp"

InputParser::InputParser() {
}

InputParser::~InputParser() {
}

void InputParser::toStringVector(int argc, char* argv[])
{
    if(argc < 1)
    {
        std::cerr << "ERROR! Invalid Parameter Count. Exiting";
        return;
    }

    for(int i = 0; i < argc; i++)
    {
        commandFlags.push_back(argv[i]);
    }
}

void InputParser::printCommandFlags()
{
    for(std::vector<std::string>::iterator it = commandFlags.begin(); it != commandFlags.end(); it++)
    {
        std::cout << it->data() << " " << std::endl;
    }
    std::cout << std::endl;
}

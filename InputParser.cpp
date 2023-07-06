#include <iostream>

#include "InputParser.hpp"

InputParser::InputParser(int argc, char* argv[])
    :argCount(argc)
{
    InputParser::toStringVector(argc, argv);
    InputParser::parseArgs();
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
        args.push_back(argv[i]);
    }
}

void InputParser::parseArgs()
{
    char key = '-';
    for(std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
    {
        if(it->find(key) != std::string::npos)
        {
            //std::cout << "Found flag! [" << it.data() <<"]"<<  std::endl;
            commandFlags.push_back(it->data());
        }
    }
}

int InputParser::getArgCount() { return argCount; }

std::vector<std::string> InputParser::getAllArgs()
{
    return args;
}

std::vector<std::string> InputParser::getCommandFlags()
{
    return commandFlags;
}

void InputParser::printAllArgs()
{
    for(std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
    {
        std::cout << it->data() << " ";
    }
    std::cout << std::endl;
}

void InputParser::printCommandFlags()
{
    for(std::vector<std::string>::iterator it = commandFlags.begin(); it != commandFlags.end(); it++)
    {
        std::cout << it->data() << " ";
    }
    std::cout << std::endl;
}


#include <iostream>
#include <string>
#include <vector>

#include "InputParser.hpp"
#include "CommandHandler.hpp"

int main(int argc, char* argv[]) 
{

    InputParser parser(argc, argv);
    std::cout << std::endl;
    if(parser.getArgCount() < 1)
    {
        std::cerr << "Invalid argc, how is that even possible?" << std::endl;
    }

    //Begin to execute command flags
    CommandHandler handler(parser.getAllArgs(), parser.getCommandFlags());
    handler.handleCommands();
}

#include <iostream>
#include <string>
#include <vector>

#include "InputParser.hpp"

int main(int argc, char* argv[]) 
{

    InputParser parser(argc, argv);
    std::cout << std::endl;
    if(parser.getArgCount() < 1)
    {
        std::cerr << "Invalid argc, how is that even possible?" << std::endl;
    }

    std::cout << "Printing command flags: " << std::endl;
    parser.printCommandFlags();

}

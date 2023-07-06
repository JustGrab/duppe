#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <streambuf>

#include "CommandHandler.hpp"

CommandHandler::CommandHandler(std::vector<std::string> allArgs, std::vector<std::string> commandFlags)
    : allArgs(allArgs),commandFlags(commandFlags)
{
}

CommandHandler::~CommandHandler() {
}

void CommandHandler::handleCommands()
{
    if(std::find(commandFlags.begin(), commandFlags.end(), "-h") != commandFlags.end())
    {
        printHelpMenu();
        exit(0);
    }
    std::vector<std::string>::iterator it = commandFlags.begin();
    std::vector<std::string>::iterator itCopy;
    while(it != commandFlags.end())
    {
        if(it->compare("-p") == 0 )
        {
            std::string newProjectName = getExtraArg("-p");
            std::cout << "New project Name: " << newProjectName << std::endl;
            handleP(newProjectName);
        }
        it++;
    }
}

std::string CommandHandler::getExtraArg(std::string commandFlag)
{
    std::vector<std::string>::iterator extraFlag = std::find(allArgs.begin(), allArgs.end(), commandFlag);
    if(extraFlag != allArgs.end() && extraFlag + 1 != allArgs.end())
    { 
        extraFlag++;
    }
    else
    {
        std::cout << "Invalid Argument " << *extraFlag << std::endl;
        exit(0);
    }
    return *extraFlag; 
}


void CommandHandler::deleteArg(std::string, std::string)
{
}

void CommandHandler::printHelpMenu()
{
    //Print help menu
    std::cout << "DUPPE" << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << "-d : create project with one Makefile and main.cpp" << std::endl;
    std::cout << "-p : uses preset directory located in /usr/shared/duppe/preset" << std::endl;
    std::cout << "Always insert new project name as the last argument!" << std::endl;
    //TODO
    //add option to add includes and flags for librarys like sdl, raylib, asio etc...
    exit(0);
}

bool CommandHandler::handleP(std::string newProjectName)
{
    std::string newPath = std::filesystem::current_path().string() + "/" + newProjectName;
    //Check to see if preset project directory exists.
    if(!std::filesystem::exists(PRESET_PATH))
    {
        std::cout << "Preset path does not exist!" << std::endl;
        return false;
    }
    //Attempt to create new projects directory at current spot
    std::filesystem::copy(PRESET_PATH, newPath, std::filesystem::copy_options::recursive, errorCode);
    
    if(errorCode)
    {
        std::cout << "ERROR! " << errorCode.message() << std::endl;
        return false;
    }
    std::cout << "Project " << newProjectName << " successfully made!" << std::endl;
    return true;
}

bool CommandHandler::handleD()
{

}

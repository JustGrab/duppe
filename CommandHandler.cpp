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
        std::cout << "PRINT HELP MENU!";
    }
    CommandHandler::handleP("test");
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
    std::cout << "Current path is: " << std::filesystem::current_path() << std::endl;
    //Attempt to create new projects directory at current spot
    std::cout << "Attemping to create project path " << newPath << std::endl;
    //std::filesystem::create_directory(newPath, errorCode);
    std::filesystem::copy(PRESET_PATH, newPath, std::filesystem::copy_options::recursive, errorCode);
    if(errorCode)
    {
        std::cout << "ERROR! " << errorCode.message() << std::endl;
    }

    return true;
}

bool CommandHandler::handleD()
{

}

#pragma once

#include <system_error>
#include <vector>
#include <string>

#define PRESET_PATH "/usr/share/duppe/preset"

class CommandHandler
{
public:
    CommandHandler(std::vector<std::string> allArgs, std::vector<std::string> commandFlags);
    CommandHandler(CommandHandler &&) = default;
    CommandHandler(const CommandHandler &) = default;
    CommandHandler &operator=(CommandHandler &&) = default;
    CommandHandler &operator=(const CommandHandler &) = default;
    ~CommandHandler();

    void handleCommands();

private:
    std::vector<std::string> allArgs;
    std::vector<std::string> commandFlags;
    std::error_code errorCode;

    std::string getExtraArg(std::string commandFlag);
    void deleteArg(std::string, std::string="");

    void printHelpMenu();
    bool handleP(std::string newProjectName);
    bool handleD();
};

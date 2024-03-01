#pragma once
#include "core/application.h"
#include "core/command.h"

#include "core/command_handler.h"
#include "platform/platform.h"

namespace ytb
{
    class HelpCommand : public Command
    {
    public:
        explicit HelpCommand(CommandHandler* commandHandler)
            : Command(CommandDetails{
                { "help" },
                "Provides help information for ytb commands."
                })
            , r_CommandHandler(commandHandler)
        {
        }

    public:
        void Execute(const CommandArguments&) override
        {
            std::cout << "For more information on a specific command, type 'help <command-name>'\n\n";

            for (const auto& [commandName, commandDetails] : r_CommandHandler->UniqueCommands())
                DisplayCommand(commandName, commandDetails);
        }

    private:
        void DisplayCommand(const std::string commandName, const CommandDetails& commandDetails)
        {
            std::cout << commandName << ":\n";
            std::cout << "  - " << commandDetails.description;
            std::cout << '\n';

            if (commandDetails.commandAliases.size() <= 1)
            {
                std::cout << '\n';
                return;
            }

            std::cout << "  - Aliases: " << '\n';
            for (const auto& alias : commandDetails.commandAliases)
                std::cout << "    * " << alias << '\n';

            std::cout << "\n";
        }

    private:
        CommandHandler* r_CommandHandler = nullptr;
    };
}
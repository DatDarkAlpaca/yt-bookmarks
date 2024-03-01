#include "pch.h"
#include "command_handler.h"
#include "utils/string_utils.h"

namespace ytb
{
	CommandHandler::CommandHandler(Application* application)
		: r_Application(application)
	{

	}

	void CommandHandler::DisplaySuffix(const std::string& suffix)
	{
        if (suffix.empty())
            std::cout << "> ";
        else
            std::cout << suffix << ' ';
	}

    std::optional<CommandInformation> CommandHandler::GetUserCommand()
    {
        std::string input;
        std::getline(std::cin, input);

        auto commandArguments = utils::Split(input);

        if (commandArguments.size() <= 0)
            return std::nullopt;


        CommandInformation information;
        CommandArguments arguments;

        information.commandName = commandArguments[0];
        if (information.commandName.empty())
            return std::nullopt;

        {
            auto commandArgsBegin = commandArguments.begin() + 1;
            auto commandArgsEnd = commandArguments.end();

            arguments.arguments = { commandArgsBegin, commandArgsEnd };
            information.arguments = arguments;
        }

        return information;
    }

    bool CommandHandler::ExecuteCommand(const CommandInformation& commandInformation)
    {
        if (m_CommandMap.find(commandInformation.commandName) != m_CommandMap.end())
        {
            m_CommandMap[commandInformation.commandName]->Execute(commandInformation.arguments);
            return true;
        }

        return false;
    }

    void CommandHandler::AddCommand(std::shared_ptr<Command> command)
    {
        command->SetApplication(r_Application);

        m_UniqueCommands[command->Details().commandAliases[0]] = command->Details();

        for (const auto& alias : command->Details().commandAliases)
        {
            if (m_CommandMap.find(alias) != m_CommandMap.end())
                throw "Failed to create command: This command name has already been registered";

            m_CommandMap[alias] = command;
        }
    }

    void CommandHandler::AddCommands(const std::vector<std::shared_ptr<Command>>& commands)
    {
        for (const auto& command : commands)
            AddCommand(command);
    }
}
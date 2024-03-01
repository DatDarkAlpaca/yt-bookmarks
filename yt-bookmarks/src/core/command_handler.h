#pragma once
#include <unordered_map>
#include <iostream>
#include <optional>

#include "core/command.h"

namespace ytb
{
    class Application;

	class CommandHandler
	{
    public:
        explicit CommandHandler(Application* application);

    public:
        void DisplaySuffix(const std::string& suffix = "");

        std::optional<CommandInformation> GetUserCommand();

	public:
        bool ExecuteCommand(const CommandInformation& commandInformation);

    public:
        void AddCommand(std::shared_ptr<Command> command);

        void AddCommands(const std::vector<std::shared_ptr<Command>>& commands);

        auto CommandMap() const { return m_CommandMap; }

        auto UniqueCommands() const { return m_UniqueCommands; }

    private:
        std::unordered_map<std::string, std::shared_ptr<Command>> m_CommandMap;
        std::unordered_map<std::string, CommandDetails> m_UniqueCommands;
        Application* r_Application;
	};
}
#pragma once
#include <fstream>
#include "core/command_handler.h"
#include "core/resources_handler.h"

namespace ytb
{
    class Application
    {
    public:
        explicit Application()
            : m_CommandHandler(this)
        {
            ResourcesHandler::InitializeResources();

            m_Running = true;
        }

    public:
        void Run()
        {
            ShowHeader();

            while (m_Running)
            {
                m_CommandHandler.DisplaySuffix(ResourcesHandler::Get("commands", "suffix"));

                auto command = m_CommandHandler.GetUserCommand();
                if (!command.has_value())
                    continue;

                if(!m_CommandHandler.ExecuteCommand(command.value()))
                    std::cerr << "This command does not exist. For a list of available commands, write: help\n";
            }
        }

    public:
        void ShowHeader()
        {
            std::cout << "-= Youtube Bookmarks v1.0 =-\n";
            std::cout << "Type 'help' for a list of commands\n\n";
        }
        
        void Close()
        {
            m_Running = false;
        }

    public:
        CommandHandler& Command() { return m_CommandHandler; }

    private:
        CommandHandler m_CommandHandler;
        bool m_Running = false;
    };
}
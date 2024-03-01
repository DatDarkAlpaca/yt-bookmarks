#pragma once
#include "core/application.h"
#include "core/command.h"

namespace ytb
{
    class QuitCommand : public Command
    {
    public:
        explicit QuitCommand()
            : Command(CommandDetails{
                { "quit", "close", "exit" },
                "Quits the ytb program."
                })
        {
        }

    public:
        void Execute(const CommandArguments&) override
        {
            application->Close();
        }
    };
}
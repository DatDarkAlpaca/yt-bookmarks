#pragma once
#include "core/application.h"
#include "core/command.h"

#include "utils/string_utils.h"
#include "platform/platform.h"

namespace ytb
{
    class ClearCommand : public Command
    {
    public:
        explicit ClearCommand()
            : Command(CommandDetails{
                { "clear", "cls" },
                "Clears the screen.\n       --header: Shows the application header."
                })
        {
        }

    public:
        void Execute(const CommandArguments& arguments) override
        {
            platform::ClearConsole();

            if(utils::HasValue("--header", arguments.arguments))
                application->ShowHeader();
        }
    };
}
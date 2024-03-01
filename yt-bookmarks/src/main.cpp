#include "pch.h"
#include "core/application.h"
#include "commands/commands.h"

using namespace ytb;

void main()
{
    Application application;
    auto& commands = application.Command();

    commands.AddCommand(std::make_shared<HelpCommand>(&commands));
    commands.AddCommand(std::make_shared<BookmarksCommand>());
    commands.AddCommand(std::make_shared<ClearCommand>());
    commands.AddCommand(std::make_shared<QuitCommand>());

    application.Run();
}
#pragma once
#include "core/application.h"
#include "core/command.h"

#include "utils/string_utils.h"
#include "platform/platform.h"

namespace ytb
{
    class BookmarksCommand : public Command
    {
    public:
        explicit BookmarksCommand();

    private:
        void AddBookmark();

        void RemoveBookmark();

        void ShowBookmarksList();

        void ShowBookmarksHelp();

    public:
        void Execute(const CommandArguments& arguments) override;
    };
}
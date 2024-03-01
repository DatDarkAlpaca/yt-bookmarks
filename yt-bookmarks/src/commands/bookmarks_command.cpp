#include "pch.h"
#include "bookmarks_command.h"

namespace ytb
{
    BookmarksCommand::BookmarksCommand()
        : Command(CommandDetails{
            { "bookmarks" },
            "Main command for handling ytb bookmarks."
        })
    {
    }

    void BookmarksCommand::AddBookmark()
    {

    }

    void BookmarksCommand::RemoveBookmark()
    {

    }

    void BookmarksCommand::ShowBookmarksList()
    {

    }

    void BookmarksCommand::ShowBookmarksHelp()
    {
    }

    void BookmarksCommand::Execute(const CommandArguments& arguments)
    {
        if (utils::HasValue("--add", arguments.arguments))
        {
            AddBookmark();
        }

        if (utils::HasValue("--remove", arguments.arguments))
        {
            RemoveBookmark();
        }

        if (utils::HasValue("--list", arguments.arguments))
        {
            ShowBookmarksList();
        }

        else
        {
            ShowBookmarksHelp();
        }
    }
}
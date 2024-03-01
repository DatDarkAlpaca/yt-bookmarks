#pragma once
#include <string>

namespace ytb { class Application; }

namespace ytb
{
	struct CommandArguments
	{
	public:
		operator std::vector<std::string>() { return arguments; }
		
		operator const std::vector<std::string>& () const { return arguments; }

	public:
		std::vector<std::string> arguments;
	};

	struct CommandDetails
	{
		std::vector<std::string> commandAliases;
		std::string description;
	};

	struct CommandInformation
	{
		std::string commandName;
		CommandArguments arguments;
	};

	class Command
	{
	public:
		explicit Command(const CommandDetails& details)
			: m_Details(details)
		{

		}

		virtual ~Command() = default;

	public:
		virtual void Execute(const CommandArguments& arguments) = 0;

	public:
		void SetApplication(ytb::Application* application)
		{
			this->application = application;
		}

	public:
		CommandDetails Details() const { return m_Details; }

	protected:
		ytb::Application* application = nullptr;

	private:
		CommandDetails m_Details;
	};
}
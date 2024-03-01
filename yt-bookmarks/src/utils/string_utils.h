#pragma once
#include <sstream>
#include <string>
#include <vector>

namespace ytb::utils
{
	inline std::vector<std::string> Split(const std::string& input, char separator = ' ')
	{
		std::vector<std::string> results;

		std::string currentString;
		for (const char& character : input)
		{
			if (character == separator)
			{
				results.push_back(currentString);
				currentString.clear();
			}
			else
				currentString += character;
		}

		results.push_back(currentString);
		return results;
	}

	inline bool HasValue(const std::string& value, const std::vector<std::string>& arguments)
	{
		for (const auto& argument : arguments)
		{
			if (argument == value)
				return true;
		}

		return false;
	}
}
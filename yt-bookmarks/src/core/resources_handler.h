#pragma once
#include <filesystem>
#include <mini/ini.h>
#include <fstream>

namespace ytb
{
	class ResourcesHandler
	{
	public:
		static void InitializeResources()
		{
			using namespace std::filesystem;

			// Options:
			create_directory("res");
			(!exists(OptionsPath)) ? CreateOptions() : GetOptions();
		}

	public:
		static std::string Get(const std::string& section, const std::string& value)
		{
			return s_Structure[section][value];
		}

	private:
		static void CreateOptions()
		{
			mINI::INIFile optionsFile(OptionsPath);
			mINI::INIStructure ini;

			// Commands section:
			{
				ini["commands"]["suffix"] = ">";
			}
			
			s_Structure = ini;
			optionsFile.generate(ini);
		}

		static void GetOptions()
		{
			mINI::INIFile optionsFile(OptionsPath);
			optionsFile.read(s_Structure);
		}

	public:
		static inline mINI::INIStructure Structure() { return s_Structure; }

	private:
		static inline mINI::INIStructure s_Structure;
		static constexpr const char* OptionsPath = "res/options.ini";
	};
}
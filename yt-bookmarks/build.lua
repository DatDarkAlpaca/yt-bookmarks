create_project("yt-bookmarks", "ConsoleApp")

files { 
    "src/**.h",
    "src/**.cpp",
}

includedirs { "%{vendor_path}/mINI/src" }
workspace "HazelCustom"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist" 
    }

    outputdir = "%{cfg.buildcfg}.%{cfg.system}.%{cfg.architecture}"

    -- Include directories relative to root folder (solution directory)
    IncludeDir = {}
    IncludeDir["GLFW"] = "HazelCustom/vendor/GLFW/include"
    IncludeDir["Glad"] = "HazelCustom/vendor/Glad/include"
    IncludeDir["ImGui"] = "HazelCustom/vendor/imgui"

    include "HazelCustom/vendor/GLFW"
    include "HazelCustom/vendor/Glad"
    include "HazelCustom/vendor/imgui"

    startproject "Sandbox"

    project "HazelCustom"
        location "HazelCustom"
        kind "SharedLib" 
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "hczpch.h"
        pchsource "HazelCustom/src/hczpch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
        
        -- Compiler include directories
        includedirs
        {
        	"%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}",
            "%{IncludeDir.ImGui}"
        }

        links
        {
            "GLFW",
            "Glad",
            "ImGui",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

        defines
        {
            "HCZ_PLATFORM_WINDOWS",
            "HCZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox"
        }

        filter "configurations:Debug"
            defines "HCZ_DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "HCZ_RELEASE"
            buildoptions "/MDd"
            optimize "On"

        filter "configurations:Dist"
            defines "HCZ_DIST"
            buildoptions "/MDd"
            optimize "On"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "HazelCustom/vendor/spdlog/include",
            "HazelCustom/src"
        }

        links
        {
            "HazelCustom"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

        defines
        {
            "HCZ_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "HCZ_DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "HCZ_RELEASE"
            buildoptions "/MDd"
            optimize "On"

        filter "configurations:Dist"
            defines "HCZ_DIST"
            buildoptions "/MDd"
            optimize "On"
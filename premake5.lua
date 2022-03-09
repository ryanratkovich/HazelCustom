workspace "HazelCustom"
    architecture "x64"
    startproject "Sandbox"

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
    IncludeDir["glm"] = "HazelCustom/vendor/glm"

    include "HazelCustom/vendor/GLFW"
    include "HazelCustom/vendor/Glad"
    include "HazelCustom/vendor/imgui"

    project "HazelCustom"
        location "HazelCustom"
        kind "StaticLib" 
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "hczpch.h"
        pchsource "HazelCustom/src/hczpch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
            "%{prj.name}/vendor/glm/glm**.hpp",
            "%{prj.name}/vendor/glm/glm**.inl"
        }
        
        defines
        {
            "_CRT_SECURE_NO_WARNINGS"
        }

        -- Compiler include directories
        includedirs
        {
        	"%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}",
            "%{IncludeDir.ImGui}",
            "%{IncludeDir.glm}"
        }

        links
        {
            "GLFW",
            "Glad",
            "ImGui",
            "opengl32.lib"
        }

        filter "system:windows"
            systemversion "latest"

        defines
        {
            "HCZ_PLATFORM_WINDOWS",
            "HCZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        filter "configurations:Debug"
            defines "HCZ_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "HCZ_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HCZ_DIST"
            runtime "Release"
            optimize "on"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

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
            "HazelCustom/src",
            "HazelCustom/vendor",
            "%{IncludeDir.glm}"
        }

        links
        {
            "HazelCustom"
        }

        filter "system:windows"
            systemversion "latest"

        defines
        {
            "HCZ_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "HCZ_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "HCZ_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HCZ_DIST"
            runtime "Release"
            optimize "on"
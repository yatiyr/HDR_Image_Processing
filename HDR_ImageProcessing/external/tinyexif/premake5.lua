project "TinyEXIF"
    kind "StaticLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/${prj.name}")

    files
    {
        "TinyEXIF.h",
        "TinyEXIF.cpp",
        "tinyxml2.cpp",
        "tinyxml2.h"
    }

    filter "configurations:Debug"
        defines "HDR_IP_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "HDR_IP_RELEASE"
        runtime "Release"
        optimize "on"

project "HDR_ImageProcessing"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"


	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Precomp.h"
	pchsource "src/Config/Precomp.cpp"

	files
	{
		"src/**.h",
		"src/**.hpp",
		"src/**.cpp",
		"src/**.c",

		"external/stb_image/**.h",
		"external/stb_image/**.cpp",
		"external/tinyexr/**.h",
		"external/tinyexr/**.cpp",
		"external/tinyexr/**.c",
		"external/glm/glm/**.hpp",
		"external/glm/glm/**.inl",
	}

	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}


	includedirs
	{
		"%{IncludeDir.Spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImPlot}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.tinyexr}",
                "%{IncludeDir.Eigen}",
		"%{IncludeDir.Spectra}",
		"src",
		"src/Config"
	}


	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
	}


	filter "configurations:Debug"
		defines "HDR_IP_DBG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HDR_IP_RELEASE"
		runtime "Release"
		optimize "speed"

	filter "configurations:Dist"
		defines "HDR_IP_DIST"
		runtime "Release"
		optimize "speed"
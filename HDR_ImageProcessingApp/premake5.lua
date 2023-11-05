project "HDR_ImageProcessingApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"src/**.h",
		"src/**.hpp",
		"src/**.cpp",
		"src/**.c"
	}

	includedirs
	{
		"%{wks.location}/HDR_ImageProcessing/external/spdlog/include",
		"%{wks.location}/HDR_ImageProcessing/src",
		"%{wks.location}/HDR_ImageProcessing/src/Config",
		"%{wks.location}/HDR_ImageProcessing/external",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
                "%{IncludeDir.Eigen}",
		"%{IncludeDir.Spectra}",
		"%{IncludeDir.stb_image}",
                "%{IncludeDir.TinyEXIF}",
		"src"
	}

	links
	{
		"HDR_ImageProcessing"
	}

	postbuildcommands
	{
		'{COPY} "%{wks.location}/HDR_ImageProcessingApp/assets" "%{cfg.targetdir}/assets"',
	}

	filter "configurations:Debug"
		defines "HDR_IPApp_DBG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HDR_IPApp_RELEASE"
		runtime "Release"
		optimize "speed"

	filter "configurations:Dist"
		defines "HDR_IPApp_DIST"
		runtime "Release"
		optimize "speed"

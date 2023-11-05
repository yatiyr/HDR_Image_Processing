include "dependencies.lua"

workspace "HDR_ImageProcessing"
	architecture "x86_64"
	startproject "HDR_ImageProcessingApp"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Lib"
	include "HDR_ImageProcessing"
group ""

group "App"
	include "HDR_ImageProcessingApp"
group ""

group "ThirdParty"
	include "HDR_ImageProcessing/external/glfw"
	include "HDR_ImageProcessing/external/glad"
	include "HDR_ImageProcessing/external/imgui"
        include "HDR_ImageProcessing/external/tinyexif"
group ""
#include <Precomp.h>
#include <HDR_IP/System/ResourceSystem/ResourceManager.h>


#include <stb_image.h>
#include <tinyexr.h>

namespace HDR_IP
{


	struct ResourceManagerData
	{



		std::unordered_map<std::string, uint32_t> StringLookupTable;
		std::unordered_map<uint32_t, std::string> IDLookupTable;


		uint32_t counter = 0;

		std::filesystem::path root;
	} s_ResourceManagerData;


	static uint32_t Allocate(std::string name)
	{
		s_ResourceManagerData.StringLookupTable[name] = s_ResourceManagerData.counter;
		s_ResourceManagerData.IDLookupTable[s_ResourceManagerData.counter] = name;
		s_ResourceManagerData.counter++;

		return s_ResourceManagerData.counter - 1;
	}

	// Reads the structure in root file path and loads the resources
	int ResourceManager::Init(std::filesystem::path rootFilePath)
	{
		HDR_IP_WARN("Initializing Resource Manager");
		s_ResourceManagerData.counter = 0;

		// Configure Root path
		s_ResourceManagerData.root = rootFilePath;
		HDR_IP_INFO("\tRoot path is : {0}", rootFilePath);

		std::filesystem::path assetPath = rootFilePath / "assets";
		std::filesystem::path modelPath = assetPath / "models";
		std::filesystem::path modelDatabasePath = assetPath / "modelDatabase";

		std::filesystem::path shaderPath = assetPath / "shaders";
		std::filesystem::path shaderSrcPath = shaderPath / "src";
		std::filesystem::path shaderIncludePath = shaderPath / "include";

		std::filesystem::path materialPath = assetPath / "materials";

		std::filesystem::path texturePath = assetPath / "textures";



		HDR_IP_WARN("Resource Manager has been inititalized!");
		return 0;
	}


}
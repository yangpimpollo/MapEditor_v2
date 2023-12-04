#include "prime/ResourceManager.h"

wl::ResourceManager* wl::ResourceManager::instance_;

wl::ResourceManager* wl::ResourceManager::getInstance()
{
	if (instance_ == nullptr)
		instance_ = new wl::ResourceManager();
	return instance_;
}

wl::ResourceManager::ResourceManager()
{
}

wl::ResourceManager::~ResourceManager()
{
	std::cout << "delete Resource Manager" << std::endl;
}


void wl::ResourceManager::loadResources(std::string name)
{
	// Check if a all_files contains "name" file
	if (!std::binary_search(all_files.begin(), all_files.end(), name)){
		std::cout << "load scene:" << name << "resources" << std::endl;
		readResources(name);
		indexResources(name);
	}
	else {
		//std::cout << "ya esta cargado" << std::endl;
	}
}

void wl::ResourceManager::clearResources(std::string name)
{
	auto it = std::find(all_files.begin(), all_files.end(), name);
	if (it != all_files.end()) {
		all_files.erase(it);

		str_header.erase(name);
		str_font.erase(name);
		str_texture.erase(name);
		str_sound.erase(name);
		str_string.erase(name);

		font.erase(name);
		texture.erase(name);
		sound.erase(name);

		en_pack.erase(name);
		zh_pack.erase(name);
		sp_pack.erase(name);

		std::cout << "clear: " << name << " resources" << std::endl;
	}
}

void wl::ResourceManager::readResources(std::string name)
{
	std::map<std::string, int> type = {
		{ "header" , 0 },
		{   "font" , 1 },
		{"texture" , 2 },
		{  "sound" , 3 },
		{ "string" , 4 }
	};

	std::string datatext;
	std::fstream initFile;
	initFile.open("./config/" + name + ".wo");  //, std::ios::in | std::ios::out | std::ios::app);
	if (!initFile) {
		std::cout << "Error occurred: file not loaded" << std::endl;
		exit(-1);
	}
	std::getline(initFile, datatext);

	while (std::getline(initFile, datatext)) {
		switch (type[findLabel("type", datatext)]) {
		case 0:
			if (str_header.contains(name)) { str_header.at(name).push_back(datatext); }
			else { str_header[name] = std::vector<std::string>{ datatext }; } break;
		case 1:
			if (str_font.contains(name)) { str_font.at(name).push_back(datatext); }
			else { str_font[name] = std::vector<std::string>{ datatext }; } break;
		case 2:
			if (str_texture.contains(name)) { str_texture.at(name).push_back(datatext); }
			else { str_texture[name] = std::vector<std::string>{ datatext }; } break;
		case 3:
			if (str_sound.contains(name)) { str_sound.at(name).push_back(datatext); }
			else { str_sound[name] = std::vector<std::string>{ datatext }; } break;
		case 4:
			if (str_string.contains(name)) { str_string.at(name).push_back(datatext); }
			else { str_string[name] = std::vector<std::string>{ datatext }; } break;

		}
		//std::cout << datatext << std::endl;
	}
	//std::cout << "read" << std::endl;
	initFile.close();
}

void wl::ResourceManager::indexResources(std::string name)
{
	std::cout << findLabel("name", str_header.at(name)[1]) << std::endl;

	if (str_font.contains(name)) {
		for (const auto& elem : str_font.at(name)) {
			sf::Font res_;
			if (!res_.loadFromFile("./res/" + name + "/" + findLabel("dat", elem))) {}
			if (font.contains(name)) { font.at(name)[findLabel("id", elem)] = res_; }
			else { font[name] = std::map<std::string, sf::Font>{ {findLabel("id", elem), res_ } }; }
			std::cout << "   -" << findLabel("id", elem) << std::endl;
		}
	}

	if (str_texture.contains(name)) {
		for (const auto& elem : str_texture.at(name)) {
			sf::Texture res_;
			if (!res_.loadFromFile("./res/" + name + "/" + findLabel("dat", elem))) {}
			if (texture.contains(name)) { texture.at(name)[findLabel("id", elem)] = res_; }
			else { texture[name] = std::map<std::string, sf::Texture>{ {findLabel("id", elem), res_ } }; }
			std::cout << "   -" << findLabel("id", elem) << std::endl;
		}
	}

	if (str_sound.contains(name)) {
		for (const auto& elem : str_sound.at(name)) {
			sf::SoundBuffer res_;
			if (!res_.loadFromFile("./res/" + name + "/" + findLabel("dat", elem))) {}
			if (sound.contains(name)) { sound.at(name)[findLabel("id", elem)] = res_; }
			else { sound[name] = std::map<std::string, sf::SoundBuffer>{ {findLabel("id", elem), res_ } }; }
			std::cout << "   -" << findLabel("id", elem) << std::endl;
		}
	}

	if (str_string.contains(name)) {
		for (const auto& elem : str_string.at(name)) {

			if (en_pack.contains(name)) {
				en_pack.at(name)[findLabel("id", elem)] = to_wstring(findLabel("EN", elem));
				zh_pack.at(name)[findLabel("id", elem)] = to_wstring(findLabel("ZH", elem));
				sp_pack.at(name)[findLabel("id", elem)] = to_wstring(findLabel("SP", elem));
			}
			else {
				en_pack[name] = std::map<std::string, std::wstring>{ {findLabel("id", elem), to_wstring(findLabel("EN", elem))} };
				zh_pack[name] = std::map<std::string, std::wstring>{ {findLabel("id", elem), to_wstring(findLabel("ZH", elem))} };
				sp_pack[name] = std::map<std::string, std::wstring>{ {findLabel("id", elem), to_wstring(findLabel("SP", elem))} };
			}
		}
	}

	all_files.push_back(name);
	std::cout << "loaded " << name << " : complete" << std::endl;
}

std::string wl::ResourceManager::findLabel(std::string name, std::string arg)
{
	if (arg == "") return "";
	auto ini = arg.find(name + "='") + name.size() + 2;
	auto end = arg.find("'", ini + 1);
	return  arg.substr(ini, end - ini);
}

std::wstring wl::ResourceManager::to_wstring(std::string str)
{
	using convert_t = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.from_bytes(str);
}



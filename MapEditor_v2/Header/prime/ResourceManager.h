#pragma once
#ifndef RESOURCE_MANAGER_H_INCLUDED
#define RESOURCE_MANAGER_H_INCLUDED

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <codecvt>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "prime/Window.h"

#define res wl::ResourceManager::getInstance()

namespace wl
{
	class ResourceManager
	{
	public:
		static wl::ResourceManager* getInstance();
		void loadResources(std::string name);
		void clearResources(std::string name);

		inline sf::Font& getFont(std::string name, std::string id) {
			try { return font.at(name).at(id); }
			catch (const std::out_of_range& e) { }
		};
		inline sf::Texture& getTexture(std::string name, std::string id) {
			try { return texture.at(name).at(id); }
			catch (const std::out_of_range& e) { std::runtime_error("Font not found");}
		};
		inline sf::SoundBuffer& getSound(std::string name, std::string id) { return sound.at(name).at(id); };

		inline std::wstring& getENstr(std::string name, std::string id) { return en_pack.at(name).at(id); };
		inline std::wstring& getZHstr(std::string name, std::string id) { return zh_pack.at(name).at(id); };
		inline std::wstring& getSPstr(std::string name, std::string id) { return sp_pack.at(name).at(id); };

	private:
		ResourceManager();
		~ResourceManager();
		void readResources(std::string name);
		void indexResources(std::string name);
		
		std::string findLabel(std::string name, std::string arg);
		std::wstring to_wstring(std::string str);

		std::vector<std::string> all_files;

		std::map<std::string, std::vector<std::string>> str_header;
		std::map<std::string, std::vector<std::string>> str_font;
		std::map<std::string, std::vector<std::string>> str_texture;
		std::map<std::string, std::vector<std::string>> str_sound;
		std::map<std::string, std::vector<std::string>> str_string;

		std::map <std::string, std::map<std::string, sf::Font>> font;
		std::map <std::string, std::map<std::string, sf::Texture>> texture;
		std::map <std::string, std::map<std::string, sf::SoundBuffer>> sound;

		std::map <std::string, std::map<std::string, std::wstring>> en_pack;
		std::map <std::string, std::map<std::string, std::wstring>> zh_pack;
		std::map <std::string, std::map<std::string, std::wstring>> sp_pack;

		static wl::ResourceManager* instance_;

	};



} // namespace wl

#endif
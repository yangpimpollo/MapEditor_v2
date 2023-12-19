#pragma once
#ifndef OBJECT_MANAGER_H_INCLUDED
#define OBJECT_MANAGER_H_INCLUDED

#include <iostream>
#include <string> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "prime/ResourceManager.h"
#include "phykit/APhyObject.h"
#include "phykit/ASpriteShape.h"

#define obj_mng wl::ObjectManager::getInstance()

namespace wl
{
	class ObjectManager : public sf::Drawable
	{
	public:
		static wl::ObjectManager* getInstance();
		void loadRoomObjects(std::string name);

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		ObjectManager();
		~ObjectManager();
		static wl::ObjectManager* instance_;

		std::vector<wl::APhyObject*> allObjects;
		std::vector<std::pair <float, int>> intervals;

		std::string findLabel(std::string name, std::string arg);
		void selectionSort(std::vector<std::pair <float, int>>& array);
	};






} // namespace wl

#endif
#pragma once
#ifndef APHY_OBJECT_H_INCLUDED
#define APHI_OBJECT_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "guikit/ARect.h"
#include "prime/math.h"
#include "prime/ResourceManager.h"
#include "prime/Window.h"

namespace wl
{

	class APhyObject : public sf::Drawable
	{
	public:
		inline bool operator==(const APhyObject& other) const { return this == &other; };
		inline bool equals(const APhyObject& other) const { return *this == other; };
		inline std::string getID() { return objectId; };
		inline void setID(std::string arg) { this->objectId = arg; };
		inline void generateID() { this->objectId = wl::math::genID(); };

		virtual void update(sf::Time deltaTime) = 0;
		virtual void processEvents(sf::Event event) = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	protected:
		std::string objectId;

	};

} // namespace wl


#endif
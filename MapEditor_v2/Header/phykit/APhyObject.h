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

	protected:
		std::string objectId;

	};

} // namespace wl


#endif
#pragma once
#ifndef APHY_OBJECT_H_INCLUDED
#define APHI_OBJECT_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "guikit/ARect.h"
#include "prime/ResourceManager.h"
#include "prime/Window.h"

#include "phykit/AEditTool.h"

namespace wl
{

	class APhyObject : public sf::Drawable
	{
	public:
		inline bool operator==(const APhyObject& other) const { return this == &other; }
		inline bool equals(const APhyObject& other) const { return *this == other; }
	private:

	};

} // namespace wl


#endif
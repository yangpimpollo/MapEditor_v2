#pragma once
#ifndef AGUI_OBJECT_H_INCLUDED
#define AGUI_OBJECT_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "prime/ResourceManager.h"
#include "prime/Window.h"

namespace wl
{
	namespace objectState
	{
		enum
		{
			normal = 0,
			hovered = 1,
			clicked = 2,       //press
			event_click = 3    //release
		};
	};

	class AGuiObject : public sf::Drawable
	{
	public:
		inline bool operator==(const AGuiObject& other) const { return this == &other; }
		inline bool equals(const AGuiObject& other) const { return *this == other; }
	private:

	};

} // namespace wl


#endif
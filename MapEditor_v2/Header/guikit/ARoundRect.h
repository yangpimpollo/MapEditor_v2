#pragma once
#ifndef AROUND_RECT_H_INCLUDED
#define AROUND_RECT_H_INCLUDED

#include "guikit/AGuiObject.h"

namespace wl
{
	class ARoundRect : public sf::ConvexShape
	{
	public:
		ARoundRect();
		ARoundRect(sf::Vector2f position, sf::Vector2f size, float radius = 4.f);
		~ARoundRect();
		bool contains();

	private:
		std::vector<sf::Vector2f> newpoints;
	};


} // namespace wl


#endif
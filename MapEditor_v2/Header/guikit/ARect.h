#pragma once
#ifndef ARECT_H_INCLUDED
#define ARECT_H_INCLUDED

#include "guikit/AGuiObject.h"

namespace wl
{
	class ARect
	{
	public:
		ARect();
		ARect(sf::Vector2f position, sf::Vector2f size);
		~ARect();

		inline void setPosition(sf::Vector2f arg) { this->position = arg; };
		inline void setSize(sf::Vector2f arg) { this->size = arg; };
		inline sf::Vector2f getPosition() { return this->position; };
		inline sf::Vector2f getSize() { return this->size; };
		inline sf::Vector2f getCenter() { return position + size / 2.f; }

		inline bool contains();
		inline int getQuadrant();
		inline bool inCorner();

	protected:
		sf::Vector2f position, size;

	};

	inline ARect::ARect()
	{
	}

	inline ARect::ARect(sf::Vector2f position, sf::Vector2f size)
		: position(position), size(size)
	{
	}

	inline ARect::~ARect()
	{
	}

	inline bool ARect::contains()
	{
		if (getQuadrant() != 33) { return false; }
		else { return true; }	
	}

	inline int ARect::getQuadrant()
	{
		int _i, _j;

		sf::Vector2i imouse_pos = sf::Mouse::getPosition(*win);
		sf::Vector2f mouse_pos = sf::Vector2f(static_cast<float>(imouse_pos.x), static_cast<float>(imouse_pos.y));

		if (mouse_pos.x < position.x) { _j = 1; }
		else if (mouse_pos.x == position.x) { _j = 2; }
		else if (mouse_pos.x > position.x && mouse_pos.x < position.x + size.x) { _j = 3; }
		else if (mouse_pos.x == position.x + size.x) { _j = 4; }
		else if (mouse_pos.x > position.x + size.x) { _j = 5; }

		if (mouse_pos.y < position.y) { _i = 1; }
		else if (mouse_pos.y == position.y) { _i = 2; }
		else if (mouse_pos.y > position.y && mouse_pos.y < position.y + size.y) { _i = 3; }
		else if (mouse_pos.y == position.y + size.y) { _i = 4; }
		else if (mouse_pos.y > position.y + size.y) { _i = 5; }

		return _i * 10 + _j;
	}

	inline bool ARect::inCorner()
	{
		sf::Vector2i imouse_pos = sf::Mouse::getPosition(*win);
		sf::Vector2f mouse_pos = sf::Vector2f(static_cast<float>(imouse_pos.x), static_cast<float>(imouse_pos.y));

		sf::Vector2f cornerPos = (position + size) - sf::Vector2f(3.f, 3.f);

		if (mouse_pos.x > cornerPos.x && mouse_pos.x < cornerPos.x + 6.f) {
			if (mouse_pos.y > cornerPos.y && mouse_pos.y < cornerPos.y + 6.f) return true;
		}
		return false;
	}

} // namespace wl


#endif

#pragma once
#ifndef WORKMAP_H_INCLUDED
#define WORKMAP_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "prime/ResourceManager.h"
#include "prime/Window.h"

#define res wl::ResourceManager::getInstance()
#define win wl::Window::getInstance()

namespace wl
{
	class WorkMap :public sf::Drawable
	{
	public:
		WorkMap();
		~WorkMap();
		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::View viewMap;

		sf::RectangleShape drawABox;
		sf::Text mouse_X, mouse_Y;
	};


} // namespace wl




#endif
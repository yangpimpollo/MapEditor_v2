#pragma once
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

namespace wl
{
	class Scene : public sf::Drawable
	{
	public:
		virtual bool loadScene() {};
		virtual void initScene() {};
		virtual void update(sf::Time deltaTime) {};
		virtual void processEvents(sf::Event event) {};
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) {};
		virtual bool destroyScene() {};

	private:

	};






} // namespace wl

#endif

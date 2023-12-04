#pragma once
#ifndef SCENE_MANAGER_H_INCLUDED
#define SCENE_MANAGER_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "prime/ResourceManager.h"
#include "prime/WorkGui.h"

namespace wl
{
	class SceneManager : public sf::Drawable
	{
	public:
		static wl::SceneManager* getInstance();
		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		SceneManager();
		~SceneManager();
		static wl::SceneManager* instance_;

		sf::RectangleShape drawABox;
	};


} // namespace wl

#endif

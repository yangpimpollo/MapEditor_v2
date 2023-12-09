#pragma once
#ifndef TESTER3_H_INCLUDED
#define TESTER3_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "prime/ResourceManager.h"
#include "prime/Window.h"

#include "guikit/AListener.h"
#include "phykit/ASpriteShape.h"

namespace wl
{
	class Tester3 : public sf::Drawable, public wl::AListener
	{
	public:
		static wl::Tester3* getInstance();
		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void actionPerformed(AGuiObject& obj) override;

	private:
		Tester3();
		~Tester3();
		static wl::Tester3* instance_;

		sf::View viewTest;
	};


} // namespace wl

#endif

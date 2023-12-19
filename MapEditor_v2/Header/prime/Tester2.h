#pragma once
#ifndef TESTER2_H_INCLUDED
#define TESTER2_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "game_core.h"
#include "prime/ObjectManager.h"
#include "prime/ResourceManager.h"
#include "prime/Window.h"

#include "guikit/AButton.h"
#include "guikit/AFrame.h"
#include "guikit/AList.h"
#include "guikit/AListener.h"

#include "phykit/ASpriteShape.h"

namespace wl
{
	class Tester2 : public sf::Drawable, public wl::AListener
	{
	public:
		static wl::Tester2* getInstance();
		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void actionPerformed(AGuiObject& obj) override;
	private:
		Tester2();
		~Tester2();
		static wl::Tester2* instance_;

		sf::View viewTest;
		sf::Text fps_txt, mouse_X, mouse_Y;

		wl::ASpriteShape sp1;

	};


} // namespace wl

#endif

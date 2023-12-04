#pragma once
#ifndef TESTER1_H_INCLUDED
#define TESTER1_H_INCLUDED

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "game_core.h"
#include "prime/ResourceManager.h"
#include "prime/Window.h"

#include "guikit/AButton.h"
#include "guikit/AFrame.h"
#include "guikit/AList.h"
#include "guikit/AListener.h"

namespace wl
{
	class Tester1 : public sf::Drawable, public wl::AListener
	{
	public:
		static wl::Tester1* getInstance();
		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void actionPerformed(AGuiObject& obj) override;
	private:
		Tester1();
		~Tester1();
		static wl::Tester1* instance_;

		sf::View viewTest;
		sf::Text fps_txt, mouse_X, mouse_Y;

		wl::AButton bt1, bt2, bt3, bt4;
		sf::RectangleShape texbox;
		wl::AFrame fr1;

		wl::AList li1;

		sf::Sprite sp1;
	};


} // namespace wl

#endif

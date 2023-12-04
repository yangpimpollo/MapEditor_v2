#pragma once
#ifndef ABUTTON_H_INCLUDED
#define ABUTTON_H_INCLUDED

#include "guikit/AButtonBase.h"

namespace wl
{
	class AButton : public wl::AButtonBase
	{
	public:
		AButton();
		~AButton();
		AButton(sf::Vector2f position, sf::Vector2f size, sf::String arg, float radius = 4.f);
		AButton(sf::Vector2f position, sf::Vector2f size, sf::Texture* tex, float radius = 4.f);

		void update(sf::Time deltaTime) override;
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		inline void setTextures(sf::Texture t1, sf::Texture t2) {
			tex1 = t1; tex2 = t2;
		};
		inline void setColors(sf::Color c1, sf::Color c2, sf::Color c3, sf::Color c4) {
			color1 = c1; color2 = c2; color3 = c3; color4 = c4; };
		inline void setFont(sf::Font arg) { font = arg; }
		inline bool contains() override { return roundshape.contains(); };
		void setPosition(sf::Vector2f arg) override;

	private:
		sf::Vector2f text_size;

		sf::Font font;
		sf::Texture tex1;
		sf::Texture tex2;
		sf::Color color1 = sf::Color(15, 25, 35);       // normal
		sf::Color color2 = sf::Color(255, 70, 85);      // hovered
		sf::Color color3 = sf::Color(15, 25, 55);       // clicked
		sf::Color color4 = sf::Color(255, 255, 255);    // text_color

		wl::ARoundRect roundshape;
		sf::RectangleShape texshape;
		sf::Text text;



	};

} // namespace wl

#endif
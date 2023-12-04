#pragma once
#ifndef ALIST_H_INCLUDED
#define ALIST_H_INCLUDED

#include "guikit/AGuiObject.h"
#include "guikit/AListener.h"
#include "guikit/AButton.h"

namespace wl
{
	class AList : public wl::AGuiObject, public wl::AListener
	{
	public:
		AList();
		~AList();
		AList(sf::Vector2f position, sf::Vector2f size, std::vector<std::string> list);

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void actionPerformed(AGuiObject& obj) override;

	private:
		int bknum, btnum; 
		sf::Vector2f position, size;
		std::vector<std::string> list;
		std::vector<sf::RectangleShape> backlist;
		std::vector<wl::AButton> btnlist;

		sf::Color color1 = sf::Color(10, 15, 20);       // azul
		sf::Color color2 = sf::Color(15, 20, 25);       // gris
		sf::Color color3 = sf::Color(255, 70, 85);      // rojo
		
		sf::Color color4 = sf::Color(255, 255, 255);    // text_color


	};






} // namespace wl

#endif

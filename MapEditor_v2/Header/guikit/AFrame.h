#pragma once
#ifndef AFRAME_H_INCLUDED
#define AFRAME_H_INCLUDED

#include "guikit/AButton.h"
#include "guikit/AGuiObject.h"
#include "guikit/AListener.h"
#include "guikit/ARect.h"
#include "guikit/ARoundRect.h"


namespace wl
{
	class AFrame : public wl::AGuiObject, public wl::AListener
	{
	public:
		AFrame();
		~AFrame();
		AFrame(sf::Vector2f position, sf::Vector2f size, std::string arg);

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void buid();

		void actionPerformed(AGuiObject& obj) override;
		void setPosition(sf::Vector2f arg);
		inline void setActive(bool arg) { this->active = arg; }
	private:
		bool active = true;
		bool isDragging = false;
		sf::Vector2f position, size, mouseOffset;
		sf::Uint32 ob_state;

		sf::Color color1 = sf::Color(16, 16, 16);
		sf::Color color2 = sf::Color(255, 70, 85);
		sf::Color color3 = sf::Color(15, 25, 55);

		wl::ARoundRect header;
		wl::ARect hrect;
		wl::AButton close;
		sf::RectangleShape body;
		sf::Text title;
	};

} // namespace wl

#endif

#pragma once
#ifndef AEDIT_TOOL_H_INCLUDED
#define AEDIT_TOOL_H_INCLUDED

#include "phykit/APhyObject.h"

namespace wl
{

	class AEditTool : public wl::ARect, public wl::APhyObject
	{
	public:
		AEditTool();
		~AEditTool();
		AEditTool(sf::Vector2f position, sf::Vector2f size);

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void preedit(sf::Event event);
		void edition(sf::Event event);

		//void setPosition(sf::Vector2f arg);
		void setEnabled(bool arg) { this->activeEdit = arg; };
		void setToggle() { this->activeEdit = !activeEdit; }; 

	private:
		bool activeEdit = false;
		bool isDragging = false;
		bool isScale = false;
		bool isSelected = false;
		sf::Vector2f mouseOffset;
		sf::Vector2f sizeOffset;

		sf::RectangleShape edgeShape;
		sf::Vertex lineL[2], lineR[2];

		sf::Color color = sf::Color::Cyan;
	};










} // namespace wl

#endif

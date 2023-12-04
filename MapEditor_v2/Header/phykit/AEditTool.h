#pragma once
#ifndef AEDIT_TOOL_H_INCLUDED
#define AEDIT_TOOL_H_INCLUDED

#include "phykit/APhyObject.h"

namespace wl
{

	class AEditTool : public sf::Drawable
	{
	public:
		AEditTool();
		~AEditTool();
		AEditTool(ARect* rect);

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void setPosition(sf::Vector2f arg);
		void setEnabled(bool arg) { this->activeEdit = arg; };
		void setToggle() { this->activeEdit = !activeEdit; };

	private:
		ARect* _rect;
		bool activeEdit;
		sf::Vector2f mouseOffset;

		sf::RectangleShape rectShape;
	};










} // namespace wl

#endif

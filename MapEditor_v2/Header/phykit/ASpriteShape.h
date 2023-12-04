#pragma once
#ifndef ASPRITE_SHAPE_H_INCLUDED
#define ASPRITE_SHAPE_H_INCLUDED

#include "phykit/APhyObject.h"

namespace wl
{
	class ASpriteShape : public wl::ARect, public wl::APhyObject
	{
	public:
		ASpriteShape();
		~ASpriteShape();
		ASpriteShape(sf::Vector2f position, sf::Vector2f size, sf::Texture* tex);

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void setPosition(sf::Vector2f arg);

	private:
		//bool editMode = false;
		bool isDragging = false;
		bool isSelected = false;
		sf::Vector2f mouseOffset;

		sf::RectangleShape rectShape;
		sf::Texture tex;
		sf::Vertex lineL[2], lineR[2];

		wl::AEditTool edit;
	};



} // namespace wl

#endif









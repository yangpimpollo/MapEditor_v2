#pragma once
#ifndef ASPRITE_SHAPE_H_INCLUDED
#define ASPRITE_SHAPE_H_INCLUDED

#include "phykit/AEditTool.h"

namespace wl
{
	class ASpriteShape : public wl::AEditTool
	{
	public:
		ASpriteShape();
		~ASpriteShape();
		ASpriteShape(sf::Vector2f position, sf::Vector2f size, sf::Texture* tex, float z,std::string id="");

		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	private:

		sf::RectangleShape rectShape;
		sf::Texture tex;
	};



} // namespace wl

#endif









#include "phykit/ASpriteShape.h"

wl::ASpriteShape::ASpriteShape()
{
}

wl::ASpriteShape::~ASpriteShape()
{
}

wl::ASpriteShape::ASpriteShape(sf::Vector2f position, sf::Vector2f size, sf::Texture* tex)
	: wl::AEditTool(position, size), tex(*tex)
{
	rectShape.setPosition(position);
	rectShape.setSize(size);
	rectShape.setTexture(tex);
}

void wl::ASpriteShape::update(sf::Time deltaTime)
{
	wl::AEditTool::update(deltaTime);
	rectShape.setPosition(position);
	rectShape.setSize(size);
}

void wl::ASpriteShape::processEvents(sf::Event event)
{
	wl::AEditTool::processEvents(event);
		
}

void wl::ASpriteShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectShape);
	wl::AEditTool::draw(target, states);

}

//void wl::ASpriteShape::setPosition(sf::Vector2f arg)
//{
//	//rectShape.setPosition(position);
//}

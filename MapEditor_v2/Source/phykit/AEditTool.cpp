#include "phykit/AEditTool.h"

wl::AEditTool::AEditTool()
{
}

wl::AEditTool::~AEditTool()
{
}

wl::AEditTool::AEditTool(ARect* rect)
	: _rect(rect)
{
	rectShape.setPosition(_rect->getPosition());
	rectShape.setSize(_rect->getSize());
	rectShape.setFillColor(sf::Color::Transparent);
	rectShape.setOutlineThickness(1.5f);
	rectShape.setOutlineColor(sf::Color::Green);
}

void wl::AEditTool::update(sf::Time deltaTime)
{
}

void wl::AEditTool::processEvents(sf::Event event)
{
	if (activeEdit) {

	}
}

void wl::AEditTool::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(activeEdit) target.draw(rectShape);
}

void wl::AEditTool::setPosition(sf::Vector2f arg)
{
	rectShape.setPosition(arg);
}

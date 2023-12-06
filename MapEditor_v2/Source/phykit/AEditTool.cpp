#include "phykit/AEditTool.h"

wl::AEditTool::AEditTool()
{
}

wl::AEditTool::~AEditTool()
{
}

wl::AEditTool::AEditTool(ARect rect)
	: _rect(rect)
{
	rectShape.setPosition(_rect.getPosition());
	rectShape.setSize(_rect.getSize());
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
		//std::cout << "c1" << _rect.getPosition().x << std::endl;
		//std::cout << "c2" << _rect.getSize().x << std::endl;
		//if(_rect->contains()) std::cout << "c1" << std::endl;
		switch (_rect.getQuadrant()){
		case 24: case 42: win->setSizeCursor(1); break;
		case 32: case 34: win->setSizeCursor(2); break;
		case 22: case 44: win->setSizeCursor(3); break;
		case 23: case 43: win->setSizeCursor(4); break;
		default: win->setSizeCursor(0); 
			std::cout << "def0" << std::endl; break;
		}
	}
}

void wl::AEditTool::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(activeEdit) target.draw(rectShape);
}

void wl::AEditTool::setPosition(sf::Vector2f arg)
{
	_rect.setPosition(arg);
	rectShape.setPosition(arg);
}

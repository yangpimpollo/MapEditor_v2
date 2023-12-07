#include "phykit/AEditTool.h"

wl::AEditTool::AEditTool()
{
}

wl::AEditTool::~AEditTool()
{
}

wl::AEditTool::AEditTool(sf::Vector2f position, sf::Vector2f size)
	: wl::ARect(position, size)
{
	edgeShape.setPosition(position);
	edgeShape.setSize(size);
	edgeShape.setFillColor(sf::Color::Transparent);
	edgeShape.setOutlineThickness(1.5f);
	edgeShape.setOutlineColor(color);

	
}

void wl::AEditTool::update(sf::Time deltaTime)
{
	edgeShape.setSize(size);
	edgeShape.setPosition(position);
	
	lineL[0] = sf::Vertex(getCenter() - sf::Vector2f(5.f, 5.f), color);
	lineL[1] = sf::Vertex(getCenter() + sf::Vector2f(5.f, 5.f), color);
	lineR[0] = sf::Vertex(getCenter() - sf::Vector2f(5.f, -5.f), color);
	lineR[1] = sf::Vertex(getCenter() + sf::Vector2f(5.f, -5.f), color);
}

void wl::AEditTool::processEvents(sf::Event event)
{
	preedit(event);
	if (activeEdit) edition(event);
}

void wl::AEditTool::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (activeEdit) target.draw(edgeShape);

	if (isSelected) {
		target.draw(lineL, 2, sf::Lines);
		target.draw(lineR, 2, sf::Lines);
	}
}

void wl::AEditTool::preedit(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (contains() && !inCorner()) {
			mouseOffset = win->getCursorPos() - position;
			isDragging = true;
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		//std::cout << "click" << std::endl;
		mouseOffset = sf::Vector2f(0.f, 0.f);
		isDragging = false;
		isSelected = (contains()) ? true : false;
	}
	else if (event.type == sf::Event::MouseMoved && isDragging) {
		position = win->getCursorPos() - mouseOffset;
		setPosition(position);
	}

	if (isSelected) {
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::E)
			setToggle();
	}
	else {
		setEnabled(false);
	}
}

void wl::AEditTool::edition(sf::Event event)
{
	//if (inCorner()) {
		//win->setSizeCursor(3);
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			if (inCorner()) {
				isScale = true;
				mouseOffset = win->getCursorPos();
				sizeOffset = size;
			}
			
		}
		else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			mouseOffset = sf::Vector2f(0.f, 0.f);
			isScale = false;
		}
		else if (event.type == sf::Event::MouseMoved && isScale) {
			sf::Vector2f delta = win->getCursorPos() - mouseOffset;
			//std::cout << "click" << std::endl;
			if ((sizeOffset + delta).x > 10.f && (sizeOffset + delta).y > 10.f) {
				size = sizeOffset + delta;
			}
			setSize(size);
		}

	//}else {
		//win->setSizeCursor(0);
	//}
}

//void wl::AEditTool::setPosition(sf::Vector2f arg)
//{
//	//edgeShape.setPosition(arg);
//	//lineL[0] = sf::Vertex(getCenter() - sf::Vector2f(5.f, 5.f), color);
//	//lineL[1] = sf::Vertex(getCenter() + sf::Vector2f(5.f, 5.f), color);
//	//lineR[0] = sf::Vertex(getCenter() - sf::Vector2f(5.f, -5.f), color);
//	//lineR[1] = sf::Vertex(getCenter() + sf::Vector2f(5.f, -5.f), color);
//
//}

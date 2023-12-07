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
	edgeShape.setFillColor(sf::Color(255,0,255, 50));
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
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (inCorner() && activeEdit) {
			isScale = true;
			mouseOffset = win->getCursorPos();
			sizeOffset = size;
		}else if (contains()) {
			mouseOffset = win->getCursorPos() - position;
			isDragging = true;
		}
	}else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		//std::cout << "click" << std::endl;
		isSelected = (contains()) ? true : false;
		mouseOffset = sf::Vector2f(0.f, 0.f);
		isDragging = false;
		mouseOffset = sf::Vector2f(0.f, 0.f);
		isScale = false;

	}else if (event.type == sf::Event::MouseMoved) {

		if (isScale) {
			sf::Vector2f delta = win->getCursorPos() - mouseOffset;
			if ((sizeOffset + delta).x > 10.f && (sizeOffset + delta).y > 10.f) {
				size = sizeOffset + delta;
			}
			setSize(size);
		}else if (isDragging) {
			position = win->getCursorPos() - mouseOffset;
			setPosition(position);
		}

	}

	if (isSelected) {
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::E)
			setToggle();
	}else {
		setEnabled(false);
	}

	if (inCorner() && activeEdit) {
		win->setSizeCursor(3);
	}else {
		win->setSizeCursor(0);
	}
}

void wl::AEditTool::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (activeEdit) target.draw(edgeShape);

	if (isSelected) {
		target.draw(lineL, 2, sf::Lines);
		target.draw(lineR, 2, sf::Lines);
	}
}

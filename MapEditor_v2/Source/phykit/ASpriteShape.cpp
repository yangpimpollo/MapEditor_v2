#include "phykit/ASpriteShape.h"

wl::ASpriteShape::ASpriteShape()
{
}

wl::ASpriteShape::~ASpriteShape()
{
}

wl::ASpriteShape::ASpriteShape(sf::Vector2f position, sf::Vector2f size, sf::Texture* tex)
	: wl::ARect(position, size), tex(*tex)
{
	rectShape.setPosition(position);
	rectShape.setSize(size);
	rectShape.setTexture(tex);

	edit = wl::AEditTool(this);
}

void wl::ASpriteShape::update(sf::Time deltaTime)
{
}

void wl::ASpriteShape::processEvents(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (contains()) {
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
			edit.setToggle();
	}
	else {
		edit.setEnabled(false);
	}

	sf::Vector2f center = position + size / 2.f;

	lineL[0] = sf::Vertex(center - sf::Vector2f(5.f, 5.f), sf::Color::Black);
	lineL[1] = sf::Vertex(center + sf::Vector2f(5.f, 5.f), sf::Color::Black);
	lineR[0] = sf::Vertex(center - sf::Vector2f(5.f, -5.f), sf::Color::Black);
	lineR[1] = sf::Vertex(center + sf::Vector2f(5.f, -5.f), sf::Color::Black);
		
}

void wl::ASpriteShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectShape);
	target.draw(edit);
	if (isSelected) {
		target.draw(lineL, 2, sf::Lines);
		target.draw(lineR, 2, sf::Lines);
	}
}

void wl::ASpriteShape::setPosition(sf::Vector2f arg)
{
	rectShape.setPosition(arg);
	edit.setPosition(arg);
}

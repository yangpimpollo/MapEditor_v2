#include "guikit/AList.h"

wl::AList::AList()
{
}

wl::AList::~AList()
{
}

wl::AList::AList(sf::Vector2f position, sf::Vector2f size, std::vector<std::string> list)
	: position(position), size(size), list(list)
{
	bknum = size.y / 20;
	btnum = (list.size()<bknum)? list.size() : bknum;

	for (int i = 0; i < bknum; i++) {
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(size.x, 20.f));
		rect.setPosition(sf::Vector2f(position.x, position.y + i*20.f));
		rect.setFillColor((i % 2 != 0)? color2 : color1);
		backlist.push_back(rect);
	}

	for (int i = 0; i < btnum; i++) {
		wl::AButton btn = wl::AButton(
			sf::Vector2f(position.x + 5.f, position.y + 1.f + i * 20.f), 
			sf::Vector2f(size.x - 10.f, 18.f), 
			list.at(i),
			5.f
		);
		btn.setColors(
			sf::Color::Transparent,      // normal
			sf::Color(255, 70, 85),      // hovered
			sf::Color(15, 25, 55),       // clicked
			sf::Color(255, 255, 255)    // text_color
		);
		btnlist.push_back(btn);
	}


}

void wl::AList::update(sf::Time deltaTime)
{
}

void wl::AList::processEvents(sf::Event event)
{
	for (int i = 0; i < btnum; i++) {

		btnlist.at(i).processEvents(event);
	}
}

void wl::AList::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < bknum; i++) {

		target.draw(backlist.at(i));
	}

	for (int i = 0; i < btnum; i++) {

		target.draw(btnlist.at(i));
	}
}

void wl::AList::actionPerformed(AGuiObject& obj)
{
}

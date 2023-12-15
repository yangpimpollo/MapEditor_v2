#include "pieces/workmap/WorkMap.h"

wl::WorkMap::WorkMap()
{
	//-----------
	viewMap = sf::View(sf::FloatRect(0.f, 0.f, 900, 600));
	viewMap.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//-----------

	drawABox.setSize(sf::Vector2f(1218.f, 754.f));
	drawABox.setPosition(sf::Vector2f(0.f, 0.f));
	drawABox.setTexture(&res->getTexture("global", "map"));

	mouse_X.setFont(res->getFont("global", "CascadiaMono300"));
	mouse_X.setCharacterSize(12);
	mouse_X.setFillColor(sf::Color::Green);
	mouse_X.setPosition(40.f, 95.f);

	mouse_Y.setFont(res->getFont("global", "CascadiaMono300"));
	mouse_Y.setCharacterSize(12);
	mouse_Y.setFillColor(sf::Color::Green);
	mouse_Y.setPosition(40.f, 110.f);
}

wl::WorkMap::~WorkMap()
{
}

void wl::WorkMap::update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { viewMap.move(-0.01f, 0.f); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { viewMap.move(0.01f, 0.f); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { viewMap.move(0.f, -0.01f); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { viewMap.move(0.f, 0.01f); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
		std::cout << "view centerX: " << viewMap.getCenter().x << std::endl;
		std::cout << "view centerY: " << viewMap.getCenter().y << std::endl;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		//std::cout << "view centerX: " << viewMap.getCenter().x << std::endl;
		//std::cout << "view centerY: " << viewMap.getCenter().y << std::endl;
		viewMap.setCenter(0.f, 0.f);
	}

	
	std::string x = std::to_string((int)win->mapPixelToCoords(sf::Mouse::getPosition(*win), viewMap).x);
	std::string y = std::to_string((int)win->mapPixelToCoords(sf::Mouse::getPosition(*win), viewMap).y);
	this->mouse_X.setString("screen x: " + x);
	this->mouse_Y.setString("screen y: " + y);
}

void wl::WorkMap::processEvents(sf::Event event)
{
	if (event.type == sf::Event::Resized)
	{
		viewMap.setSize(event.size.width, event.size.height);
		viewMap.setCenter(event.size.width / 2, event.size.height / 2);
	}


	if (event.type == sf::Event::MouseWheelScrolled)
	{
		float delta = event.mouseWheelScroll.delta;

		viewMap.zoom(1.f + delta * 0.1f);
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		std::cout << "click" << std::endl;
	}
}

void wl::WorkMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(viewMap);
	target.draw(drawABox);
	target.draw(mouse_X);
	target.draw(mouse_Y);
}

#include "prime/Window.h"

wl::Window* wl::Window::instance_;

wl::Window* wl::Window::getInstance()
{
	if (instance_ == nullptr) 
		instance_ = new wl::Window();
	return instance_;
}

void wl::Window::processEvents(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		this->close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		this->close();

	//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::E) {
	//	//std::cout << "E" << std::endl;

	//	
	//}
	//else {
	//	
	//}


	//if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	//	
	//	cursor1
	//	this->setMouseCursor(cursor1);
	//}
	//else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
	//	this->setMouseCursor(cursor);
	//}
}

wl::Window::Window()
{
	std::cout << "create game window" << std::endl;

	int WIDTH = 900;
	int HEIGHT = 600;
	int winStyle = 1;
	std::string TITLE = "wild_mapEditor";

	sf::ContextSettings settings; settings.antialiasingLevel = 8;
	sf::Image cursorImg = res->getTexture("global", "cursor").copyToImage();
	cursor.loadFromPixels(cursorImg.getPixelsPtr(), sf::Vector2u(20, 20), sf::Vector2u(0, 0));

	this->create(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Default, settings);
	this->setIcon(64, 64, sf::Image(res->getTexture("global", "icon").copyToImage()).getPixelsPtr());
	this->setMouseCursor(cursor);

	//--------------------------------------

	s_cursor1.loadFromSystem(sf::Cursor::SizeBottomLeftTopRight);
	s_cursor2.loadFromSystem(sf::Cursor::SizeHorizontal);
	s_cursor3.loadFromSystem(sf::Cursor::SizeTopLeftBottomRight);
	s_cursor4.loadFromSystem(sf::Cursor::SizeVertical);
}

wl::Window::~Window()
{
	std::cout << "delete game window" << std::endl;
}

sf::Vector2f wl::Window::getCursorPos()
{
	sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(*this);
	return sf::Vector2f(static_cast<float>(mouse_pos_i.x), static_cast<float>(mouse_pos_i.y));
}

void wl::Window::setSizeCursor(int arg)
{
	
	switch (arg){
	case 1: setMouseCursor(s_cursor1); break;
	case 2: setMouseCursor(s_cursor2); break;
	case 3: setMouseCursor(s_cursor3); break;
	case 4: setMouseCursor(s_cursor4); break;
	default: setMouseCursor(cursor); break;
	}
}

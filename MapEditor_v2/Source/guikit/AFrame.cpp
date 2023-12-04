#include "guikit/AFrame.h"

wl::AFrame::AFrame()
{
}

wl::AFrame::~AFrame()
{
}

wl::AFrame::AFrame(sf::Vector2f position, sf::Vector2f size, std::string arg)
	: position(position), size(size)
{
	header = wl::ARoundRect(position, sf::Vector2f(size.x, 22.f), 2.f);
	header.setFillColor(color2);
	hrect = wl::ARect(position, sf::Vector2f(size.x - 22.f, 22.f));

	title.setFont(res->getFont("global_res", "CascadiaMono300"));
	title.setString(arg);
	title.setCharacterSize(12);
	title.setFillColor(sf::Color::Black);
	title.setPosition(position.x + 5.f, position.y + 3.f);

	close = wl::AButton(position + sf::Vector2f(size.x - 22.f, 0.f), sf::Vector2f(22.f, 22.f), &res->getTexture("global_res", "close1"), 2.f);
	close.setColors(color2, color1, color3, sf::Color::Black);
	close.setTextures(res->getTexture("global_res", "close1"), res->getTexture("global_res", "close2"));

	body.setPosition(position.x, position.y + 10.f);
	body.setSize(size);
	body.setFillColor(color1);

}

void wl::AFrame::update(sf::Time deltaTime)
{
	
}

void wl::AFrame::processEvents(sf::Event event)
{
	
	

	if (active) {
		close.processEvents(event);

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			if (hrect.contains()) {
				mouseOffset = win->getCursorPos() - position;
				isDragging = true;				
			}
		}else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			mouseOffset = sf::Vector2f(0.f, 0.f);
			isDragging = false;
		}else if (event.type == sf::Event::MouseMoved && isDragging){
			position = win->getCursorPos() - mouseOffset;
			setPosition(position);
		}


	}
}

void wl::AFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (active) {
		target.draw(body);
		target.draw(header);
		target.draw(title);
		target.draw(close);
	}
}

void wl::AFrame::buid()
{
	close.addActionListener(*this);
}

void wl::AFrame::actionPerformed(AGuiObject& obj)
{
}

void wl::AFrame::setPosition(sf::Vector2f arg)
{
	header.setPosition(arg);
	hrect.setPosition(arg);
	title.setPosition(arg.x + 5.f, arg.y + 3.f);
	close.setPosition(position + sf::Vector2f(size.x - 22.f, 0.f));
	body.setPosition(position.x, position.y + 10.f);
}

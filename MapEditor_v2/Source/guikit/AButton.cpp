#include "guikit/AButton.h"

wl::AButton::AButton()
{
}

wl::AButton::~AButton()
{
}

wl::AButton::AButton(sf::Vector2f position, sf::Vector2f size, sf::String arg, float radius)
	: AButtonBase(position, size)
{
	text.setFont(res->getFont("global", "CascadiaMono300"));
	text.setString(arg);
	text.setCharacterSize(12);
	text.setFillColor(color4);
	text_size = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
	text.setPosition(position.x + ((size.x - text_size.x) / 2), position.y + 3);

	roundshape = ARoundRect(position, size, radius);
	roundshape.setFillColor(color1);
}

wl::AButton::AButton(sf::Vector2f position, sf::Vector2f size, sf::Texture* tex, float radius)
	: AButtonBase(position, size), tex1(*tex), tex2(*tex)
{
	roundshape = ARoundRect(position, size, radius);
	texshape.setSize(size);
	texshape.setPosition(position);
	texshape.setTexture(&tex1);
}

void wl::AButton::update(sf::Time deltaTime)
{
}

void wl::AButton::processEvents(sf::Event event)
{
	AButtonBase::processEvents(event);

	switch (m_btnstate) {
	case objectState::normal: { 
		roundshape.setFillColor(color1);
		texshape.setTexture(&tex1);
	}break;
	case objectState::hovered: { 
		roundshape.setFillColor(color2);
		texshape.setTexture(&tex2);
	}break;
	case objectState::clicked: {
		roundshape.setFillColor(color3);
		
		//std::cout << "click" << std::endl;
	}break;

	case objectState::event_click: {
		roundshape.setFillColor(color2);
		//std::cout << "event" << std::endl;
		//try {
		actionListener->actionPerformed(*this);
		//} catch (const std::out_of_range& e) { 
		//	std::runtime_error("Font not found"); 
		//}
	}break;
	}
	
}

void wl::AButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(roundshape);
	target.draw(texshape);
	target.draw(text);
}

void wl::AButton::setPosition(sf::Vector2f arg)
{
	position = arg;
	texshape.setPosition(position);
	text.setPosition(position.x + ((size.x - text_size.x) / 2), position.y + 3);
	roundshape.setPosition(position);
}


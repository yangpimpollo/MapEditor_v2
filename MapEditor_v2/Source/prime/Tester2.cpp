#include "prime/Tester2.h"

wl::Tester2* wl::Tester2::instance_;

wl::Tester2::Tester2()
{	

	//-----------
	viewTest = sf::View(sf::FloatRect(0.f, 0.f, 900, 600));
	viewTest.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//-----------

	fps_txt.setFont(res->getFont("global", "CascadiaMono300"));
	fps_txt.setCharacterSize(15);
	fps_txt.setFillColor(sf::Color::Red);
	fps_txt.setPosition(40.f, 40.f);

	mouse_X.setFont(res->getFont("global", "CascadiaMono300"));
	mouse_X.setCharacterSize(12);
	mouse_X.setFillColor(sf::Color::Red);
	mouse_X.setPosition(40.f, 65.f);

	mouse_Y.setFont(res->getFont("global", "CascadiaMono300"));
	mouse_Y.setCharacterSize(12);
	mouse_Y.setFillColor(sf::Color::Red);
	mouse_Y.setPosition(40.f, 80.f);

	//------------------------------------------------------------------//

	sp1 = wl::ASpriteShape(
		sf::Vector2f(200.f, 200.f), 
		sf::Vector2f(100.f, 100.f), 
		&res->getTexture("scene1", "pixel5")
	);

}

wl::Tester2::~Tester2()
{
}

wl::Tester2* wl::Tester2::getInstance()
{
    if (instance_ == nullptr)
        instance_ = new wl::Tester2();
    return instance_;
}

void wl::Tester2::update(sf::Time deltaTime)
{
	std::string fps = std::to_string(wl::game_core::getInstance()->getFPS());
	fps_txt.setString("fps: " + fps);

	std::string x = std::to_string(sf::Mouse::getPosition(*win).x);
	std::string y = std::to_string(sf::Mouse::getPosition(*win).y);
	this->mouse_X.setString("screen x: " + x);
	this->mouse_Y.setString("screen y: " + y);

	//------------------------------------------------------------------//
	sp1.update(deltaTime);
}

void wl::Tester2::processEvents(sf::Event event)
{
	if (event.type == sf::Event::Resized)
	{
		viewTest.setSize(event.size.width, event.size.height);
		viewTest.setCenter(event.size.width / 2, event.size.height / 2);
	}

	sp1.processEvents(event);
}

void wl::Tester2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(viewTest);
	target.draw(this->fps_txt);
	target.draw(this->mouse_X);
	target.draw(this->mouse_Y);

	//------------------------------------------------------------------//

	target.draw(this->sp1);
}

void wl::Tester2::actionPerformed(AGuiObject& obj)
{
}



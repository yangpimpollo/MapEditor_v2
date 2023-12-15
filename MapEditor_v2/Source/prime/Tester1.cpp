#include "prime/Tester1.h"

wl::Tester1* wl::Tester1::instance_;

wl::Tester1::Tester1()
{
	//-----------
	viewTest = sf::View(sf::FloatRect(0.f, 0.f, 900, 600));
	viewTest.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//-----------

	sp1.setPosition(450.f, 400.f);
	sp1.setTexture(res->getTexture("scene1", "pixel5"));

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

	bt1 = wl::AButton(sf::Vector2f(200.f, 20.f), sf::Vector2f(80.f, 22.f), "LoadRes", 0.f);
	bt2 = wl::AButton(sf::Vector2f(200.f, 50.f), sf::Vector2f(80.f, 22.f), "changeTex1");
	bt3 = wl::AButton(sf::Vector2f(200.f, 80.f), sf::Vector2f(80.f, 22.f), "changeTex2");
	bt4 = wl::AButton(sf::Vector2f(320.f, 20.f), sf::Vector2f(30.f, 30.f), &res->getTexture("global", "icon"));
	bt1.addActionListener(*this);
	bt2.addActionListener(*this);
	bt3.addActionListener(*this);
	bt4.addActionListener(*this);

	texbox.setSize(sf::Vector2f(200.f, 200.f));
	texbox.setPosition(sf::Vector2f(50.f, 150.f));
	texbox.setTexture(&res->getTexture("global", "pixel5"));

	//-----------
	
	fr1 = wl::AFrame(sf::Vector2f(20.f, 380.f), sf::Vector2f(350.f, 200.f), "LoadRes");
	fr1.buid();

	//-----------
	std::vector<std::string> list = { "Avion", "barco", "camion", "dado" };
	li1 = wl::AList(sf::Vector2f(450.f, 50.f), sf::Vector2f(350.f, 350.f), list);

}

wl::Tester1::~Tester1()
{
}

wl::Tester1* wl::Tester1::getInstance()
{
    if (instance_ == nullptr)
        instance_ = new wl::Tester1();
    return instance_;
}

void wl::Tester1::update(sf::Time deltaTime)
{
	std::string fps = std::to_string(wl::game_core::getInstance()->getFPS());
	fps_txt.setString("fps: " + fps);

	std::string x = std::to_string(sf::Mouse::getPosition(*win).x);
	std::string y = std::to_string(sf::Mouse::getPosition(*win).y);
	this->mouse_X.setString("screen x: " + x);
	this->mouse_Y.setString("screen y: " + y);

	fr1.update(deltaTime);
}

void wl::Tester1::processEvents(sf::Event event)
{
	if (event.type == sf::Event::Resized)
	{
		viewTest.setSize(event.size.width, event.size.height);
		viewTest.setCenter(event.size.width / 2, event.size.height / 2);
	}

	bt1.processEvents(event);
	bt2.processEvents(event);
	bt3.processEvents(event);
	bt4.processEvents(event);
	fr1.processEvents(event);
	li1.processEvents(event);
}

void wl::Tester1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(viewTest);
	target.draw(this->fps_txt);
	target.draw(this->mouse_X);
	target.draw(this->mouse_Y);
	target.draw(this->bt1);
	target.draw(this->bt2);
	target.draw(this->bt3);
	target.draw(this->bt4);
	target.draw(this->texbox);
	target.draw(this->fr1);
	target.draw(this->li1);
	target.draw(this->sp1);
}

void wl::Tester1::actionPerformed(AGuiObject& obj)
{
	if (obj == bt1) res->loadRoom("scene1");
	if (obj == bt2) {
		texbox.setSize(sf::Vector2f(200.f, 200.f));
		texbox.setTexture(&res->getTexture("scene1", "pixel3"));
	}
	if (obj == bt3) {
		texbox.setSize(sf::Vector2f(200.f, 200.f));
		texbox.setTexture(&res->getTexture("scene1", "pixel4"));
	}
	if (obj == bt4) res->closeRoom("scene1");
}

#include "prime/Tester3.h"

wl::Tester3* wl::Tester3::instance_;


wl::Tester3* wl::Tester3::getInstance()
{
	if (instance_ == nullptr)
		instance_ = new wl::Tester3();
	return instance_;
}

wl::Tester3::Tester3()
{
	//-----------
	viewTest = sf::View(sf::FloatRect(0.f, 0.f, 900, 600));
	viewTest.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//-----------
}

wl::Tester3::~Tester3()
{
}

void wl::Tester3::update(sf::Time deltaTime)
{
}

void wl::Tester3::processEvents(sf::Event event)
{
	if (event.type == sf::Event::Resized)
	{
		viewTest.setSize(event.size.width, event.size.height);
		viewTest.setCenter(event.size.width / 2, event.size.height / 2);
	}

	//--------------------------

}

void wl::Tester3::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(viewTest);

	//--------------------------
}

void wl::Tester3::actionPerformed(AGuiObject& obj)
{
}



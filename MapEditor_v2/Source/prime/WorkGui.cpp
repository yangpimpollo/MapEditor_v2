#include "prime/WorkGui.h"

wl::WorkGui* wl::WorkGui::instance_;

wl::WorkGui::WorkGui()
{
}

wl::WorkGui::~WorkGui()
{
}

wl::WorkGui* wl::WorkGui::getInstance()
{
	if (instance_ == nullptr)
		instance_ = new wl::WorkGui();
	return instance_;
}

void wl::WorkGui::update(sf::Time deltaTime)
{
}

void wl::WorkGui::processEvents(sf::Event event)
{
}

void wl::WorkGui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

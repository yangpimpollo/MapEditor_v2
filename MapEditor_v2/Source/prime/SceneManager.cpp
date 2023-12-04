#include "prime/SceneManager.h"

wl::SceneManager* wl::SceneManager::instance_;

wl::SceneManager::SceneManager()
{
}

wl::SceneManager::~SceneManager()
{
}

wl::SceneManager* wl::SceneManager::getInstance()
{
	if (instance_ == nullptr)
		instance_ = new wl::SceneManager();
	return instance_;
}

void wl::SceneManager::update(sf::Time deltaTime)
{
	wl::WorkGui::getInstance()->update(deltaTime);
	
}

void wl::SceneManager::processEvents(sf::Event event)
{
	wl::WorkGui::getInstance()->processEvents(event);
}

void wl::SceneManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*wl::WorkGui::getInstance());
}

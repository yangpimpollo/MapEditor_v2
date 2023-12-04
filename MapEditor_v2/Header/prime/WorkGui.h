#pragma once
#ifndef WORKGUI_H_INCLUDED
#define WORKGUI_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

namespace wl
{
	class WorkGui :public sf::Drawable
	{
	public:
		static wl::WorkGui* getInstance();
		void update(sf::Time deltaTime);
		void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		WorkGui();
		~WorkGui();
		static wl::WorkGui* instance_;
	};


} // namespace wl




#endif

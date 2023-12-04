#pragma once
#ifndef ABUTTON_BASE_H_INCLUDED
#define ABUTTON_BASE_H_INCLUDED

#include "guikit/AGuiObject.h"
#include "guikit/AListener.h"
#include "guikit/ARect.h"
#include "guikit/ARoundRect.h"

namespace wl
{
	class AButtonBase : public wl::AGuiObject
	{
	public:
		AButtonBase();
		~AButtonBase();
		AButtonBase(sf::Vector2f position, sf::Vector2f size);
		virtual void update(sf::Time deltaTime)= 0;
		virtual void processEvents(sf::Event event);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
		inline void addActionListener(wl::AListener& arg) { actionListener = &arg; }

		virtual bool contains() = 0;
		virtual void setPosition(sf::Vector2f arg) = 0;

	protected:
		sf::Uint32 m_btnstate;
		wl::AListener* actionListener;
		sf::Vector2f position, size;
	};

	inline AButtonBase::AButtonBase()
	{
	}

	inline AButtonBase::~AButtonBase()
	{
	}

	inline AButtonBase::AButtonBase(sf::Vector2f position, sf::Vector2f size)
		: position(position), size(size)
	{
	}

	inline void AButtonBase::processEvents(sf::Event event)
	{
		if (contains()) {
			m_btnstate = objectState::hovered;
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				m_btnstate = objectState::clicked;
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				m_btnstate = objectState::event_click;
			}
		}
		else {
			m_btnstate = objectState::normal;
		}
	}

} // namespace wl

#endif
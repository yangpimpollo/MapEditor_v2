#include "phykit/AEditTool.h"

wl::AEditTool::AEditTool()
{
}

wl::AEditTool::~AEditTool()
{
}

wl::AEditTool::AEditTool(sf::Vector2f position, sf::Vector2f size)
	: wl::ARect(position, size)
{
	edgeShape.setPosition(position);
	edgeShape.setSize(size);
	edgeShape.setFillColor(sf::Color(255,0,255, 50));
	edgeShape.setOutlineThickness(1.5f);
	edgeShape.setOutlineColor(color);

	//--------------------------
	id_tx.setFont(res->getFont("global_res", "CascadiaMono300"));
	id_tx.setCharacterSize(10);
	id_tx.setFillColor(color);
	w_tx.setFont(res->getFont("global_res", "CascadiaMono300"));
	w_tx.setCharacterSize(10);
	w_tx.setFillColor(color);
	h_tx.setFont(res->getFont("global_res", "CascadiaMono300"));
	h_tx.setCharacterSize(10);
	h_tx.setFillColor(color);
	x_tx.setFont(res->getFont("global_res", "CascadiaMono300"));
	x_tx.setCharacterSize(10);
	x_tx.setFillColor(color);
	y_tx.setFont(res->getFont("global_res", "CascadiaMono300"));
	y_tx.setCharacterSize(10);
	y_tx.setFillColor(color);
	z_tx.setFont(res->getFont("global_res", "CascadiaMono300"));
	z_tx.setCharacterSize(10);
	z_tx.setFillColor(color);
	//--------------------------

}

void wl::AEditTool::update(sf::Time deltaTime)
{
	edgeShape.setSize(size);
	edgeShape.setPosition(position); 

	//--------------------------
	id_tx.setPosition(position.x, position.y - 15.f); 
	id_tx.setString(getID());
	w_tx.setPosition(position.x + size.x + 5.f, position.y);
	w_tx.setString("w:" + std::to_string((int)size.x));
	h_tx.setPosition(position.x + size.x + 5.f, position.y + 15.f);
	h_tx.setString("h:" + std::to_string((int)size.y));
	x_tx.setPosition(position.x + size.x + 5.f, position.y + 30.f);
	x_tx.setString("x:" + std::to_string((int)position.x));
	y_tx.setPosition(position.x + size.x + 5.f, position.y + 45.f);
	y_tx.setString("y:" + std::to_string((int)position.y));
	z_tx.setPosition(position.x + size.x + 5.f, position.y + 60.f);
	z_tx.setString("z:");
	//--------------------------
	
	lineL[0] = sf::Vertex(getCenter() - sf::Vector2f(5.f, 5.f), color);
	lineL[1] = sf::Vertex(getCenter() + sf::Vector2f(5.f, 5.f), color);
	lineR[0] = sf::Vertex(getCenter() - sf::Vector2f(5.f, -5.f), color);
	lineR[1] = sf::Vertex(getCenter() + sf::Vector2f(5.f, -5.f), color);
}

void wl::AEditTool::processEvents(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (inCorner() && activeEdit) {
			isScale = true;
			mouseOffset = win->getCursorPos();
			sizeOffset = size;
		}else if (contains()) {
			mouseOffset = win->getCursorPos() - position;
			isDragging = true;
		}
	}else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		//std::cout << "click" << std::endl;
		isSelected = (contains()) ? true : false;
		mouseOffset = sf::Vector2f(0.f, 0.f);
		isDragging = false;
		mouseOffset = sf::Vector2f(0.f, 0.f);
		isScale = false;

	}else if (event.type == sf::Event::MouseMoved) {

		if (isScale) {
			sf::Vector2f delta = win->getCursorPos() - mouseOffset;
			if ((sizeOffset + delta).x > 10.f && (sizeOffset + delta).y > 10.f) {
				size = sizeOffset + delta;
			}
			setSize(size);
		}else if (isDragging) {
			position = win->getCursorPos() - mouseOffset;
			setPosition(position);
		}

	}

	if (isSelected) {
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::E)
			setToggle();
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
			setToggle();
	}else {
		setEnabled(false);
	}

	if (inCorner() && activeEdit) {
		win->setSizeCursor(3);
	}else {
		win->setSizeCursor(0);
	}
}

void wl::AEditTool::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (activeEdit) { 
		target.draw(edgeShape); 
		target.draw(id_tx);
		target.draw(w_tx);
		target.draw(h_tx);
		target.draw(x_tx);
		target.draw(y_tx);
		target.draw(z_tx);
	}

	if (isSelected) {
		target.draw(lineL, 2, sf::Lines);
		target.draw(lineR, 2, sf::Lines);
	}
}

#include "guikit/ARoundRect.h"

wl::ARoundRect::ARoundRect()
{
}

wl::ARoundRect::ARoundRect(sf::Vector2f position, sf::Vector2f size, float radius)
{
	std::vector<sf::Vector2f> circlepoints;

    // build the circle
    sf::Vector2f center = sf::Vector2f(radius, radius);

    sf::Vector2f befpoint = sf::Vector2f(-radius, 0.f); // point 0
    sf::Vector2f nowpoint;

    circlepoints.push_back(befpoint + center);

    for (int i = 1; i < 16; i++) {
        nowpoint.x = (befpoint.x * cos(0.392699)) - (befpoint.y * sin(0.392699));
        nowpoint.y = (befpoint.x * sin(0.392699)) + (befpoint.y * cos(0.392699));
        circlepoints.push_back(nowpoint + center);
        befpoint = nowpoint;
    }

    // build the round rect
    float noroundWi = size.x - 2 * radius;
    float noroundHe = size.y - 2 * radius;
    this->setPointCount(20);
    for (int i = 0; i < 5; i++) newpoints.push_back(circlepoints[i]);
    for (int i = 4; i < 9; i++) newpoints.push_back(circlepoints[i] + sf::Vector2f(noroundWi, 0.f));
    for (int i = 8; i < 13; i++) newpoints.push_back(circlepoints[i] + sf::Vector2f(noroundWi, noroundHe));
    for (int i = 12; i < 16; i++) newpoints.push_back(circlepoints[i] + sf::Vector2f(0.f, noroundHe));
    newpoints.push_back(circlepoints[0] + sf::Vector2f(0.f, noroundHe));
    for (int i = 0; i < 20; i++) this->setPoint(i, newpoints[i]);

    this->setPosition(position);

    
}

wl::ARoundRect::~ARoundRect()
{
}

bool wl::ARoundRect::contains()
{
    sf::Vector2i imouse_pos = sf::Mouse::getPosition(*win);

    sf::Vector2f mouse_pos = sf::Vector2f(static_cast<float>(imouse_pos.x), static_cast<float>(imouse_pos.y));
    sf::Vector2f position = getPosition();

    //  Point in convex polygon
    for (int i = 0; i < 20; i++) {
        int ini = i;
        int fin = (i == 19) ? 0 : i + 1;
        float iniX = newpoints[ini].x + position.x;
        float iniY = newpoints[ini].y + position.y;
        float finX = newpoints[fin].x + position.x;
        float finY = newpoints[fin].y + position.y;

        float A = -(finY - iniY);
        float B = finX - iniX;
        float C = -(A * iniX + B * iniY);

        if (A * mouse_pos.x + B * mouse_pos.y + C < 0) return false;
    }
    return true;
}

#include "prime/ObjectManager.h"

wl::ObjectManager* wl::ObjectManager::instance_;

wl::ObjectManager::ObjectManager() {}
wl::ObjectManager::~ObjectManager() { std::cout << "delete Object Manager" << std::endl; }

wl::ObjectManager* wl::ObjectManager::getInstance()
{
	if (instance_ == nullptr) instance_ = new wl::ObjectManager();
	return instance_;
}

void wl::ObjectManager::loadRoomObjects(std::string name)
{
	std::vector<std::string> str_object = res->getObjects(name);

	for (int i = 0; i < str_object.size(); i++) {

		std::string _id = findLabel("id", str_object[i]);
		std::string _tex = findLabel("tex", str_object[i]);

		float _x = std::stof(findLabel("x", str_object[i]));
		float _y = std::stof(findLabel("y", str_object[i]));
		float _z = std::stof(findLabel("z", str_object[i]));
		float _w = std::stof(findLabel("w", str_object[i]));
		float _h = std::stof(findLabel("h", str_object[i]));

		allObjects.push_back(new wl::ASpriteShape(
			sf::Vector2f(_x, _y),
			sf::Vector2f(_w, _h),
			&res->getTexture(name, _tex),
			_z,
			_id
		));

		intervals.push_back(std::make_pair(_z, i));
	}

}

void wl::ObjectManager::update(sf::Time deltaTime)
{
	for (int i = 0; i < allObjects.size(); i++) {
		allObjects[i]->update(deltaTime);
		intervals[i].first= dynamic_cast<wl::ASpriteShape*>(allObjects[intervals[i].second])->getZbuffer();
	}

	selectionSort(intervals);
}

void wl::ObjectManager::processEvents(sf::Event event)
{
	for (wl::APhyObject* arg : allObjects) {
		arg->processEvents(event);
	}
}

void wl::ObjectManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < allObjects.size(); i++) {
		target.draw(*allObjects[intervals[i].second]);
	}
}

std::string wl::ObjectManager::findLabel(std::string name, std::string arg)
{
	if (arg.find(name + "='") != std::string::npos) {
		auto ini = arg.find(name + "='") + name.size() + 2;
		auto end = arg.find("'", ini + 1);
		return  arg.substr(ini, end - ini);
	}
	else { return ""; }
}

void wl::ObjectManager::selectionSort(std::vector<std::pair<float, int>>& array)
{
	int n = array.size();

	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) if (array[j].first < array[minIndex].first) minIndex = j;
		std::swap(array[i], array[minIndex]);
	}
}



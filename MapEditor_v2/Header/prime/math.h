#pragma once
#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

namespace wl
{
	class math
	{
	public:
		//math();
		//~math();
		inline static std::string genID();

		inline sf::Vector2f normalize(sf::Vector2f vector);
		inline void swap(std::pair <float, int>& arg0, std::pair <float, int>& arg1);
		inline int partition(std::vector<std::pair <float, int>>& array, int init, int end);
		inline void quickSort(std::vector<std::pair <float, short>>& array, int init, int end);

	private:

	};

	//math::math()
	//{
	//}

	//math::~math()
	//{
	//}

	inline std::string math::genID()
	{
		const std::string allChar = "3M80z9j375694LD6uGa1ngR6307h19i0472594HYP122eC08Nc5E260pldQ5643sZBFKrO85wX3Amx1bW1UI7t42qvTo8S78yfV9Jk";

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, allChar.size() - 1);

		std::string uniqueId = "_@";

		for (int i = 0; i < 8; ++i) {
			char character = allChar[distrib(gen)];
			uniqueId += character;
		}
		return uniqueId;
	}

	inline sf::Vector2f math::normalize(sf::Vector2f vector)
	{
		return sf::Vector2f();
	}

	inline void math::swap(std::pair<float, int>& arg0, std::pair<float, int>& arg1)
	{
	}

	inline int math::partition(std::vector<std::pair<float, int>>& array, int init, int end)
	{
		return 0;
	}

	inline void math::quickSort(std::vector<std::pair<float, short>>& array, int init, int end)
	{
	}


} // namespace wl

#endif
#pragma once
#ifndef _GAME_H_
#include "Achievement.h"
#include <iostream>


// Game class
class Game
{
private:
	std::string m_name, m_publisher, m_dev;
	Achievement* m_achievement = nullptr;
	int m_numberOfAchieve;

public:

	void setGame(const std::string n, const std::string p, const std::string d, const int numberOfAchievements);
	int addGameAchieve(const std::string t, const std::string d, const int s);
	std::string getInfo();
	std::string getName();
};

#endif

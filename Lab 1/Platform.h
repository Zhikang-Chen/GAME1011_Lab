#pragma once
#include <string>

#ifndef _PLATFORM_H_
#include "Achievement.h"
#include "Game.h"
#include <iostream>
// Platform class
class Platform
{
private:
	std::string m_name, m_manufacturer;
	Game* m_pgames;
	int m_numberOfGames;

private:

	int findGame(std::string gameName);

public:

	void setPlatform(std::string n, std::string m, int g);
	int addGame(const std::string n, const std::string p, const std::string d, int a);
	std::string getGameInfo();
	std::string getGameInfo(std::string gameName);
	int addGameAchievement(std::string gameName, const std::string& t, const std::string& d, const int s);
	std::string getPlatformInfo();
	std::string getPlatformName();
};

#endif

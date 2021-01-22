#include "Platform.h"
#include "Achievement.h"
#include "Game.h"
#include <iostream>

// Find and return index of game with in m_games
// If the game is not in the array return -1
int Platform::findGame(std::string gameName)
{
	for (auto i = 0; i < m_numberOfGames; i++)
	{
		if (m_games[i].getName() == gameName)
		{
			return i;
		}
		if (m_games[i].getName().empty())
		{
			return -1;
		}
	}
	return -1;
}

// Set member variable
void Platform::setPlatform(std::string n, std::string m, int g)
{
	m_name = n;
	m_manufacturer = m;
	m_games = new Game[g];
	m_numberOfGames = g;
}

// Add games to m_games
int Platform::addGame(const std::string n, const std::string p, const std::string d, int a)
{
	for (auto i = 0; i < m_numberOfGames; i++)
	{
		if (m_games[i].getInfo().empty())
		{
			m_games[i].setGame(n, p, d, a);
			return 0;
		}
	}
	return 1;
}

// Get all game information
std::string Platform::getGameInfo()
{
	std::string s;
	for (auto i = 0; i < m_numberOfGames; i++)
	{
		if (m_games[i].getInfo().empty())
			break;
		s += m_games[i].getInfo() + "\n\n";
	}
	return s;
}

// Overload for getGameInfo
// Get info of game from name
// Why would I have this? No ideas
std::string Platform::getGameInfo(std::string gameName)
{
	const auto index = findGame(gameName);
	if (index == -1)
		return "";

	return m_games[index].getInfo();
}

// Add achievement to game
int Platform::addGameAchievement(std::string gameName, const std::string& t, const std::string& d, const int s)
{
	const auto index = findGame(gameName);
	if (index == -1 || m_games[index].addGameAchieve(t, d, s) == 1)
		return 1;
	return 0;
}

// Create and return a string containing information of the platform
std::string Platform::getPlatformInfo()
{
	if (m_name.empty() && m_manufacturer.empty())
		return "";

	auto info = "Name: " + m_name + "\nManufacturer: " + m_manufacturer + "\nGames: \n" + getGameInfo();
	return (info);
}

// Return name of the platform
std::string Platform::getPlatformName()
{
	return m_name;
}

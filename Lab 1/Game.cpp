#include "Game.h"
#include "Achievement.h"


	// Set game class
	void Game::setGame(const std::string n, const std::string p, const std::string d, const int numberOfAchievements)
	{
		m_name = n;
		m_publisher = p;
		m_dev = d;
		m_achievement = new Achievement[numberOfAchievements];
		m_numberOfAchieve = numberOfAchievements;
	}

	// Add achievement to m_achievement
	int Game::addGameAchieve(const std::string t, const std::string d, const int s)
	{
		for (auto i = 0; i < m_numberOfAchieve; i++)
		{
			if (m_achievement[i].getAchievement().empty())
			{
				m_achievement[i].setAchievement(t, d, s);
				return 0;
			}
		}
		return 1;
	}

	// Create and return a string containing of the game
	std::string Game::getInfo()
	{
		if (m_name.empty() && m_publisher.empty() && m_dev.empty())
			return "";
		auto info = "Name: " + m_name +
			"\nPublisher: " + m_publisher +
			"\nDeveloper: " + m_dev +
			"\nAchievements: ";
		for (auto i = 0; i < m_numberOfAchieve; i++)
		{
			if (m_achievement[i].getAchievement().empty())
			{
				return info;
			}
			info += "\n\n" + m_achievement[i].getAchievement();
		}
		return info;
	}

	// Return m_name
	std::string Game::getName() { return m_name; }

#include "Achievement.h"
#include <iostream>
#include <string>

Achievement::Achievement()
{
	m_scoreValue = -1;
}

// Set Achievement
void Achievement::setAchievement(std::string t, std::string d, int s)
{
	m_title = t;
	m_description = d;
	m_scoreValue = s;
}

// Create return a string containing information of the achievement
std::string Achievement::getAchievement()
{
	if (m_title.empty() && m_description.empty() && m_scoreValue == -1)
		return "";

	auto s = "Title: " + m_title +
		"\nScore Value: " + std::to_string(m_scoreValue) +
		"\nDescription: " + m_description;
	
	return s;
}

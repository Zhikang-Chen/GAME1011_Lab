#pragma once
#ifndef _ACHIEVEMENT_H_

#include<iostream>

// Achievement class
class Achievement
{
private:
	std::string m_title, m_description;
	int m_scoreValue;

public:
	Achievement();
	void setAchievement(std::string t, std::string d, int s); // Set Achievement
	std::string getAchievement(); // Create return a string containing information of the achievement
};

#endif

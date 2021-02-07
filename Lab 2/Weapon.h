#pragma once
#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>

class Weapon
{
private:
	// Member
	std::string m_name,
	            m_description;
	int m_damage;
	std::string *m_pAbilities;

public:
	Weapon(std::string n, std::string d, int da, std::string* a);
	Weapon(std::string n, std::string d, int da);
	// Function
	int SetAbilities(std::string* a);
	std::string GetInfo();
	
	friend std::ostream &operator <<(std::ostream &output, Weapon &w)
	{
		output << w.GetInfo();
		return output;
	};
};

#endif
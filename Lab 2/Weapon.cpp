#include "Weapon.h"

#include <string>

Weapon::Weapon(std::string n, std::string d, int da, std::string* a) : m_name(n), m_description(d), m_damage(da), m_pAbilities(a) { }

Weapon::Weapon(std::string n, std::string d, int da) : m_name(n), m_description(d), m_damage(da) { }

int Weapon::SetAbilities(std::string* a)
{
	if (m_pAbilities == nullptr)
	{
		m_pAbilities = a;
		return 0;
	}
	return 1;
}


std::string Weapon::GetInfo()
{
	std::string s = "Name: " + m_name +
					"\nDescription: " + m_description +
					"\nDamage: " + std::to_string(m_damage) + 
					"\nAbilities: ";

	if(m_pAbilities == nullptr)
	{
		s += "None";
	}
	else
	{
		for (int i = 0; i <= m_pAbilities->size(); ++i)
		{
			s += "\n" + m_pAbilities[i];
		}		
	}
	return s;
}


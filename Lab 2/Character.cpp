#include "Character.h"
#include <string>


//Start of Bread class
void Bread::DisplayInfo()
{
	std::cout << "Name: (Insert bread brand here) " + m_name +
		"\nHealth: " + std::to_string(m_health) << std::endl;
	if (m_pWeapon == nullptr)
		std::cout << "Weapon : None" << std::endl;
	else
	{
		std::cout << "\nWeapon" << std::endl;
		std::cout << m_pWeapon->GetInfo() << std::endl;
	}
	std::cout << std::endl;
}
//End of Bread

//Start of Pastafarian class
void Pastafarian::DisplayInfo()
{
	std::cout << "Name: FSM "  + m_name +
		"\nHealth: " + std::to_string(m_health) << std::endl;
	if (m_pWeapon == nullptr)
		std::cout << "Weapon : None" << std::endl;
	else
	{
		std::cout << "\nWeapon" << std::endl;
		std::cout << m_pWeapon->GetInfo() << std::endl;
	}
	std::cout << std::endl;
}
//End of Pastafarian class

//Start of AnimeCharacter
void AnimeCharacter::DisplayInfo()
{
	std::cout << "Name: " + m_name + " San" +
		"\nHealth: " + std::to_string(m_health) << std::endl;
	if (m_pWeapon == nullptr)
		std::cout << "Weapon : None" << std::endl;
	else
	{
		std::cout << "\nWeapon" << std::endl;
		std::cout << m_pWeapon->GetInfo() << std::endl;
	}
	std::cout << std::endl;
}
//End of AnimeCharacter

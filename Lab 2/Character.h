#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
#include "Weapon.h"

class Character
{
protected:
	// Member
	std::string m_name;
	Weapon* m_pWeapon;
	int m_health;

	// Function
	Character(std::string n, int h, Weapon *w) : m_name(n), m_health(h), m_pWeapon(w) {}
	Character(std::string n, int h) : m_name(n), m_health(h) {}
	void SetWeapon(Weapon* w) { m_pWeapon = w; }
public:
	virtual void DisplayInfo() = 0;
	std::string GetName() { return m_name; }
	
};

class Bread : public Character
{
public:
	Bread(std::string n, int h) : Character( n, h, new Weapon("M16", "A gun", 29)) {}
	Bread(std::string n, int h, Weapon *w) : Character(n, h, w) {}
	void DisplayInfo() override;
};

//I had to search "spaghetti religion" on google for this

class Pastafarian : public Character
{
public:
	Pastafarian(std::string n, int h) : Character(n, h, new Weapon("Noodles", "It's edible", 3)) {}
	Pastafarian(std::string n, int h, Weapon *w) : Character(n, h, w) {}
	void DisplayInfo() override;
};

class AnimeCharacter : public Character
{
public:
	AnimeCharacter(std::string n, int h) : Character(n, h ,new Weapon("Katana", "Japanese sword", 40)) {}
	AnimeCharacter(std::string n, int h, Weapon *w) : Character(n, h, w) {}
	void DisplayInfo() override;
};

#endif

#include <iostream>
#include <map>
#include <string>


#include "Character.h"
#include "Weapon.h"
using namespace std;

int main()
{
	//map<string, Character*> c;
	Character* c[10];
	int index = 0; 
	
	bool quit = false;
	string manu;
	cout << "Welcome" << endl;
	do
	{
		try
		{
			cout << "1. Create new character" << endl;
			cout << "2. View all character" << endl;
			cout << "3. Delete character" << endl;
			cout << "4. Exit program" << endl;
			cin >> manu;
			cout << endl;

			if (stoi(manu) == 1)
			{
				if (index <= 9)
				{
					string race;
					string name;
					RACE:
					cout << "\tPlease select the race of your character" << endl;
					cout << "\t1. Bread" << endl;
					cout << "\t2. Pastafarian" << endl;
					cout << "\t3. Anime Character" << endl << "\t";
					cin >> race;
					if (stoi(race) > 3 || stoi(race) < 0)
					{
						cout << "\tInvalid race" << endl;
						goto RACE;
					}
					
					cout << "\tPlease enter the m_name of your character" << endl << "\t";
					cin.ignore();
					getline(cin, name);
					
					if (stoi(race) == 1)
					{
						c[index] = new Bread(name, 1);
					}
					else if (stoi(race) == 2)
					{
						c[index] = new Pastafarian(name, 5);
					}
					else if (stoi(race) == 3)
					{
						c[index] = new AnimeCharacter(name, 398389275);
					}
					cout << endl;

					++index;
				}
				else
					cout << "You can not create anymore character" << endl;
			}
			else if (stoi(manu) == 2)
			{
				for (int i = 0; i < index; ++i)
				{
					if(c[i] != nullptr)
						c[i]->DisplayInfo();
				}
			}
			else if (stoi(manu) == 3)
			{
				string name;
				int DeleteIndex = -1;
				cout << "\nPlease enter the m_name of the character you want to delete" << endl;
				cin.ignore();
				getline(cin, name);
				for (int i = 0; i < index; ++i)
				{
					if(c[i]->GetName() == name)
					{
						DeleteIndex = i;
					}
				}

				if (DeleteIndex != -1)
				{
					delete c[DeleteIndex];
					c[DeleteIndex] = nullptr;
				}
				else
					cout << "\tUnable to delete character" << endl;
				
			}
			else if (stoi(manu) == 4)
				quit = true;

		}
		catch (std::invalid_argument)
		{
			cout << "\nInvalid Input" << endl;
		}


		
	} while (!quit);


	
	return 0;
}
//This program was written by Zhikang Chen
#include <iostream>
#include <string>
#include "Achievement.h"
#include "Game.h"
#include "Platform.h"
using namespace std;

// Convert input from string to 
// Return -1 if the function is unable to do so
int inputPrecess(std::string input)
{
	int processedInput;
	try
	{
		processedInput = stoi(input);
	}
	catch (std::invalid_argument)
	{
		return -1;
	}
	return processedInput;
}


int main()
{
	//Ask user to enter the amount of platform within the array
	Platform *consoles;
	string userInput;
	GETPLATFORM:
	cout << "Please enter the amount of platform" << endl;
	cin >> userInput;
	int platform = inputPrecess(userInput);
	if(platform < 0)
	{
		cout << "Invalid input" << endl;
		cout << "------------------------------------" << endl;
		goto GETPLATFORM;
	}
	consoles = new Platform[platform];

	//Main menu
	MAINMENU:
	cout << "------------------------------------" << endl;
	cout << "1. Add new platform \n2. View existing platform \n3. Add item to platform \n4. Exit" << endl;
	cin >> userInput;
	int processedInput = inputPrecess(userInput);
	if (processedInput == 1)
	{
		// Add platform to consoles
		string name, manufacturer;
		int game, index = 0;
		for (auto i = 0; i < platform; ++i)
		{
			if (consoles[i].getPlatformInfo().empty())
			{
				break;
			}
			index++;
		}
		
		if (index == platform)
		{
			cout << "You can't add anymore platform" << endl;
			goto MAINMENU;
		}

		cout << "Please enter the m_name of the platform" << endl;
		cin >> name;
		
		cout << "Please enter the manufacturer of the platform" << endl;
		cin >> manufacturer;
		
		GAME:
		cout << "Please enter the amount of games will be in the platform" << endl;
		cin >> userInput;
		game = inputPrecess(userInput);
		if (game < 0)
		{
			cout << "Invalid input" << endl;
			goto GAME;
		}
		consoles[index].setPlatform(name, manufacturer, game);
		goto MAINMENU;
	}
	else if (processedInput == 2)
	{
		// Display platform in consoles
		if (!consoles[0].getPlatformInfo().empty())
		{
			for (auto i = 0; i < platform; i++)
			{
				if (consoles[i].getPlatformInfo().empty())
					break;
				cout << consoles[i].getPlatformInfo() << endl;
			}
			goto MAINMENU;
		}
		else
			cout << "You have no platform" << endl;
	}
	else if (processedInput == 3)
	{
		// Display all the existing platform
		if (!consoles[0].getPlatformInfo().empty())
		{
			// Display all the console m_name
			for (auto i = 0; i < platform; i++)
			{
				if (consoles[i].getPlatformInfo().empty())
					break;
				cout << i + 1 << ". " << consoles[i].getPlatformName() << endl;
			}

			// Ask user to select a console
			CONSOLE:
			cout << "Please select a platform (enter 'back' to get back)" << endl;
			cin >> userInput;
			if (userInput == "back")
				goto MAINMENU;
			int consoleIndex = inputPrecess(userInput)-1;
			cout << consoleIndex;
			if(consoleIndex == -1 | consoleIndex >= platform | consoles[consoleIndex].getPlatformInfo().empty())
			{
				cout << "Invalid input" << endl;
				goto CONSOLE;
			}
			
			// Second menu
			SECONDMENU:
			cout << consoles[consoleIndex].getPlatformName() << endl;
			cout << "1. Add game \n2. View existing game \n3. Add achievement to game \n4. Back" << endl;
			cin >> userInput;
			processedInput = inputPrecess(userInput);
			if(processedInput < 0 || processedInput > 4)
			{
				cout << "Invalid input" << endl;
				goto SECONDMENU;
			}
			else if(processedInput == 1)
			{
				// Add game
				string name, publisher, dev;
				int achieve;

				cout << "Please enter the m_name of the game" << endl;
				cin >> name;
				cout << "Please enter the publisher of the game" << endl;
				cin >> publisher;
				cout << "Please enter the developer of the game" << endl;
				cin >> dev;
				ACHIEVEMENT:
				cout << "Please enter the the amount of achievement of the game" << endl;
				cin >> userInput;
				achieve = inputPrecess(userInput);
				if(achieve <= -1)
				{
					cout << "Invalid input" << endl;
					goto ACHIEVEMENT;
				}
				
				if (!consoles[consoleIndex].addGame(name, publisher, dev, achieve))
					cout << "Unable to add game";
				goto SECONDMENU;
			}
			else if(processedInput == 2)
			{
				// Display all the existing game within select console
				cout << consoles[consoleIndex].getGameInfo() << endl;
				goto SECONDMENU;
			}
			else if(processedInput == 3)
			{

				// Add new achievement to the game
				string name, title, description;
				int scoreValue;
				cout << "Please enter the m_name of the game" << endl;
				cin >> name;
				cout << "Please enter the title of the achievement" << endl;
				cin >> title;
				cout << "Please enter the description of the achievement" << endl;
				cin >> description;
				SCOREVALUE:
				cout << "Please enter the score of the achievement" << endl;
				cin >> userInput;
				scoreValue = inputPrecess(userInput);
				if(scoreValue <= -1)
				{
					cout << "Invalid value" << endl;
					goto SCOREVALUE;
				}
				if(!consoles[consoleIndex].addGameAchievement(name, title, description, scoreValue));
				{
					cout << "Unable to add achievement";
				}
				goto SECONDMENU;
			}
		}
		else
		{
			cout << "You have no platform" << endl;
		}
		goto MAINMENU;
	}
	else if(processedInput < 0 || processedInput > 4)
	{
		cout << "Invalid Input" << endl;
		goto MAINMENU;
	}
	return 0;
}
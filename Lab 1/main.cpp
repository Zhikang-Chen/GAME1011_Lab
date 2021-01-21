#include <iostream>
#include <string>
using namespace std;

// Achievement class
class Achievement
{
private:
	string m_title, m_description;
	int m_scoreValue;

public:

	Achievement()
	{
		m_scoreValue = -1;
	}

	// Set Achievement
	void setAchievement(string t, string d, int s)
	{
		m_title = std::move(t);
		m_description = std::move(d);
		m_scoreValue = s;
	}

	// Create return a string containing information of the achievement
	string getAchievement()
	{
		if (m_title.empty() && m_description.empty() && m_scoreValue == -1)
			return "";

		auto s = "Title: " + m_title +
			"\nScore Value: " + to_string(m_scoreValue) +
			"\nDescription: " + m_description;
		return s;
	}

};

// Game class
class Game
{
private:
	string m_name, m_publisher, m_dev;
	Achievement * m_achievement = nullptr;
	int m_numberOfAchieve;

public:

	// Set game class
	void setGame(const string n, const string p, const string d, const int numberOfAchievements)
	{
		m_name = n;
		m_publisher = p;
		m_dev = d;
		m_achievement = new Achievement[numberOfAchievements];
		m_numberOfAchieve = numberOfAchievements;
	}

	// Add achievement to m_achievement
	int addGameAchieve(const string t, const string d, const int s)
	{
		for (auto i = 0 ; i < m_numberOfAchieve; i++)
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
	string getInfo()
	{
		if (m_name.empty() && m_publisher.empty() && m_dev.empty())
			return "";
		auto info = "Name: " + m_name +
			"\nPublisher: " + m_publisher +
			"\nDeveloper: " + m_dev +
			"\n Achievements: ";
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
	string getName(){return m_name;}
};

// Platform class
class Platform
{
private:
	string m_name, m_manufacturer;
	Game* m_games;
	int m_numberOfGames;

private:

	// Find and return index of game with in m_games
	// If the game is not in the array return -1
	int findGame(string gameName)
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

public:

	// Set member variable
	void setPlatform(string n, string m, int g)
	{
		m_name = n;
		m_manufacturer = m;
		m_games = new Game[g];
		m_numberOfGames = g;
	}

	// Add games to m_games
	int addGame(const string n, const string p, const string d, int a)
	{
		for (auto i = 0; i < m_numberOfGames; i++)
		{
			if(m_games[i].getInfo().empty())
			{
				m_games[i].setGame(n, p, d, a);
				return 0;
			}
		}
		return 1;
	}

	// Get all game information
	string getGameInfo()
	{
		string s;
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
	string getGameInfo(string gameName)
	{
		const auto index = findGame(gameName);
		if (index == -1)
			return "";
		
		return m_games[index].getInfo();
	}

	// Add achievement to game
	int addGameAchievement(string gameName, const string& t, const string& d, const int s)
	{
		const auto index = findGame(gameName);
		if (index == -1 || m_games[index].addGameAchieve(t, d, s) == 1)
			return 1;
		return 0;	
	}

	// Create and return a string containing information of the platform
	string getPlatformInfo()
	{
		if (m_name.empty() && m_manufacturer.empty())
			return "";
		
		auto info = "Name: " + m_name + "\nManufacturer: " + m_manufacturer + "\n";
		return (info);
	}

	// Return name of the platform
	string getPlatformName()
	{
		return m_name;
	}
};

// Convert input from string to 
// Return -1 if the function is unable to do so
int inputPrecess(string input)
{
	int processedInput;
	try
	{
		processedInput = stoi(input);
	}
	catch (invalid_argument)
	{
		return -1;
	}
	return processedInput;
}


int main()
{
	//setPlatform yBox("YBox180", "Megasoft", 9);
	//yBox.addGame("Call of Nature", "Crow Software", "Inactivision", 20);
	//yBox.addGame("Everyone's Sky", "Goodbye Games", "Goodbye Games", 20);
	//yBox.addGame("Accessory of War", "Ybox Game Studios", "Peoeple Who Made Forknight", 20);
	//yBox.addGame("Trade Marked 1979 : Battlefront", "EL DEIDRE", "Electronic Lettuce", 20);
	//yBox.addGame("The #005AFF Box", "Pipe", "Pipe", 20);
	//yBox.addGame("The Reals 4", "Minis", "Electronic Lettuce", 20);
	//yBox.addGame("Hitperson", "Can't think of a Joke", "Punch Line", 20);
	//yBox.addGame("Insert Videogame Related SCP Here", "[REDACTED]", "[REDACTED]", 20);
	//yBox.addGame("Insert Funny Names here", "I Am Out Of Ideas", "IDK", 20);
	//cout << yBox.getGameInfo();

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
	INPUT:
	cout << "------------------------------------" << endl;
	cout << "1. Add new platform \n2. View existing platform \n3. Games \n4. Exit" << endl;
	cin >> userInput;
	int processedInput = inputPrecess(userInput);
	if (processedInput == 1)
	{
		// Add platform to consoles
		string name, manufacturer;
		int numberOfGame, index = 0;
		for (auto i = 0; i < platform; ++i)
		{
			if (!consoles[i].getPlatformInfo().empty())
			{
				index++;
				break;
			}
		}
		
		if (index == platform)
		{
			cout << "You can't add anymore platform" << endl;
			goto INPUT;
		}

		cout << "Please enter the name of the platform" << endl;
		cin >> name;
		
		cout << "Please enter the manufacturer of the platform" << endl;
		cin >> manufacturer;
		
		INPUTGAME:
		cout << "Please enter the amount of games will be in the platform" << endl;
		cin >> userInput;
		numberOfGame = inputPrecess(userInput);
		if (numberOfGame < 0)
		{
			cout << "Invalid input" << endl;
			goto INPUTGAME;
		}
		consoles[index].setPlatform(name, manufacturer, numberOfGame);
		goto INPUT;
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
			goto INPUT;
		}
		else
			cout << "You have not platform" << endl;
	}
	else if (processedInput == 3)
	{
		//Display all the existing platform
		if (!consoles[0].getPlatformInfo().empty())
		{
			for (auto i = 0; i < platform; i++)
			{
				if (consoles[i].getPlatformInfo().empty())
					break;
				cout << i + 1 << ". " << consoles[i].getPlatformName() << endl;
			}

			CONSOLE:
			cout << "Please select a platform (enter 'back' to get back)" << endl;
			cin >> userInput;
			if (userInput == "back")
				goto INPUT;
			int consoleIndex = inputPrecess(userInput)-1;
			cout << consoleIndex;
			if(consoleIndex == -1 | consoleIndex >= platform | consoles[consoleIndex].getPlatformInfo().empty())
			{
				cout << "Invalid input" << endl;
				goto CONSOLE;
			}
			
			//Second menu
			MOREINPUTCHECK:
			cout << consoles[consoleIndex].getPlatformName() << endl;
			cout << "1. Add game \n2. View existing game \n3. Add achievement to game \n4. Back" << endl;
			cin >> userInput;
			int processedInput = inputPrecess(userInput);
			if(processedInput < 0 || processedInput > 4)
			{
				cout << "Invalid input" << endl;
				goto MOREINPUTCHECK;
			}
			else if(processedInput == 1)
			{
				string name, publisher, dev;
				int achieve;

				cout << "Please enter the name of the game" << endl;
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
				goto MOREINPUTCHECK;
			}
			else if(processedInput == 2)
			{
				cout << consoles[consoleIndex].getGameInfo() << endl;
				goto MOREINPUTCHECK;
			}
			else if(processedInput == 3)
			{
				string name, title, description;
				int scoreValue;
				cout << "Please enter the name of the game" << endl;
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
				}
				if(!consoles[consoleIndex].addGameAchievement(name, title, description, scoreValue));
				{
					cout << "Unable to add achievement";
				}
				goto MOREINPUTCHECK;
			}
		}
		else
		{
			cout << "You have no platform" << endl;
		}
		goto INPUT;
	}
	else if(processedInput < 0 || processedInput > 4)
	{
		cout << "Invalid Input" << endl;
		goto INPUT;
	}

	



	return 0;
}
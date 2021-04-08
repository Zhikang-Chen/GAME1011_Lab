#include <string>

#include "DynTempQueue.h"
#include "DynTempStack.h"
#include "time.h"
#include "random"

const string NAMELIST[] =
{
	"Ak-47",
	"Bread",
	"John",
	"Ork",
	"Bob",
	"MP5",
	"M16",
	"Type 4"
};

class Gun
{
public:
	Gun(int ROF = 0, int ER = 0, string n = "Bread", bool e = true)
	{
		m_rateOfFire = ROF;
		m_effectiveRange = ER;
		m_name = n;
		m_edible = e;
	}

	string GetInfo()
	{
		string s = "Rate of fire: " + std::to_string(m_rateOfFire) +
			"\nEffective Range: " + std::to_string(m_effectiveRange) +
			"\nName: " + m_name;
		if (m_edible)
			s += "\nEdibility: Yes";
		else
			s += "\nEdibility: No";
		return s;
	}
	
	friend std::ostream& operator<<(std::ostream& output, Gun& g)
	{
		output << g.m_name;
		return output;
	};
	
	int m_rateOfFire;
	int m_effectiveRange;
	string m_name;
	bool m_edible;
};

int main()
{
	srand(time(nullptr));
	DynTempStack<int> numStack;
	DynTempStack<Gun> gunsStack;
	DynTempQueue<int> numQueue;
	DynTempQueue<Gun> gunQueue;
	char c;

	do
	{
		cout << "1. Primitive type stack" << endl;
		cout << "2. Non-primitive type stack" << endl;
		cout << "3. Primitive type queue" << endl;
		cout << "4. Non-primitive type queue" << endl;
		cout << "5. Exit" << endl;
		
		cin >> c;
		if (c == '1')
		{
			// Stack for numbers
			cout << "Push random number" << endl;
			for (unsigned int i = 0; i < 10; i++)
			{
				int ran = rand();
				numStack.push(ran);
				cout << "Pushing " + to_string(ran) << endl;
				cout << "--------------Current Stack--------------" << endl;
				numStack.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}

			cout << "Pop numbers" << endl;
			while (!numStack.isEmpty())
			{
				int num;
				numStack.pop(num);
				cout << "Popping " + to_string(num) << endl;
				cout << "--------------Current Stack--------------" << endl;
				numStack.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}
		}
		else if (c == '2')
		{
			// Stack for guns
			cout << "Push guns" << endl;
			for (unsigned int i = 0; i < 10; i++)
			{
				auto g = Gun(rand(), rand(), NAMELIST[rand() % 8], rand() % 1);
				gunsStack.push(g);
				cout << "Pushing " << g << endl;
				cout << "--------------Current Stack--------------" << endl;
				gunsStack.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}

			cout << "Pop guns" << endl;
			while (!gunsStack.isEmpty())
			{
				Gun gun;
				gunsStack.pop(gun);
				cout << "Popping " << gun << endl;
				cout << "--------------Current Stack--------------" << endl;
				gunsStack.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}
		}
		else if (c == '3')
		{
			// Queue for numbers
			cout << "Push random number" << endl;
			for (unsigned int i = 0; i < 10; i++)
			{
				int ran = rand();
				numQueue.enqueue(ran);
				cout << "Pushing " + to_string(ran) << endl;
				cout << "--------------Current Queue--------------" << endl;
				numQueue.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}

			cout << "Pop numbers" << endl;
			while (!numQueue.isEmpty())
			{
				int num;
				numQueue.dequeue(num);
				cout << "Popping " + to_string(num) << endl;
				cout << "--------------Current Queue--------------" << endl;
				numQueue.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}
		}
		else if (c == '4')
		{
			// Queue for guns
			cout << "Push guns" << endl;
			for (unsigned int i = 0; i < 10; i++)
			{
				auto g = Gun(rand(), rand(), NAMELIST[rand() % 8], rand() % 1);
				gunQueue.enqueue(g);
				cout << "Pushing " << g << endl;
				cout << "--------------Current Queue--------------" << endl;
				gunQueue.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}

			cout << "Pop guns" << endl;
			while (!gunQueue.isEmpty())
			{
				Gun gun;
				gunQueue.dequeue(gun);
				cout << "Popping " << gun << endl;
				cout << "--------------Current Queue--------------" << endl;
				gunQueue.display();
				cout << "-----------------------------------------" << endl;
				//cout << "Press anything to continue" << endl;
				cin.get();
			}
		}
	}while (c != '5');
	return 0;
}
#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <string>
using namespace std;

bool isPalindrome(const string s)
{
	string str = s;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	if (str[0] != str[str.size() - 1])
	{
		return false;
	}
	if ( !str.substr(1, str.size() - 2).empty())
	{
		
		if (isPalindrome(str.substr(1, str.size() - 2)))
			return true;
		else
			return false;
	}
}

string reverse(string s)
{
	string str = s;
	char temp = str[0];
	str[0] = str[str.size() - 1];
	str[str.size() - 1] = temp;

	if (!str.substr(1, str.size() - 2).empty())
		str = str[0] + reverse(str.substr(1, str.size() - 2)) + str[str.size() - 1];
	return str;
}

int partition(int arr[], int low, int high)
{
	auto pivot = arr[high];
	auto i = low;
	int temp;
	
	for(int j = low; j < high; ++j)
	{
		if (arr[j] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;

	
	return (i);
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
	{
		auto pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int* createRandomIntArray( int size,int min = 0, int max = 100 )
{
	int* arr = new int[size];
	for(int i = 0; i < size; ++i)
	{
		arr[i] = min + rand() % (max + 1);
	}
	return arr;
}

int main()
{
	srand(time(nullptr));
	char c;
	do
	{
		string s;
		cout << "1. Palindrome" << endl;
		cout << "2. Quicksort" << endl;
		cout << "3. Reverse String" << endl;
		cout << "4. Exit" << endl;
		cin >> c;

		if(c == '1')
		{
			cout << "Please enter a string" << endl;
			cin >> s;
			if(isPalindrome(s))
				cout << "The string is Palindrome" <<endl;
			else
				cout << "The string is not Palindrome" << endl;
		}
		else if(c == '2')
		{
			cout << "Please enter the size of array" << endl;
			cin >> s;
			int size = stoi(s);
			auto arr = createRandomIntArray(size);
			cout << "Unsorted Array" << endl;
			for (int i = 0; i < size; ++i)
				cout << arr[i] << endl;
			cout << "-----------------------------" << endl;
			quickSort(arr, 0, size-1);
			cout << "Sorted Array" << endl;
			for (int i = 0; i < size; ++i)
				cout << arr[i] << endl;
			//cout << "Quicksort" << endl;
		}
		else if(c == '3')
		{
			cout << "Please enter a string you want to reverse" << endl;
			cin >> s;
			cout << reverse(s) << endl;
			//cout << "Reverse String" << endl;
		}
	} while (c != '4');


	
	//if (isPalindrome(s))
	//{
	//	cout << "It is" << endl;
	//}
	//else
	//	cout << "no" << endl;
		
}

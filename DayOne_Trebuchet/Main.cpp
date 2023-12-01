#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> GetStringsFromFile(string a_fileName)
{
	ifstream file(a_fileName);
	if (!file)
	{
		cout << "Unable to Open the file!" << endl;
		system("pause");
	}

	string fetchedWord;
	vector<string> wordList;

	while (!file.eof())
	{
		getline(file, fetchedWord);
		wordList.push_back(fetchedWord);
	}

	file.close();

	return wordList;
}

/// <summary>
/// Checks each character in a string to find an integer
/// </summary>
/// <param name="a_word">String to be checked</param>
/// <returns>First number found in string</returns>
int FindFirstNumber(string a_word)
{
	for (int i = 0; i < a_word.length(); i++)
	{
		char testChar = a_word[i];
		if (isdigit(testChar))
		{
			// Convert the character to its numeric form (0 has value of 48)
			return testChar - '0';
		}
	}

	return 0;
}

/// <summary>
/// Checks each character in a string backwards to find an integer
/// </summary>
/// <param name="a_word">String to be checked</param>
/// <returns>Last number found in string</returns>
int FindSecondNumber(string a_word)
{
	for (int i = a_word.length(); i >= 0; i--)
	{
		char testChar = a_word[i];
		if (isdigit(testChar))
		{
			// Convert the character to its numeric form (0 has value of 48)
			return testChar - '0';
		}
	}

	return 0;
}

/// <summary>
/// Combines the 2 found numbers to make 1 number (1 and 2 becomes 12)
/// </summary>
/// <param name="a_firstDigit">The Tens value</param>
/// <param name="a_secondDigit">The units value</param>
/// <returns></returns>
int CombineNumbers(int a_firstDigit, int a_secondDigit)
{
	return (a_firstDigit * 10) + a_secondDigit;
}

int main()
{
	vector<string> codeList = GetStringsFromFile("TrebuchetWords.txt");
	int runningTotal = 0;

	for (int i = 0; i < codeList.size(); i++)
	{
		
		int firstNum = FindFirstNumber(codeList[i]);
		int secondNum = FindSecondNumber(codeList[i]);
		
		cout << i << ":   " << codeList[i] << "   ->   " << CombineNumbers(firstNum, secondNum) << endl;

		runningTotal += CombineNumbers(firstNum, secondNum);
		
		
	}

	cout << runningTotal << endl;

	return 0;
}
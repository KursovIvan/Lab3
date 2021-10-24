#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//функция проверки ввода ключа
int enterKey()
{
	int keyT = 0;
	while (true)
	{
		cout << "Enter encryption step (negative for decryption): " << endl;
		cin >> keyT;

		if (cin.fail() || cin.peek() != '\n' || keyT == 0 || keyT % 26 == 0)
		{
			cout << "Incorrect input" << endl;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else return keyT % 26; //такой вывод обеспечивает зацикленность ключа по количеству букв в алфавите
	}
}
int main()
{
	int j = 1;
	int key = 0;
	bool isMessageTrue = true;
	string message;	
	//происходит ввод строки, пока введеная строка не будет содерджать спец символы, цифры или буквы другого языка
	do
	{
		cout << "Enter message (english language without special symbols and numbers): " << endl;
		getline(cin, message);		
		isMessageTrue = true;

		for (auto& ch : message)
		{
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ')
			{
			}
			else 
			{ 
				cout << "Message contains incorrect symbols" << endl; 
				isMessageTrue = false;
				break;
			}
		}
	}
	while (!isMessageTrue);

	key = enterKey();
	j = size(message);
	//каждый символ сдвигается на ключ по таблице ASCII
	if (key > 0)
	{
		cout << "Encrypted message: ";

		for (int i = 0; i < j; i++)
		{			
			if (message[i] >= 'a')
			{
				message[i] = message[i] + key;
				if (message[i] > 'z')
				{
					message[i] = message[i] - 'z' + 'a' - 1; //так обеспечивается зацикленность
				}
			}
			else if (message[i] >= 'A')
			{
				message[i] = message[i] + key;
				if (message[i] > 'Z')
				{
					message[i] = message[i] - 'Z' + 'A' - 1;
				}
			}
			else message[i] = ' ';
			cout << message[i];
		}
	}
	else
	{
		cout << "Decrypted message: ";

		for (int i = 0; i < j; i++)
		{
			if (message[i] <= 'Z' && message[i] >= 'A')
			{
				message[i] = message[i] + key;
				if (message[i] < 'A')
				{
					message[i] = message[i] + 'Z' - 'A' + 1;
				}
			}
			else if (message[i] <= 'z' && message[i] >= 'a')
			{
				message[i] = message[i] + key;
				if (message[i] < 'a')
				{
					message[i] = message[i] + 'z' - 'a' + 1;
				}
			}
			else message[i] = ' ';
			cout << message[i];
		}
	}

	_getch();
	return 0;
}
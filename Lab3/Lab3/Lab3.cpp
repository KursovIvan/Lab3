#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
    int j = 1;
    int key = 1;

    string message;

    cout << "Enter message: " << endl;
    getline(cin, message);

    cout << "Enter encryption step (negative for decryption): " << endl;
    cin >> key;

    j = size(message);

    if (key > 0)
    {
        cout << "Encrypted message: ";

        for (int i = 0; i < j; i++)
        {
            if (message[i] == ' ')
            {
                message[i] = ' ';
            }
            else if (message[i] >= 'a')
            {
                message[i] = message[i] + key;
                if (message[i] > 'z')
                {
                    message[i] = message[i] - 'z' + 'a' - 1;
                }
            }
            else
            {
                message[i] = message[i] + key;
                if (message[i] > 'Z')
                {
                    message[i] = message[i] - 'Z' + 'A' - 1;
                }
            }

            cout << message[i];
        }
    }
    else
    {
        cout << "Decrypted message: ";

        for (int i = 0; i < j; i++)
        {
            if (message[i] == ' ')
            {
                message[i] = ' ';
            }
            else if (message[i] <= 'Z')
            {
                message[i] = message[i] + key;
                if (message[i] < 'A')
                {
                    message[i] = message[i] + 'Z' - 'A' + 1;
                }
            }
            else 
            {
                message[i] = message[i] + key;
                if (message[i] < 'a')
                {
                    message[i] = message[i] + 'z' - 'a' + 1;
                }
            }

            cout << message[i];
        }
    }

    _getch();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//26
void EncriptText()
{
    string plainText;
    cout << "enter the plain text for encription (in small letters only)" << endl;
    cin >> plainText;
    int key;
    cout << "enter the key for encription" << endl;
    cin >> key;
    string encriptedText = "";
    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            encriptedText += char((plainText[i] - 'a' + key) % 26 + 'a');
        }
    }
    cout << "The Encripted text will be :" << encriptedText;
}
void DecriptText()
{
    string encriptedText;
    cout << "enter the encripted Text for decription (in small letters only)" << endl;
    cin >> encriptedText;
    int key;
    cout << "enter the key for decription" << endl;
    cin >> key;
    string plainText = "";
    for (int i = 0; i < encriptedText.length(); i++)
    {
        if (encriptedText[i] >= 'a' && encriptedText[i] <= 'z')
        {
            plainText += char((encriptedText[i] - 'a' - key + 26) % 26 + 'a');
        }
    }
    cout << "The decripted text will be :" << plainText;
}
int main()
{
    int x;
    cout << "Enter 1 to Encription and 2 for Decription " << endl;
    cin >> x;
    if (x == 1)
        EncriptText();
    else if (x == 2)
        DecriptText();
    else
        cout << "Invalid Input" << endl;
}
#include <bits/stdc++.h>
using namespace std;
vector<char> key={'j','i','b','r','k','t','c','n','o','f','q','y','g','a','u','z','h','s','v','w','m','x','l','d','e','p'};
//26!
void EncriptText()
{
    string plainText;
    cout << "enter the plain text for encription (in small letters only)" << endl;
    cin >> plainText;
    string encriptedText = plainText;
    for(int alpha = 0; alpha < 26; alpha++)
    {    
        for (int i = 0; i < encriptedText.length(); i++)
        {
            if (encriptedText[i] == 'a'+alpha )
            {
                encriptedText[i] = key[alpha];
            }
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
            // plainText += char('z' + (plainText[i] - 'a' - key));
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
    if (x == 1){
        EncriptText();
    }
    else if (x == 2)
        DecriptText();
    else
        cout << "Invalid Input" << endl;
}
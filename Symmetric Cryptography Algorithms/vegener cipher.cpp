#include <bits/stdc++.h>
using namespace std;
//26^key length
void EncryptText()
{
    string plainText="the key is hidden under the door pad";
    // cout << "enter the plain text for encryption (in small letters only)" << endl;
    // cin >> plainText;
    string xyz ="guidance";
    // cout << "enter the key for encryption" << endl;
    // cin >> key;
    int size=0;
    for(int i=0;i<plainText.length();i++)
    {
        if(isalpha(plainText[i]))
        size++;
    }
    int temp = size / xyz.length();
    int rem = size % xyz.length();
    string key;
    while(temp--){
        key+=xyz;
    }
    temp=0;
    while(rem--){
        key+=xyz[temp++];
    }
    string encryptedText = "";
    temp=0;
    for (int i = 0; i < plainText.length(); i++)
    {
        if(isalpha(plainText[i]))
        encryptedText+=char((((plainText[i]-'a')+(key[temp++]-'a'))%26)+'a');
    }
    cout << "The Encrypted text will be :" << encryptedText << endl;
}
void DecryptText()
{
    string encryptedText="zbmnelkwnclgeawrjyzwhrfsulxdd";
    // cout << "enter the plain text for decryption (in small letters only)" << endl;
    // cin >> encryptedText;
    string xyz="guidance";
    // cout << "enter the key for decryption" << endl;
    // cin >> key;
    int size=0;
    for(int i=0;i<encryptedText.length();i++)
    {
        if(isalpha(encryptedText[i]))
        size++;
    }
    int temp = size / xyz.length();
    int rem = size % xyz.length();
    string key;
    while(temp--){
        key+=xyz;
    }
    temp=0;
    while(rem--){
        key+=xyz[temp++];
    }
    temp=0;
    string plainText = "";
    for (int i = 0; i < encryptedText.length(); i++)
    {
        if(isalpha(encryptedText[i]))
        plainText+=((( encryptedText[i]-'a')-(key[temp++]-'a') +26 )%26 +'a');
    }
    cout << "The decripted text will be :" << plainText << endl;
}
int main()
{
    
        EncryptText();
        DecryptText();
}
#include <bits/stdc++.h>
using namespace std;

string Encryption()
{
    string text;
    cout << "enter the plain text : ";
    cin >> text;
    int key1, key2;
    cout << "enter first key :";
    cin >> key1;
    cout << "enter second key :";
    cin >> key2;
    string encrypted = "";
    int n = text.length();
    for (int i = 0; i < n; i++)
    {
        encrypted += (char)((key1 * (text[i] - 'a') + key2) % 26 + 'a');
    }
    return encrypted;
}
int inverse(int aa){
    int a=26;
    int b=aa;
    int x=0,y=1;
    while(b>0){
        int q=a/b;
        int r=a%b;
        a=b;
        b=r;
        int t=x-q*y;
        x=y;
        y=t;
    }
    if(a==1)
    return (x+26)%26;
    return 0;
}
string Decryption()
{
    string text;
    cout << "enter the encrypted text : ";
    cin >> text;
    int key1, key2;
    cout << "enter first key :";
    cin >> key1;
    cout << "enter second key :";
    cin >> key2;
    string decrypted = "";
    int n = text.length();
    int inv=inverse(key1);
    for (int i = 0; i < n; i++){
        int temp = ((inv * ((text[i] - 'a') - key2)) % 26);
        decrypted+=(char)((temp +26 )%26 +'a');
    }
    return decrypted;

}
int main()
{
    int x;
    cout << "Enter 1 to Encryption and 2 for Decryption " << endl;
    cin >> x;
    string encrypted,decrypted;
    if (x == 1){
        encrypted = Encryption();
        cout << "Encrypted text:" << encrypted << endl;
    }
    else if (x == 2){
        decrypted = Decryption();
        cout << "Decrypted text:" <<decrypted << endl;
    }
    else
        cout << "Invalid Input" << endl;
    
    
}
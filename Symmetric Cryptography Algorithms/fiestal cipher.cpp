#include <bits/stdc++.h>
using namespace std;

string roundFunction(const string& halfBlock,const string& key) {
    string result;
    for (size_t i = 0; i < halfBlock.size(); ++i) {
        result += halfBlock[i] ^ key[i % key.size()];
    }
    return result;
}

string feistelEncrypt(const string& plaintext, const vector<string>& subkeys) {
    string left = plaintext.substr(0, plaintext.size() / 2);
    string right = plaintext.substr(plaintext.size() / 2);

    for (const auto& key : subkeys) {
        string tempRight = right;
        right = roundFunction(right, key);  
        right = roundFunction(left,right);               
        left = tempRight;                  
    }

    return left + right;
}

string feistelDecrypt(const string& ciphertext, const vector<string>& subkeys) {
    string left = ciphertext.substr(0, ciphertext.size() / 2);
    string right = ciphertext.substr(ciphertext.size() / 2);

    for (auto key :subkeys) {
        string tempLeft = left;
        left = roundFunction(left,key);    
        left = roundFunction(right , left);                
        right = tempLeft;                  
    }

    return left + right;
}

int main() {
    string plaintext, key;
    int numRounds;

    cout << "Enter the plaintext (length must be even): ";
    getline(cin, plaintext);
    int keysize=plaintext.size()/2;
    // cout << "Enter the key: ";
    // getline(cin, key);
    cout << "Enter the number of rounds: ";
    cin >> numRounds;
    vector<string> subkeys;
    for (int i = 0; i < numRounds; i++)
    {
        string key="";
        srand(time(0)); 
        for (int i = 0; i < keysize; i++) {
            key += (rand() % 2) ? '1' : '0';
        }
        subkeys.push_back(key);
    }
    for(auto i:subkeys){
        cout<<"Keys generated:"<<i<<endl;
    }
    string ciphertext = feistelEncrypt(plaintext, subkeys);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = feistelDecrypt(ciphertext, subkeys);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//25!
vector<char> text = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<vector<char>> creatMatrix(string key)
{
    vector<vector<char>>mat;
    unordered_set<char>s;
    vector<char>temp;
    s.insert('j');
    for (int i = 0; i < key.size(); i++)
    {
        if(key[i]=='j')
        key[i]='i';
        if(s.find(key[i]) == s.end()){
            temp.push_back(key[i]);
            s.insert(key[i]);
        }
        if(temp.size()==5){
            mat.push_back(temp);
            temp.clear();
        }
    }
    for (int i = 0; i < text.size(); i++)
    {
        if(s.find(text[i]) == s.end()){
            temp.push_back(text[i]);
            s.insert(text[i]);
        }
        if(temp.size()==5){
            mat.push_back(temp);
            temp.clear();
        }
    }
    return mat;
}
string prepareText(string plaintext) {
    string text = "";
    for (int i = 0; i < plaintext.size(); i++) {
        text += plaintext[i];
        if (i + 1 < plaintext.size() && plaintext[i] == plaintext[i + 1]) {
            text += 'x';
        } else if (i + 1 < plaintext.size()) {
            text += plaintext[++i];
        }
    }
    if (text.size() % 2 != 0) text += 'z';
    return text;
}

string encrypt(string diagraph, vector<vector<char>> &matrix) {
    string ciphertext = "";
    for (int i = 0; i < diagraph.size(); i += 2) {
        char a = diagraph[i];
        char b = diagraph[i + 1];
        int r1, c1, r2, c2;
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (matrix[row][col] == a) {
                    r1 = row; c1 = col;
                }
                if (matrix[row][col] == b) {
                    r2 = row; c2 = col;
                }
            }
        }
        // for same row
        if (r1 == r2) {
            ciphertext += matrix[r1][(c1 + 1) % 5];
            ciphertext += matrix[r2][(c2 + 1) % 5];
        }
        // for same column
        else if (c1 == c2) {
            ciphertext += matrix[(r1 + 1) % 5][c1];
            ciphertext += matrix[(r2 + 1) % 5][c2];
        } else {
            ciphertext += matrix[r1][c2];
            ciphertext += matrix[r2][c1];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, vector<vector<char>> &matrix) {
    string decryptedText = "";
    for (int i = 0; i < ciphertext.size(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        int r1, c1, r2, c2;
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (matrix[row][col] == a) {
                    r1 = row; c1 = col;
                }
                if (matrix[row][col] == b) {
                    r2 = row; c2 = col;
                }
            }
        }
        if (r1 == r2) {
            decryptedText += matrix[r1][(c1 + 4) % 5];
            decryptedText += matrix[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            decryptedText += matrix[(r1 + 4) % 5][c1];
            decryptedText += matrix[(r2 + 4) % 5][c2];
        } else {
            decryptedText += matrix[r1][c2];
            decryptedText += matrix[r2][c1];
        }
    }
    return decryptedText;
}

int main() {
    string plaintext = "lifeisfullofsurprises"; //
    string key = "health";

    vector<vector<char>>matrix;
    matrix=creatMatrix(key);

    cout << "Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    string diagraph = prepareText(plaintext);
    cout << "Diagraph: " << diagraph << "\n";

    string encryptedText = encrypt(diagraph, matrix);
    cout << "Encrypted Text: " << encryptedText << "\n";

    string decryptedText = decrypt(encryptedText, matrix);
    cout << "Decrypted Text: " << decryptedText << "\n";

    return 0;
}
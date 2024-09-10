#include <bits/stdc++.h>
using namespace std;
//
string encryption(const string& text, int key) {
    if (key == 1) return text; 

    vector<string> fence(key);
    int r = 2 * (key - 1);
    int l = 0;

    for (int row = 0; row < key; row++) {
        int step1 = r - 2 * row;
        int step2 = 2 * row;

        if (step1 == 0) step1 = step2; 
        if (step2 == 0) step2 = step1;

        string temp="";
        for (int j = row; j < text.length();) {
            temp.push_back(text[j]);
            j += step1;

            if (step1 != step2 && j < text.length()) {
                temp.push_back(text[j]);
                j += step2;
            }
        }
        fence[row] = temp;
    }

    string encodedText;
    for (const string& line : fence) {
        encodedText += line;
    }

    return encodedText;
}
string decryption(const string& text, int key){
    
    if (key == 1) return text; 

    vector<int> railLengths(key, 0);
    int r = 2 * key - 2;
    int l = 0;
    int textLength = text.length();

    for (int row = 0; row < key; row++) {
        int step1 = r - 2 * row;  
        int step2 = 2 * row;      

        if (step1 == 0) step1 = step2;
        if (step2 == 0) step2 = step1;

        for (int j = row; j < textLength;) {
            railLengths[row]++;
            j += step1;

            if (step1 != step2 && j < textLength) {
                railLengths[row]++;
                j += step2;
            }
        }
    }

    vector<string> fence(key);
    int index = 0;
    for (int row = 0; row < key; row++) {
        fence[row] = text.substr(index, railLengths[row]);
        index += railLengths[row];
    }
    string decodedText;
    int maxcolsize=0;
    for(auto i:fence){
        if(maxcolsize<i.size())
        maxcolsize=i.size();
    }
    string sub=fence[0],end=fence[key-1];
        int ind=1;
        for (int i = 0; i < fence[key-1].size(); i++)
        {
            string xyz="";
            xyz+=end[i];
            sub.insert(ind,xyz);
            ind+=2;
        }
    for (int col = 0; col < maxcolsize; col++)
    {
        string temp="";
        for (int row = 0; row < fence.size(); row++)
        {
            if (col < fence[row].size()){
                if(row != 0 && row != key-1)
                temp +=fence[row][col];
            }
        }
        if(col&1){
            reverse(temp.begin(),temp.end());
            decodedText+=temp;
        }
        else{
            decodedText+=temp;
        }
    }
    ind=0;
    for (int i = 0; i < sub.size(); i++)
    {
        string xyz="";
        xyz+=sub[i];
        decodedText.insert(ind,xyz);
        ind+=key-1;
    }
    
    
    return decodedText;

}

int main() {
    string text = "weareunderattackfleeatonce";
    int key=5;

    // cout << "Enter the text to be encrypted: ";
    // getline(cin, text);
    // cout << "Enter the key: ";
    // cin >> key;

    string encoded = encryption(text, key);
    cout << "Encoded Text: " << encoded << endl;

    string ori=decryption(encoded, key);
    cout << "Decoded Text: " << ori << endl;


    return 0;
}

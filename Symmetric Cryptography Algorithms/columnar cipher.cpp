#include <bits/stdc++.h>
using namespace std;

vector<int> generateKey(string& key){
    vector<pair<int,int>> keyList;
    for(int i=0;i<key.size();i++){
        keyList.push_back({key[i] - 'a',i});
    }
    sort(keyList.begin(),keyList.end());
    int ind=0;
    for(auto& i:keyList){
        i.first = ind++;
        swap(i.first,i.second);
    }
    sort(keyList.begin(),keyList.end());
    vector<int> ans;
    for(auto& i:keyList){
        ans.push_back(i.second);
    }
    return ans;
}
string resuffleText(const string& text, vector<int>& key){
    string temp="";
    vector<pair<int,int>>p;
    for(int i=0;i<key.size();i++){
        p.push_back({key[i],i});
    }
    sort(p.begin(),p.end());

    for (int i = 0; i < key.size(); i++)
    {
        temp+=text[p[i].second];
    }
    // cout<<temp<<endl;
    return temp;
    
}

string suffleText(const string& text, vector<int>& key){
    string temp="";
    for (int i = 0; i < key.size(); i++)
    {
        temp+=text[key[i]];
    }
    // cout<<temp<<endl;
    return temp;
    
}
string encryption(const string& text, vector<int>& key) {
    string encrypted="";
    string modtext=text;
    vector<string>ptext;
    string temp="";
    int rem=text.size()%key.size();
    for (int i = 0; i < key.size() - rem; i++)
    {
        modtext+='z';
    }
    for (int i = 0; i < modtext.size(); i++)
    {
        if(temp.size()==key.size()){
            ptext.push_back(temp);
            temp="";
        }
        temp+=modtext[i];

    }
    ptext.push_back(temp);
    for(auto& i:ptext){
        i=suffleText(i,key);
    }
    for (int col = 0; col < key.size(); col++)
    {
        for (int row = 0; row < ptext.size(); row++)
        {
            encrypted+=ptext[row][col];
        }
        
    }
    return encrypted;
}
string decryption(const string& text, vector<int>& key){

    string decrypted="";
    string temp="";
    vector<string>ptext;
    string half="";
    int n=text.size()/key.size();
    for (int col = 0; col < n; col++)
    {
        for (int row = col; row < text.size();)
        {
            half+=text[row];
             row+=n;
        }
    }
    // cout<<half<<endl;
    for (int i = 0; i < text.size(); i++)
    {
        if(temp.size()==key.size()){
            ptext.push_back(temp);
            temp="";
        }
        temp+=half[i];
    }
    ptext.push_back(temp);
    for(auto& i:ptext){
        i=resuffleText(i,key);
    }
    // for(auto i:ptext){
    //     cout<<i<<endl;
    // }
    string ans="";
    for(auto i:ptext){
        ans+=i;
    }
    return ans;
}

int main() {
    string text ;
    string key;

    cout << "Enter the text to be encrypted: ";
    getline(cin, text);
    cout << "Enter the key: ";
    cin >> key;

    vector<int>genkey;
    genkey=generateKey(key);

    string encoded = encryption(text, genkey);
    cout << "Encoded Text: " << encoded << endl;

    string ori=decryption(encoded, genkey);
    cout << "Decoded Text: " << ori << endl;


    return 0;
}

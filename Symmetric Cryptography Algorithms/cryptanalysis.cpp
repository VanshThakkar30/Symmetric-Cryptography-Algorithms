#include<bits/stdc++.h>
using namespace std;

vector<pair<char, double>> key = {
    {'a', 8.167}, {'b', 1.49}, {'c', 2.782}, {'d', 4.253}, {'e', 12.702},
    {'f', 2.228}, {'g', 2.015}, {'h', 6.094}, {'i', 6.966}, {'j', 0.153},
    {'k', 0.772}, {'l', 4.025}, {'m', 2.406}, {'n', 6.749}, {'o', 7.507},
    {'p', 1.929}, {'q', 0.095}, {'r', 5.987}, {'s', 6.327}, {'t', 9.056},
    {'u', 2.758}, {'v', 0.978}, {'w', 2.360}, {'x', 0.150}, {'y', 1.974},
    {'z', 0.074}
};

map<char, double> calculateFrequency(const string& text) {
    map<char, double> freq;
    int sum = 0;

    for(auto i:text){
        if(i >= 'a' && i <= 'z'){
            freq[i]++;
            sum++;
        }
    }

    for (auto& i : freq) {
        i.second = (i.second / sum) * 100;
    }

    return freq;
}

map<char, char> createMapping(const map<char, double>& freq) {
    vector<pair<char, double>> freqVec(freq.begin(), freq.end());

    sort(freqVec.begin(), freqVec.end(), [](const pair<char, double>& a, const pair<char, double>& b) {
        return a.second > b.second;
    });

    sort(key.begin(), key.end(), [](const pair<char, double>& a, const pair<char, double>& b) {
        return a.second > b.second;
    });

    map<char, char> mapping;
    for (int i = 0; i < freqVec.size(); ++i) {
        mapping[freqVec[i].first] = key[i].first;
    }

    return mapping;
}

string decryptText(const string& text, const map<char, char>& mapping) {
    string decryptedText = text;

    for (int i = 0; i < text.length(); ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            char mappedChar = mapping.at(text[i]);
            decryptedText[i] = mappedChar;
        }
    }

    return decryptedText;
}

 int main(){

    string encriptedText="dkxyvrh 1 - qegt vkr hxccwv keur: xuwdr wn cehrq nwvvwtp et vkr hwsrhcxto gwvk krh nwnvrh, gkrt nkr tevwdrn x vxuowtp, duevkrq gkwvr hxccwv gwvk x yedorv gxvdk hit yxnv. nkr leuuegn wv qegt x hxccwv keur gkrt niqqrtub nkr lxuun x uetp gxb ve x dihwein kxuu gwvk fxtb uedorq qeehn el xuu nwmrn. nkr lwtqn x nfxuu orb ve x qeeh vee nfxuu leh krh ve lwv, civ vkheipk gkwdk nkr nrrn xt xvvhxdvwsr pxhqrt. nkr vkrt qwndesrhn x cevvur uxcruurq 'qhwto fr', vkr detvrtvn el gkwdk dxinr krh ve nkhwto vee nfxuu ve hrxdk vkr orb. x dxor gwvk 'rxv fr' et wv dxinrn krh ve pheg ve nidk x vhrfrtqein nwmr krh krxq kwvn vkr drwuwtp.";
    
    int n = encriptedText.length();

    map<char,double>freq=calculateFrequency(encriptedText);

    map<char, char> mapping = createMapping(freq);

    string decryptedText = decryptText(encriptedText, mapping);

    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
    
}


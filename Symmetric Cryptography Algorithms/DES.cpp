#include<bits/stdc++.h>
using namespace std;

private:
vector<int>parityTable ={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};

deque<int>parityDrop(deque<int> key){

}

int main(){

    //input
    deque<int>plainText(64);
    cout<<"Enter the plain text for encryption"<<endl;
    for (int i = 0; i < 64; i++)
    {
        cin>>plainText[i];
    }
    
    cout<<"Enter the key for encryption"<<endl;
    deque<int>key(64);
    for (int i = 0; i < 64; i++)
    {
        cin>>key[i];
    }

    key=parityDrop(plainText,key)

    
}
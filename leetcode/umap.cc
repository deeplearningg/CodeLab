#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int numJewelsInStones(string J, string S) {
    int num_jewels = 0;
    unordered_map<char,int> umap;
    for(int i = 0;i < J.size();i++){
        //umap.insert( unordered_map::value_type(J[i], i) );
        auto temp = make_pair(J[i],i);
        umap.insert( temp );
    }
    for(auto iter = umap.begin();iter != umap.end();iter++){
        cout << iter->first <<"\t" << iter->second << endl;
    }
    for(int i = 0;i < S.size();i++){
        if(umap.find(S[i]) != umap.end())
            num_jewels ++;
    }
    return num_jewels;
}
int main(){
    string S = "aAAbbbb";
    string J = "aA";
    cout << numJewelsInStones(J,S) << endl;
}

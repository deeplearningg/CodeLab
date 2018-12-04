#include <map>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    string str1 = "abhaoacbaqdbj";
    string str2 = "abcdefg";
    map<int,char> m;
    unordered_map<char,int> umap;
    for(size_t i = 0;i < str2.size();i++){
        m.insert(pair<int,char>(i,str2[i]));
        umap.insert(pair<char,int>(str2[i],i));
    }
    for(auto iter = m.begin();iter != m.end();iter++)
        cout << iter->first <<"\t" << iter->second << endl;
    cout << umap['c'] << endl;
    cout << umap['s'] << endl;
    return 0;
}

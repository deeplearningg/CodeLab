#include <map>
#include <string>
#include <iostream>
using namespace std;
void helper(size_t i,size_t j,string str,string& record);
string longestPalindrome(string s) {
    string LPalindrome = "";
    for(size_t i = 0,j = s.size() - 1;i < s.size() && j >= 0;i++,j--){
        string temp = "";
        helper(i,j,s,temp);
        if( temp.size() > LPalindrome.size() ){
            LPalindrome.assign(temp);
        }
    }
    return LPalindrome;
}
void helper(size_t i,size_t j,string str,string& record){
    record.clear();
    string temp = "";
    cout << i << "\t" << j << endl;
    for(size_t k = 0,p = j;k <= i && p < str.size();k++,p++){
        cout << str[k] << "\t" << str[p] << endl;
        if(str[k] == str[p]){
            temp += str[k];
        }
        else{
            if(temp.size() > record.size())
                record.assign(temp);
            temp.clear();
        }
    }
    cout << record;
}
int main(){
    cout << longestPalindrome("a");
    return 0;
}



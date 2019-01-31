#include<iostream>
#include<map>
int main(){
    std::map<int,int> mymap;
    mymap[0] = 'a';
    mymap[1] = 'b';
    mymap[2] = 'c';
    for(auto val:mymap){
        std::cout << val.first << "\t" << val.second << "\t" ;

    }
    std::cout << std::endl;
    return 0;
}

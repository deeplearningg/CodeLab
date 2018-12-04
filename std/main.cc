#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector< int > vec(10);
    for(size_t i = 0;i < vec.size();i++){
        vec[i] = i%4;
        cout << vec[i] << "\t";
    }
    cout << endl;
    for(auto iter = vec.begin();iter != vec.end();iter++){
        if(*iter == 1){
            if(iter + 1 == vec.end()){
                vec.erase(iter);
                break;
            }
            vec.erase(iter);
            iter++;
        }
    }
    for(size_t i = 0;i < vec.size();i++)
        cout << vec[i] << "\t";

    return 0;

}

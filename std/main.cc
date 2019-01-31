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
    double *arr = new double[10];
    for(size_t i = 0;i < 10;i++)
        arr[i] = i;
    vector< double > vec1(arr,arr+10);
    for(size_t i = 0;i < vec1.size();i++)
        cout << vec1[i] << "\t";
    cout << endl;
    delete [] arr;
    return 0;

}

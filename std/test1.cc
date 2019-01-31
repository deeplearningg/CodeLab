#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
inline double max(double d1,double d2){
    return d1 > d2 ? d1:d2;
}
inline double min(double d1,double d2){
    return d1 < d2 ? d1:d2;
}
void display(const double* arr, size_t n){
    cout << endl;
    for(size_t i = 0;i < n;i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int main(){
    size_t xsize = 6;
    double arr1[] = {1,3,5,7,8,9};
    double *arr2 = new double[xsize];
    double rand[] = {0,-2,3,6,7,4};
    memcpy(arr2,arr1,sizeof(double)*xsize);
    //srand(time(0));
    display(arr1,xsize);
    int flag = 1;
    cin >> flag;
    for(size_t i = 0;i < xsize/2;i++){
        //double temp1 = rand()%10;
        //double temp2 = rand()%10;
        if(flag){
            arr1[2*i]   = max(arr1[2*i],rand[2*i]);
            arr1[2*i+1] = min(arr1[2*i+1],rand[2*i+1]);
        }
        else{
            arr1[2*i]   = max(arr2[2*i],rand[2*i]);
            arr1[2*i+1] = min(arr2[2*i+1],rand[2*i+1]);

        }
    }
    display(arr1,xsize);

    return 0;

}

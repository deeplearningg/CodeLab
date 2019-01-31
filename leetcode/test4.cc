#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void swap(int&x,int&y){
    int temp = x;
    x = !y;
    y = !temp;
}
int main(){
    string str1 = "123456";
    string ch( 1,str1[0] );
//    cout << ch << endl;

    int x = 1;
    int y = 0;
    swap(x,x);
    //cout << x << "\t" << y << endl;
    cout << (1&4) << endl;

    return 0;
}

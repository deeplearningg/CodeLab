#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;
int main()
{
    int M = 4;
    int N = 3;
    vector< vector<int> > Arr;
    vector< vector<int> > Arr2;
    Arr.resize(M);
    Arr2.resize(M);
    for(size_t i = 0; i < M; i++){
        Arr[i].resize(N);
        Arr2[i].resize(N);
    }
    srand(1);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            Arr[i][j]=rand();
        }
    }
    ofstream outfile;
    outfile.open("ModuleData",ios::out|ios::binary);
    if(!outfile.is_open()){
        cout<<" the file open fail"<<endl;
        exit(1);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
        outfile<<Arr[i][j]<<" ";
        }
        outfile<<"\r\n";
    }
    outfile.close();


    ifstream infile;
    infile.open("ModuleData",ios::in|ios::binary);
    if(!infile.is_open()){
        cout<<"file open fail"<<endl;
        exit(1);
    }
    string line,s;
    int row=0;
    while( getline( infile, line ) ){
        int col=0;
        stringstream ss;
        ss<<line;
        while(ss){
            int a;
            ss>>a;
            Arr2[row][col]=a;
            col++;
        }
        row++;
    }
    infile.close();

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<Arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

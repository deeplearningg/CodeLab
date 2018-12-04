#include <iostream>
#include "hmetis.h"
using namespace std;
int main(){
    int nvtxs = 7;
    int nhedges = 4;
    int *vwgts = nullptr;
    int eptr[5] = {0,2,6,9,12};
    int eind[12] = {0,2,0,1,3,4,3,4,6,2,5,6};
    int *hewgts = nullptr;
    int nparts = 2;
    int ubfactor = 5;
    int options[9] = {0,0,0,0,0,0,0,0,0};
    int part[7] = {-1,-1,-1,-1,-1,-1,-1};
    int edgecut;
    HMETIS_PartRecursive(nvtxs,nhedges,vwgts,eptr,eind, hewgts,nparts,ubfactor,
                         options,part,&edgecut);
    for(size_t i = 0;i < nvtxs;i++){
        cout << i << "->" << part[i] << "\t";
    }
    cout << endl;
    HMETIS_PartKway(nvtxs,nhedges,vwgts,eptr,eind, hewgts,nparts,ubfactor,
                         options,part,&edgecut);
    for(size_t i = 0;i < nvtxs;i++){
        cout << i << "->" << part[i] << "\t";
    }
    cout << endl;



    return 0;
}

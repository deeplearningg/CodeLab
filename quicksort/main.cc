#include <chrono>  // time
#include <cstdlib>  // rand
#include <iostream>
#include "util.h"
#include "quicksort.h"
#include "mergeSort.h"
#include "IterativeMergeSort.h"
// Driver program to test above functions
int main()
{
    size_t n = 14111;
    std::vector< int > ret(n);
    for(int i = 0;i < n;i++)
        ret[i] = i;
    std::vector< double > ref(n);
    srand(0);
    for ( size_t i = 0; i < n; i++ ) {
        ref[i] = rand()%(33);
    }

//    QuickSort qs(ref);
    MergeSort ms(ref);
    auto t1 = std::chrono::high_resolution_clock::now();
#if 1
// parallel sort
    //qs.quickSort(ret,0,ret.size()-1);
    ms.mergeSort(ret, 0, n - 1);
	//mergeSort(ref, n);


#endif
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tms = t2 - t1;
    std::cout << "Sorted in " << tms.count()/1000.0 << " sec." << std::endl;
#if 1
    for(size_t i = 0;i < n;i++){
        std::cout << ref[ ret[i] ] << "\t";
        if( (i+1)%8 == 0 )
            std::cout << std::endl;
    }
    std::cout << std::endl;
#endif
    return 0;
}


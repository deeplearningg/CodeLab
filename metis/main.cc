#include <iostream>
#include "metis.h"
int main(){
#if 1
    idx_t nvtxs = 7;
    idx_t nEdges = 11;
    idx_t xadj[nvtxs+1] = {0,3,6,10,14,17,20,22};//nvtxs + 1
    idx_t adjncy[2*nEdges] = {5,3,2,\
                              1,3,4,\
                              5,4,2,1,\
                              2,3,6,7,\
                              1,3,6,\
                              5,4,7,\
                              6,4};//2*edges
    for(size_t i = 0;i < 2*nEdges;i++)
        adjncy[i] -= 1;
    idx_t nparts = 2;
    idx_t ncon = 1;
    idx_t objval;
    idx_t part1[nvtxs],part2[nvtxs];//nvtxs
#endif
#if 0
    idx_t nvtxs = 6;
    idx_t nEdges    = 7;
    idx_t ncon  = 1;
    idx_t nparts    = 2;

    idx_t objval;
    idx_t part[nvtxs];


    // Indexes of starting points in adjacent array
    idx_t xadj[nvtxs+1] = {0,2,5,7,9,12,14};
    // Adjacent vertices in consecutive index order
    idx_t adjncy[2 * nEdges] = {1,3,\
                                0,4,2,\
                                1,5,\
                                0,4,\
                                3,1,5,\
                                4,2};

    idx_t part1[nvtxs],part2[nvtxs];//nvtxs
#endif
#if 0
    idx_t nvtxs = 3;
    idx_t ncon = 1;
    idx_t xadj[4] = {0,2,4,6};//nvtxs + 1
    idx_t adjncy[6]= {0,1,\
                      0,2,\
                      1,2};//2*edges
    idx_t nparts = 2;
    idx_t objval;
    idx_t part1[3],part2[3];//nvtxs
#endif
///////////////////////////////////////////////////////////
    METIS_PartGraphRecursive(&nvtxs,\
                             &ncon,\
                             xadj,adjncy,\
                             nullptr,nullptr,nullptr,\
                             &nparts,\
                             nullptr,nullptr,nullptr,\
                             &objval,\
                             part1
                            );
    for(size_t i = 0;i < nvtxs;i++)
        std::cout << part1[i] << "\t";
    std::cout << std::endl;
    METIS_PartGraphKway(&nvtxs,\
                         &ncon,\
                         xadj,adjncy,\
                         nullptr,nullptr,nullptr,\
                         &nparts,\
                         nullptr,nullptr,nullptr,\
                         &objval,\
                         part2
                        );
    for(size_t i = 0;i < nvtxs;i++)
        std::cout << part2[i] << "\t";
    std::cout << std::endl;
    return 0;

}

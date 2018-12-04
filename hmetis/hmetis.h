#ifndef HMETIS_H
#define HMETIS_H
void HMETIS_PartRecursive(int nvtxs, int nhedges, int *vwgts, int *eptr,
                          int *eind, int *hewgts, int nparts, int ubfactor,
                          int *options, int *part, int *edgecut);
void HMETIS_PartKway(int nvtxs, int nhedges, int *vwgts, int *eptr,
                          int *eind, int *hewgts, int nparts, int ubfactor,
                          int *options, int *part, int *edgecut);
#endif

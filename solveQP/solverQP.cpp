#include "solverQP.h"
#include "laspack/qmatrix.h"
#include "laspack/vector.h"
#include "laspack/itersolv.h"
#include "laspack/precond.h"
#include "laspack/rtc.h"



CQP::CQP(void) {}
CQP::~CQP(void) {}

void CQP::setValue(const int&i, const int&j, const double& val)
{
  mapA[i][j] = val;
}

void CQP::getValue(const int&i, const int&j, double& val)
{
  val = mapA[i][j];
}


void CQP::solverQP(const int& iterMax, const vector<double>& vecB, vector<double>& vecX)
{
  // build matrix, vectors
  QMatrix matA;
  size_t i;
  map<int, double>::iterator iter;

  size_t nrows = mapA.size();
  size_t nnz;
  size_t pos;
  size_t k;

  Q_Constr(&matA, "A", nrows, False, Rowws, Normal, True);

  for(i = 0; i < mapA.size(); ++i)
    {
      nnz = mapA[i].size();
      Q_SetLen(&matA, i, nnz);
      k = 0;
      for(iter = mapA[i].begin(); iter != mapA[i].end(); ++iter)
	{
	  Q_SetEntry(&matA, i, k++, iter->first, iter->second);
	}
    }

  Vector vb;
  Vector vx;

  V_Constr(&vb, "b", nrows, Normal, True);
  V_Constr(&vx, "x", nrows, Normal, True);

  for(i = 0; i < nrows; ++i)
    V_SetCmp(&vb, i, vecB[i]);

  // solve
  SetRTCAccuracy(1e-4); 
  V_SetAllCmp(&vx, 0.0);

  BiCGSTABIter(&matA, &vx, &vb, iterMax,
            ILUPrecond, 1.0);
  

  for(i = 0; i < nrows; ++i)
    vecX[i] = V_GetCmp(&vx, i);

  Q_Destr(&matA);
  V_Destr(&vb);
  V_Destr(&vx);

  
}

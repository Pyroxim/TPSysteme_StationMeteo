//---------------------------------------------------------------------------
#ifndef SM9111H
#define SM9111H
//---------------------------------------------------------------------------
#include <tchar.h>
#include "dask.h"
//---------------------------------------------------------------------------
class SM9111
{
	I16 IDCarte;
	F64 ValTemp, ValHumid, ValPluie;

	public :
		SM9111();
		~SM9111();

		int Initialisation();
		float AcquisitionTemp();
		float AcquisitionHumid();
		bool TestPluie();
};

#endif

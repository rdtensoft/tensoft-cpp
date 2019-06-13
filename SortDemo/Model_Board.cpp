//---------------------------------------------------------------------------

#pragma hdrstop

#include "Model_Board.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void TBoardModel::boardFillWithRandomData (int count) {
	Fdata.clear();
	for (int i = 0; i < count; i++)
		Fdata.push_back ( Random(MAX_VALUE) );
}

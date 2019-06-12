//---------------------------------------------------------------------------

#ifndef Model_BoardH
#define Model_BoardH
#include <vector>
#include <algorithm>
//---------------------------------------------------------------------------
class TBoardModel
{
private:
	std::vector<int>Fdata;
	int getData(int index){return Fdata[index];}
	void setData(int index, int value){Fdata[index] = value;}
	int FMAX_VALUE;
public:
	TBoardModel (){FMAX_VALUE = 0;}
	void clear(){Fdata.clear();}
	int size(){return Fdata.size();}
	void boardFillWithRandomData (int count);
	void swap(int a, int b){std::swap(Fdata[a], Fdata[b]);}
	__property int data [int index] = {read= getData, write= setData};
	__property int MAX_VALUE = {read=FMAX_VALUE, write=FMAX_VALUE};

};

#endif

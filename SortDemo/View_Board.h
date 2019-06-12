//---------------------------------------------------------------------------

#ifndef View_BoardH
#define View_BoardH
//---------------------------------------------------------------------------

#include <Vcl.ExtCtrls.hpp>
#include <vector>

class TBoardView {
private:
	TPaintBox* FPaintBox1;
	std::vector<int> Fdata;
	int FMAX_VALUE;
public:
	TBoardView () {FPaintBox1 = NULL; FMAX_VALUE=0;}
	void DrawBoardItem (int index);
	__property TPaintBox* PaintBox1 = {read=FPaintBox1, write=FPaintBox1};
	__property std::vector<int> data = {read=Fdata, write=Fdata};
	__property int MAX_VALUE = {read=FMAX_VALUE, write=FMAX_VALUE};
};

#endif

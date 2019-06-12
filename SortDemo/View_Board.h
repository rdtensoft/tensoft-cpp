//---------------------------------------------------------------------------

#ifndef View_BoardH
#define View_BoardH
//---------------------------------------------------------------------------

#include <Vcl.ExtCtrls.hpp>
#include <vector>
class TBoardModel;


class TBoardView {
private:
	TBoardModel* FBoardModel;
	TPaintBox* FPaintBox1;
	int FMAX_VALUE;
public:
	TBoardView () {FPaintBox1 = NULL; FMAX_VALUE=0;}
	void DrawBoardItem (int index);
	__property TPaintBox* PaintBox1 = {read=FPaintBox1, write=FPaintBox1};
	__property int MAX_VALUE = {read=FMAX_VALUE, write=FMAX_VALUE};
	__property TBoardModel* BoardModel = {read=FBoardModel, write=FBoardModel};

};

#endif

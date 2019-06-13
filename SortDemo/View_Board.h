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
public:
	TBoardView () {FPaintBox1 = NULL;}
	void DrawBoardItem (int index);
	__property TPaintBox* PaintBox1 = {read=FPaintBox1, write=FPaintBox1};
	__property TBoardModel* BoardModel = {read=FBoardModel, write=FBoardModel};

};

#endif

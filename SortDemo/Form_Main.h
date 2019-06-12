//---------------------------------------------------------------------------

#ifndef Form_MainH
#define Form_MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include "View_Board.h"
#include "Model_Board.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *PaintBox1;
	TTimer *tmrReady;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TButton *Button2;
	TActionList *ActionList1;
	TAction *actRunQuickSort;
	TAction *actRunBubbleSort;
	TAction *actShuflleData;
	TButton *Button3;
	void __fastcall tmrReadyTimer(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall actRunQuickSortExecute(TObject *Sender);
	void __fastcall actRunBubbleSortExecute(TObject *Sender);
	void __fastcall actShuflleDataExecute(TObject *Sender);
private:	// User declarations
	void VisualSwapBoardItems (int i, int j);
	void qsort(int L, int R);
	std::unique_ptr<TBoardView> BoardView;
	std::unique_ptr<TBoardModel> BoardModel;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

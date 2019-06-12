//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>

#pragma hdrstop

#include "Form_Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
// ---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	const unsigned int MAX_VALUE = 1000;
	BoardModel.reset(new TBoardModel());

	BoardView.reset(new TBoardView());
	BoardView->PaintBox1 = PaintBox1;
	BoardModel->MAX_VALUE = MAX_VALUE;
	BoardView->BoardModel = BoardModel.get();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
	tmrReady->Enabled = false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
static float HueToRGB(float v1, float v2, float vH) {
	if (vH < 0) vH += 1;
	if (vH > 1) vH -= 1;
	if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1) return v2;
	if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
	return v1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
	for (unsigned int i=0; i<BoardModel->size(); i++) {
		BoardView->DrawBoardItem(i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	int count = PaintBox1->Width / 3;
	BoardModel->boardFillWithRandomData (count);
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
void TForm1::VisualSwapBoardItems (int i, int j) {
	BoardModel->swap(i,j);
	BoardView->DrawBoardItem(i);
	BoardView->DrawBoardItem(j);
	for (int i=0; i < 100000; i++) { }  // sleep < 1ms
}
//---------------------------------------------------------------------------
void TForm1::qsort(int L, int R) {
	int i, j, mid, piv;
	i = L;
	j = R;
	mid = L + (R - L) / 2;
	piv = BoardModel->data[mid];
	while (i<R || j>L) {
		while (BoardModel->data[i] < piv)
			i++;
		while (BoardModel->data[j] > piv)
			j--;
		if (i <= j) {
			// swap(i, j);
            VisualSwapBoardItems(i, j);
			i++;
			j--;
		} else {
			if (i < R) qsort(i, R);
			if (j > L) qsort(L, j);
			return;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actRunQuickSortExecute(TObject *Sender)
{
	unsigned long enlapsedMs = 0;
	unsigned long start = GetTickCount();
	// ----------------------------------------------
	// Algorithm: Quick Sort
	qsort(0, BoardModel->size() - 1);
	// ----------------------------------------------
	enlapsedMs = GetTickCount() - start;
	Caption = L"[Results] QuickSort: "+
		FormatFloat(L"###,###",enlapsedMs) + " ms";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actRunBubbleSortExecute(TObject *Sender)
{
	unsigned long enlapsedMs = 0;
	unsigned long start = GetTickCount();
	// ----------------------------------------------
	// Algorithm: Bubble Sort
	for(unsigned int i = 0; i < BoardModel->size(); i++ )
		for(unsigned int j = 0; j < BoardModel->size() - 1; j++ ) {
			if( BoardModel->data[j] > BoardModel->data[j+1] ) {
				// swap( j, j+1 );
				VisualSwapBoardItems(j, j+1);
			}
		}
	// ----------------------------------------------
	enlapsedMs = GetTickCount() - start;
	Caption = L"[Results] BubbleSort: "+
		FormatFloat(L"###,###",enlapsedMs) + " ms.";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actShuflleDataExecute(TObject *Sender)
{
	int count = PaintBox1->Width / 3;
	BoardModel->boardFillWithRandomData (count);
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------


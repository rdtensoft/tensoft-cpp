//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
#include "ThreadProgress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TProgressBar* __fastcall TForm1::ProgressBarFactory (TComponent* AOwner) {
	TProgressBar* pbar = new TProgressBar(AOwner);
	pbar->Parent = GroupBox2;
	pbar->Align = alTop;
	pbar->AlignWithMargins = true;
	pbar->Max = 200;
	pbar->Position = pbar->Max;
	return pbar;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ProgressBarFactory(this);
    // new TProgressTread(tre / false);
}
//---------------------------------------------------------------------------
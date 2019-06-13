//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadProgress.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TProgressTread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TProgressTread::TProgressTread(bool CreateSuspended, TProgressBar* bar)
	: TThread(CreateSuspended)
{

	this->FreeOnTerminate = true;
	pbar = bar;
}
//---------------------------------------------------------------------------
void __fastcall TProgressTread::Execute()
{
	NameThreadForDebugging(System::String(L"Progress Tread"));
	//---- Place thread code here ----
	Sleep(1000);
	while(!Terminated)
	{
		 Synchronize(&UpdateProgressBar);
		 Sleep(1);
	}
}
//---------------------------------------------------------------------------
void __fastcall TProgressTread::UpdateProgressBar()
{
	if(pbar->Position > 0)
	{
		--pbar->Position;
	}
	else
		pbar->Visible = false;
}
//---------------------------------------------------------------------------


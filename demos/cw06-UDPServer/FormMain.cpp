//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
#include <IdStack.hpp>
#include <IdGlobal.hpp>

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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Lines = GStack->LocalAddresses;
	Memo1->Lines->Add("----------------");
	IdUDPServer1->DefaultPort = 10123;
	IdUDPServer1->Active = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	IdUDPClient1->Broadcast (L"Zażółć! рождаются",10123,L"",
		IndyTextEncoding_UTF8());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding)
{
	String s = BytesToString(AData, IndyTextEncoding_UTF8());
	Memo1->Lines->Add (s);
}
//---------------------------------------------------------------------------

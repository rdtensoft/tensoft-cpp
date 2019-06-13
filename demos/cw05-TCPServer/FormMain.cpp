//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
#include <IdGlobal.hpp>
#include <IdStack.hpp>
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
void __fastcall TForm1::btnConnectClick(TObject *Sender)
{
	IdTCPClient1->Host = edtHost->Text;
	IdTCPClient1->Port = StrToIntDef(edtPort->Text,12321);
	IdTCPClient1->Connect();
	btnSend->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnSendClick(TObject *Sender)
{
  IdTCPClient1->IOHandler->WriteLnRFC(Edit1->Text,TIdTextEncoding_UTF8);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnStartServerClick(TObject *Sender)
{
	IdTCPServer1->DefaultPort = StrToIntDef(edtPort->Text,12321);
	IdTCPServer1->Active = True;
	IdTCPServer1->StartListening();
	Shape1->Brush->Color = (TColor)RGB (128,255,128);
	Memo1->Lines->Add("Server started on port "+IdTCPServer1->DefaultPort);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTCPServer1Connect(TIdContext *AContext)
{
	Memo1->Lines->Add("Connected from: "+AContext->Binding->PeerIP+"  (name:"+
		GStack->HostByAddress(AContext->Binding->PeerIP)+")");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTCPServer1Execute(TIdContext *AContext)
{
	bool isMggEnd;
	String s = AContext->Connection->IOHandler->ReadLnRFC(isMggEnd,
		TIdTextEncoding_UTF8);
	Memo1->Lines->Add(s);
}
//---------------------------------------------------------------------------

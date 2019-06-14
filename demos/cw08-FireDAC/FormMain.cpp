//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
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
	Variant res = FDConnection1->ExecSQLScalar("SELECT count(*) FROM {id Orders}");
	dynamic_cast<TButton*>(Sender)->Caption = res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Variant c = "USA";
	Variant res = FDConnection1->ExecSQLScalar(
		"select count(*) from {id Customers} where country = :country",
		&c, 0 );
	dynamic_cast<TButton*>(Sender)->Caption = res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	TTabSheet* tab = new TTabSheet(this);
	tab->Caption = "Select from TFDConnection";
	tab->PageControl = PageControl1;
	TDataSet* ds;
	FDConnection1->ExecSQL("Select * from {id Orders}",ds);
	TDBGrid* dbgr = new TDBGrid(tab);
	dbgr->Parent = tab;
	dbgr->Align = alClient;
	dbgr->DataSource = new TDataSource(tab);
	dbgr->DataSource->DataSet = ds;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	try {
		FDConnection1->Open("SYSDBA","maasterkey");
	} catch (EFDDBEngineException& e) {
		if (e.Kind == ekUserPwdInvalid) {
			dynamic_cast<TButton*>(Sender)->Caption = "Niepoprawne has³o";
		}
	}
}
//---------------------------------------------------------------------------

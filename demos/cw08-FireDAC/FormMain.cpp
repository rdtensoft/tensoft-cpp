//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
#include <ctime>
#include <vector>
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
	// ----
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
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	// ------------
	TTabSheet* tab = new TTabSheet(this);
	tab->Caption = "ArrayDML test";
	tab->PageControl = PageControl1;
	TMemo* mm = new TMemo (tab);
	mm->Parent = tab;
	mm->Align = alClient;
	// ------------
	FDConnection1->ExecSQL("DELETE FROM FDQA_PRODUCTS");
	FDQuery1->SQL->Text = "INSERT INTO FDQA_PRODUCTS"
		" (PRODUCTID, PRODUCTNAME, FROMDATE, SUPPLIERID,"
		"  CATEGORYID, QUANTITYPERUNIT, UNITPRICE, UNITSINSTOCK,"
		"  UNITSONORDER, ONDATE)"
		" VALUES (:PRODUCTID, :PRODUCTNAME, :FROMDATE, :SUPPLIERID,"
		"  :CATEGORYID, :QUANTITYPERUNIT, :UNITPRICE, :UNITSINSTOCK,"
		"  :UNITSONORDER, :ONDATE)";
	std::clock_t c_start1 = std::clock();
	for (int i=0; i < 5000; i++) {
		FDQuery1->ParamByName("PRODUCTID")->AsLargeInt = i;
		FDQuery1->ParamByName("PRODUCTNAME")->AsString = "AAA";
		FDQuery1->ParamByName("FROMDATE")->AsDate = TDate(2019,01,01);
		FDQuery1->ParamByName("SUPPLIERID")->AsLargeInt = 1;
		FDQuery1->ParamByName("CATEGORYID")->AsLargeInt = 1;
		FDQuery1->ParamByName("QUANTITYPERUNIT")->AsString = "12 x 1kg";
		FDQuery1->ParamByName("UNITPRICE")->AsCurrency = 1234;
		FDQuery1->ParamByName("UNITSINSTOCK")->AsInteger = 10;
		FDQuery1->ParamByName("UNITSONORDER")->AsInteger = 20;
		FDQuery1->ParamByName("ONDATE")->AsDate = TDate(2019,02,02);
		FDQuery1->Execute();
	}
	std::clock_t c_result1 = std::clock() - c_start1;
	mm->Lines->Add("Classic Insert: " + (String)c_result1 + "ms");
	// ------------
	FDConnection1->ExecSQL("DELETE FROM FDQA_PRODUCTS");
	std::clock_t c_start2 = std::clock();
	FDQuery1->Params->ArraySize = 5000;
	for (int i=0; i < 5000; i++) {
		FDQuery1->ParamByName("PRODUCTID")->AsLargeInts[i] = i;
		FDQuery1->ParamByName("PRODUCTNAME")->AsStrings[i] = "AAA";
		FDQuery1->ParamByName("FROMDATE")->AsDates[i] = TDate(2019,01,01);
		FDQuery1->ParamByName("SUPPLIERID")->AsLargeInts[i] = 1;
		FDQuery1->ParamByName("CATEGORYID")->AsLargeInts[i] = 1;
		FDQuery1->ParamByName("QUANTITYPERUNIT")->AsStrings[i] = "12 x 1kg";
		FDQuery1->ParamByName("UNITPRICE")->AsCurrencys[i] = 1234;
		FDQuery1->ParamByName("UNITSINSTOCK")->AsIntegers[i] = 10;
		FDQuery1->ParamByName("UNITSONORDER")->AsIntegers[i] = 20;
		FDQuery1->ParamByName("ONDATE")->AsDates[i] = TDate(2019,02,02);
	}
	FDQuery1->Execute(5000,0);
	std::clock_t c_result2 = std::clock() - c_start2;
	mm->Lines->Add("Array DML Insert: " + (String)c_result2 + "ms");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	// ------------
	TTabSheet* tab = new TTabSheet(this);
	tab->Caption = "ArrayDML test";
	tab->PageControl = PageControl1;
	TMemo* mm = new TMemo (tab);
	mm->Parent = tab;
	mm->Align = alClient;
	// ------------
	std::vector<String> cmds;
	cmds.push_back("SELECT * from {id Customers}");
	cmds.push_back("SELECT {ucase(Country)} from {id Customers}");
	cmds.push_back("SELECT * from {id Orders} where OrderDate>{d 1995-08-12}");
	cmds.push_back("SELECT {CHARACTER_LENGTH(Country)} from {id Customers}");
	cmds.push_back("SELECT {CURDATE()} from RDB$DATABASE");

	for (int i = 0; i < cmds.size(); i++) {
		FDQuery1->SQL->Text = cmds[i];
		FDQuery1->Prepare();
		mm->Lines->Add("------------------------");
		mm->Lines->Add("  "+cmds[i]);
		mm->Lines->Add("  "+FDQuery1->Text);
	}
}
//---------------------------------------------------------------------------


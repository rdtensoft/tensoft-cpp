//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBoxSend;
	TButton *btnSend;
	TEdit *Edit1;
	TGroupBox *GroupBoxConnect;
	TLabel *Label2;
	TButton *btnConnect;
	TEdit *edtHost;
	TGroupBox *GroupBox2;
	TButton *btnStartServer;
	TMemo *Memo1;
	TPanel *pnServerStatus;
	TShape *Shape1;
	TGroupBox *GroupBoxParams;
	TLabel *Label1;
	TEdit *edtPort;
	TIdTCPClient *IdTCPClient1;
	TIdTCPServer *IdTCPServer1;
	TSplitter *Splitter1;
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall btnSendClick(TObject *Sender);
	void __fastcall btnStartServerClick(TObject *Sender);
	void __fastcall IdTCPServer1Connect(TIdContext *AContext);
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

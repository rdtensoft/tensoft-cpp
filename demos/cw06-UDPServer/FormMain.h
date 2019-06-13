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
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TMemo *Memo1;
	TIdUDPServer *IdUDPServer1;
	TIdUDPClient *IdUDPClient1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

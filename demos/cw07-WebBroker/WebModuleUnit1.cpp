 
//---------------------------------------------------------------------------
#include "WebModuleUnit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TComponentClass WebModuleClass = __classid(TWebModule1);
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled)
{
	if ( Request->MethodType == mtGet ) {
	Response->ContentType = "appliction/json";
		Response->Content =
		"[{\"name\":\"Bogdan\"},{\"name\":\"Adam\"}]";
	} else if (Request->MethodType == mtPost) {
		Response->ContentType = "appliction/json";
		Response->Content = "{\"response\":"+Request->Content+"}";
	}
}
//---------------------------------------------------------------------------



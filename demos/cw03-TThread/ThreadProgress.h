//---------------------------------------------------------------------------

#ifndef ThreadProgressH
#define ThreadProgressH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TProgressThread : public TThread
{
protected:
	void __fastcall Execute();
	TProgressBar* pbar;
    void __fastcall UpdateProgressBar();
public:
	__fastcall TProgressThread(bool CreateSuspended, TProgressBar* bar );
};
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef ThreadProgressH
#define ThreadProgressH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TProgressTread : public TThread
{
protected:
	void __fastcall Execute();
public:
	__fastcall TProgressTread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif

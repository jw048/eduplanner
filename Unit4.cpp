//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::loginbtnClick(TObject *Sender)
{
	int c = 0;
	String ad;
	username = usernameed->Text;
	passcode = passcodeed->Text;
	RESTClient1->BaseURL = "http://127.0.0.1:8000/login/"+username+"/"+passcode+"/N";
	RESTRequest1->Execute();
	name = RESTResponse1->Content;
	c = name.Pos(":");
	name = name.Delete(1,c);
	c = name.Pos('"');
	name = name.Delete(1,c);
	c = name.Pos('"');
	name = name.SubString(1, c-1);
	if(name == "false"){
		Label1->Caption = "Login Failure";
	}
	else{
		RESTClient1->BaseURL = "http://127.0.0.1:8000/login/"+username+"/"+passcode+"/Y";
		RESTRequest1->Execute();
		ad = RESTResponse1->Content;
		c = ad.Pos(":");
		ad = ad.Delete(1,c);
		c = ad.Pos('"');
		ad = ad.Delete(1,c);
		c = ad.Pos('"');
		ad = ad.SubString(1, c-1);
		if(ad == "Y"){
			Form5->Show();
			Form4->Hide();
		}
		else{
			Form6->Show();
			Form4->Hide();
		}
	}
}
//---------------------------------------------------------------------------

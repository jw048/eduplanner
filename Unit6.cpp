//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit9.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormShow(TObject *Sender)
{
	welcomelabel->Caption = "Welcome " + Form4->name + "!";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::gpabtnClick(TObject *Sender)
{
    Form7->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::csbtnClick(TObject *Sender)
{
	int c;
	RESTClient1->BaseURL = "http://127.0.0.1:8000/detergrade/"+Form4->name;
	RESTRequest1->Execute();
	detergrade = RESTResponse1->Content;
	c = detergrade.Pos(":");
	detergrade = detergrade.Delete(1,c);
	c = detergrade.Pos("}");
    detergrade = detergrade.SubString(1,c-1);
	if (detergrade == "1") {
		Form9->Show();
	}
	if (detergrade == "2") {
		Form1->Show();
	}
	if (detergrade == "3") {
		Form2->Show();
	}
	if (detergrade == "4") {
		Form3->Show();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
	String ch, na, t, val_temp[1000]={};
	int c = 0, slot = 0, i, j;
	na = Form4->name;
	welcomel->Caption = "Welcome "+na+"!";
	RESTClient1->BaseURL = "http://127.0.0.1:8000/adtimemod/date/time/"+na+"/prt";
	RESTRequest1->Execute();
	ch = RESTResponse1->Content;
	c = ch.Pos('{');
	ch = ch.Delete(1,c);
	t = ch;
	while(c > 0) {
		c = t.Pos('}');
		t = t.Delete(1, c);
		c = t.Pos('{');
		slot++;
	}
	ShowMessage(slot);
	if(slot == 0){
		printmemo->Lines->Add("No time frame added");
	}
	else {
		for (i = 0; i < slot; i++) {
			for (j = 0; j < 4; j++) {
				c = ch.Pos(':');
				ch = ch.Delete(1,c);
				c = ch.Pos('"');
				ch = ch.Delete(1,c);
				c = ch.Pos('"');
				val_temp[j] = ch.SubString(1, c-1);
			}
			printmemo->Lines->Add("date: "+val_temp[0]+"   time: "+val_temp[1]+"   availability: "+val_temp[2]+"   student: "+val_temp[3]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::addbtnClick(TObject *Sender)
{
	String d, t, rt, na;
	d = dateadd->Date;
	t = timeadd->Text;
	na = Form4->name;
	RESTClient1->BaseURL = "http://127.0.0.1:8000/adtimemod/"+d+"/"+t+"/"+na+"/add";
	RESTRequest1->Execute();
	rt = RESTResponse1->Content;
	ShowMessage(rt);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::deletebtnClick(TObject *Sender)
{
	String d, t, rt, na;
	d = datedelete->Date;
	t = timedelete->Text;
	na = Form4->name;
	RESTClient1->BaseURL = "http://127.0.0.1:8000/adtimemod/"+d+"/"+t+"/"+na+"/delete";
	RESTRequest1->Execute();
	rt = RESTResponse1->Content;
	ShowMessage(rt);
}
//---------------------------------------------------------------------------

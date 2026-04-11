//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)
{
    scheduledmm->Text = "";
	String nm, ch, temp, val_temp[1000]={};
	int c = 0, mt = 0, i, j;
	nm = Form4->name;
	RESTClient1->BaseURL = "http://127.0.0.1:8000/stmeetcheck/"+nm;
	RESTRequest1->Execute();
	ch = RESTResponse1->Content;
	c = ch.Pos("[");
	temp = ch;
	while(c > 0) {
		c = temp.Pos('}');
		temp = temp.Delete(1, c);
		c = temp.Pos('{');
		mt++;
	}
	if(mt == 0){
		scheduledmm->Lines->Add("(No meeting scheduled)");
	}
	else {
		for (i = 0; i < mt; i++) {
			for (j = 0; j < 3; j++) {
				c = ch.Pos(':');
				ch = ch.Delete(1,c);
				c = ch.Pos('"');
				ch = ch.Delete(1,c);
				c = ch.Pos('"');
				val_temp[j] = ch.SubString(1, c-1);
			}
			scheduledmm->Lines->Add("counselor name: "+val_temp[0]+"   date: "+val_temp[1]+"   time: "+val_temp[2]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::dateselectbtnClick(TObject *Sender)
{
    mtnglist->Clear();
	String avil, temp, val_temp[1000]={};
	int c, cnt, i, j;
	dte = schecalendar->Date;
	RESTClient2->BaseURL = "http://127.0.0.1:8000/mtngprt/"+dte;
	RESTRequest2->Execute();
	avil = RESTResponse2->Content;
	c = avil.Pos('[');
	temp = avil;
    c = temp.Pos('}');
	while(c > 0) {
		c = temp.Pos('}');
		temp = temp.Delete(1,c);
		c = temp.Pos('{');
		cnt++;
	}
	ShowMessage(cnt);
	if(cnt == 0){
		ShowMessage("no available meeting time in selected date");
	}
	else {
		for (i = 0; i < cnt; i++) {
			for (j = 0; j < 2; j++) {
				c = avil.Pos(':');
				avil = avil.Delete(1,c);
				c = avil.Pos('"');
				avil = avil.Delete(1,c);
				c = avil.Pos('"');
				val_temp[j] = avil.SubString(1, c-1);
			}
			adname[i] = val_temp[0];
			aviltme[i] = val_temp[1];
			mtnglist->Items->Add("conselor name: "+val_temp[0]+", time: "+val_temp[1]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::schedulebtnClick(TObject *Sender)
{
    String tm, rt;
	tm = mtnglist->Items->Strings[mtnglist->ItemIndex];
	ShowMessage(tm);
	RESTClient3->BaseURL = "http://127.0.0.1:8000/stmeetapp/"+adname[mtnglist->ItemIndex]+"/"+dte+"/"+tm+"/"+Form4->name;
	RESTRequest3->Execute();
	rt = RESTResponse3->Content;
	ShowMessage(rt);
	RESTClient4->BaseURL = "http://127.0.0.1:8000/confirmemail/"+Form4->name+"/"+dte+"/"+tm+"/st";
	RESTRequest4->Execute();
	rt = RESTResponse4->Content;
	ShowMessage(rt);
	RESTClient4->BaseURL = "http://127.0.0.1:8000/confirmemail/"+Form4->name+"/"+dte+"/"+tm+"/ad";
	RESTRequest4->Execute();
	rt = RESTResponse4->Content;
	ShowMessage(rt);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::returnbtnClick(TObject *Sender)
{
    Form8->Hide();
}
//---------------------------------------------------------------------------

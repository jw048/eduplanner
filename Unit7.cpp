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
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::startbtnClick(TObject *Sender)
{
	String coursename, n, grades, scale, all_gpa[1000]={}, rt_courses, all_courses[1000]={};
	int avg_grade =0, check, total =0, i=0, num_courses = 0;
	n = Form4->name;
	RESTClient2->BaseURL = "http://127.0.0.1:8000/courses/"+n;
	RESTRequest2->Execute();
	rt_courses = RESTResponse2->Content;
	check = rt_courses.Pos('"');
	while(check > 0) {
		rt_courses = rt_courses.Delete(1,check);
		check = rt_courses.Pos('"');
		all_courses[total] = rt_courses.SubString(1,check-1);
		rt_courses = rt_courses.Delete(1,check);
		check = rt_courses.Pos('"');
		total++;
	}
	for (i = 0; i < total; i++) {
		coursename = all_courses[i];
		RESTClient1->BaseURL = "http://127.0.0.1:8000/tot_gpa/"+Form4->name+"/"+coursename+"/yes";
		RESTRequest1->Execute();
		scale = RESTResponse1->Content;
		RESTClient1->BaseURL = "http://127.0.0.1:8000/tot_gpa/"+Form4->name+"/"+coursename+"/no";
		RESTRequest1->Execute();
		grades = RESTResponse1->Content;
		if (grades != "false") {
			check = scale.Pos('"');
			scale = scale.Delete(1,check);
			check = scale.Pos('"');
			scale = scale.SubString(1,check-1);
			gradesmemo->Lines->Add("course: " + coursename);
			gradesmemo->Lines->Add("grade: " + grades + " ( " + scale + " )");
			gradesmemo->Lines->Add("");
		}
		if (scale == "*Warning*") {
			RESTClient3->BaseURL = "http://127.0.0.1:8000/warningemail/"+n+"/"+grades+"/"+coursename;
			RESTRequest3->Execute();
			ShowMessage("Warning Email sent - "+coursename+" ( "+grades+" )");
			w++;
		}
		if (scale == "*Danger; meeting with counselor required*") {
			RESTClient3->BaseURL = "http://127.0.0.1:8000/dangeremail/"+n+"/"+grades+"/"+coursename;
			RESTRequest3->Execute();
			ShowMessage("GPA 'Danger'level notification Email sent - "+coursename+" ( "+grades+" )");
			d++;
		}
	}
	warning->Caption = w;
	danger->Caption = d;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::mtbtnClick(TObject *Sender)
{
    Form8->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::homebtnClick(TObject *Sender)
{
	Form7->Hide();
}
//---------------------------------------------------------------------------

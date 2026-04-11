//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit6.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int totalCredits;
int summerTotal;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
    isUpdating = false;

	// reset all ComboBoxes
	for (int i = 0; i < ComponentCount; i++)
	{
		TComboBox *cb = dynamic_cast<TComboBox*>(Components[i]);
		if (cb)
			cb->ItemIndex = -1;
	}

	Label3->Caption = "0";
}
//---------------------------------------------------------------------------
int TForm3::GetCredits(String course)
{
	if (course == "" || course.Pos("Optional"))
		return 0;

	if (course.Pos("A year"))
		return 2;

	return 1;
}
void TForm3::UpdateSummerCredits()
{
	String c1 = ComboBox1->Text;
	String c2 = ComboBox2->Text;

	// Check if either is a year course
	bool isYear1 = c1.Pos("A year");
	bool isYear2 = c2.Pos("A year");

	// Sync year course text
	if (isYear1)
		ComboBox2->Text = c1;
	else if (isYear2)
		ComboBox1->Text = c2;

	// Assign 1 credit per semester if year course, else normal
	int credit1 = 0;
	int credit2 = 0;

	if (isYear1 || isYear2)
	{
		credit1 = 1;
		credit2 = 1;
	}
	else
	{
		credit1 = GetCredits(c1); // 0 or 1
		credit2 = GetCredits(c2); // 0 or 1
	}

	// Update labels
	Label11->Caption = IntToStr(credit1);
	Label12->Caption = IntToStr(credit2);

	// Total credits = sum of both
    totalCredits = credit1 + credit2;

	// Summer total = number of courses selected
	summerTotal = 0;
	if (credit1 > 0) summerTotal++;
	if (credit2 > 0) summerTotal++;

	Label14->Caption = IntToStr(summerTotal);
	Label3->Caption  = FloatToStr(totalCredits);
}

void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{

	UpdateSummerCredits();
}
void __fastcall TForm3::ComboBox2Change(TObject *Sender)
{
	UpdateSummerCredits();
}




//---------------------------------------------------------------------------

bool TForm3::IsRealSelection(TComboBox* cb)
{
	return cb->ItemIndex >= 0 &&
		   cb->Text != "" &&
		   cb->Text != "Choose Class" &&
		   cb->Text != "<- Select subject" &&
		   cb->Text != "Select Subjects";
}

int TForm3::GetSemesterCredit(String course)
{

	if (course == "" || course.Pos("Optional"))
		return 0;

	return 1;

}

// returns 1 or 1.5 for AP courses
double TForm3::GetAPCredit(String course)
{
	if (course.Pos("AP"))
		return 1.5;
	if (course == "" || course.Pos("Optional"))
		return 0;
	return 1;
}

// Recalculate ALL labels and totalCredits
void TForm3::UpdateAllCredits()
{
	 if (isUpdating) return;
    isUpdating = true;

	totalCredits = 0;

	// -------- ComboBox5 & 6 --------
    int credit5 = IsRealSelection(ComboBox5) ? 1 : 0;
	int credit6 = IsRealSelection(ComboBox6) ? 1 : 0;

    Label21->Caption = IntToStr(credit5);
    Label22->Caption = IntToStr(credit6);

    totalCredits += credit5 + credit6;

	// -------- ComboBox7 & 8 (AP) --------
	double credit7 = IsRealSelection(ComboBox7) ? GetAPCredit(ComboBox7->Text) : 0;
	double credit8 = IsRealSelection(ComboBox8) ? GetAPCredit(ComboBox8->Text) : 0;

	Label23->Caption = FormatFloat("0.0", credit7);
	Label24->Caption = FormatFloat("0.0", credit8);

    totalCredits += credit7 + credit8;

	// -------- ComboBox3,4,12 --------
    int credit9  = IsRealSelection(ComboBox3)  ? 1 : 0;
    int credit10 = IsRealSelection(ComboBox4)  ? 1 : 0;
	int credit11 = IsRealSelection(ComboBox12) ? 1 : 0;

    Label27->Caption = IntToStr(credit9);
    Label40->Caption = IntToStr(credit10);
    Label26->Caption = IntToStr(credit11);

	totalCredits += credit9 + credit10 + credit11;

	// -------- Regular 1-credit classes --------
	int c17 = IsRealSelection(ComboBox17) ? 1 : 0;
	int c18 = IsRealSelection(ComboBox18) ? 1 : 0;
	int c23 = IsRealSelection(ComboBox23) ? 1 : 0;
	int c24 = IsRealSelection(ComboBox24) ? 1 : 0;
    int c25 = IsRealSelection(ComboBox25) ? 1 : 0;

    Label33->Caption = IntToStr(c17);
    Label34->Caption = IntToStr(c18);
    Label37->Caption = IntToStr(c23);
	Label39->Caption = IntToStr(c24);
    Label41->Caption = IntToStr(c25);

    totalCredits += c17 + c18 + c23 + c24 + c25;

	// -------- AP classes (1.0 or 1.5) --------
	double c19 = IsRealSelection(ComboBox19) ? GetAPCredit(ComboBox19->Text) : 0;
	double c20 = IsRealSelection(ComboBox20) ? GetAPCredit(ComboBox20->Text) : 0;

	Label36->Caption = FormatFloat("0.0", c19);
	Label25->Caption = FormatFloat("0.0", c20);

	totalCredits += c19 + c20;

	// -------- TOTAL --------
	Label3->Caption = FormatFloat("0.0", totalCredits);

	isUpdating = false;
}


void __fastcall TForm3::ComboBox5Change(TObject *Sender)
{
	UpdateAllCredits();
}
void __fastcall TForm3::ComboBox6Change(TObject *Sender)
{
	UpdateAllCredits();
}
void __fastcall TForm3::ComboBox7Change(TObject *Sender)
{
	UpdateAllCredits();
}
void __fastcall TForm3::ComboBox8Change(TObject *Sender)
{
	UpdateAllCredits();
}
void __fastcall TForm3::ComboBox12Change(TObject *Sender)
{

	ComboBox9->Items->Clear();  // clear previous items

	if (ComboBox12->Text == "World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox9->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox9->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox9->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			ComboBox9->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Study Hall")
	{
		ComboBox9->Items->Add("Study Hall");
		ComboBox9->Items->Add("Free Period");
	}

	UpdateAllCredits();  // recalc credits after selection
}
void __fastcall TForm3::ComboBox3Change(TObject *Sender)
{

	ComboBox10->Items->Clear();  // clear previous items

	if (ComboBox3->Text == "World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox10->Items->Add(arr[i]);
	}
	else if (ComboBox3->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox10->Items->Add(arr[i]);
	}
	else if (ComboBox3->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox10->Items->Add(arr[i]);
	}
	else if (ComboBox3->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			ComboBox10->Items->Add(arr[i]);
	}
	else if (ComboBox3->Text == "Study Hall")
	{
		ComboBox10->Items->Add("Study Hall");
		ComboBox10->Items->Add("Free Period");
	}

	UpdateAllCredits();
}
void __fastcall TForm3::ComboBox4Change(TObject *Sender)
{
	 ComboBox11->Items->Clear();

	if (ComboBox4->Text == "World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox11->Items->Add(arr[i]);
	}
	else if (ComboBox4->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox11->Items->Add(arr[i]);
	}
	else if (ComboBox4->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox11->Items->Add(arr[i]);
	}
	else if (ComboBox4->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			ComboBox11->Items->Add(arr[i]);
	}
	else if (ComboBox4->Text == "Study Hall")
	{
		ComboBox11->Items->Add("Study Hall");
		ComboBox11->Items->Add("Free Period");
	}

	UpdateAllCredits();  // recalc credits after selection
}
void __fastcall TForm3::ComboBox21Change(TObject *Sender)
{
	UpdateAllCredits();
}

void __fastcall TForm3::ComboBox9Change(TObject *Sender)
{
	UpdateAllCredits();
}

void __fastcall TForm3::ComboBox16Change(TObject *Sender)
{
	ComboBox23->Items->Clear();  // clear previous items

	if (ComboBox16->Text == "World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox23->Items->Add(arr[i]);
	}
	else if (ComboBox16->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox23->Items->Add(arr[i]);
	}
	else if (ComboBox16->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox23->Items->Add(arr[i]);
	}
	else if (ComboBox16->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			ComboBox23->Items->Add(arr[i]);
	}
	else if (ComboBox16->Text == "Study Hall")
	{
		ComboBox23->Items->Add("Study Hall");
		ComboBox23->Items->Add("Free Period");
	}

	UpdateAllCredits();  // recalc credits after selection
}
void __fastcall TForm3::ComboBox13Change(TObject *Sender)
{
	ComboBox24->Items->Clear();  // clear previous items

	if (ComboBox13->Text == "World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox24->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox24->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox24->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			ComboBox24->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Study Hall")
	{
		ComboBox24->Items->Add("Study Hall");
		ComboBox24->Items->Add("Free Period");
	}

	UpdateAllCredits();  // recalc credits after selection
}
void __fastcall TForm3::ComboBox14Change(TObject *Sender)
{
	ComboBox25->Items->Clear();  // clear previous items

	if (ComboBox14->Text == "World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox25->Items->Add(arr[i]);
	}
	else if (ComboBox14->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox25->Items->Add(arr[i]);
	}
	else if (ComboBox14->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox25->Items->Add(arr[i]);
	}
	else if (ComboBox14->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			ComboBox25->Items->Add(arr[i]);
	}
	else if (ComboBox14->Text == "Study Hall")
	{
		ComboBox25->Items->Add("Study Hall");
		ComboBox25->Items->Add("Free Period");
	}

	UpdateAllCredits();  // recalc credits after selection
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ComboBox17Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ComboBox18Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ComboBox19Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ComboBox20Change(TObject *Sender)
{
	UpdateAllCredits();
}
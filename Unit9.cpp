//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit6.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
int totalCredits1;
int summerTotal1;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
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
	Label11->Caption = "0";
	Label12->Caption = "0";
	Label14->Caption = "0";
}
//---------------------------------------------------------------------------

int TForm9::GetCredits(String course)
{
	if (course == "" || course.Pos("Optional"))
		return 0;

	if (course.Pos("A year"))
		return 2;

	return 1;
}
void TForm9::UpdateSummerCredits()
{
if (isUpdating) return;
isUpdating = true;

// Read selections
String c1 = ComboBox1->Text;
String c2 = ComboBox2->Text;

// Detect year courses
bool isYear1 = c1.Pos("A year") > 0;
bool isYear2 = c2.Pos("A year") > 0;

// Sync year courses ONLY if one is a year course AND the other is empty
if (isYear1 && !isYear2)
    ComboBox2->Text = c1;  // now ComboBox2 mirrors ComboBox1
else if (isYear2 && !isYear1)
    ComboBox1->Text = c2;  // now ComboBox1 mirrors ComboBox2

// Re-read after sync
c1 = ComboBox1->Text;
c2 = ComboBox2->Text;

isYear1 = c1.Pos("A year") > 0;
isYear2 = c2.Pos("A year") > 0;

// Compute individual credits
int credit1 = 0;
int credit2 = 0;

// Only assign 1 credit to year course if both boxes are filled
if (isYear1 && isYear2)
{
    credit1 = 1;
    credit2 = 1;
}
else
{
    // Normal courses
    credit1 = (c1 != "" && !isYear1) ? GetCredits(c1) : 0;
    credit2 = (c2 != "" && !isYear2) ? GetCredits(c2) : 0;
}

// Update labels individually
Label11->Caption = IntToStr(credit1);
Label12->Caption = IntToStr(credit2);

// Update totals
totalCredits1 = credit1 + credit2;
Label3->Caption = IntToStr(totalCredits1);

// Summer total = count of selected courses
summerTotal1 = 0;
if (credit1 > 0) summerTotal1++;
if (credit2 > 0) summerTotal1++;
Label14->Caption = IntToStr(summerTotal1);

isUpdating = false;
}
//---------------------------------------------------------------------------




bool TForm9::IsRealSelection(TComboBox* cb)
{
	return cb->ItemIndex >= 0 &&
		   cb->Text != "" &&
		   cb->Text != "Choose Class" &&
		   cb->Text != "<- Select subject" &&
		   cb->Text != "Select Subjects";
}

int TForm9::GetSemesterCredit(String course)
{

	if (course == "" || course.Pos("Optional"))
		return 0;

	return 1;

}

// Recalculate ALL labels and totalCredits1
void TForm9::UpdateAllCredits()
{
	if (isUpdating) return;
	isUpdating = true;

	totalCredits1 = 0;

	int c5  = IsRealSelection(ComboBox5)  ? 1 : 0;
	int c6  = IsRealSelection(ComboBox6)  ? 1 : 0;
	int c7  = IsRealSelection(ComboBox7)  ? 1 : 0;
	int c8  = IsRealSelection(ComboBox8)  ? 1 : 0;
	int c9  = IsRealSelection(ComboBox9)  ? 1 : 0;
	int c10 = IsRealSelection(ComboBox3)? 1 : 0;
	int c11 = IsRealSelection(ComboBox4)? 1 : 0;

	Label21->Caption = IntToStr(c5);
	Label22->Caption = IntToStr(c6);
	Label23->Caption = IntToStr(c7);
	Label24->Caption = IntToStr(c8);
	Label25->Caption = IntToStr(c9);
	Label27->Caption = IntToStr(c10);
	Label40->Caption = IntToStr(c11);
    int c12 = IsRealSelection(ComboBox12) ? 1 : 0;
    int c13 = IsRealSelection(ComboBox13) ? 1 : 0;
    int c14 = IsRealSelection(ComboBox14) ? 1 : 0;
    int c15 = IsRealSelection(ComboBox15) ? 1 : 0;
    int c16 = IsRealSelection(ComboBox16) ? 1 : 0;
    int c17 = IsRealSelection(ComboBox17) ? 1 : 0;
    int c18 = IsRealSelection(ComboBox18) ? 1 : 0;

    // -------- Update labels --------
    Label37->Caption = IntToStr(c12);
    Label38->Caption = IntToStr(c13);
    Label20->Caption = IntToStr(c14);
    Label32->Caption = IntToStr(c15);
    Label34->Caption = IntToStr(c16);
    Label33->Caption = IntToStr(c17);
    Label36->Caption = IntToStr(c18);

    // -------- Calculate total --------
    totalCredits1 += c12 + c13 + c14 + c15 + c16 + c17 + c18;

	totalCredits1 += c5 + c6 + c7 + c8 + c9 + c10 + c11;

	Label3->Caption = IntToStr(totalCredits1);

	isUpdating = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox1Change(TObject *Sender)
{
	UpdateSummerCredits();
}

//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox2Change(TObject *Sender)
{
	UpdateSummerCredits();
}


void __fastcall TForm9::ComboBox5Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox6Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox7Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox8Change(TObject *Sender)
{
    UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox9Change(TObject *Sender)
{
	UpdateAllCredits();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ComboBox3Change(TObject *Sender)
{
	ComboBox10->Items->Clear(); // ? clear old items

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

    ComboBox10->ItemIndex = -1; // ? reset selection
	UpdateAllCredits();
}
void __fastcall TForm9::ComboBox4Change(TObject *Sender)
{

		ComboBox11->Items->Clear();
		if (ComboBox4->Text=="World Language")
		{
			String arr[5] = {"Spanish","Chinese","Latin","French","German"};
			for(int i = 0; i < 5; i++)
				ComboBox11->Items->Add(arr[i]);
		}
		else if (ComboBox3->Text == "Business")
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


		UpdateAllCredits();
}



void __fastcall TForm9::ComboBox14Change(TObject *Sender)
{
   UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox15Change(TObject *Sender)
{
    UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox16Change(TObject *Sender)
{
    UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox17Change(TObject *Sender)
{
    UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox18Change(TObject *Sender)
{
    UpdateAllCredits();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox12Change(TObject *Sender)
{
	ComboBox19->Items->Clear();
	if (ComboBox12->Text=="World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox19->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox19->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox19->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			 ComboBox19->Items->Add(arr[i]);
	}
	else if (ComboBox12->Text == "Study Hall")
	{
		ComboBox19->Items->Add("Study Hall");
		ComboBox19->Items->Add("Free Period");
	}


	UpdateAllCredits();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ComboBox13Change(TObject *Sender)
{
	ComboBox20->Items->Clear();
	if (ComboBox13->Text=="World Language")
	{
		String arr[5] = {"Spanish","Chinese","Latin","French","German"};
		for(int i = 0; i < 5; i++)
			ComboBox20->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Business")
	{
		String arr[3] = {"Business 1","Business 2","Business Technology"};
		for(int i = 0; i < 3; i++)
			ComboBox20->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Computer Science")
	{
		String arr[2] = {"Computer Programming 1","AP Computer Programming"};
		for(int i = 0; i < 2; i++)
			ComboBox20->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Music")
	{
		String arr[4] = {"Band","Orchestra","Piano","Guitar"};
		for(int i = 0; i < 4; i++)
			 ComboBox20->Items->Add(arr[i]);
	}
	else if (ComboBox13->Text == "Study Hall")
	{
		ComboBox20->Items->Add("Study Hall");
		ComboBox20->Items->Add("Free Period");
	}


	UpdateAllCredits();
}

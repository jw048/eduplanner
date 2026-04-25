//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label5;
	TLabel *Label9;
	TLabel *Label15;
	TGroupBox *GroupBox1;
	TLabel *Label8;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TGroupBox *GroupBox2;
	TLabel *Label16;
	TGroupBox *GroupBox3;
	TLabel *Label17;
	TGroupBox *GroupBox4;
	TLabel *Label18;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TGroupBox *GroupBox5;
	TLabel *Label19;
	TComboBox *ComboBox5;
	TComboBox *ComboBox6;
	TComboBox *ComboBox7;
	TComboBox *ComboBox8;
	TComboBox *ComboBox9;
	TComboBox *ComboBox10;
	TComboBox *ComboBox11;
	TGroupBox *GroupBox10;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label24;
	TLabel *Label23;
	TLabel *Label26;
	TLabel *Label25;
	TLabel *Label27;
	TLabel *Label40;
	TGroupBox *GroupBox6;
	TLabel *Label28;
	TGroupBox *GroupBox7;
	TLabel *Label29;
	TGroupBox *GroupBox8;
	TLabel *Label30;
	TComboBox *ComboBox12;
	TComboBox *ComboBox13;
	TGroupBox *GroupBox9;
	TLabel *Label31;
	TComboBox *ComboBox14;
	TComboBox *ComboBox15;
	TComboBox *ComboBox16;
	TComboBox *ComboBox17;
	TComboBox *ComboBox18;
	TComboBox *ComboBox19;
	TComboBox *ComboBox20;
	TGroupBox *GroupBox11;
	TLabel *Label20;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall ComboBox4Change(TObject *Sender);
	void __fastcall ComboBox5Change(TObject *Sender);
	void __fastcall ComboBox6Change(TObject *Sender);
	void __fastcall ComboBox7Change(TObject *Sender);
	void __fastcall ComboBox8Change(TObject *Sender);
	void __fastcall ComboBox9Change(TObject *Sender);
	void __fastcall ComboBox12Change(TObject *Sender);
	void __fastcall ComboBox13Change(TObject *Sender);
	void __fastcall ComboBox14Change(TObject *Sender);
	void __fastcall ComboBox15Change(TObject *Sender);
	void __fastcall ComboBox16Change(TObject *Sender);
	void __fastcall ComboBox17Change(TObject *Sender);
	void __fastcall ComboBox18Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	int summerCredit;
	int summerTotal;

	bool isUpdating;

	bool IsRealSelection(TComboBox* cb);
	int GetSemesterCredit(String course);
	void UpdateAllCredits();
	int GetCredits(String course);
	void UpdateSummerCredits();
	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif

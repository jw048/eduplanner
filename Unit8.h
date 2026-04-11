//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <REST.Client.hpp>
#include <REST.Response.Adapter.hpp>
#include <REST.Types.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TMonthCalendar *schecalendar;
	TListBox *mtnglist;
	TButton *schedulebtn;
	TMemo *scheduledmm;
	TButton *returnbtn;
	TButton *dateselectbtn;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter1;
	TFDMemTable *FDMemTable1;
	TRESTClient *RESTClient2;
	TRESTRequest *RESTRequest2;
	TRESTResponse *RESTResponse2;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter2;
	TFDMemTable *FDMemTable2;
	TRESTClient *RESTClient3;
	TRESTRequest *RESTRequest3;
	TRESTResponse *RESTResponse3;
	TRESTClient *RESTClient4;
	TRESTRequest *RESTRequest4;
	TRESTResponse *RESTResponse4;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter3;
	TFDMemTable *FDMemTable3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall dateselectbtnClick(TObject *Sender);
	void __fastcall schedulebtnClick(TObject *Sender);
	void __fastcall returnbtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
	String adname[1000]={}, dte, aviltme[1000]={};
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif

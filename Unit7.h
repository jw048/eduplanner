//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
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
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TMemo *gradesmemo;
	TButton *startbtn;
	TButton *mtbtn;
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
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter3;
	TFDMemTable *FDMemTable3;
	TRESTClient *RESTClient4;
	TRESTRequest *RESTRequest4;
	TRESTResponse *RESTResponse4;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter4;
	TFDMemTable *FDMemTable4;
	TLabel *warningconst;
	TLabel *dangerconst;
	TLabel *warning;
	TLabel *danger;
	TButton *homebtn;
	void __fastcall startbtnClick(TObject *Sender);
	void __fastcall mtbtnClick(TObject *Sender);
	void __fastcall homebtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
    int w = 0, d = 0;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif

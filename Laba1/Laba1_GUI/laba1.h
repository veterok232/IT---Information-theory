//---------------------------------------------------------------------------

#ifndef laba1H
#define laba1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TMemo *sourceMessageField;
	TMemo *resultMessageField;
	TMemo *keyField;
	TComboBox *cboxSelectMethod;
	TLabel *lbl1;
	TButton *btnStart;
	TLabel *lbl2;
	TLabel *Label1;
	TRadioButton *rbtnEncrypt;
	TRadioButton *rbtnDecrypt;
	void __fastcall btnStartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif

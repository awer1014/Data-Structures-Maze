//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TButton *Button3;
	TButton *Button4;
	TGroupBox *GroupBox2;
	TOpenDialog *OpenDialog1;
	TGroupBox *GroupBox3;
	TEdit *Edit3;
	TLabel *Label3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TTabSheet *TabSheet5;
	TStringGrid *StringGrid1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

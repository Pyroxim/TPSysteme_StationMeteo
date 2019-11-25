//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "SM9111.h"
#include <Vcl.ExtCtrls.hpp>
#include "mysql.h"
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Button1;
	TLabel *Label1;
	TTimer *Timer1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *LabelTemp;
	TLabel *LabelHumid;
	TLabel *LabelPluie;
	TLabel *LabelBDD;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private: 	// Déclarations utilisateur
	SM9111 *carteMeteo;

	MYSQL *mySQL;
	MYSQL_STMT *stmt;
	MYSQL_BIND bind[3];
	bool is_null;
	int temp_data;
	float humid_data;
    bool pluie_data;

	int IDCarte;
	int valHumid;
	int valTemp;
	bool pluie;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

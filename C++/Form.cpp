//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form.h"
#include "SM9111.h"
#include <iostream>
#include <string>
#include <sstream>

#define INSERT_SAMPLE "INSERT INTO \
                       test_table(col1,col2,col3) \
                       VALUES(?,?,?)"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//--------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	carteMeteo = new(SM9111);

	IDCarte = -1;

	mySQL = mysql_init(NULL);

	if(!mysql_real_connect(mySQL, "192.168.64.130", "applicpp", "applicpp", "TPMeteo", 0, NULL, 0))
	{
		LabelBDD->Caption = "Connexion � la BDD �chou�e";
	}
	else
	{
		LabelBDD->Caption = "Connexion � la BDD r�ussie";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	IDCarte = carteMeteo->Initialisation(); 	//La fonction Initialisation renvoie l'ID de la carte

	if(IDCarte == -1)   //On teste donc si une carte a �t� trouv�e
		Label1->Color = clRed;
	else
	{
		Label1->Color = clGreen;
		Timer1->Enabled = True;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)    //La fonction du timer r�cup�re les valeurs de chaque capteur toutes les secondes, et actualise les labels sur l'interface
{
	valTemp = carteMeteo->AcquisitionTemp() * 7 - 35;   //On calcule la valeur physique de temp�rature avec la valeur analogique r�cup�r�e
	LabelTemp->Caption = valTemp;

	valHumid = carteMeteo->AcquisitionHumid() * 10;     //On fait de m�me avec le taux d'humidit�
	LabelHumid->Caption = valHumid;

	pluie = carteMeteo->TestPluie();	//On r�cup�re le bool�en renvoy� par TestPluie()

	if(pluie)   // Et on fait un test if...else
	{
		LabelPluie->Caption = "IL PLEUT";
	}
	else
	{
		LabelPluie->Caption = "IL PLEUT PAS";
	}

	/*stmt = mysql_stmt_init(mySQL);

	mysql_stmt_prepare(stmt, INSERT_SAMPLE, strlen(INSERT_SAMPLE));

	fprintf(stdout, " prepare, INSERT r�ussi\n");
	memset(bind, 0, sizeof(bind));

	bind[0].buffer_type = MYSQL_TYPE_INT;
	bind[0].buffer = (char *)&temp_data;
	bind[0].is_null = 0;
	bind[0].length = 0;

	bind[1].buffer_type = MYSQL_TYPE_FLOAT;
	bind[1].buffer = (char *)&humid_data;
	bind[1].is_null = 0;
	bind[1].length = 0;

	bind[2].buffer_type = MYSQL_TYPE_SHORT;
	bind[2].buffer = (char *)&pluie_data;
	bind[2].is_null = &test_pluie;
	bind[2].length = 0;

	mysql_stmt_bind_param(stmt, bind);

	temp_data = valTemp;
	humid_data = humidTemp;
	is_null= 1;

	mysql_stmt_execute(stmt); */

	std::ostreamstring query;

}
//---------------------------------------------------------------------------



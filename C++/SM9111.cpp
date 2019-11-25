//---------------------------------------------------------------------------
#pragma hdrstop

#include <fmx.h>
#include "SM9111.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

SM9111::SM9111()
{

}

SM9111::~SM9111()
{

}

int SM9111::Initialisation()    //Initialisation de la connection avec la carte 9111
{
	IDCarte = Register_Card(PCI_9111DG,0);

	AI_9111_Config(this->IDCarte,TRIG_INT_PACER,P9111_TRGMOD_SOFT,0);
	AO_9111_Config(this->IDCarte,P9111_AO_UNIPOLAR);

	return this->IDCarte;
}

float SM9111::AcquisitionTemp() //Fonction test du capteur de température, récupération d'une valeur analogique dans un float
{
	AI_VReadChannel(this->IDCarte,3,AD_B_10_V,&this->ValTemp);

	return this->ValTemp;
}

float SM9111::AcquisitionHumid()    //Fonction test du capteur d'humidité, récupération d'une valeur analogique dans un float
{
	AI_VReadChannel(this->IDCarte,4,AD_B_10_V,&this->ValHumid);

	return this->ValHumid;
}

bool SM9111::TestPluie()    //Fonction test du détecteur de pluie
{
	AI_VReadChannel(this->IDCarte,7,AD_B_10_V,&this->ValPluie);

	if(this->ValPluie == 10)    //Renvoie un booléen car le signal de sortie du capteur est 0 ou 1
	{
		return true;
	}
	else
	{
		return false;
	}
}

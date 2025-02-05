#ifndef OPM
#define OPM 0

#include "CException.h"
#include "CMatrice.h"

template <typename MType> class CMatrice;
class COperationMatrice
{
public :
	/*********************************************************
	Calcul la transpos� de la matrice
	*********************************************************/
	template<class MType> static CMatrice<MType>& OPMTranspose(CMatrice<MType>& MATMatrice);

	template<class MType> static CMatrice<MType>& OPMExtraireMatrice1(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne);

	template<class MType> static CMatrice<MType>& OPMExtraireMatrice2(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne);
	
	template<class MType> static CMatrice<MType>* OPMExtraireMatriceCarree(CMatrice<MType>& MATMatrice, int iDimension);
};
#endif //OPM

/*********************************************************
Calcul la transpos� de la matrice
*********************************************************
Entr�e: (rien)
N�cessite: (la matrice doit contenir des �l�ments)
Sortie: CMatrice<MType> : la tranpos� de la matrice
Entra�ne : (la matrice en sortie est la tranpos� de la matrice sur laquelle on travaille)
*********************************************************/
template <class MType>
CMatrice<MType>& COperationMatrice::OPMTranspose(CMatrice<MType>& MATMatrice)
{
	// Cas matrice carr� : uiMATNbLigne == uiMATNbColonne
	if (MATMatrice.MATLireNombreColonne() == MATMatrice.MATLireNombreLigne())
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATMatrice.MATLireNombreLigne(), MATMatrice.MATLireNombreColonne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= MATMatrice.MATLireNombreColonne(); uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= MATMatrice.MATLireNombreLigne(); uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carr� : uiMATNbLigne < uiMATNbColonne
	else if (MATMatrice.MATLireNombreColonne() > MATMatrice.MATLireNombreLigne())
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATMatrice.MATLireNombreColonne(), MATMatrice.MATLireNombreLigne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= MATMatrice.MATLireNombreLigne(); uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= MATMatrice.MATLireNombreColonne(); uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carr� : uiMATNbLigne > uiMATNbColonne
	else
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATMatrice.MATLireNombreColonne(), MATMatrice.MATLireNombreLigne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= MATMatrice.MATLireNombreLigne(); uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= MATMatrice.MATLireNombreColonne(); uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
}

/*********************************************************
Extrait une sous-matrice de la matrice pass� en param�tre
*********************************************************
Entr�e: 
CMatrice<MType>& MATMatrice : la matrice dont on va extraire la sous matrice
int iIndiceLigne : indice de la ligne de l'�l�ment en haut � gauche de la sous matrice
int iIndiceColonne : indice de la colonne de l'�l�ment en haut � gauche de la sous matrice
int iNombreLigne : nombre de ligne de la sous matrice
int iNombreColonne : nombre de colonne de la sous matrice
N�cessite: (rien)
Sortie: CMatrice<MType> : la sous matrice de dimension iNombreLigne*iNombreColonne de la matrice MATMatrice
Entra�ne : (renvoie une sous matrice) ou
(Exception dimension_incorrecte est lev�)
*********************************************************/
template <class MType>
CMatrice<MType>& COperationMatrice::OPMExtraireMatrice1(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne)
{
	//test notre de lignes/colones choisis
	if (iNombreLigne <= 0 || iNombreColonne <= 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Test si on est bien dans la matrice
	if (iIndiceLigne <= 0 || iIndiceLigne > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}
	
	
	if (iIndiceColonne <= 0 || iIndiceColonne > int(MATMatrice.MATLireNombreColonne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// on v�rifie que la sous matrice ne d�passe pas
	if ((iIndiceColonne + iNombreColonne - 1) > int(MATMatrice.MATLireNombreColonne()) || (iIndiceLigne + iNombreLigne - 1) > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	CMatrice<MType>* pMATSousMatrice = new CMatrice<MType>(iNombreLigne, iNombreColonne);
	int iBoucleLigne = 1;
	for (int iBoucleIndiceLigne = iIndiceLigne; iBoucleIndiceLigne < iIndiceLigne + iNombreLigne; iBoucleIndiceLigne++, iBoucleLigne++)
	{
		int iBoucleColonne = 1;
		for (int iBoucleIndiceColonne = iIndiceColonne; iBoucleIndiceColonne < iIndiceColonne + iNombreColonne; iBoucleIndiceColonne++, iBoucleColonne++)
		{
			pMATSousMatrice->MATModifierElement(iBoucleLigne, iBoucleColonne, MATMatrice.MATLireElement(iBoucleIndiceLigne, iBoucleIndiceColonne));
		}
	}

	return *pMATSousMatrice;
}

/*********************************************************
Extrait une sous-matrice de la matrice pass� en param�tre
*********************************************************
Entr�e:
CMatrice<MType>& MATMatrice : la matrice dont on va extraire la sous matrice
int iIndiceLigne : indice de la ligne de l'�l�ment de d�part pour cr�er la sous matrice
int iIndiceColonne : indice de la colonne de l'�l�ment de d�part pour cr�er la sous matrice
int iNombreLigne : nombre de ligne de la sous matrice
int iNombreColonne : nombre de colonne de la sous matrice
N�cessite: (rien)
Sortie: CMatrice<MType> : la sous matrice de dimension iNombreLigne*iNombreColonne de la matrice MATMatrice
Entra�ne : (renvoie une sous matrice) ou
(Exception dimension_incorrecte est lev�)
*********************************************************/
template <class MType>
CMatrice<MType>& COperationMatrice::OPMExtraireMatrice2(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne)
{
	//test si les dimensions sont valides
	if (iNombreLigne <= 0 || iNombreColonne <= 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Test si on est bien dans la matrice
	///on regarde si i est dans la matrice
	if (iIndiceLigne <= 0 || iIndiceLigne > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	///test de n' <= n/2 et m'<=m/2
	if (iNombreLigne > (int(MATMatrice.MATLireNombreLigne())) / 2 && iNombreColonne > (int(MATMatrice.MATLireNombreColonne())) / 2)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	///on regarde si j est dans la matrice
	if (iIndiceColonne <= 0 || iIndiceColonne > int(MATMatrice.MATLireNombreColonne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// on v�rifie que la sous matrice ne d�passe pas
	///i+n' <= n et j+m' <= m
	if ((iIndiceColonne + iNombreColonne - 1) > int(MATMatrice.MATLireNombreColonne()) || (iIndiceLigne + iNombreLigne - 1) > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	//condition sur i et j
	/// i>= n' et j>=m'
	if (iIndiceLigne <= iNombreLigne && iIndiceColonne <= iNombreColonne)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	CMatrice<MType>* pMATSousMatrice = new CMatrice<MType>(iNombreLigne, iNombreColonne);
	int iBoucleLigne = 1;
	for (int iBoucleIndiceLigne = iIndiceLigne - iNombreLigne; iBoucleIndiceLigne < iIndiceLigne + iNombreLigne; iBoucleIndiceLigne++, iBoucleLigne++)
	{
		int iBoucleColonne = 1;
		for (int iBoucleIndiceColonne = iIndiceColonne - iNombreColonne; iBoucleIndiceColonne < iIndiceColonne + iNombreColonne; iBoucleIndiceColonne++, iBoucleColonne++)
		{
			pMATSousMatrice->MATModifierElement(iBoucleLigne, iBoucleColonne, MATMatrice.MATLireElement(iBoucleIndiceLigne, iBoucleIndiceColonne));
		}
	}
	return *pMATSousMatrice;
}

/*********************************************************
Extrait une toutes sous-matrice carr� de dimension iDimension
de la matrice pass� en param�tre
*********************************************************
Entr�e:
CMatrice<MType>& MATMatrice : la matrice dont on va extraire les sous matrice
int iDimension : la taille des sous matrices carr�es � renvoyer
N�cessite: (rien)
Sortie: CMatrice<MType>* : la liste des sous matrice carr�e de dimension iDimension de la matrice MATMatrice
Entra�ne : (renvoie une liste de sous matrice) ou
(Exception dimension_incorrecte est lev�)
*********************************************************/
template<class MType> 
CMatrice<MType>* COperationMatrice::OPMExtraireMatriceCarree(CMatrice<MType>& MATMatrice, int iDimension)
{
	int iMinimum = (MATMatrice.MATLireNombreLigne() < MATMatrice.MATLireNombreColonne()) ? MATMatrice.MATLireNombreLigne() : MATMatrice.MATLireNombreColonne();

	if (iDimension > iMinimum)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	int iNbSousMatriceColonne = int(MATMatrice.MATLireNombreColonne()) - (iDimension - 1);
	int iNbSousMatriceLigne = int(MATMatrice.MATLireNombreLigne()) - (iDimension - 1);
	int iNbSousMatrice = iNbSousMatriceColonne * iNbSousMatriceLigne;

	CMatrice<MType>* pMATListSousMatrice = new CMatrice<MType>[iNbSousMatrice];

	int iTantQueListe = 0;

	while (iTantQueListe < iNbSousMatrice)
	{
		for (int iBoucleIndiceLigne = 1; iBoucleIndiceLigne <= iNbSousMatriceLigne; iBoucleIndiceLigne++)
		{
			for (int iBoucleIndiceColonne = 1; iBoucleIndiceColonne <= iNbSousMatriceColonne; iBoucleIndiceColonne++)
			{
				pMATListSousMatrice[iTantQueListe] = OPMExtraireMatrice1(MATMatrice, iBoucleIndiceLigne, iBoucleIndiceColonne, iDimension, iDimension);
				iTantQueListe++;
				//OPMExtraireMatrice1(MATMatrice, iBoucleIndiceLigne, iBoucleIndiceColonne, iDimension, iDimension).MATAfficherMatrice();
			}
		}
	}

	return pMATListSousMatrice;
}
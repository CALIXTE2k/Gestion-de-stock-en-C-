//Bibliotheques

#include <iostream>
#include <string>
#include <vector>
#include "gestion.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <ctype.h>

using namespace std;

//definition de l'id
int gestion::last_id = 10012000;

//definition constructeur
gestion::gestion(int id, string nom, int quantite, float prix, string categorie, string date) : id(id), nom(nom), quantite(quantite), prix(prix), categorie(categorie), date(date) {}
vector<gestion> tableau;



//Definition des fonctions
void enregistrer()
{
char nb;

cout<<"Nb : Veuillez entrer un nombre positif.\n ";


cout<<"Saisisser le nombre de produit a enregistrer :\n";
cin>>nb;

cout<<"\n\n";
//condition
while(!isdigit(nb))
{
    cout<<" reesayer :\n";
    cin>>nb;

}

cout<<"\n\n";



//variables
        string  nom, categorie, date;
        int quantite;
        float prix;


for(int i=0;i<nb;i++)
{
    //incrementation de l'id
gestion::last_id++;
        int id = gestion::last_id;

    cout<<"ID : "<<id<<" \n\n";
    cout<<"Entrer le nom : \n";
    cin>>nom;


    cout<<"Entrer la categorie : \n";
    cin>>categorie;

    cout<<"Entrer la quantite : \n";
    cin>>quantite;

    cout<<"Entrer le prix :\n";
    cin>>prix;

    cout<<"Entrer la date : \n";
    cin>>date;

        tableau.push_back(gestion(id, nom, quantite, prix, categorie, date));
        cout<<"\n\n";
}

}




//fonction afficher
void afficher()
{
        cout<<"ID \t\t"<<"Nom \t"<<"Quantite \t"<<"Prix \t"<<"Categorie \t"<<"Date \t";
        cout<<"\n";
for(size_t i = 0; i < tableau.size(); i++)
{
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t\t"<<tableau[i].prix<<"\t"<<tableau[i].categorie<<"\t \t"<<tableau[i].date;
        cout<<"\n";
}
    }




    //fonction modifier
void modifier()
{
    string nom, categorie, date;
        int id, quantite, prix;
        cout<<"Entrez l' ID du produit a modifier : \n";
        cin>>id;
for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
    {
        cout<<"Entrez le nouveau nom : \n";
        cin>>tableau[i].nom;

        cout<<"Entrez la nouvelle quantite : \n";
        cin>>tableau[i].quantite;

        cout<<"Entrez le nouveau prix :\n";
        cin>>tableau[i].prix;

        cout<<"Entrez la nouvelle categorie : \n";
        cin>>tableau[i].categorie;

        cout<<"Entrez la nouvelle date : \n";
        cin>>tableau[i].date;
        return;
    }

}
cout<<"Produit non trouve \n";
}



//fonction supprimer
void supprimer()
{
int id;
        cout<<"Entrez l' ID du produit a effacer \n";
        cin>>id;
for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
    {
        tableau.erase(tableau.begin()+i);
        return;
    }
}
cout<<"Produit non trouve \n";
}



void entrepot()
{
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MENU ENTREPOT $$$$$$$$$$$$$$$$$$$$$$$$$$\n\n"
    <<"1- Presser [X] pour faire un depot. \n"
    <<"2- Presser [Y] pour faire un retrait. \n"
    <<"3- Presser [Z] pour quitter le menu entrepot. \n\n"
    <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
}



void depot()
{
    int id, qte;
    cout << "Entrez l' ID du produit pour le depot: \n";
    cin >> id;

    for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
        {
            cout << "Entrez la quantite a ajouter: \n";
            cin >> qte;

            if (qte < 0) {
                cout << "Erreur: la quantite doit etre positive. \n";
                return;
            }

            int new_qte = tableau[i].quantite + qte;

            if (new_qte > 1000)
    {
        cout << "Attention: le stock maximum est atteint. \n";
        tableau[i].quantite = new_qte;
    }
             else if (new_qte < 300)
    {
        cout << "Attention: le stock est inferieur a la limite minimale." << endl;
        tableau[i].quantite = new_qte;
    }        else
    {
        tableau[i].quantite = new_qte;
    }
        }

    }
    cout << "Produit non trouve \n";
}


void retrait()
{
    int id, qte;
    cout << "Entrez l' ID du produit pour le retrait : \n";
    cin >> id;

    for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
        {
            cout << "Entrez la quantite a retirer: \n";
            cin >> qte;

            if (tableau[i].quantite - qte <= 0) {
                cout << "Erreur: la quantite doit etre positive. \n";
                return;
            }

            int new_qte = tableau[i].quantite - qte;

            if (new_qte > 1000)
    {
        cout << "Attention: le stock maximum est atteint. \n";
    tableau[i].quantite = new_qte;
    }
             else if (new_qte < 300)
    {
        cout << "Attention: le stock est inferieur a la limite minimale." << endl;
        tableau[i].quantite = new_qte;
    }        else
    {
        tableau[i].quantite = new_qte;
    }
    }
    }
    cout << "Produit non trouve \n";
}


//pour la recherche des produits
void code()
{
    int id;
    cout << "Entrez l' ID du produit a rechercher : \n";
    cin >> id;
    cout<<"\n";
         for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
        {
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t"<<tableau[i].prix<<" \t"<<tableau[i].categorie<<" \t"<<tableau[i].date;
        cout<<"\n";
        return;
        }
    }
cout<<"Produit non trouve \n";
}


void categ()
{
    string categorie;
    cout << "Entrez la categorie du produit a rechercher: \n";
    cin >> categorie;
         for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].categorie == categorie)
        {
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t"<<tableau[i].prix<<" \t"<<tableau[i].categorie<<" \t"<<tableau[i].date;
        cout<<"\n";
        return;
        }
    }
//cout<<"Produit non trouve \n";
}


void dater()
{
    string date;
    cout << "Entrez la date du produit a rechercher: \n";
    cin >> date;
         for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].date == date)
        {
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t"<<tableau[i].prix<<" \t"<<tableau[i].categorie<<" \t"<<tableau[i].date;
        cout<<"\n";
        return;
        }
    }
//cout<<"Produit non trouve \n";
}



void recherche()
{
    cout<<"N.B : La recherche peut etre effectue par code,par categorie ou par date d'enregistrement.\n\n";
     cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MENU RECHERCHE $$$$$$$$$$$$$$$$$$$$$$$$$$\n\n"
    <<"1- Presser [M] pour rechercher par code \n"
    <<"2- Presser [N] pour rechercher par categorie \n"
    <<"3- Presser [S] pour rechercher par date \n"
    <<"4- Presser [T] pour quitter le menu. \n\n"
    <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
}



//fonction menu (programme)

void programme()
{


//variable
	char choix;

	//boucle
	do
    {

	//les options du menu (programme)
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MENU GESTION DE STOCK $$$$$$$$$$$$$$$$$$$$$$$$$$\n\n"
		<<"1- Presser [A] pour enregistrer un produit. \n"
		<<"2- Presser [B] pour modifier un produit. \n"
		<<"3- Presser [I] pour afficher.\n"
		<<"3- Presser [C] pour supprimer un produit. \n"
		<<"4- Presser [E] pour visiter l'entrepot. \n"
		<<"5- Presser [F] pour rechercher produits. \n"
		<<"6- Presser [H] pour quitter le programme. \n\n"
	    <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";

//le choix
cout<<"-- Faites votre choix:\n";
            cin>>choix;

            //switch
switch(choix)
{

    //case#1
case 'A':
case 'a':{





//clear
system("cls");
//appel de la focnction
char u;
    enregistrer();
    cout<<"================================================================================\n";
    afficher();
    cout<<"================================================================================\n\n";

    //condition
    cout<<"Voulez-vous recommencer l'enregistrement des produits ? [Y\N]\n";
    cin>>u;

    //clear
    system("cls");
//condition
if(u=='Y' || u=='y')
{
    enregistrer();
}
else
    if(u=='N' || u=='n')
{
    //clear
    system("cls");
    //appel menu
programme();
}
    break;
}



    //case #2
case 'B':
case 'b':{
    //variable
    int stop;
stop=5;

    //clear
    system("cls");

    cout<<"================================================================================\n";
    afficher();
    cout<<"================================================================================\n\n";

//boucle
do{
    modifier();
    cout<<"\n";
    //clear
    system("cls");
    //message
    cout<<"Vous avez modifier avec succes !!!!\n";
//affichage
afficher();
cout<<"\n";
    cout<<"Taper un chiffre different de 5 pour continuer"
    " ou taper 5 pour choisir une autre option :\n";
    cin>>stop;
}while(stop != 5);
//if
if(stop == 5)
{
    //clear
    system("cls");
    programme();
}
    break;
}

case 'I':
case 'i':{

//clear
system("cls");

cout<<"\n";
cout<<"Voici la liste des produits dans l'entrepot :\n\n";
//appel de l'affichage
afficher();

cout<<"\n\n";

break;

}

case 'C':
case 'c':{
    //variable
    int stop1;
stop1=5;

    //clear
    system("cls");
    afficher();
    cout<<"\n";
//boucle
do{
    supprimer();
    cout<<"\n";
    //clear
    system("cls");
    //message
    cout<<"Vous avez supprimer avec succes !!!!\n\n";
//affichage
    cout<<"================================================================================\n\n";
    afficher();
    cout<<"================================================================================\n\n";

cout<<"\n";
    cout<<"Taper un chiffre different de 5 pour continuer"
    " ou taper 5 pour choisir une autre option :\n";
    cin>>stop1;
}while(stop1 != 5);
//if
if(stop1 == 5)
{
    //clear
    system("cls");
    programme();
}
    break;
}


case 'E':
case 'e':{

    //clear
    system("cls");

    //variable
char choixentrepot;

//appel menu entrepot
do{
    entrepot();

    cout<<endl;

 //message pour le choix
 cout<<"Choisissez l'option qui vous convients pour l'entrepot :\n";
cin>>choixentrepot;


//switch pour le menu entrepot
    switch(choixentrepot)
    {

    case 'X':
    case 'x':{

        //variable
    int stop7;
stop7=6;

    //clear
    system("cls");

    cout<<"================================================================================\n\n";
    afficher();
    cout<<"================================================================================\n\n";

//boucle
do{
    depot();
    cout<<"\n";
    //clear
    system("cls");
    //message
    cout<<"Votre depot a ete effectuer avec succes !!!!\n\n";
//affichage
    cout<<"================================================================================\n";
    afficher();
    cout<<"================================================================================\n\n";

    cout<<"Taper un chiffre different de 6 pour continuer"
    " ou taper 6 pour choisir une autre option (entrepot) :\n";
    cin>>stop7;
}while(stop7 != 6);
//if
if(stop7 == 6)
{
    //clear
    system("cls");
}
//entrepot();
        break;
    }


    case 'Y':
    case 'y':{

        //clear
system("cls");
 //variable
    int stop44;
stop44=6;

    //clear
    system("cls");

    cout<<"================================================================================\n\n";
    afficher();
    cout<<"================================================================================\n\n";

//boucle
do{
    retrait();
    cout<<"\n";
    //clear
    system("cls");
    //message
    cout<<"Votre retrait a ete effectuer avec succes !!!!\n\n";
//affichage
    cout<<"================================================================================\n";
    afficher();
    cout<<"================================================================================\n\n";

    cout<<"Taper un chiffre different de 6 pour continuer"
    " ou taper 6 pour choisir une autre option (entrepot) :\n";
    cin>>stop44;
}while(stop44 != 6);
//if
if(stop44 == 6)
{
    //clear
    system("cls");
}
        break;
    }



    case 'Z':
    case 'z':{

system("cls");

//variable
    char k;

    cout<<"Voulez-vous quitter le menu entrepot ? [Y/N]?\n";
    cin>>k;

//condition
if(k == 'Y' || k == 'y')
    {
        //clear
        system("cls");
        //appel menu gestion de stock
        programme();
    }
    else
        if(k == 'N' || k == 'n')
    {
        //clear le message
        system("cls");
    }
break;
}


default:{

    cout<<"Erreur !!!\n";
    //clear le message
    system("cls");
break;
}
    }
}while(choixentrepot != 'z' || choixentrepot != 'Z');
}


    case 'F':
    case 'f':{



    //boucle

    //clear
    system("cls");

    //variable
char choixrecherche;

//boucle
do{
//appel menu recherche
    recherche();
    cout<<endl;

 //message pour le choix
 cout<<"Choisissez l'option qui vous convients pour la recherche :\n";
cin>>choixrecherche;


        switch(choixrecherche)
        {
  case 'M':
  case 'm':{
//par code

 //clear
system("cls");
 //variable
    int stop61;
stop61=6;



    cout<<"================================================================================\n\n";
    afficher();
    cout<<"================================================================================\n\n";

//boucle
do{


        cout<<"\n\n";
        //appel fonction code
    code();
    cout<<"\n";
    //message
    cout<<"Votre recherche par code a ete effectuer avec succes !!!!\n\n";


    cout<<"Taper un chiffre different de 6 pour continuer"
    " ou taper 6 pour choisir une autre option du menu recherche :\n";
    cin>>stop61;
}while(stop61 != 6);
//if
if(stop61 == 6)
{
    //clear
    system("cls");
}
        break;
  }


    case 'N':
    case 'n':{
         //clear
system("cls");
 //variable
    int stop62;
stop62=6;



    cout<<"================================================================================\n\n";
    afficher();
    cout<<"================================================================================\n\n";

//boucle
do{
        cout<<"\n\n";
    //appel fonction categorie
    categ();
    cout<<"\n";
    //clear
    system("cls");
    //message
    cout<<"Votre recherche par categorie a ete effectuer avec succes !!!!\n\n";


    cout<<"Taper un chiffre different de 6 pour continuer"
    " ou taper 6 pour choisir une autre option du menu recherche :\n";
    cin>>stop62;
}while(stop62 != 6);
//if
if(stop62 == 6)
{
    //clear
    system("cls");
}
        break;
    }


    case 'S':
    case 's':{
        //clear
system("cls");
 //variable
    int stop62;
stop62=6;



    cout<<"================================================================================\n\n";
    afficher();
    cout<<"================================================================================\n\n";

//boucle
do{
        cout<<"\n\n";
    //appel fonction categorie
    dater();
    cout<<"\n";
    //clear
    system("cls");
    //message
    cout<<"Votre recherche par categorie a ete effectuer avec succes !!!!\n\n";


    cout<<"Taper un chiffre different de 6 pour continuer"
    " ou taper 6 pour choisir une autre option du menu recherche :\n";
    cin>>stop62;
}while(stop62 != 6);
//if
if(stop62 == 6)
{
    //clear
    system("cls");
}        break;
}


    case 'T':
    case 't':{


system("cls");

//variable
    char l;

    cout<<"Voulez-vous quitter le menu recherche ? [Y/N]?\n";
    cin>>l;

//condition
if(l == 'Y' || l == 'y')
    {
        //clear
        system("cls");
        //appel menu gestion de stock
        programme();
    }
    else
        if(l == 'N' || l == 'n')
    {
        //clear le message
        system("cls");
    }
break;
    }

        //return;
    default:{

    cout<<"Erreur !!!\n";
    //clear le message
    system("cls");
    break;
    }
        }
}while(choixrecherche != 'T' || choixrecherche != 't');
    }



case 'H':
case 'h':{
    //variable
    char m;

    cout<<"Voulez-vous arreter le programme [Y/N]?\n";
    cin>>m;

//condition
if(m == 'Y' || m == 'y')
    {
        exit(1);
    }
    else
        if(m == 'N' || m == 'n')
    {
        //clear le message
        system("cls");
        //affichage du menu
programme();
    }
break;
}
default:{
    cout<<"Erreur !!!\n";
    //clear le message
    system("cls");
break;
}
}
    }while(choix != 'H' || choix != 'h');
}





int main()
{
//fond colorer
system("color FF");

     //pour ajouter la date et l'heure dans le menu

//Declaration argument pour l'heure
time_t tt;

//variable pour stocker le retour de l'heure actuel
struct tm*ti;

//activation
time (&tt);

//utilisation l'heure actuel
ti = localtime(&tt);

cout<<"----- Le jour,la date et l'heure de lancement du programme est : -----\n";
cout<<"                        "<<asctime(ti);

cout<<"\n\n\n\n";
//Membre du groupe et explication du projet.
cout<<"==========================================================================\n\n";

cout<<"Ce programme est creer par un groupe d'etudiant d'ESIH composer de :\n\n";
cout<<"1- REMILIEN Makelele Melchior\n\n";
cout<<"2- ESPERANCE Sophonie Christella\n";
cout<<"3- JOSEPH John Walney\n";
cout<<"4- MADEUS Rootchy\n";
cout<<"5- REMILIEN Makelele Melchior\n\n";
cout<<"6- CALIXTE Needless \n";
cout<<"==========================================================================\n\n";
cout<<" IMPORTANT : Il permet de faire une gestion de stock pour les entreprises de commercialisation de produits alimentaires.\n\n\n";
cout<<"\n\n\n";


    int answer;
    answer=0;
do {
    programme();
        cout<<"================================================================================\n";
        cout<<"Execution complete \n";
        cout<<"Recommencez le programme?, pressez 1!\n";
        cin>>answer;
        system("CLS");
    } while(answer ==1);
    cout<<"Au revoir! \n";
    return 0;

}

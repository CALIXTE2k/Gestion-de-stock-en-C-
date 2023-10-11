#include <iostream>
#include <string>
#include <vector>
#include "gestion.h"
#include <fstream>
#include <stdlib.h>

using namespace std;
int gestion::last_id = 10012000;
gestion::gestion(int id, string nom, int quantite, string categorie, string date) : id(id), nom(nom), quantite(quantite), categorie(categorie), date(date) {}
vector<gestion> tableau;
void enregistrer()
{
        string  nom, categorie, date;
        int quantite;
        gestion::last_id++;
        int id = gestion::last_id;
    cout<<"Produit: "<<id<<" \n";
    cout<<"Entrer le nom: \n";
    cin>>nom;

    cout<<"Entrer la categorie: \n";
    cin>>categorie;

    cout<<"Entrer la quantite: \n";
    cin>>quantite;

    cout<<"Entrer la date: \n";
    cin>>date;
        tableau.push_back(gestion(id, nom, quantite, categorie, date));
}
void afficher()
{
        cout<<"ID \t\t"<<"Nom \t"<<"Quantite \t"<<"Categorie \t"<<"Date \t";
        cout<<"\n";
for(size_t i = 0; i < tableau.size(); i++)
{
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t\t"<<tableau[i].categorie<<" \t\t"<<tableau[i].date;
        cout<<"\n";
}
    }
void modifier()
{
    string nom, categorie, date;
        int id, quantite;
        cout<<"Entrez l' ID du produit a afficher \n";
        cin>>id;
for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
    {
        cout<<"Entrez le nouveau nom: \n";
        cin>>tableau[i].nom;

        cout<<"Entrez la nouvelle quantite: \n";
        cin>>tableau[i].quantite;

        cout<<"Entrez la nouvelle categorie: \n";
        cin>>tableau[i].categorie;


        cout<<"Entrez la nouvelle date: \n";
        cin>>tableau[i].date;
        return;
    }

}
cout<<"Produit non trouve \n";
}
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
void menuentrepot()
{
    cout<<"================================================================================\n"
    <<"1. Depot \n"
    <<"2. Retrait \n"
    <<"3. Quitter \n\n";
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

    cout << "Quantite modifiee avec succes!" << endl;
            return;
        }
    }
    cout << "Produit non trouve \n";
}
void retrait()
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

    cout << "Quantite modifiee avec succes!" << endl;
            return;
        }
    }
    cout << "Produit non trouve \n";
}
void code()
{
    int id;
    cout << "Entrez l' ID du produit a rechercher: \n";
    cin >> id;
         for(size_t i = 0; i < tableau.size(); i++)
{
    if (tableau[i].id == id)
        {
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t"<<tableau[i].categorie<<" \t"<<tableau[i].date;
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
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t"<<tableau[i].categorie<<" \t"<<tableau[i].date;
        cout<<"\n";
        return;
        }
    }
cout<<"Produit non trouve \n";
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
        cout<<tableau[i].id<<" \t"<<tableau[i].nom<<" \t"<<tableau[i].quantite<<" \t"<<tableau[i].categorie<<" \t"<<tableau[i].date;
        cout<<"\n";
        return;
        }
    }
cout<<"Produit non trouve \n";
}
void menurecherche()
{
     cout<<"================================================================================\n"
    <<"1. Recherche par code \n"
    <<"2. Recherche par categorie \n"
    <<"3. Recherche par date \n"
    <<"4. Quitter \n\n";
}

void programme()
{
	int choix;
        cout<<"================================================================================\n"
		<<"1. Enregistrer un produit \n"
		<<"2. Modifier un produit \n"
		<<"3. Supprimer un produit \n"
		<<"4. Afficher les produits \n"
		<<"5. Entrepot \n"
		<<"6. Rechercher \n"
		<<"7. Ordre alphabetique \n"
		<<"8. Quitter le programme \n"
		<<"================================================================================\n\n";

            cin>>choix;
switch(choix)
{
case 1:
    int stop1;
    stop1=1;
    do{
    enregistrer();
    cout<<"================================================================================\n";
    afficher();
    cout<<"================================================================================\n";
    cout<<"Continuez?(1) \n";
    cin>>stop1;
    system("CLS");
      }while(stop1==1);
    break;
case 2:
    int stop2;
    stop2=1;
    do{
    afficher();
    cout<<"================================================================================\n";
    modifier();
    cout<<"================================================================================\n";
    afficher();
    cout<<"Continuez?(1) \n";
    cin>>stop2;
    system("CLS");
      }while(stop2==1);
    break;
case 3:
    int stop3;
    stop3=1;
    do{
    afficher();
    cout<<"================================================================================\n";
    supprimer();
    cout<<"================================================================================\n";
    afficher();
    cout<<"Continuez?(1) \n";
    cin>>stop3;
    system("CLS");
      }while(stop3==1);
    break;
case 4:
    afficher();
    break;
case 5:
int choixentrepot;
    menuentrepot();
cin>>choixentrepot;
    switch(choixentrepot)
    {
    case 1:
        int stop51;
    stop51=1;
    do{
    afficher();
    cout<<"================================================================================\n";
        depot();
    cout<<"================================================================================\n";
    afficher();
    cout<<"Continuez?(1) \n";
    cin>>stop51;
    system("CLS");
      }while(stop51==1);
        break;
    case 2:
        int stop52;
    stop52=1;
    do{
    afficher();
    cout<<"================================================================================\n";
        retrait();
    cout<<"================================================================================\n";
    afficher();
    cout<<"Continuez?(1) \n";
    cin>>stop52;
    system("CLS");
      }while(stop52==1);
        break;
    case 3:
        return;
    default:
    cout<<"Choix invalide.\n";
    }
    case 6:
int choixrecherche;
    menurecherche();
cin>>choixrecherche;
     switch(choixrecherche)
    {
    case 1:
        int stop61;
    stop61=1;
    do{
    afficher();
    cout<<"================================================================================\n";
        code();
     cout<<"================================================================================\n";
    cout<<"Continuez?(1) \n";
    cin>>stop61;
    system("CLS");
      }while(stop61==1);
        break;
    case 2:
        int stop62;
    stop62=1;
    do{
    afficher();
    cout<<"================================================================================\n";
        categ();
    cout<<"================================================================================\n";
    cout<<"Continuez?(1) \n";
    cin>>stop62;
    system("CLS");
      }while(stop62==1);
        break;
    case 3:
    int stop63;
    stop63=1;
    do{
    afficher();
    cout<<"================================================================================\n";
        dater();
    cout<<"================================================================================\n";
    cout<<"Continuez?(1) \n";
    cin>>stop63;
    system("CLS");
      }while(stop63==1);
        break;
    case 4:
        return;
    default:
    cout<<"Choix invalide.\n";
    }
case 8:
    return;
default:
    cout<<"Choix invalide.\n";
}
}
int main()
{
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

#include <string>
#include <iostream>

using namespace std;

class gestion
{
    //encapsulation type public pour les variables
    public:
        static int last_id;
        int id;
        string nom;
        int quantite;
        float prix;
        string categorie;
        string date;

//declaration constructeur
    gestion(int id, string nom, int quantite,float prix, string categorie, string date);
};

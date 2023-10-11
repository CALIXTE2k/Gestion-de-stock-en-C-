#include <string>
#include <iostream>

using namespace std;

class gestion
{
    public:
        static int last_id;
        int id;
        string nom;
        int quantite;
        string categorie;
        string date;
    gestion(int id, string nom, int quantite, string categorie, string date);
};

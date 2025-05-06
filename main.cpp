#include <iostream>
#include "contact.cpp"

using namespace std;

int main()
{

    GestionnaireContacts gestionnaire;

    gestionnaire.ajouterContact("Dupont", "Alice","alice@gmail.com","061234567");

    gestionnaire.ajouterContact("Pupont", "Alice","alice@gmail.com","061234567");


    gestionnaire.ajouterContact("Martin", "Bob", "alice@gmail.com", "0629010954");
    gestionnaire.ajouterContact("Vartin", "Bob", "alice@gmail.com", "0629010954");
    gestionnaire.ajouterContact("Zartin", "Bob", "alice@gmail.com", "0629010954");
    gestionnaire.ajouterContact("aartin", "Bob", "alice@gmail.com", "0629010954");
    gestionnaire.ajouterContact("Bartin", "Bob", "alice@gmail.com", "0629010954");
    gestionnaire.ajouterContact("Cartin", "Bob", "alice@gmail.com", "0629010954");

    gestionnaire.afficherArbre(3);
    gestionnaire.afficherListe();
    gestionnaire.supprimerContact("aartin");

    gestionnaire.afficherArbre(3);
    gestionnaire.afficherListe();


    gestionnaire.triB();









    return 0;

}

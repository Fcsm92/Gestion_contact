#include <iostream>
#include <cstring>
#include <ctime>


struct contact
{
    char nom[50];
    char prenom [50];
    char telephone[10];
    char mail[100];
    time_t date_ajout;

    // liste
    Contact* suivant;
    Contact* precedent;

    //arbre
    Contact* gauche; //fils gauche
    Contact* droit;  //fils droit
};



class GestionnaireContacts {
 private:
    Contac* teteListe;
    Contact* racineArbre;

    public:
    GestionnaireContacts() : teteListe(nullptr), racineArbre(nullptr) {}
    
    void ajouterContact(const char* nom, const char* prenom, const char* mail){

        // creation contact
        Contact* c = new Contact();
        strcpy(nouveau->nom = nom);
        strcpy(nouveau->prenom = prenom);
        strcpy(nouveau->mail = mail);

        //ajout tete de la lisre et insertion dans l'arbre
        nouveau->suivant= teteListe;
        teteliste=nouveau;

        insertionDsArbre(racine,nouveau);

       
    } 

    void supprimerContact(Contact *aSupprimer){
            if (aSupprimer->precedent){
                aSupprimer->precedent->suivant=aSupprimer->suivant;
            }
            if (aSupprimer->suivant){
                aSupprimer->suivant->precedent=aSupprimer->precedent;
            }
            delete aSupprimer;
        }
      
    // insertion avec recursivité    
    void insererDsArbre(Contact *&racine,Contact *nouveau){
            //Si arbre vide
            if (racine=nullptr){
                racine=nouveau
            }

            //si le contact est alphabetiquement plus petit
            else if (strcmp(nouveau->nom,racine->nom)< 0){
                insererDsArbre(racine->gauche, nouveau);
            }
            //si plus grand
            else{
                insererDsArbre(racine->droite, nouveau);
            }
        }



    }




}

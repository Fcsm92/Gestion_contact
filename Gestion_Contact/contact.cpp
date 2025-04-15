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
    Contact* teteListe;
    Contact* racineArbre;

    Contact* rechercheDsArbre(Contact* racine, const char*nom){
        //Si arbre vide
        if(!racine) return nullptr;

        //sinon on compare les nom
        int cpt= strcmp(nom,racine->nom);
        //Si bon nom
        if (cpt==0) return racine;
        //Sinon on cherche l'enfant droit ou gache
        return rechercheArbre(cmp<0 ? racine->gauche : racine->droite, nom);
    }

    void supprimerContactListe(Contact* aSupprimer){
        if (!teteListe || !aSupprimer) return;
        
        if (teteListe==aSupprimer){
            teteListe=teteListe->suivant;
        }

        //supprimer dans la liste
        if (aSupprimer->precedent){
            aSupprimer->precedent->suivant=aSupprimer->suivant;
        }
        if (aSupprimer->suivant){
            aSupprimer->suivant->precedent=aSupprimer->precedent;
        }
    
    }


    Contact* supprimerArbre(Contact* racine,const char* nom){
        if (!racine) return nullptr;

        int ctp=strcmp(nom, racine->nom);
        if (cpt<0){
            racine->gauche=supprimerArbre(racine->gauche,nom);
        }
        else if (cpt>0){
            racine->droit=supprimerArbre(racine->droit,nom);

        }
        //si c'est le bon
        else {
            if (!racine->gauche){
                Contact * temp = racine->droit;
                return temp;
            }
            else if (!racine->droit){
                Contact * temp = racine->gauche;
                return temp;
            }

            //si deux enfant
            Contact* temp= trouverMinimum(racine->droit);
            strncpy(racine->nom, temp->nom);
            strncpy(racine->prenom, temp->prenom);
            strncpy(racine->mail, temp->mail);
            strncpy(racine->telephone, temp->telephone);
            racine->droit=supprimerArbre  (racine->droit, temp->nom);
        }
        return racine;
    }

    Contact *trouverMinimum(Contact* noeud){

        Contact* courant=noeud;
        while (courant && courant->gauche){
            courant=courant->gauche;
        }
        return courant;
    }

    


    public:
    GestionnaireContacts() : teteListe(nullptr), racineArbre(nullptr) {}
    
    void ajouterContact(const char* nom, const char* prenom, const char* mail, const char* telephone){

        // creation contact
        Contact* nouveauc = new Contact();
        strncpy(nouveau->nom = nom, 49);
        strncpy(nouveau->prenom = prenom, 49);
        strncpy(nouveau->mail = mail, 99);
        strncpy(nouveau->telephone = mail, 14);
        nouveau->gauche= nouveau->droit= nouveau->suivant=nullptr;

        //ajout tete de la liste et insertion dans l'arbre
        nouveau->suivant= teteListe;
        *teteListe->precedent=nouveaux
        teteliste=nouveau;

        insertionDsArbre(racineArbre,nouveau);

       
    } 


      
    // insertion avec recursivité    
    void insererDsArbre(Contact *&racine,Contact *nouveau){
            //Si arbre vide
            if (racine=nullptr){
                racine=nouveau;
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



    


    void supprimerContact(Contact char nom){
        Contact *aSupprimer = rechercheDsArbre(racineArbre,nom);
        if (!aSupprimer){
            return false
        }
       supprimerContactListe(aSupprimer);


       racineArbre=supprimerArbre(racineArbre,nom);

       delete aSupprimer;
       return true;
    }




}

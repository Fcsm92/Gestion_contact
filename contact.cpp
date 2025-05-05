//
// Created by ryoul on 29/04/2025.
//
#include <iostream>
#include <cstring>
#include <ctime>


struct Contact
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

    Contact** conversionLenT(Contact* tete, int&taille) {
        //compter le nombre de contact
        taille=0;
        Contact* courant =tete;
        while (courant!=nullptr) {
            taille++;
            courant=courant->suivant;
            }

        // creation dynamique du tableau
    Contact** tableau=new Contact *[taille];

    //remplissage du tableau
    courant=tete;
    for (int i=0;i<taille;i++) {
        tableau[i]=courant;
        courant=courant->suivant;
    }
        return tableau;

    }
    Contact* rechercheDsArbre(Contact* racine, const char*nom){
        //Si arbre vide
        if(!racine) return nullptr;

        //sinon on compare les nom
        int cpt= strcmp(nom,racine->nom);
        //Si bon nom
        if (cpt==0) return racine;
        //Sinon on cherche l'enfant droit ou gache
        return rechercheDsArbre(cpt<0 ? racine->gauche : racine->droit, nom);
    }

    void supprimerContactListe(Contact* aSupprimer){
        if (!teteListe || !aSupprimer) return;

        if (teteListe==aSupprimer){
            teteListe=teteListe->suivant;
            if (teteListe) teteListe->precedent = nullptr;

        }

        //supprimer dans la liste
        if (aSupprimer->precedent){
            aSupprimer->precedent->suivant=aSupprimer->suivant;
        }
        if (aSupprimer->suivant){
            aSupprimer->suivant->precedent=aSupprimer->precedent;
        }
        std::cout << "contact supprimer dans liste";
    }


    Contact* supprimerArbre(Contact* racine,const char* nom){
        if (!racine) return nullptr;

        int cpt=strcmp(nom, racine->nom);
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
            strcpy(racine->nom, temp->nom);
            strcpy(racine->prenom, temp->prenom);
            strcpy(racine->mail, temp->mail);
            strcpy(racine->telephone, temp->telephone);
            racine->droit=supprimerArbre  (racine->droit, temp->nom);
        }

        std::cout << "contact supprimer dans l'arbre";
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

    ~GestionnaireContacts() {
        Contact* courant = teteListe;
        while (courant) {
            Contact* temp = courant;
            courant = courant->suivant;
            delete temp;
        }
    }


    // Affiche l'arbre avec différents types de parcours
    void afficherArbre(int mode = 0) {
        std::cout << "\n=== CONTACTS DANS L'ARBRE ===" << std::endl;
        switch(mode) {
            case 0:
                std::cout << "Parcours Inordre (trié par nom):" << std::endl;
                afficherInordre(racineArbre);
                break;
            case 1:
                std::cout << "Parcours Préordre:" << std::endl;
                afficherPreordre(racineArbre);
                break;
            case 2:
                std::cout << "Parcours Postordre:" << std::endl;
                afficherPostordre(racineArbre);
                break;
            case 3:
                std::cout << "Affichage hiérarchique:" << std::endl;
                afficherHierarchique(racineArbre, 0);
                break;
            default:
                std::cerr << "Mode d'affichage invalide!" << std::endl;
        }
    }


    void ajouterContact(const char* nom, const char* prenom, const char* mail, const char* telephone){

        // creation contact
        Contact* nouveau = new Contact();
        strcpy(nouveau->nom , nom);
        strcpy(nouveau->prenom, prenom);
        strcpy(nouveau->mail,mail);
        strcpy(nouveau->telephone, telephone);
        nouveau->gauche= nouveau->droit= nouveau->suivant=nullptr;

        //ajout tete de la liste et insertion dans l'arbre
        if (teteListe) teteListe->precedent = nouveau;
        nouveau->suivant= teteListe;
        teteListe=nouveau;

        insererDsArbre(racineArbre,nouveau);
        std::cout<< "contact ajouté";


    }



    // insertion avec recursivité
    void insererDsArbre(Contact *&racine,Contact *nouveau){
            //Si arbre vide
            if (racine==nullptr){
                racine=nouveau;
            }

            //si le contact est alphabetiquement plus petit
            else if (strcmp(nouveau->nom,racine->nom)< 0){
                insererDsArbre(racine->gauche, nouveau);
            }
            //si plus grand
            else{
                insererDsArbre(racine->droit, nouveau);
            }
        std::cout<< "contact ajouté dans l'arbre"<<std::endl;
        }


    void afficherListe() {
        Contact* courant=teteListe;
        while (courant!=nullptr) {
            std::cout << courant->nom << "\n ";
            courant=courant->suivant;
        }
    }



    int supprimerContact(const char* nom){
        Contact *aSupprimer = rechercheDsArbre(racineArbre,nom);
        if (!aSupprimer){
            std::cout<<"Contact inexistant"<<std::endl;
            return false;
        }
       supprimerContactListe(aSupprimer);


       racineArbre=supprimerArbre(racineArbre,nom);

       delete aSupprimer;
        std::cout<< "  contact supprimeé totalement"<<std::endl;

       return true;
    }

    // Parcours inordre (ordre alphabétique)
    void afficherInordre(Contact* racine) {
        if (!racine) return;
        afficherInordre(racine->gauche);
        std::cout << "- " << racine->nom << " " << racine->prenom
                  << " (" << racine->telephone << ")" << std::endl;
        afficherInordre(racine->droit);
    }

    // Parcours préordre
    void afficherPreordre(Contact* racine) {
        if (!racine) return;
        std::cout << "- " << racine->nom << std::endl;
        afficherPreordre(racine->gauche);
        afficherPreordre(racine->droit);
    }

    // Parcours postordre
    void afficherPostordre(Contact* racine) {
        if (!racine) return;
        afficherPostordre(racine->gauche);
        afficherPostordre(racine->droit);
        std::cout << "- " << racine->nom << std::endl;
    }

    // Affichage hiérarchique (arborescence)
    void afficherHierarchique(Contact* racine, int niveau) {
        if (!racine) return;

        afficherHierarchique(racine->droit, niveau + 1);

        for (int i = 0; i < niveau; ++i)
            std::cout << "    ";

        std::cout << "---" << racine->nom << std::endl;

        afficherHierarchique(racine->gauche, niveau + 1);
    }



};

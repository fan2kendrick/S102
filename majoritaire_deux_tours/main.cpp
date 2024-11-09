    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <fstream>

    using namespace std;

    string lireLigne()
    {
        string ligne;
        while (true)
        {
            getline(cin, ligne);
            // cout << ligne << endl;
            if (ligne.substr(0, 2) != "//")
                break;
        }
        return ligne;
    }

    int lireEntier()
    {
        string ligne;
        while (true)
        {
            getline(cin, ligne);
            if (isdigit(ligne[0]))
                break;
        }
        return stoi(ligne);
    }

    struct participant
    {
        string nom;
        string prenom;
        int choix;
        int choix2;
    };

    // Ces fonctions ont été utilisées pour le debug.

    // void afficherParticipants(vector<participant> tableau)
    // {
    //     for (participant p : tableau)
    //     {
    //         if (p.nom == p.prenom)
    //             continue;
    //         cout << p.nom << " " << p.prenom << " " << p.choix << " " << p.choix2 << endl;
    //     }
    // }

    // void afficherVecteurString(vector<string> tableau)
    // {
    //     for (unsigned i = 0; i <= tableau.size() - 1; ++i)
    //     {
    //         cout << tableau[i] << endl;
    //     }
    // }

    // void afficherGlacesEtVotes(vector<string> glaces, vector<int> votes)
    // {
    //     cout << "Il y a " << glaces.size() << " glaces dispo :" << endl;
    //     for (unsigned i = 0; i <= glaces.size() - 1; ++i)
    //     {
    //         cout << "- " << glaces[i] << " avec " << votes[i] << " votes. " << endl;
    //     }
    // }

    int trouverIndiceAvecValeur(int valeur, vector<int> tableau)
    {
        int indice;
        for (unsigned i = 0; i <= tableau.size() - 1; ++i)
        {
            if (tableau[i] != valeur) continue;
            // cout << " indice : " << tableau[i] << " " << i << endl;
            indice = i;
        }
        return indice;
    }


    int trouverMajoriteAbsolue(vector<int> tableau, vector<participant> participants)
    {
        int majorite;
        for (int i : tableau)
        {
            // cout << i << " " << participants.size()/2 << endl;
            if (i < participants.size() / 2) continue;
            majorite = trouverIndiceAvecValeur(i, tableau);
        }

        for(int i = 0; i <= participants.size() - 1; ++i)
        {
            if(participants[i] < participants.size() / 2) continue;
            majorite = trouverIndiceAvecValeur(participants[i], tableau);

        } 
        // cout << "maj" <<  majorite << endl;
        return majorite;
    }
    // [20, 30, 40, 50, 60]
    // for(int i = 0; i < tab.size() - 1; ++i) // 0, 1, 2, 3, 4 ...
    // for(int i : tab) // 20, 30, 40, 50, 60

    int main()
    {
        vector<participant> listeParticipants;
        vector<string> glaces = {lireLigne(), lireLigne(), lireLigne(), lireLigne()};
        vector<int> choixDesGlaces = {0, 0, 0, 0};

        for (unsigned i = 0; i < 116; ++i)
        {
            string nom = lireLigne();
            string prenom = lireLigne();
            int choix = lireEntier();
            int choix2 = lireEntier();
            // cout << prenom << nom << choix << endl;
            listeParticipants.push_back(participant{nom, prenom, choix, choix2});
        }

        for (participant p : listeParticipants)
        {
            choixDesGlaces[p.choix - 1] += 1;
        }

        sort(choixDesGlaces.begin(), choixDesGlaces.end(), greater<int>());
        int gagnant = 0;

        // afficherParticipants(listeParticipants);
        // afficherGlacesEtVotes(glaces, choixDesGlaces);
        trouverMajoriteAbsolue(choixDesGlaces, listeParticipants);
        choixDesGlaces = {0, 0, 0, 0};

        //    afficherGlacesEtVotes(glaces, choixDesGlaces);

        if (gagnant == 0)
        {
            for (participant p : listeParticipants)
            {
                choixDesGlaces[p.choix2 - 1] += 1;
            }
            // afficherGlacesEtVotes(glaces, choixDesGlaces);
            gagnant = trouverMajoriteAbsolue(choixDesGlaces, listeParticipants);
        }

        cout << "c'est la glace " << glaces[gagnant] << " qui a gagne" << endl;

        return 0;
    }

    // ./a.out < entree2.txt > sortie_2.txt
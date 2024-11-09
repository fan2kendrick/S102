#include <iostream>
#include <vector>

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
    vector <int> choix;
};

// Ces fonctions ont été utilisées pour le debug.

// void afficherParticipants(vector<participant> tableau)
// {
//     for (participant& p : tableau)
//     {
//         if (p.nom == p.prenom)
//             continue;
//         cout << p.nom << " " << p.prenom << " " << p.choix << " " << p.choix2 << endl;
//     }
// }

// void afficherVecteurString(vector<string> tableau)
// {
//     for (size_t i = 0; i <= tableau.size() - 1; ++i)
//     {
//         cout << tableau[i] << endl;
//     }
// }

// void afficherGlacesEtVotes(vector<string> glaces, vector<int> votes)
// {
//     cout << "Il y a " << glaces.size() << " glaces dispo :" << endl;
//     for (size_t i = 0; i <= glaces.size() - 1; ++i)
//     {
//         cout << "- " << glaces[i] << " avec " << votes[i] << " votes. " << endl;
//     }
// }

int main()
{
    vector<participant> listeParticipants;
    vector<string> glaces = {lireLigne(), lireLigne(), lireLigne(), lireLigne()};
    vector<int> choixDesGlaces = {0, 0, 0, 0};

    for (unsigned i = 0; i < 116; ++i)
    {
        string nom = lireLigne();
        string prenom = lireLigne();
        vector <int> choix = {lireEntier(), lireEntier(), lireEntier(), lireEntier()};
        // cout << prenom << nom << choix << endl;
        listeParticipants.push_back(participant{nom, prenom, choix});
    }

    for(participant& p : listeParticipants)
    {
        // cout << p.nom << " " << p.prenom << " a voté pour :" << endl;
        for(size_t i = 0; i < p.choix.size(); ++i)
        {
            // cout << p.choix[i] << " " << i << endl;
            choixDesGlaces[p.choix[i] - 1] += i + 1;
            // cout << p.choix[i] << endl;
        }
    }

    /*
     * {4, 3, 2, 1}
     * tableau {4,3,2,1}
     * JE HAIS REMPLIR DES FICHIERS D'ENTREES SANS PROGRAMME EXTERNE
    */

    int valeurPlusGrande = choixDesGlaces[0];
    size_t gagnant = 0;

    // for(int& i : choixDesGlaces)
    // {
    //     cout << i << endl;
    // }

    for(size_t i = 0; i < choixDesGlaces.size(); ++i)
    {
        if(choixDesGlaces[i] > valeurPlusGrande)
        {
            valeurPlusGrande = choixDesGlaces[i];
            gagnant = i;
            continue;
        }
    }

    cout << "c'est la glace " << glaces[gagnant] << " qui a gagne" << endl;

    return 0;
}

// ./a.out < entree.txt > sortie_.txt

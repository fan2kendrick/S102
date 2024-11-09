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
};

// Ces fonctions ont été utilisées pour le debug.

// void afficherParticipants(vector<participant> tableau)
// {
//     for (participant p : tableau)
//     {
//         if (p.nom == p.prenom)
//             continue;
//         cout << p.nom << " " << p.prenom << " " << p.choix << endl;
//     }
// }

// void afficherVecteurString(vector<string> tableau)
// {
//     for (unsigned i = 0; i <= tab.size() - 1; ++i)
//     {
//         cout << tab[i] << endl;
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
        // cout << prenom << nom << choix << endl;
        listeParticipants.push_back(participant{nom, prenom, choix});
    }

    for (participant p : listeParticipants)
    {
        choixDesGlaces[p.choix-1] += 1;
    }

    int gagnant = 0;
    int voteLePlusHaut = choixDesGlaces[0];
    for(int i = 1; i < choixDesGlaces.size(); i++) 
    {
        if(choixDesGlaces[i] > voteLePlusHaut)
        {
            voteLePlusHaut = choixDesGlaces[i]; 
            gagnant = i; 
        }
    }
    // afficherParticipants(listeParticipants);
    // afficherGlacesEtVotes(glaces, choixDesGlaces);

    cout << "c'est la glace " << glaces[gagnant] << " qui a gagne" << endl;

    return 0;
}

// ./a.out < entree1.txt > sortie_1.txt
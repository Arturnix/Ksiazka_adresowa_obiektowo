#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class AdresatMenedzer {

const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
vector<Adresat> adresaci;
int idOstatniegoAdresata;
PlikZAdresatami plikZAdresatami;

Adresat podajDaneNowegoAdresata ();

public:
    AdresatMenedzer(int idZalogowanegoUzytkownika) : ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata ();
    void wypiszWszystkichAdresatow ();
};

#endif // ADRESATMENEDZER_H

#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"
#include "Uzytkownik.h"
#include "AdresatMenedzer.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    MetodyPomocnicze metodyPomocnicze;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkownikow ();
    void logowanieUzytkownika ();
    void zmianaHaslaZalogowanegoUzytkownika ();
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void wylogujUzytkownika ();
};
#endif // KSIAZKAADRESOWA_H

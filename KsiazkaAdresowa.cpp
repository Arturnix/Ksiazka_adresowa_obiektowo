#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {

    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    AdresatMenedzer adresatMenedzer(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {

    AdresatMenedzer adresatMenedzer(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenedzer.wypiszWszystkichAdresatow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {

    uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {

     metodyPomocnicze.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {

   metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika () {

    uzytkownikMenedzer.wylogujUzytkownika();
}

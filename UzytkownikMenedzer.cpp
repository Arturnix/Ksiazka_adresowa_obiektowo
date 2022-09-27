#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika () {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow () {

    for (int i = 0; i < (int)uzytkownicy.size(); i++) {

        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {

    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika () {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin (string login) {

    for (int i = 0; i < (int)uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku() {

    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    idZalogowanegoUzytkownika = 0;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
     return;
}

void UzytkownikMenedzer::wylogujUzytkownika () {

    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int id) {
    idZalogowanegoUzytkownika = id;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika () {
    return idZalogowanegoUzytkownika;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany () {
    if (idZalogowanegoUzytkownika > 0) {
        return true;
    } else {
        return false;
    }
}
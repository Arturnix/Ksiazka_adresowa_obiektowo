#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
        cout << "Nowy adresat zostal dodany" << endl;
    } else {
        cout << "Blad! Nie udalo sie dodac nowego adresata do pliku" << endl;
    }
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {

    string imie, nazwisko, numerTelefonu, email, adresZamieszkania;

    adresat.ustawId(plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adresZamieszkania = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdresZamieszkania(adresZamieszkania);

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdresZamieszkania() << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

int AdresatMenedzer::usunAdresata() {
    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (!czyIstniejeAdresat) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}

int AdresatMenedzer::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edytujAdresata() {
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adresZamieszkania = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < (int)adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                imie = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                nazwisko = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                numerTelefonu = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNumerTelefonu(numerTelefonu);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                email = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawEmail(email);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresZamieszkania = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawAdresZamieszkania(adresZamieszkania);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (!czyIstniejeAdresat) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Adresat adresat) {

    plikZAdresatami.edytujAdresataWPliku(adresat);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

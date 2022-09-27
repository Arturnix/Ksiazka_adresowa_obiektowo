#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata () {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawIdKontaktu(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);

    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    string imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    string nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    string numerTelefonu = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    string eMail = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEMail(eMail);

    cout << "Podaj adres: ";
    string adresZamieszkania = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdresZamieszkania (adresZamieszkania);

    return adresat;
}

void AdresatMenedzer::wypiszWszystkichAdresatow () {

    for (int i = 0; i < (int)adresaci.size(); i++) {

        cout << "Imie: " << adresaci[i].pobierzImie() << endl;
        cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << endl;
        cout << "Numer telefonu: " << adresaci[i].pobierzNumerTelefonu() << endl;
        cout << "e-mail: " << adresaci[i].pobierzEMail() << endl;
        cout << "Adres zamieszkania: " << adresaci[i].pobierzAdresZamieszkania() << endl << endl;
    }
    system("pause");
}

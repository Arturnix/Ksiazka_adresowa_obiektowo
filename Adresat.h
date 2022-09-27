#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {

    int idKontaktu;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string eMail;
    string adresZamieszkania;

public:
    void ustawIdUzytkownika (int noweIdUzytkownika);
    void ustawIdKontaktu (int noweIdKontaktu);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEMail(string nowyEMail);
    void ustawAdresZamieszkania(string nowyAdresZamieszkania);

    string pobierzImie ();
    string pobierzNazwisko ();
    string pobierzNumerTelefonu ();
    string pobierzEMail ();
    string pobierzAdresZamieszkania ();
    int pobierzIdKontaktu ();
    int pobierzIdUzytkownika ();
};

#endif // ADRESAT_H

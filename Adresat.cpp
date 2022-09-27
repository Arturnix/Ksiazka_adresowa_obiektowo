#include "Adresat.h"

void Adresat::ustawIdKontaktu (int noweIdKontaktu) {
    idKontaktu = noweIdKontaktu;
}

void Adresat::ustawIdUzytkownika (int noweIdUzytkownika) {
    idUzytkownika = noweIdUzytkownika;
}

void Adresat::ustawImie(string noweImie) {
    imie = noweImie;
}

void Adresat::ustawNazwisko(string noweNazwisko) {
    nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu) {
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustawEMail(string nowyEMail) {
    eMail = nowyEMail;
}

void Adresat::ustawAdresZamieszkania(string nowyAdresZamieszkania) {
    adresZamieszkania = nowyAdresZamieszkania;
}

string Adresat::pobierzImie () {
    return imie;
}

string Adresat::pobierzNazwisko () {
    return nazwisko;
}

string Adresat::pobierzNumerTelefonu () {
    return numerTelefonu;
}

string Adresat::pobierzEMail () {
    return eMail;
}

string Adresat::pobierzAdresZamieszkania () {
    return adresZamieszkania;
}

int Adresat::pobierzIdKontaktu () {
    return idKontaktu;
}

int Adresat::pobierzIdUzytkownika () {
    return idUzytkownika;
}

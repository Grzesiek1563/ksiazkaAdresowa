#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
struct DaneOsoby
{
    int idKontaktu;
    string imie, nazwisko, nrTelefonu, adresZamieszkania, email;
};
bool sprawdzCzyKsiazkaAdresowaZawieraKontakty (vector<DaneOsoby> &kontakty)
{
    if (kontakty.size() == 0)
    {
        cout<<endl<<"Twoja ksiazka adresowa jest pusta. Dodaj nowe kontakty.";
        Sleep(1500);
        return false;
    }
    else
    return true;
}
bool sprawdzCzyIstniejeJuzTakiKontakt (string imie, string nazwisko, vector<DaneOsoby> &kontakty)
{
    bool istniejeJuzTakiKontakt = false;
    int iloscKontaktow = kontakty.size();
    for (int i = 0; i < iloscKontaktow; i++)
    {
        if(imie == kontakty[i].imie && nazwisko == kontakty[i].nazwisko)
        {
            istniejeJuzTakiKontakt = true;
        }
    }
    if(istniejeJuzTakiKontakt)
    {
        cout<<"Posiadasz  juz osobe o takim imieniu i nazwisku w swoich kontaktach. Czy chcesz kontynuowac? (T/N)"<<endl;
        char znakDecyzji = getch();
        if (znakDecyzji == 'N' || znakDecyzji == 'n')
        {
            cout<<"Przerwano dodawanie kontaktu";
            Sleep(1000);
            return false;
        }
    }
    return true;
}
void zapiszDaneUzytkownika(vector<DaneOsoby> &kontakty)
{
    int iloscKontaktow = kontakty.size();
    fstream ksiazkaAdresowa;
    ksiazkaAdresowa.open("daneUzytkownika.txt",ios::out);
    for(int i = 0; i < iloscKontaktow; i++)
    {
        ksiazkaAdresowa<<kontakty[i].idKontaktu<<"|";
        ksiazkaAdresowa<<kontakty[i].imie<<"|";
        ksiazkaAdresowa<<kontakty[i].nazwisko<<"|";
        ksiazkaAdresowa<<kontakty[i].nrTelefonu<<"|";
        ksiazkaAdresowa<<kontakty[i].email<<"|";
        ksiazkaAdresowa<<kontakty[i].adresZamieszkania<<"|"<<endl;
    }
    ksiazkaAdresowa.close();
}
void dodajKontakt (vector<DaneOsoby> &kontakty)
{
    int iloscKontaktow = kontakty.size();
    bool kontynowacDodawanieKontaktu = true;
    DaneOsoby osobaDoDodania;
    string imie, nazwisko;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    kontynowacDodawanieKontaktu = sprawdzCzyIstniejeJuzTakiKontakt(imie,nazwisko,kontakty);
    if(kontynowacDodawanieKontaktu)
    {
        osobaDoDodania.imie = imie;
        osobaDoDodania.nazwisko = nazwisko;
        cout<<"Podaj numer telefonu: ";
        cin.sync();
        getline(cin, osobaDoDodania.nrTelefonu);
        cout<<"Podaj adres zamieszkania: ";
        cin.sync();
        getline(cin, osobaDoDodania.adresZamieszkania);
        cout<<"Podaj email: ";
        cin>>osobaDoDodania.email;
        if (iloscKontaktow == 0)
        {
            osobaDoDodania.idKontaktu = 1;
        }
        else
        {
            osobaDoDodania.idKontaktu = kontakty[iloscKontaktow - 1].idKontaktu + 1;
        }
        kontakty.push_back(osobaDoDodania);
        zapiszDaneUzytkownika(kontakty);
    }
}
void wyszukiwanieImieniem(vector<DaneOsoby> &kontakty, string &imieDoOdszukania)
{
    int iloscKontaktow = kontakty.size();
    bool ksiazkaZawieraPodaneImie = false;
    for(int i = 0; i < iloscKontaktow; i++)
    {
        if (kontakty[i].imie == imieDoOdszukania)
        {
            cout<<"ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
            cout<<kontakty[i].imie<<" "<<kontakty[i].nazwisko<<endl;
            cout<<"Numer telefonu: "<<kontakty[i].nrTelefonu<<endl;
            cout<<"Email: "<<kontakty[i].email<<endl;
            cout<<"Adres zamieszkania: "<<kontakty[i].adresZamieszkania<<endl;
            ksiazkaZawieraPodaneImie = true;
        }
    }
    if (!ksiazkaZawieraPodaneImie)
        cout<<"W Twojej ksiazce nie ma osoby o takim imeniu"<<endl;
    system("pause");
}
void wyszukiwanieNazwiskiem(vector<DaneOsoby> &kontakty, string &nazwiskoDoOdszukania)
{
    int iloscKontaktow = kontakty.size();
    bool ksiazkaZawieraPodaneNazwisko = false;
    for(int i = 0; i < iloscKontaktow; i++)
    {
        if (kontakty[i].nazwisko == nazwiskoDoOdszukania)
        {
            cout<<"ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
            cout<<kontakty[i].imie<<" "<<kontakty[i].nazwisko<<endl;
            cout<<"Numer telefonu: "<<kontakty[i].nrTelefonu<<endl;
            cout<<"Email: "<<kontakty[i].email<<endl;
            cout<<"Adres zamieszkania: "<<kontakty[i].adresZamieszkania<<endl;
            ksiazkaZawieraPodaneNazwisko = true;
        }
    }
    if (!ksiazkaZawieraPodaneNazwisko)
        cout<<"W Twojej ksiazce nie ma osoby o takim nazwisku"<<endl;
    system("pause");
}
void wyswietlWszystkieKontakty(vector<DaneOsoby> &kontakty)
{
    int iloscKontaktow = kontakty.size();
    for(int i = 0; i < iloscKontaktow; i++)
    {
        cout<<"ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
        cout<<kontakty[i].imie<<" "<<kontakty[i].nazwisko<<endl;
        cout<<"Numer telefonu: "<<kontakty[i].nrTelefonu<<endl;
        cout<<"Email: "<<kontakty[i].email<<endl;
        cout<<"Adres zamieszkania: "<<kontakty[i].adresZamieszkania<<endl;
    }
}
void usunAdresata (vector<DaneOsoby> &kontakty)
{
    bool ksiazkaAdresowaZawieraKontakty = sprawdzCzyKsiazkaAdresowaZawieraKontakty(kontakty);
    if (ksiazkaAdresowaZawieraKontakty)
    {
        cout<<"Oto lista wszystkich kontaktow: "<<endl;
        wyswietlWszystkieKontakty(kontakty);
        cout<<"Aby usunac kontakt, wpisz jego ID: ";
        int idKontaktuDoUsuniecia;
        cin>>idKontaktuDoUsuniecia;
        char potwierdzenieUsuniecia;
        cout<<"Czy jestes pewien ze chcesz usunac ten kontakt(t/n)?";
        potwierdzenieUsuniecia = getch();
        if (potwierdzenieUsuniecia == 't' || potwierdzenieUsuniecia == 'T')
        {
            for(int i = 0; i < kontakty.size(); i++)
            {
                if(kontakty[i].idKontaktu == idKontaktuDoUsuniecia)
                {
                    kontakty.erase(kontakty.begin() + i);
                }
            }
        }
        zapiszDaneUzytkownika(kontakty);
    }
}
void edytujAdresata (vector<DaneOsoby> &kontakty)
{
    cout<<"Oto lista wszystkich kontaktow: "<<endl;
    wyswietlWszystkieKontakty(kontakty);
    int idEdytowanegoKontaktu;
    cout<<"Podaj ID kontaktu dla ktorego chcesz wprowadzic zmiany: ";
    cin>>idEdytowanegoKontaktu;
    system("cls");
    cout<<"1 - imie"<<endl<<"2 - nazwisko"<<endl<<"3 - numer telefonu"<<endl;
    cout<<"4 - email"<<endl<<"5 - adres"<<endl<<"6 - powrot do menu"<<endl;
    char znakWyboru;
    znakWyboru = getch();
    system("cls");
    switch(znakWyboru)
    {
    case '1':
    {
        string noweImie;
        cout<<"Podaj nowe imie: ";
        cin>>noweImie;
        for(int i = 0; i < kontakty.size(); i++)
        {
            if(kontakty[i].idKontaktu == idEdytowanegoKontaktu)
                kontakty[i].imie = noweImie;
        }
    }
    break;
    case '2':
    {
        string noweNazwisko;
        cout<<"Podaj nowe nazwisko: ";
        cin>>noweNazwisko;
        for(int i = 0; i < kontakty.size(); i++)
        {
            if(kontakty[i].idKontaktu == idEdytowanegoKontaktu)
                kontakty[i].nazwisko = noweNazwisko;
        }
    }
    break;
    case '3':
    {
        string nowyNrTelefonu;
        cout<<"Podaj nowy numer telefonu: ";
        cin.sync();
        getline(cin, nowyNrTelefonu);
        for(int i = 0; i < kontakty.size(); i++)
        {
            if(kontakty[i].idKontaktu == idEdytowanegoKontaktu)
                kontakty[i].nrTelefonu = nowyNrTelefonu;
        }
    }
    break;
    case '4':
    {
        string nowyEmail;
        cout<<"Podaj nowy email: ";
        cin>>nowyEmail;
        for(int i = 0; i < kontakty.size(); i++)
        {
            if(kontakty[i].idKontaktu == idEdytowanegoKontaktu)
                kontakty[i].email = nowyEmail;
        }
    }
    break;
    case '5':
    {
        string nowyAdres;
        cout<<"Podaj nowy adres: ";
        cin.sync();
        getline(cin, nowyAdres);
        for(int i = 0; i < kontakty.size(); i++)
        {
            if(kontakty[i].idKontaktu == idEdytowanegoKontaktu)
                kontakty[i].adresZamieszkania = nowyAdres;
        }
    }
    break;
    case '6':
    {
        ;
    }
    break;
    default:
    {
        cout<<"Wybrales nieprawidlowy numer."<<endl;
        Sleep(1500);
    }
    }
    zapiszDaneUzytkownika(kontakty);
}
vector<DaneOsoby> wczytajDaneUzytkownika()
{
    fstream ksiazkaAdresowa;
    ksiazkaAdresowa.open("daneUzytkownika.txt",ios::in);
    vector<DaneOsoby> kontakty(0);
    if (ksiazkaAdresowa.good() == true)
    {
        string zaczytanaLinia;
        string daneAdresata [6];
        while(getline(ksiazkaAdresowa, zaczytanaLinia))
        {
            int indeksDanej = 0;
            DaneOsoby osobaDoPrzypisania;
            string danaDoPrzypisania = "";
            int dlugoscZaczytanejLinii = zaczytanaLinia.length();
            for(int i=0; i<dlugoscZaczytanejLinii; i++)
            {
                if(zaczytanaLinia[i] != '|')
                {
                    danaDoPrzypisania += zaczytanaLinia[i];
                }
                else if(zaczytanaLinia[i] == '|')
                {
                    daneAdresata[indeksDanej] = danaDoPrzypisania;
                    danaDoPrzypisania = "";
                    indeksDanej++;
                }
            }
            osobaDoPrzypisania.idKontaktu = atoi(daneAdresata[0].c_str());
            osobaDoPrzypisania.imie = daneAdresata[1];
            osobaDoPrzypisania.nazwisko = daneAdresata[2];
            osobaDoPrzypisania.nrTelefonu = daneAdresata[3];
            osobaDoPrzypisania.email = daneAdresata[4];
            osobaDoPrzypisania.adresZamieszkania = daneAdresata[5];
            kontakty.push_back(osobaDoPrzypisania);
        }
    }
    ksiazkaAdresowa.close();
    return kontakty;
}
int main()
{
    bool ksiazkaAdresowaZawieraKontakty = false;
    vector<DaneOsoby> kontakty(0);
    kontakty = wczytajDaneUzytkownika();
    char wyborOpcji;
    while (1)
    {
        system("cls");
        cout<<"KSIAZKA ADRESOWA"<<endl;
        cout<<"1. Dodaj adresata"<<endl;
        cout<<"2. Wyszukaj po imieniu"<<endl;
        cout<<"3. Wyszukaj po nazwisku"<<endl;
        cout<<"4. Wyswietl wszystkich adresatow"<<endl;
        cout<<"5. Usun adresata"<<endl;
        cout<<"6. Edytuj adresata"<<endl;
        cout<<"9. Zakoncz program"<<endl;
        cout<<"Twoj wybor: ";
        wyborOpcji = getch();
        switch(wyborOpcji)
        {
        case '1':
        {
            system("cls");
            dodajKontakt(kontakty);
        }
        break;
        case '2':
        {
            system("cls");
            ksiazkaAdresowaZawieraKontakty = sprawdzCzyKsiazkaAdresowaZawieraKontakty(kontakty);
            if (ksiazkaAdresowaZawieraKontakty)
            {
                string imieDoOdszukania;
                cout<<"Podaj imie: ";
                cin>>imieDoOdszukania;
                wyszukiwanieImieniem(kontakty, imieDoOdszukania);
            }
        }
        break;
        case '3':
        {
            system("cls");
            ksiazkaAdresowaZawieraKontakty = sprawdzCzyKsiazkaAdresowaZawieraKontakty(kontakty);
            if (ksiazkaAdresowaZawieraKontakty)
            {
                string nazwiskoDoOdszukania;
                cout<<"Podaj nazwisko: ";
                cin>>nazwiskoDoOdszukania;
                wyszukiwanieNazwiskiem(kontakty, nazwiskoDoOdszukania);
            }
        }
        break;
        case '4':
        {
            system("cls");
            ksiazkaAdresowaZawieraKontakty = sprawdzCzyKsiazkaAdresowaZawieraKontakty(kontakty);
            if (ksiazkaAdresowaZawieraKontakty)
            {
                wyswietlWszystkieKontakty(kontakty);
                system("pause");
            }
        }
        break;
        case '5':
        {
            system("cls");
            usunAdresata(kontakty);
        }
        break;
        case '6':
        {
            system("cls");
            edytujAdresata(kontakty);
        }
        break;
        case '9':
        {
            exit(0);
        }

        break;
        default:
        {
            cout<<"Wybrales nieprawidlowy numer."<<endl;
            Sleep(1500);
        }
        }
    }
    return 0;
}

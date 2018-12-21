#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include<Portfelinw.h>
#include<Aktywo.h>

using namespace std;

int main()
{
    int choice;
    Portfelinw <Aktywo> portfel;
    portfel.wczytaj();
    while(1)
    {
        cout<<"1.Dodaj skladnik"<<endl<<"2.Usun skladnik"<<endl<<"3.Edytuj skladnik"<<endl<<"4.Wyswietl stan oszczednosci"<<endl<<"5.Wyjdz"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            portfel.dodaj();
            break;
        case 2:
            portfel.usun();
            break;
        case 3:
            portfel.edytuj();
            break;
        case 4:
            portfel.symulacja();
            break;
        case 5:
            portfel.zapisz();
            exit(0);
            break;
        }
        portfel.odswiez();
    }
    return 0;
}

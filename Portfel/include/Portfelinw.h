#ifndef PORTFELINW_H
#define PORTFELINW_H
#include<Nieruchomosc.h>
#include<Kontrakt.h>
#include<Funduszinw.h>
#include<Funduszinwzdyw.h>
#include<Lokata.h>
#include<fstream>

template <class T> class Portfelinw
{
    public:
        Portfelinw()
        {
            rozmiartabnier=0;
            rozmiartabkon=0;
            rozmiartabfun=0;
            rozmiartabdyw=0;
            rozmiartablok=0;
            oszczednosci=0;
        }
        virtual ~Portfelinw() {}
        double Getoszczednosci() { return oszczednosci; }
        void Setoszczednosci(double val) { oszczednosci = val; }
        void dodaj()
        {
            int choice;
            double val,val1;
            string val2;
            cout<<"1.Nieruchomosc"<<endl<<"2.Kontrakt"<<endl<<"3.Fundusz inwestycyjny"<<endl<<"4.Fundusz inwestycyjny z dywidenda"<<endl<<"5.Lokata"<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                {
                    cout<<"Podaj wartosc: ";
                    cin>>val;
                    cout<<"Podaj nazwe: ";
                    cin>>val2;
                    Nieruchomosc * nieruchomosc=new Nieruchomosc(val,val2);
                    listanieruchomosci[rozmiartabnier]=nieruchomosc;
                    spalonenier[rozmiartabnier]=1;
                    rozmiartabnier++;
                    oszczednosci=oszczednosci+nieruchomosc->Getwartosc();
                    break;
                }
            case 2:
                {
                    cout<<"Podaj przychod: ";
                    cin>>val;
                    cout<<"Podaj nazwe: ";
                    cin>>val2;
                    Kontrakt * kontrakt=new Kontrakt(val,val2);
                    listakontraktow[rozmiartabkon]=kontrakt;
                    spalonekon[rozmiartabkon]=1;
                    rozmiartabkon++;
                    break;
                }
            case 3:
                {
                    cout<<"Podaj wartosc: ";
                    cin>>val;
                    cout<<"Podaj nazwe: ";
                    cin>>val2;
                    Funduszinw * fundusz=new Funduszinw(val,val2);
                    listafunduszy[rozmiartabfun]=fundusz;
                    spalonefun[rozmiartabfun]=1;
                    rozmiartabfun++;
                    oszczednosci=oszczednosci+fundusz->Getwartosc();
                    break;
                }
            case 4:
                {
                    cout<<"Podaj wartosc: ";
                    cin>>val;
                    cout<<"Podaj dywidende: ";
                    cin>>val1;
                    cout<<"Podaj nazwe: ";
                    cin>>val2;
                    Funduszinwzdyw * funduszzdyw=new Funduszinwzdyw(val,val1,val2);
                    listazdywidenda[rozmiartabdyw]=funduszzdyw;
                    spalonedyw[rozmiartabdyw]=1;
                    rozmiartabdyw++;
                    oszczednosci=oszczednosci+funduszzdyw->Getwartosc();
                    break;
                }
            case 5:
                {
                    cout<<"Podaj stan konta: ";
                    cin>>val;
                    cout<<"Podaj oprocentowanie: ";
                    cin>>val1;
                    cout<<"Podaj nazwe: ";
                    cin>>val2;
                    Lokata * lokata=new Lokata(val,val1,val2);
                    listalokat[rozmiartablok]=lokata;
                    spalonelok[rozmiartablok]=1;
                    rozmiartablok++;
                    oszczednosci=oszczednosci+lokata->Getstankonta();
                    break;
                }
            }
        }
        void usun()
        {
            int choice,index,flag=0;
            cout<<"1.Nieruchomosc"<<endl<<"2.Kontrakt"<<endl<<"3.Fundusz inwestycyjny"<<endl<<"4.Fundusz inwestycyjny z dywidenda"<<endl<<"5.Lokata"<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                for(int i=0;i<rozmiartabnier;i++)
                {
                    if(spalonenier[i])
                    {
                        cout<<i<<"."<<listanieruchomosci[i]->Getnazwa()<<endl;
                        flag=1;
                    }
                }
                if(flag)
                {
                    cin>>index;
                    oszczednosci-=listanieruchomosci[index]->Getwartosc();
                    delete listanieruchomosci[index];
                    spalonenier[index]=0;
                }
                break;
            case 2:
                for(int i=0;i<rozmiartabkon;i++)
                {
                    if(spalonekon[i])
                    {
                        cout<<i<<"."<<listakontraktow[i]->Getnazwa()<<endl;
                        flag=1;
                    }
                }
                if(flag)
                {
                    cin>>index;
                    delete listakontraktow[index];
                    spalonekon[index]=0;
                }
                break;
            case 3:
                for(int i=0;i<rozmiartabfun;i++)
                {
                    if(spalonefun[i])
                    {
                        cout<<i<<"."<<listafunduszy[i]->Getnazwa()<<endl;
                        flag=1;
                    }
                }
                if(flag)
                {
                    cin>>index;
                    oszczednosci-=listafunduszy[index]->Getwartosc();
                    delete listafunduszy[index];
                    spalonefun[index]=0;
                }
                break;
            case 4:
                for(int i=0;i<rozmiartabdyw;i++)
                {
                    if(spalonedyw[i])
                    {
                        cout<<i<<"."<<listazdywidenda[i]->Getnazwa()<<endl;
                        flag=1;
                    }
                }
                if(flag)
                {
                    cin>>index;
                    oszczednosci-=listazdywidenda[index]->Getwartosc();
                    delete listazdywidenda[index];
                    spalonedyw[index]=0;
                }
                break;
            case 5:
                for(int i=0;i<rozmiartablok;i++)
                {
                    if(spalonelok[i])
                    {
                        cout<<i<<"."<<listalokat[i]->Getnazwa()<<endl;
                        flag=1;
                    }
                }
                if(flag)
                {
                    cin>>index;
                    oszczednosci-=listalokat[index]->Getstankonta();
                    delete listalokat[index];
                    spalonelok[index]=0;
                }
                break;
            }
        }
        void edytuj()
        {
            int choice,index,updown;
            double zmiana;
            cout<<"1.Nieruchomosc"<<endl<<"2.Kontrakt"<<endl<<"3.Fundusz inwestycyjny"<<endl<<"4.Fundusz inwestycyjny z dywidenda"<<endl<<"5.Lokata"<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                for(int i=0;i<rozmiartabnier;i++)
                {
                    if(spalonenier[i])
                    {
                        cout<<i<<"."<<listanieruchomosci[i]->Getnazwa()<<endl;
                    }
                }
                cin>>index;
                cout<<"Podaj nowa wartosc"<<endl;
                cin>>zmiana;
                listanieruchomosci[index]->Setwartosc(zmiana);
                break;
            case 2:
                for(int i=0;i<rozmiartabkon;i++)
                {
                    if(spalonekon[i])
                    {
                        cout<<i<<"."<<listakontraktow[i]->Getnazwa()<<endl;
                    }
                }
                cin>>index;
                cout<<"Podaj nowy przychod"<<endl;
                cin>>zmiana;
                listakontraktow[index]->Setprzychod(zmiana);
                break;
            case 3:
                for(int i=0;i<rozmiartabfun;i++)
                {
                    if(spalonefun[i])
                    {
                        cout<<i<<"."<<listafunduszy[i]->Getnazwa()<<endl;
                    }
                }
                cin>>index;
                cout<<"Podaj nowa wartosc"<<endl;
                cin>>zmiana;
                listafunduszy[index]->Setwartosc(zmiana);
                break;
            case 4:
                for(int i=0;i<rozmiartabdyw;i++)
                {
                    if(spalonedyw[i])
                    {
                        cout<<i<<"."<<listazdywidenda[i]->Getnazwa()<<endl;
                    }
                }
                cin>>index;
                cout<<"1.Zmien wartosc funduszu"<<endl<<"2.Zmien dywidende funduszu"<<endl;
                cin>>updown;
                if(updown==1)
                {
                    cout<<"Podaj nowa wartosc"<<endl;
                    cin>>zmiana;
                    listazdywidenda[index]->Setwartosc(zmiana);
                }
                else
                {
                    cout<<"Podaj nowa dywidende"<<endl;
                    cin>>zmiana;
                    listazdywidenda[index]->Setdywidenda(zmiana);
                }
                break;
            case 5:
                for(int i=0;i<rozmiartablok;i++)
                {
                    if(spalonelok[i])
                    {
                        cout<<i<<"."<<listalokat[i]->Getnazwa()<<endl;
                    }
                }
                cin>>index;
                cout<<"1.Zmien stan konta na lokacie"<<endl<<"2.Zmien oprocentowanie lokaty"<<endl;
                cin>>updown;
                if(updown==1)
                {
                    cout<<"Podaj nowy stan konta"<<endl;
                    cin>>zmiana;
                    listalokat[index]->Setstankonta(zmiana);
                }
                else
                {
                    cout<<"Podaj nowe oprocentowanie"<<endl;
                    cin>>zmiana;
                    listalokat[index]->Setoprocentowanie(zmiana);
                }
                break;
            }
        }
        void odswiez()
        {
            for(int i=0;i<rozmiartabkon;i++)
            {
                if(spalonekon[i])
                    oszczednosci+=listakontraktow[i]->Getprzychod();
            }
            for(int i=0;i<rozmiartabdyw;i++)
            {
                if(spalonedyw[i])
                    oszczednosci+=listazdywidenda[i]->Getdywidenda();
            }
            for(int i=0;i<rozmiartablok;i++)
            {
                if(spalonelok[i])
                {
                    double wzrost=listalokat[i]->Getstankonta()*listalokat[i]->Getoprocentowanie();
                    oszczednosci+=wzrost;
                    listalokat[i]->Setstankonta(listalokat[i]->Getstankonta()+wzrost);
                }
            }
            stanoszczednosci[rozmiartaboszcz]=oszczednosci;
            rozmiartaboszcz++;
        }
        void symulacja()
        {
            int counter;
            cout<<"Z ilu iteracji zasymulowac stan oszczednosci? (max "<<rozmiartaboszcz<<")"<<endl;
            cin>>counter;
            for(int i=rozmiartaboszcz-counter;i<rozmiartaboszcz;i++)
            {
                cout<<i+1<<"."<<stanoszczednosci[i]<<endl;
            }
        }
        void zapisz()
        {
            int n=0;
            fstream plik;
            plik.open("save.txt",ios::out|ios::trunc);
            plik<<oszczednosci<<endl;
            for(int i=0;i<rozmiartabnier;i++) n+=spalonenier[i];
            plik<<n<<endl;
            for(int i=0;i<rozmiartabnier;i++)
            {
                if(spalonenier[i])
                    plik<<listanieruchomosci[i]->Getnazwa()<<endl<<listanieruchomosci[i]->Getwartosc()<<endl;
            }
            n=0;
            for(int i=0;i<rozmiartabkon;i++) n+=spalonekon[i];
            plik<<n<<endl;
            for(int i=0;i<rozmiartabkon;i++)
            {
                if(spalonekon[i])
                    plik<<listakontraktow[i]->Getnazwa()<<endl<<listakontraktow[i]->Getprzychod()<<endl;
            }
            n=0;
            for(int i=0;i<rozmiartabfun;i++) n+=spalonefun[i];
            plik<<n<<endl;
            for(int i=0;i<rozmiartabfun;i++)
            {
                if(spalonefun[i])
                    plik<<listafunduszy[i]->Getnazwa()<<endl<<listafunduszy[i]->Getwartosc()<<endl;
            }
            n=0;
            for(int i=0;i<rozmiartabdyw;i++) n+=spalonedyw[i];
            plik<<n<<endl;
            for(int i=0;i<rozmiartabdyw;i++)
            {
                if(spalonedyw[i])
                    plik<<listazdywidenda[i]->Getnazwa()<<endl<<listazdywidenda[i]->Getwartosc()<<endl<<listazdywidenda[i]->Getdywidenda()<<endl;
            }
            n=0;
            for(int i=0;i<rozmiartablok;i++) n+=spalonelok[i];
            plik<<n<<endl;
            for(int i=0;i<rozmiartablok;i++)
            {
                if(spalonelok[i])
                    plik<<listalokat[i]->Getnazwa()<<endl<<listalokat[i]->Getstankonta()<<endl<<listalokat[i]->Getoprocentowanie()*100<<endl;
            }
            plik.close();
        }
        void wczytaj()
        {
            fstream plik;
            string nazwa;
            double val,val1;
            plik.open("save.txt",ios::in);
            plik>>oszczednosci;
            plik>>rozmiartabnier;
            for(int i=0;i<rozmiartabnier;i++) spalonenier[i]=1;
            for(int i=0;i<rozmiartabnier;i++)
            {
                plik>>nazwa;
                plik>>val;
                Nieruchomosc * nieruchomosc=new Nieruchomosc(val,nazwa);
                listanieruchomosci[i]=nieruchomosc;
            }
            plik>>rozmiartabkon;
            for(int i=0;i<rozmiartabkon;i++) spalonekon[i]=1;
            for(int i=0;i<rozmiartabkon;i++)
            {
                plik>>nazwa;
                plik>>val;
                Kontrakt * kontrakt=new Kontrakt(val,nazwa);
                listakontraktow[i]=kontrakt;
            }
            plik>>rozmiartabfun;
            for(int i=0;i<rozmiartabfun;i++) spalonefun[i]=1;
            for(int i=0;i<rozmiartabfun;i++)
            {
                plik>>nazwa;
                plik>>val;
                Funduszinw * fundusz=new Funduszinw(val,nazwa);
                listafunduszy[i]=fundusz;
            }
            plik>>rozmiartabdyw;
            for(int i=0;i<rozmiartabdyw;i++) spalonedyw[i]=1;
            for(int i=0;i<rozmiartabdyw;i++)
            {
                plik>>nazwa;
                plik>>val;
                plik>>val1;
                Funduszinwzdyw * funduszzdyw=new Funduszinwzdyw(val,val1,nazwa);
                listazdywidenda[i]=funduszzdyw;
            }
            plik>>rozmiartablok;
            for(int i=0;i<rozmiartablok;i++) spalonelok[i]=1;
            for(int i=0;i<rozmiartablok;i++)
            {
                plik>>nazwa;
                plik>>val;
                plik>>val1;
                Lokata * lokata=new Lokata(val,val1,nazwa);
                listalokat[i]=lokata;
            }
            plik.close();
        }
    protected:
    private:
        double oszczednosci=0;
        Nieruchomosc * listanieruchomosci[10000];
        int rozmiartabnier=0;
        int spalonenier[10000];
        Kontrakt * listakontraktow[10000];
        int rozmiartabkon=0;
        int spalonekon[10000];
        Lokata * listalokat[10000];
        int rozmiartablok=0;
        int spalonelok[10000];
        Funduszinw * listafunduszy[10000];
        int rozmiartabfun=0;
        int spalonefun[10000];
        Funduszinwzdyw * listazdywidenda[10000];
        int rozmiartabdyw=0;
        int spalonedyw[10000];
        double stanoszczednosci[100000];
        int rozmiartaboszcz=0;
};

#endif // PORTFELINW_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <typeinfo>
using namespace std;

///***********************************************///
class Masina
{
protected:
    int id;
    int nr_locuri;
    static int nr_masini;
public:
    Masina(int,int);
    Masina(const Masina&);
    virtual ~Masina();

    Masina& operator=(Masina&);

    void set_id(int id){this->id=id;}
    int get_id()const {return id;}

    void set_nr_locuri(int nr_locuri){this->nr_locuri=nr_locuri;}
    int get_nr_locuri()const {return nr_locuri;}

    virtual void citire(istream&);
    friend istream& operator>>(istream&, Masina&);

    virtual void afisare(ostream&) const;
    friend ostream& operator<<(ostream&, Masina&);

    static void nrMasini(){
        cout<<"La expozitie sunt expuse: "<<nr_masini<<" masini"<<endl;
    }
    int static get_nr_masini(){return nr_masini;}

};
int Masina::nr_masini;

Masina::Masina(int id=0, int nr_locuri=0)
{
    this->id=id;
    this->nr_locuri=nr_locuri;
    nr_masini++;
}
Masina::~Masina()
{
    this->id=0;
    this->nr_locuri=0;
}
Masina::Masina(const Masina& m)
{
    this->id=m.id;
    this->nr_locuri=m.nr_locuri;
}
Masina& Masina::operator=(Masina& m)
{
    if(this!=&m)
    {
        this->id=m.id;
        this->nr_locuri=m.nr_locuri;
    }
    return *this;
}
void Masina::citire(istream& in)
{
    cout<<"Introduceti id-ul masinii: ";
    in>>id;
    cout<<"Introduceti nr de locuri ale masinii: ";
    in>>nr_locuri;
}
istream& operator>>(istream& in, Masina& m)
{
    m.citire(in);
    return in;
}
void Masina::afisare(ostream& out) const
{
    out<<"Id-ul masinii este: "<<id<<endl;
    out<<"Masina are "<<nr_locuri<<" locuri"<<endl;
}
ostream& operator<<(ostream& out, Masina& m)
{
    m.afisare(out);
    return out;
}

///***********************************************///
class Coupe:public Masina
{
private:
    int nivel_rigiditate;
public:
    Coupe(int, int, int);
    Coupe(const Coupe&);
    ~Coupe();

    Coupe& operator=(Coupe&);

    void citire(istream&);
    friend istream& operator>>(istream&, Coupe&);

    void afisare(ostream&) const;
    friend ostream& operator<<(ostream&, Coupe&);
};
Coupe::Coupe(int id=0, int nr_locuri=0, int nivel_rigiditate=0):Masina(id, nr_locuri)
{
    this->nivel_rigiditate=nivel_rigiditate;
}
Coupe::~Coupe()
{
    this->nivel_rigiditate=0;
}
Coupe::Coupe(const Coupe& c):Masina(c)
{
    this->nivel_rigiditate=c.nivel_rigiditate;
}
Coupe& Coupe::operator=(Coupe& c)
{
    if(this!=&c)
    {
        Masina::operator=(c);
        this->nivel_rigiditate=c.nivel_rigiditate;
    }
    return *this;
}
void Coupe::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Introduceti nivelul de rigiditate: ";
    in>>nivel_rigiditate;
}
istream& operator>>(istream& in, Coupe& c)
{
    c.citire(in);
    return in;
}
void Coupe::afisare(ostream& out) const
{
    Masina::afisare(out);
    out<<"Nivelul de rigiditate este: "<<nivel_rigiditate<<endl;
}
ostream& operator<<(ostream& out, Coupe& c)
{
    c.afisare(out);
    return out;
}

///***********************************************///
class HotHatch:public Masina
{
private:
    string clasa;
public:
    HotHatch(int, int, string);
    HotHatch(const HotHatch&);
    ~HotHatch();

    HotHatch& operator=(HotHatch&);

    void citire(istream&);
    friend istream& operator>>(istream&, HotHatch&);

    void afisare(ostream&) const;
    friend ostream& operator<<(ostream&, HotHatch&);
};
HotHatch::HotHatch(int id=0, int nr_locuri=0, string clasa=""):Masina(id, nr_locuri)
{
    this->clasa=clasa;
}
HotHatch::~HotHatch()
{
    this->clasa="";
}
HotHatch::HotHatch(const HotHatch& h):Masina(h)
{
    this->clasa=h.clasa;
}
HotHatch& HotHatch::operator=(HotHatch& h)
{
    if(this!=&h)
    {
        Masina::operator=(h);
        this->clasa=h.clasa;
    }
    return *this;
}
void HotHatch::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Introduceti clasa: ";
        in>>clasa;

}
istream& operator>>(istream& in, HotHatch& h)
{
    h.citire(in);
    return in;
}
void HotHatch::afisare(ostream& out) const
{
    Masina::afisare(out);
    out<<"Clasa este: "<<clasa<<endl;
}
ostream& operator<<(ostream& out, HotHatch& h)
{
    h.afisare(out);
    return out;
}
///***********************************************///
class Cabrio:public Masina
{
private:
    string material_plafon;
public:
    Cabrio(int, int, string);
    Cabrio(const Cabrio&);
    ~Cabrio();

    Cabrio& operator=(Cabrio&);

    void citire(istream&);
    friend istream& operator>>(istream&, Cabrio&);

    void afisare(ostream&) const;
    friend ostream& operator<<(ostream&, Cabrio&);
};
Cabrio::Cabrio(int id=0, int nr_locuri=0, string material_plafon=""):Masina(id, nr_locuri)
{
    this->material_plafon=material_plafon;
}
Cabrio::~Cabrio()
{
    this->material_plafon="";
}
Cabrio::Cabrio(const Cabrio& c):Masina(c)
{
    this->material_plafon=c.material_plafon;
}
Cabrio& Cabrio::operator=(Cabrio& c)
{
    if(this!=&c)
    {
        Masina::operator=(c);
        this->material_plafon=c.material_plafon;
    }
    return *this;
}
void Cabrio::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Introduceti materialul plafonului: ";
    in>>material_plafon;
}
istream& operator>>(istream& in, Cabrio& c)
{
    c.citire(in);
    return in;
}
void Cabrio::afisare(ostream& out) const
{
    Masina::afisare(out);
    out<<"Materialul plafonului este: "<<material_plafon<<endl;
}
ostream& operator<<(ostream& out, Cabrio& c)
{
    c.afisare(out);
    return out;
}
///***********************************************///
class SuperSport:public Masina
{
private:
    string status;
    int pret;
public:
    SuperSport(int, int, string, int);
    SuperSport(const SuperSport&);
    ~SuperSport();

    void set_status(string status){this->status=status;}
    string get_status()const {return status;}

    void set_pret(int pret){this->pret=pret;}
    int get_pret()const {return pret;}

    SuperSport& operator=(SuperSport&);

    void citire(istream&);
    friend istream& operator>>(istream&, SuperSport&);

    void afisare(ostream&) const;
    friend ostream& operator<<(ostream&, SuperSport&);

    friend bool operator==(SuperSport& s1, SuperSport& s2);
};
SuperSport::SuperSport(int id=0, int nr_locuri=0, string status="", int pret=0):Masina(id, nr_locuri)
{
    this->status=status;
    this->pret=pret;
}
SuperSport::~SuperSport()
{
    this->status="";
    this->pret=0;
}
SuperSport::SuperSport(const SuperSport& s):Masina(s)
{
    this->status=s.status;
    this->pret=s.pret;
}
SuperSport& SuperSport::operator=(SuperSport& s)
{
    if(this!=&s)
    {
        Masina::operator=(s);
        this->status=status;
        this->pret=pret;
    }
    return *this;
}
bool operator==(SuperSport& s1, SuperSport& s2)
{
    if(s1.status==s2.status and s1.pret==s2.pret) return true;
    else return false;
}
void SuperSport::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Pretul masinii supersport este: ";
    in>>pret;
    try{
        cout<<"Statusul unul masini este vanduta/nevanduta. Introduceti statusul: ";
        in>>status;
        if(status!="vanduta" and status!="nevanduta") throw 1;
    }
    catch(int i)
    {
        cout<<"Nu ati introdus statusul corect! Alegeti dintre statusul de vanduta/nevanduta!";
        exit(EXIT_FAILURE);
    }
}
istream& operator>>(istream& in, SuperSport& s)
{
    s.citire(in);
    return in;
}
void SuperSport::afisare(ostream& out) const
{
    Masina::afisare(out);
    out<<"Pretul este: "<<pret<<endl;
    out<<"Statusul este: "<<status<<endl;
}
ostream& operator<<(ostream& out, SuperSport& s)
{
    s.afisare(out);
    return out;
}
///***********************************************///
void model(Masina*& m, int &i)
{
    string s;
    cout<<"Introduceti tipul masinii "<<i+1<<" ";
    cin>>s;
    try{
        if(s=="Coupe")
        {
            m=new Coupe;
            cin>>*m;
            i++;
        }
        else if(s=="HotHatch")
        {
            m=new HotHatch;
            cin>>*m;
            i++;
        }
        else if(s=="Cabrio")
        {
            m=new Cabrio;
            cin>>*m;
            i++;
        }
        else if(s=="SuperSport")
        {
            m=new SuperSport;
            cin>>*m;
            i++;
        }
        else throw 2;
    }
    catch(int x)
    {
        cout<<"Nu ati introdus un tip de masina valid. Incercati cu modelele: Coupe/HotHatch/Cabrio/SuperSport!"<<endl;
        cout<<"Atentie la scriere!"<<endl;
    }
    catch(bad_alloc var)
    {
        cout<<"Bad Alloc";
        exit(EXIT_FAILURE);
    }
}
template <class t> class Expozitie
{
    t *e; //delcarare vector de obiecte al unei clase
    int nr; //nr de obiecte al clasei
public:
    Expozitie(t *p=NULL, int n=0) //constructor al clasei
    {
        nr=n;
        e=new t[n]; //aloc memorie pt n obiecte
        for(int i=0;i<n;i++)
            e[i]=p[i]; //salvez in vector obiectele
    }
    Expozitie(Expozitie &x) //constructor de copiere
    {
        nr=x.nr; //copiez nr de obiecte
        e=new t[nr]; //aloc memorie
        for(int i=0;i<nr;i++)
            e[i]=x.e[i]; //copiez si elem cu elem
    }
    ~Expozitie()//destructor
    {
        delete [] e;
    }
    int get_nr(){return nr;} //getter
    t get_v(int i){return e[i];} //getter
    friend istream& operator>>(istream &in, Expozitie <t> &g)
    {
        cout<<"Introduceti numarul de masini ale expozitiei: ";
        in>>g.nr;
        g.e=new t[g.nr]; //aloc memorie in vectorul de obiecte
        cout<<"\n   Introduceti masinile "<<endl;
        for(int i=0;i<g.nr;i++)
        {
            in>>g.e[i];
            cout<<endl;
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Expozitie <t> &g)
    {
        out<<"   La expozitie sunt expuse "<<g.nr<<" masini"<<endl;
        for(int i=0;i<g.nr;i++)
            out<<g.e[i]<<endl;
        return out;
    }
};
template <> class Expozitie <SuperSport>
{
    SuperSport* stoc;
    SuperSport* vandute;
    int nr_stoc;
    int nr_vandute;
public:
    Expozitie(SuperSport *s=NULL, SuperSport *v=NULL, int nr_stoc=0, int nr_vandute=0)
    {
        this->nr_stoc=nr_stoc;
        this->nr_vandute=nr_vandute;
        try
        {
            s=new SuperSport[nr_stoc];
            v=new SuperSport[nr_vandute];
        }
        catch(bad_alloc var)
        {
            cout<<"Bad alloc \n";
            exit(EXIT_FAILURE);
        }
    }
    ~Expozitie() //destructor
    {
        delete [] stoc;
        delete [] vandute;
    }

   SuperSport get_stoc(int i){return stoc[i];} //getter
    SuperSport& operator-=(SuperSport& super)
    {
        if(nr_stoc==0) cout<<"Nu mai sunt masini nevandute: \n";
        else
        {
            for(int i=0;i<nr_stoc;i++)
                if(stoc[i].get_status()=="nevanduta" and stoc[i].get_pret()==super.get_pret() and stoc[i].get_id()==super.get_id() and stoc[i].get_nr_locuri()==super.get_nr_locuri())
                    {
                        vandute[nr_vandute++]=stoc[i];
                        stoc[i]=stoc[i+1];
                        nr_stoc--;
                    }
                else
                    {
                        cout<<"Masina introdusa nu este in stoc! Verificati stocul pentru a alege o masina! \n";
                        break;
                    }
        }
    }
    int get_stoc(){return nr_stoc;} //getter nr masini din stoc
    int get_vandute(){return nr_vandute;} //getter nr masini vandute
    void add_super(SuperSport& super)
    {
        if(super.get_status()=="nevanduta")
            stoc[nr_stoc++]=super;//adaugare masina supersport
        else if(super.get_status()=="vanduta") vandute[nr_vandute++]=super;
    }
    friend istream& operator>>(istream &in, Expozitie <SuperSport> &g)
    {
        cout<<"Introduceti numarul de masini din stoc: ";
        in>>g.nr_stoc;
        g.stoc=new SuperSport[g.nr_stoc]; //aloc memorie in vectorul de obiecte
        cout<<"\n   Introduceti masinile "<<endl;
        for(int i=0;i<g.nr_stoc;i++)
        {
            cout<<"Introduceti masina care mai e in stoc: \n";
            try
            {
                in>>g.stoc[i];
                 if(g.stoc[i].get_status()!="nevanduta") throw 1;
            }
            catch(int j)
            {
                cout<<"Introduceti statusul corect al masinii! Incercati cu nevanduta! \n";
                i--;
            }

            cout<<endl;
        }
        cout<<"\n   Introduceti numarul de masini care au fost vandute: ";
        in>>g.nr_vandute;
        g.vandute=new SuperSport[g.nr_vandute]; //aloc memorie in vectorul de obiecte
        cout<<"\n   Introduceti masinile "<<endl;
        for(int i=0;i<g.nr_vandute;i++)
        {
            cout<<"Introduceti masina care a fost vanduta: \n";
            try
            {
                in>>g.vandute[i];
                if(g.vandute[i].get_status()!="vanduta") throw 2;
            }
            catch(int j)
            {
                 cout<<"Introduceti statusul corect al masinii! Incercati cu vanduta! \n";
                i--;
            }
            cout<<endl;
        }
        return in;
    }
    void afisare_stoc()
    {
        cout<<"Afisam masinile din stoc \n";
        if(nr_stoc==0)
        {
            cout<<"Nu mai sunt masini pe stoc \n";
            return;

        }
        else
        {
           for(int i=0;i<nr_stoc;i++)
            {
                if(stoc[i].get_status()=="nevanduta")
                    cout<<stoc[i]<<endl;
            }
        }
    }
    void afisare_vandute()
    {

        if(nr_vandute==0) cout<<"Nu au fost vandute masini \n";
        else
        {
            cout<<"Afisam masinile vandute \n";
            for(int i=0;i<nr_vandute;i++)
            {
                if(vandute[i].get_status()=="vanduta")
                    cout<<vandute[i]<<endl;
            }
        }
    }
};
///Mentionez ca meniul interactiv a fost luat din cadrul laboratorului de POO
void menu_output()
{
    cout<<"\n Lapadus Raluca 254 - Proiect 3 - Nume proiect: Expozitie Masini - Tema 5 \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1.  Citim si afisam n obiecte: "; cout<<"\n";
    cout<<"2.  Verificare stoc masini: "; cout<<"\n";
    cout<<"3.  Expozitie --- Template Coupe"; cout<<"\n";
    cout<<"4.  Expozitie --- Template HotHatc"; cout<<"\n";
    cout<<"5.  Expozitie --- Template Cabrio"; cout<<"\n";
    cout<<"6.  Citit masinile SuperSport de la expozitie --- Template SuperSport Specializare"; cout<<"\n";
    cout<<"7.  Vindeti o masina SuperSport din stoc --- Template SuperSport Specializare"; cout<<"\n";
    cout<<"8.  Afisati starea expozitiei --- Template SuperSport Specializare"; cout<<"\n";
    cout<<"9. Afisati masinile SuperSport din stoc --- Template SuperSport Specializare"; cout<<"\n";
    cout<<"10. Afisati masinile SuperSport vandute --- Template SuperSport Specializare"; cout<<"\n";
    cout<<"11. Afisare STL dupa ce ati citit masinile cu ajutorul optiunii 1"; cout<<"\n";
    cout<<"0.  Iesire."; cout<<"\n";
}
void menu()
{
    int option=0, n=0;
    Masina **m;
    Expozitie<SuperSport> s;
    do{
        menu_output();
        cout<<"Introduceti optiunea dorita: ";
        cin>>option;
        if(option==1)
        {
            cout<<"Introduceti nr de masini citite: ";
            cin>>n;
            m=new Masina*[n];
            if(n>0)
            {
                for(int i=0;i<n;)
                    model(m[i],i);

                for(int i=0;i<n;i++)
                {
                    cout<<"----------------------"<<endl;
                    cout<<*m[i];
                    cout<<"----------------------"<<endl;
                }
            }
            else cout<<"Introduceti un numar de masini pozitiv"<<endl;
        }
        else if(option==2)
        {
            int nr_Coupe=0, nr_HotHatch=0, nr_Cabrio=0, nr_SuperSport=0;
            if(n>0)
            {
                for(int i=0;i<n;i++)
                {
                    Coupe *c=dynamic_cast<Coupe*>(m[i]);
                    HotHatch *h=dynamic_cast<HotHatch*>(m[i]);
                    Cabrio *cb=dynamic_cast<Cabrio*>(m[i]);
                    SuperSport *s=dynamic_cast<SuperSport*>(m[i]);

                    if(c) nr_Coupe++;
                    if(h) nr_HotHatch++;
                    if(cb) nr_Cabrio++;
                    if(s) nr_SuperSport++;
                }
              cout<<"Nr Coupe: "<<nr_Coupe<<endl;
              cout<<"Nr HotHatch: "<<nr_HotHatch<<endl;
              cout<<"Nr Cabrio: "<<nr_Cabrio<<endl;
              cout<<"Nr SuperSport: "<<nr_SuperSport<<endl;
            }
            else cout<<"Nu ati citit nicio masina!"<<endl;
        }
        else if(option==3)
        {
            Expozitie <Coupe> c;
            cin>>c;
            cout<<c<<endl;
        }
         else if(option==4)
        {
            Expozitie <HotHatch> h;
            cin>>h;
            cout<<h<<endl;
        }
         else if(option==5)
        {
            Expozitie <Cabrio> cb;
            cin>>cb;
            cout<<cb<<endl;
        }
        else if(option==6)
        {
            cout<<"Masinile din stoc sunt "<<endl;
            cin>>s;
        }
        else if(option==7)
        {
            SuperSport vanduta;
            cout<<"  Acesta este stocul masinilor nevandute din expozitie! \n";
            s.afisare_stoc();
            cout<<"Introduceti datele unei masini pe care doriti sa o vindeti \n";
            cin>>vanduta;
            s.operator-=(vanduta);

        }
        else if(option==8)
        {
            cout<<"Nr masini SuperSport in stoc: "<<s.get_stoc()<<endl;
            cout<<"Nr masini SuperSport vandute: "<<s.get_vandute()<<endl;
        }
        else if(option==9)
        {
            cout<<"Masinile din stoc "<<endl;
            s.afisare_stoc();

        }
         else if(option==10)
        {
            cout<<"Masinile vandute "<<endl;
            s.afisare_vandute();
        }
        else if(option==11)
        {
            vector<pair<Masina*, int> > cars;
            for(int i=0;i<Masina::get_nr_masini();i++)
            {
                SuperSport *ss=dynamic_cast<SuperSport*>(m[i]);
                if(typeid(*m[i]).name()==typeid(SuperSport).name())
                    cars.push_back(make_pair(m[i],ss->get_pret()));
            }
             for(int i=0;i<cars.size();i++)
             {
                 cout<<"Masina este: "<<endl<<*cars[i].first<<endl;
                cout<<"Pretul este: "<<cars[i].second<<endl;
             }
        }
        else if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        else if (option<0||option>12)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }while(option!=0);
}
int main()
{
    menu();
    return 0;
}

#include <iostream>
#include<cstring>
#include <string.h>
#include <vector>
#include <typeinfo>
#include <cstdlib>
using namespace std;


//am identificat clasa abstracata admitere
//clasele dosar,id, if, si a 2a fac;
//pt clasa a 2a fac mostenirea se face in diamant
class admitere
{

    //float nota_proba_scrisa1;
    //float nota_proba_scrisa2;
    protected:
    float bac;
    string domeniu;
    //char *nume;
    string nume;
    int adouafac;//1 daca este la a 2a facultate
    float medie;
    int nr_inregistrare;


public:
    // nr_inregistrare=0;
    admitere(){nr_inregistrare++;}

friend    istream& operator >> (istream& in, admitere& a)
    {
          cout<<"introduceti numele elevului"<<endl;

        in>>a.nume;
        cout<<"introduceti numele domeniului";
        in>>a.domeniu;
        // cout<<"introduceti nota la proba scrisa 1"<<endl;
         //cin>>nota_proba_scrisa1;
         //cout<<"introduceti nota la proba scrisa 2"<<endl;
         //cin>>nota_proba_scrisa2;
         cout<<"nota bac";
         in>>a.bac;
         cout<<"nr_inregistrare"<<endl;
         in>>a.nr_inregistrare;
         return in;
    }



friend class IF;

    virtual void medie_admitere()=0;
    virtual void afisare()=0;


};
// nr_inregistrare=0;
class IF:public admitere
{
 protected:
    char nume;
    //float medie_bac;
     float nota_proba_scrisa1;
    float nota_proba_scrisa2;
    //string cod="ID_" +nr_inregistrare;



public:
    IF(){}
int verificare;
friend istream& operator >> (istream& in, IF& a)
    {
         cout<<"introduceti numele elevului"<<endl;

        in>>a.nume;
        in>>a.domeniu;
//        a.nume=new char [strlen(x)+1];
//        strcpy(a.nume,x);
         cout<<"introduceti nota la proba scrisa 1"<<endl;
         in>>a.nota_proba_scrisa1;
         cout<<"introduceti nota la proba scrisa 2"<<endl;
         in>>a.nota_proba_scrisa2;
         cout<<"nota bac";
         in>>a.bac;
         // a.medie=0.8*(nota_proba_scrisa1+nota_proba_scrisa2)/2+0.2*bac;

       //  cout<<"doriti sa calculati media de admitere?"<<endl;
         //cin>>verificare;
         //if(verificare==1) medie_admitere();
         return in;
    }

     void medie_admitere()
{
//float medie_admitere;
   medie=0.8*(nota_proba_scrisa1+nota_proba_scrisa2)/2+0.2*bac;
   // medie_admitere=medie;

}

    void afisare()
    {
        cout<<"numele elevului este "<<nume<<endl;
        cout<<"domeniul ales este"<<domeniu<<endl;
        cout<<"nota la prima proba scrisa este "<<nota_proba_scrisa1<<endl;
        cout<<"nota la a2a proba scrisa este "<<nota_proba_scrisa2<<endl;
        cout<<"media de admitere este "<<medie<<endl;

    }


};

class ID:public admitere{

protected:
    float nota_oral;
    float bac_mate;
    //int cod=nr_i

public:
    ID(){}
    friend istream& operator >> (istream& in, ID& a)
    {
        cout<<"introduceti numele elevului"<<endl;

         in>>a.nume;
         cout<<"introduceti numele domeniului: "<<endl;
        in>>a.domeniu;
  //      a.nume=new char [strlen(x)+1];
//        strcpy(l.nume,x);
         cout<<"introduceti nota la oral"<<endl;
         in>>a.nota_oral;
         cout<<"introduceti nota la bac mate"<<endl;
         in>>a.bac_mate;
         cout<<"nota bac";
         in>>a.bac;
         return in;
    }

    void medie_admitere()
    {
          medie=0.6*nota_oral+0.4*bac_mate;
    }
     void afisare()
    {
        cout<<"numele elevului este "<<nume<<endl;
        cout<<"domeniul ales este"<<domeniu<<endl;
        cout<<"nota la proba orala este: "<<nota_oral<<endl;
        cout<<"nota la bac mate este:"<<bac_mate<<endl;
        cout<<"medie de admitere este"<<medie<<endl;
    }
};

class fac2:public IF,ID
{
    float nota_primafac;


public:
    fac2(){}

    friend istream& operator >> (istream& in, fac2& a)
    {
        cout<<"introduceti numele elevului"<<endl;

       in>>a.IF::nume;
        cout<<"introduceti numele domeniului";
        in>>a.IF::domeniu;
  //      a.nume=new char [strlen(x)+1];
//        strcpy(l.nume,x);
         cout<<"introduceti nota PRIMA FAC"<<endl;
         in>>a.nota_primafac;

         return in;
    }




void medie_admitere()
{
    cout<<"doriti sa urmati a 2a facultate la if sau id/ apasa 0 pt if si 1 pt id"<<endl;
    int aux;
    cin>>aux;

    if(aux==0)
    IF::medie=0.6*nota_oral+0.4*nota_primafac;
    else
        ID::medie=0.6*nota_oral+0.4*nota_primafac;


}

void afisare()
{
    cout<<"numele elevului este "<<IF::nume<<endl;
        cout<<"domeniul ales este"<<IF::domeniu<<endl;
        cout<<"nota prima fac "<<nota_primafac<<endl;

        cout<<"medie de admitere este"<<IF::medie<<endl;
}

};



int main()
{
    /*
    IF a;
    cin>>a;
    a.medie_admitere();
    a.afisare();*/
     ID a;
    cin>>a;
    a.medie_admitere();
    a.afisare();


   // cout << "Hello world!" << endl;
    return 0;
}

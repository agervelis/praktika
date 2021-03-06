#include <string>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <afxres.h>
#include <pbt.h>
using namespace std;
struct gear
    {
        int randlvl;
        int randMaxHP;
        int randAP;
        int randDP;
        int randgbAP;
        int randgbHP;
        int randwvAP;
        int randwvHP;
        int randmsAP;
        int randmsHP;
        int randtungAP;
        int randtungHP;
       string name;
       string EQHelmet;
       string EQArmor;
       string EQGloves;
       string EQShoes;
       string EQWEapon;
       string EQNecklace;
       string EQBelt;
    } gr[50];
double HUD (string zaidvardas,double HP,int MaxHP,int lvl,int AP,int DP,int sidabras,double exp);
void istorija ();
void mapas ();
double randomstats (int &lvl,int &MaxHP,double &HP,int &AP,int &DP,int &gbAP,int &gbHP,int &wvAP,int &wvHP,int &msAP,int &msHP,int &tungAP,int &tungHP);
double statkeitimas (int &lvl,int &MaxHP,double &HP,int &AP,int &DP,int &gbAP,int &gbHP,int &wvAP,int &wvHP,int &msAP,int &msHP,int &tungAP,int &tungHP,int st);
void equipment (string EQHelmet,string EQArmor,string EQGloves,string EQShoes,string EQWEapon,string EQNecklace,string EQBelt);
double pagrindinis (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,double &HP,int &gbHP,int &AP,int &gbAP,int &DP,int &wvHP,int &wvAP,int &msHP,int &msAP,string &name,int &gkills,int &wkills,int &mskills,int &lvl,double &exp,int &MaxHP,int &tungAP,int &tungHP,int tungkills);
double goblin (double &HP,int gbHP,int &sidabras,int &AP,int gbAP,int p,int &DP,int &gkills,int &lvl,double &exp,int &MaxHP);
double gbkova (double &HP,int gbHP,int &AP,int &DP,int &sidabras,int gbAP,int &gkills,int &lvl,double &exp,int &MaxHP);
double wolves (double &HP,int wvHP,int &sidabras,int &AP,int gbAP,int p,int &DP,int &wkills,int &lvl,double &exp,int &MaxHP);
double wvkova (double &HP,int wvHP,int &AP,int &DP,int &sidabras,int wvAP,int &wkills,int &lvl,double &exp,int &MaxHP);
double manshas (double &HP,int msHP,int &sidabras,int &AP,int msAP,int p,int &DP,int &mskills,int &lvl,double &exp,int &MaxHP);
double mskova (double &HP,int msHP,int &AP,int &DP,int &sidabras,int msAP,int &mskills,int &lvl,double &exp,int &MaxHP);
double tungkova (double &HP,int &tungHP,int &AP,int &DP,int tungAP,int &tungkills,bool &loop);
double tung (double &HP,int &tungHP,int &AP,int &DP,int tungAP,int &tungkills,bool &loop,int p);
void difficulty (int &gbHP,int &wvHP,int &msHP,int &tungHP);
void achievements (int gbHP,int gkills,int wvHP,int wkills,int msHP,int mskills,int lvl,string EQWEapon);
void misijos (int gkills,int wkills,int mskills,int &sidabras);
double potdrink (double &HP,int b,string &name,int MaxHP);
double potdrinkL (double &HP,int b,string &name,int MaxHP);
double potdrinkM (double &HP,int b,string &name,int MaxHP);
void bsalmas (int &sidabras,string &name);
void salmas (int &sidabras,string &name);
void armoras (int &sidabras,string &name);
void barmor (int &sidabras,string &name);
void pirstines (int &sidabras,string &name);
void bpirstines (int &sidabras,string &name);
void batai (int &sidabras,string &name);
void bbatai (int &sidabras,string &name);
void ginklas (int &sidabras,string &name);
void bginklas (int &sidabras,string &name);
void necklace (int &sidabras,string &name);
void bnecklace (int &sidabras,string &name);
void belt (int &sidabras,string &name);
void bbelt (int &sidabras,string &name);
void buypotsS (int &sidabras,string &name);
void buypotsSS (int &sidabras,string &name);
void buypotsM (int &sidabras,string &name);
void buypotsSM (int &sidabras,string &name);
void buypotsL (int &sidabras,string &name);
void buypotsSL (int &sidabras,string &name);
void eqarmor (string &EQArmor,string &name,int &DP,int b);
void eqbatai (string &EQArmor,string &name,int &DP,int b);
void eqgloves (string &EQArmor,string &name,int &DP,int b);
void eqhelmet (string &EQArmor,string &name,int &DP,int b);
void eqnecklace (string &EQArmor,string &name,int &DP,int b);
void eqbelt (string &EQArmor,string &name,int &DP,int b);
void eqweapon (string &EQArmor,string &name,int &DP,int b);
void parduotuve (int &sidabras,string &name);
void gobneck (string &EQNecklace,string &name,int &AP,int b);
double INVENTORYCHECK (int INV,string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,double &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name,int MaxHP);
double inventorius (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,double &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name,int MaxHP);
int main()
{
    istorija ();
    string zaidvardas;
    int p,gkills=0,wkills=0,mskills=0,tungkills=0;
    bool loop=true;
    string name;
        string EQHelmet="Nera";
       string EQArmor="Nera";
       string EQGloves="Nera";
       string EQShoes="Nera";
       string EQWEapon="Rosar Greatsword";
       string EQNecklace="Nera";
       string EQBelt="Nera";
    int gbHP=5,gbAP=1;
    int wvHP=15,wvAP=3;
    int msHP=30,msAP=6;
    int tungHP=100,tungAP=10;
   cout<<"Iveskite savo varda"<<endl;
   cin>>zaidvardas;
difficulty (gbHP,wvHP,msHP,tungHP);
    int MaxHP=100,lvl=1,AP=1,DP=1,sidabras=0;
    double HP=MaxHP,exp=0;
    cout<<endl;
    for (int i=0;i<10;i++)
    {
        gr[i].name=" ";
    }
    int rng;
   while (loop==true)
   {
       if (HP<1)
       {
           loop==false;
           break;
       }
       HUD(zaidvardas,HP,MaxHP,lvl,AP,DP,sidabras,exp);
   pagrindinis(EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,gkills,wkills,mskills,lvl,exp,MaxHP,tungAP,tungHP,tungkills);

   }
   int formule,mobkills;
   formule=(lvl*100)+(gkills*20)+(wkills*35)+(mskills*50)+(tungkills*1000);
   mobkills=gkills+wkills+mskills;
   ofstream out2 ("taskai.txt", fstream::app);
   out2<<zaidvardas<<" "<<lvl<<" "<<mobkills<<" "<<tungkills<<" "<<formule<<endl;
   out2.close();

   ofstream out ("output.html");
    out<<"<html>"<<endl;

        out<<"<head>"<<endl;
       out<< "<style>"<<endl;
       out<< "html{"<<endl;
  out<<"background: url('https://cdnb.artstation.com/p/assets/images/images/012/113/289/large/eric-_j-08212.jpg?1533108006') no-repeat center center fixed;"<<endl;
       out<<"-webkit-background-size: cover;"<<endl;
   out<<"-moz-background-size: cover;"<<endl;
  out<<"-o-background-size: cover;"<<endl;
out<<"background-size: cover;"<<endl;
  out<<"}"<<endl;
  out<<"table {"<<endl;
      out<<"font-family: arial, sans-serif;"<<endl;
      out<<"border-collapse: collapse;"<<endl;
      out<<"width: 100%;"<<endl;
  out<<"}"<<endl;

  out<<"td, th {"<<endl;
      out<<"border: 1px solid #dddddd;"<<endl;
      out<<"text-align: left;"<<endl;
      out<<"padding: 8px;"<<endl;
  	out<<"font-size: 30px;"<<endl;
  	out<<"font-weight: bold;"<<endl;

  out<<"}"<<endl;

  out<<"tr:nth-child(even) {"<<endl;
      out<<"background-color: #dddddd;"<<endl;
  	  out<<"opacity: 0.6;"<<endl;
  out<<"}"<<endl;

  out<<"tr:nth-child(odd) {"<<endl;
      out<<"background-color: red;"<<endl;
  	  out<<"opacity: 0.6;"<<endl;
  out<<"}"<<endl;

  out<<"</style>"<<endl;
  out<<"</head>"<<endl;
  out<<"<body>"<<endl;
  out<<"<h1 align=center style=color:white>ZAIDIMO TOP 100</h2>"<<endl;

  out<<"<table style=width:600px align=center>"<<endl;
  out<<"<tr>"<<endl;
      out<<"<th>Player Name</th>"<<endl;
      out<<"<th>Level</th>"<<endl;
      out<<"<th>Mobs killed</th>"<<endl;
  	out<<"<th>Boss kills</th>"<<endl;
  	out<<"<th>Total Score</th>"<<endl;
    out<<"</tr>"<<endl;

    ifstream in ("taskai.txt");
    for (int i=0;i<100;i++)
    {
        in>>zaidvardas>>lvl>>mobkills>>tungkills>>formule;
        out<<"<tr>"<<endl;
      out<<"<td>";
      out<<zaidvardas;
      out<<"</td>"<<endl;
     out<<" <td>";
     out<<lvl;
     out<<"</td>"<<endl;
      out<<"<td>";
      out<<mobkills;
      out<<"</td>"<<endl;
  	out<<"<td>";
  	out<<tungkills;
  	out<<"</td>"<<endl;
  	out<<"<td>";
  	out<<formule;
  	out<<"</td>"<<endl;
    out<<"</tr>"<<endl;
    }
    out<<"</table>"<<endl;
    out<<"</body>"<<endl;
    out<<"</html>"<<endl;
    ShellExecute(NULL,"open","outputas.html",NULL,NULL,SW_SHOW);
    return 0;
}
double HUD (string zaidvardas,double HP,int MaxHP,int lvl,int AP,int DP,int sidabras,double exp)
{
    cout<<zaidvardas<<"  |HP:"<<HP<<"/"<<MaxHP<<"| Lygis:"<<lvl<<" "<<exp<<"/100% "<<"| AP:"<<AP<<" |DP:"<<DP<<" |Sidabras: "<<sidabras<<endl;
}
double pagrindinis (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,double &HP,int &gbHP,int &AP,int &gbAP,int &DP,int &wvHP,int &wvAP,int &msHP,int &msAP,string &name,int &gkills,int &wkills,int &mskills,int &lvl,double &exp,int &MaxHP,int &tungAP,int &tungHP,int tungkills)
{
        cout<<"1.  Inventorius"<<endl;
    cout<<"2.  Equipment"<<endl;
    cout<<"3.  Parduotuve"<<endl;
    cout<<"4.  Goblin cave (Rekomenduojamas AP (1-5))"<<endl;
    cout<<"5.  Wolves den (Rekomenduojamas AP (6-9))"<<endl;
    cout<<"6.  Manshas forest (Rekomenduojamas AP (10-14))"<<endl;
    cout<<"7.  Misijos"<<endl;
    cout<<"8.  Pasiekimai"<<endl;
    cout<<"9.  Tungrad temple"<<endl;
    cout<<"10. Zemelapis"<<endl;
    cout<<"11. Random stats"<<endl;
    cout<<"0. Iseiti"<<endl;
    cout<<"Iveskite pasirinkima"<<endl;
    cin>>p;
      switch(p)
      {
    case 1 : inventorius(EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 2 : equipment(EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt);
            break;
      case 3 : parduotuve (sidabras,name);
            break;
      case 4 : goblin(HP,gbHP,sidabras,AP,gbAP,p,DP,gkills,lvl,exp,MaxHP);
            break;
      case 5 : wolves(HP,wvHP,sidabras,AP,wvAP,p,DP,wkills,lvl,exp,MaxHP);
            break;
      case 6 : manshas(HP,msHP,sidabras,AP,msAP,p,DP,mskills,lvl,exp,MaxHP);
            break;
      case 7 : misijos(gkills,wkills,mskills,sidabras);
            break;
      case 8 : achievements(gbHP,gkills,wvHP,wkills,msHP,mskills,lvl,EQWEapon);
            break;
      case 9 : tung (HP,tungHP,AP,DP,tungAP,tungkills,loop,p);
            break;
      case 10: mapas ();
            break;
      case 11: randomstats(lvl,MaxHP,HP,AP,DP,gbAP,gbHP,wvAP,wvHP,msAP,msHP,tungAP,tungHP);
            break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : loop=false;
            break;
      }
}
double inventorius (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,double &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name,int MaxHP)
{
bool loop2=true;
int INV;
cout<<"Jusu inventorius: "<<endl;
for (int i=0;i<10;i++)
{
    cout<<i+1<<". "<<gr[i].name<<endl;
}
cout<<"0. Iseiti"<<endl;
while (loop2==true)
{
  cout<<"Iveskite pasirinkima"<<endl;
cin>>INV;
switch(INV)
      {


      case 1 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 2 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 3 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 4 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 5 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 6 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 7 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 8 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 9 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      case 10 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,MaxHP);
            break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : loop2=false;
}
}

}
void parduotuve (int &sidabras,string &name)
{
    bool loop3=true;
    int SHOP;
    cout<<"1.  Salmai"<<endl;
    cout<<"2.  Sarvai"<<endl;
    cout<<"3.  Pirstines"<<endl;
    cout<<"4.  Batai"<<endl;
    cout<<"5.  Ginklai"<<endl;
    cout<<"6.  Pakabukai"<<endl;
    cout<<"7.  Dirzai"<<endl;
    cout<<"8.  HP Potion (S)"<<endl;
    cout<<"9.  HP Potion (M)"<<endl;
    cout<<"10.  HP Potion (L)"<<endl;
    cout<<"0.  Iseiti"<<endl;
    while (loop3==true)
    {
cout<<"Iveskite pasirinkima"<<endl;
cin>>SHOP;
switch(SHOP)
    {
    case 1 : salmas(sidabras,name);
        break;
    case 2 : armoras(sidabras,name);
        break;
    case 3 : pirstines(sidabras,name);
        break;
    case 4 : batai(sidabras,name);
        break;
    case 5 : ginklas(sidabras,name);
        break;
    case 6 : necklace(sidabras,name);
        break;
    case 7 : belt(sidabras,name);
        break;
    case 8 : buypotsS(sidabras,name);
        break;
    case 9 : buypotsM(sidabras,name);
        break;
    case 10 : buypotsL(sidabras,name);
        break;
        default : break;
    case 0 : loop3=false;
        break;
    }
    }

}
void equipment (string EQHelmet,string EQArmor,string EQGloves,string EQShoes,string EQWEapon,string EQNecklace,string EQBelt)
{
cout<<"Salmas: "<<EQHelmet<<endl;
cout<<"Sarvai: "<<EQArmor<<endl;
cout<<"Pirstines: "<<EQGloves<<endl;
cout<<"Batai: "<<EQShoes<<endl;
cout<<"Ginklas: "<<EQWEapon<<endl;
cout<<"Pakabukas: "<<EQNecklace<<endl;
cout<<"Dirzas: "<<EQBelt<<endl;
}
double goblin (double &HP,int gbHP,int &sidabras,int &AP,int gbAP,int p,int &DP,int &gkills,int &lvl,double &exp,int &MaxHP)
{
    cout<<"Atvykote i Goblin cave (Rekomenduojamas AP (1-5))"<<endl;
    cout<<"Goblinu HP:"<<gbHP<<"   AP:"<<gbAP<<endl;
    cout<<"Nugaledami goblinus gausite sidabro. Reti item drops: HP Potion (S)/Goblin Necklace"<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : gbkova(HP,gbHP,AP,DP,sidabras,gbAP,gkills,lvl,exp,MaxHP);
            break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
double gbkova (double &HP,int gbHP,int &AP,int &DP,int &sidabras,int gbAP,int &gkills,int &lvl,double &exp,int &MaxHP)
{
double dmg=HP;
double dmg2;
int rng = rand() % 100 + 1;
    while (gbHP>0 && HP>0)
        {
            gbHP=gbHP-AP;
            if (gbHP>0)
            {
                HP=HP-(gbAP*(1-(0.03*DP)));
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (gbHP<1)
        {
            gkills++;
            exp=exp+(20/lvl);
            if (exp>=100)
            {
                lvl++;
                AP++;
                DP++;
                MaxHP=MaxHP+5;
                exp=0;
            }
            if (gkills==5)
    {
        sidabras=sidabras+5;
    }
    else if (gkills==10)
    {
        sidabras=sidabras+5;
    }
    else if (gkills==15)
    {
        sidabras=sidabras+5;
    }
          cout<<"Nukovete goblina ir gavote 1 sidabro"<<endl;
          if (rng>0 && rng<11)
          {
              cout<<"Jus gavote Goblin necklace"<<endl;
              for (int i=0;i<10;i++)
              {
                  if (gr[i].name==" ")
                  {
                      gr[i].name="Goblin necklace";
                      break;
                  }
              }
          }
          if (rng>0 && rng<26)
          {
              cout<<"Jus gavote HP Potion (S)"<<endl;
              for (int i=0;i<10;i++)
              {
                  if (gr[i].name==" ")
                  {
                      gr[i].name="HP Potion (S)";
                      break;
                  }
              }
          }
          dmg2=HP;
          dmg=dmg-dmg2;
          cout<<"Goblinas jums padare "<<dmg<<" zalos"<<endl;
          sidabras=sidabras+1;
        }

}
double wolves (double &HP,int wvHP,int &sidabras,int &AP,int wvAP,int p,int &DP,int &wkills,int &lvl,double &exp,int &MaxHP)
{

    cout<<"Atvykote i Wolves den (Rekomenduojamas AP (6-9))"<<endl;
    cout<<"Vilku HP:"<<wvHP<<"   AP:"<<wvAP<<endl;
    cout<<"Nugaledami vilkus gausite sidabro. Reti item drops: HP Potion (M)/Wolves fang"<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : wvkova(HP,wvHP,AP,DP,sidabras,wvAP,wkills,lvl,exp,MaxHP);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
double wvkova (double &HP,int wvHP,int &AP,int &DP,int &sidabras,int wvAP,int &wkills,int &lvl,double &exp,int &MaxHP)
{
double dmg=HP;
double dmg2;
int rng = rand() % 100 + 1;
    while (wvHP>0 && HP>0)
        {
            wvHP=wvHP-AP;
            if (wvHP>0)
            {
                HP=HP-(wvAP*(1-(0.03*DP)));
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (wvHP<1)
        {
            exp=exp+(35/lvl);
            if (exp>=100)
            {
                lvl++;
                AP++;
                DP++;
                MaxHP=MaxHP+5;
                exp=0;
            }
            wkills++;
            if (wkills==5)
    {
        sidabras=sidabras+6;
    }
    else if (wkills==10)
    {
        sidabras=sidabras+6;
    }
    else if (wkills==15)
    {
        sidabras=sidabras+6;
    }
          cout<<"Nukovete vilka ir gavote 5 sidabro"<<endl;
          if (rng>0 && rng<11)
          {
              cout<<"Jus gavote Wolves fang"<<endl;
              for (int i=0;i<10;i++)
              {
                  if (gr[i].name==" ")
                  {
                      gr[i].name="Wolves fang";
                      break;
                  }
              }
          }
          if (rng>0 && rng<26)
          {
              cout<<"Jus gavote HP Potion (M)"<<endl;
              for (int i=0;i<10;i++)
              {
                  if (gr[i].name==" ")
                  {
                      gr[i].name="HP Potion (M)";
                      break;
                  }
              }
          }
          dmg2=HP;
          dmg=dmg-dmg2;
          cout<<"Vilkas jums padare "<<dmg<<" zalos"<<endl;
          sidabras=sidabras+5;
        }

}
double manshas (double &HP,int msHP,int &sidabras,int &AP,int msAP,int p,int &DP,int &mskills,int &lvl,double &exp,int &MaxHP)
{
    cout<<"Atvykote i Manshas forest (Rekomenduojamas AP (10-15))"<<endl;
    cout<<"Manshu HP:"<<msHP<<"   AP:"<<msAP<<endl;
    cout<<"Nugaledami manshas gausite sidabro. Reti item drops: HP Potion (L)/Manshas totem"<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : mskova(HP,msHP,AP,DP,sidabras,msAP,mskills,lvl,exp,MaxHP);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
double mskova (double &HP,int msHP,int &AP,int &DP,int &sidabras,int msAP,int &mskills,int &lvl,double &exp,int &MaxHP)
{
double dmg=HP;
double dmg2;
int rng = rand() % 100 + 1;
    while (msHP>0 && HP>0)
        {
            msHP=msHP-AP;
            if (msHP>0)
            {
                HP=HP-(msAP*(1-(0.03*DP)));
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (msHP<1)
        {
            exp=exp+(50/lvl);
            if (exp>=100)
            {
                lvl++;
                AP++;
                DP++;
                MaxHP=MaxHP+5;
                exp=0;
            }
            mskills++;
            if (mskills==5)
    {
        sidabras=sidabras+7;
    }
    else if (mskills==10)
    {
        sidabras=sidabras+7;
    }
    else if (mskills==15)
    {
        sidabras=sidabras+7;
    }
          cout<<"Nukovete mansha ir gavote 10 sidabro"<<endl;
          if (rng>0 && rng<11)
          {
              cout<<"Jus gavote Manshas staff"<<endl;
              for (int i=0;i<10;i++)
              {
                  if (gr[i].name==" ")
                  {
                      gr[i].name="Manshas staff";
                      break;
                  }
              }
          }
          if (rng>0 && rng<26)
          {
              cout<<"Jus gavote HP Potion (L)"<<endl;
              for (int i=0;i<10;i++)
              {
                  if (gr[i].name==" ")
                  {
                      gr[i].name="HP Potion (L)";
                      break;
                  }
              }
          }
          dmg2=HP;
          dmg=dmg-dmg2;
          cout<<"Mansha jums padare "<<dmg<<" zalos"<<endl;
          sidabras=sidabras+10;
        }

}
double INVENTORYCHECK (int INV,string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,double &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name,int MaxHP)
{
    int INV2,b=0;
    for(int k=0;k<INV;k++)
    {
    b++;
    }
    if (gr[b-1].name==" ")
    {
        cout<<"Si vieta tuscia"<<endl;

    }
    else if (gr[b-1].name=="HP Potion (S)")
    {
    cout<<"1. Panaudoti"<<endl;
    cout<<"0. Iseiti"<<endl;
     cin>>INV2;
      switch(INV2)
      {
        case 1 : potdrink(HP,b,name,MaxHP);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="HP Potion (M)")
    {
    cout<<"1. Panaudoti"<<endl;
    cout<<"0. Iseiti"<<endl;
     cin>>INV2;
      switch(INV2)
      {
        case 1 : potdrinkM(HP,b,name,MaxHP);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="HP Potion (L)")
    {
    cout<<"1. Panaudoti"<<endl;
    cout<<"0. Iseiti"<<endl;
     cin>>INV2;
      switch(INV2)
      {
        case 1 : potdrinkL(HP,b,name,MaxHP);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Goblin necklace")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : gobneck(EQNecklace,name,AP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Bronzos sarvai")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqarmor(EQArmor,name,DP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Bronzos salmas")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqhelmet(EQHelmet,name,DP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Bronzos pirstines")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqgloves(EQGloves,name,DP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Bronzos batai")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqbatai(EQShoes,name,DP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Bronzos pakabukas")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqnecklace(EQNecklace,name,AP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Bronzos dirzas")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqbelt(EQBelt,name,AP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }
    else if (gr[b-1].name=="Liverto ginklas")
    {
    cout<<"1. Uzsideti"<<endl;
    cout<<"0. Iseiti"<<endl;
    cin>>INV2;
      switch(INV2)
      {
        case 1 : eqweapon(EQWEapon,name,AP,b);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;

      }
    }

}
double potdrink (double &HP,int b,string &name,int MaxHP)
{
   gr[b-1].name=" ";
        if (HP+5>MaxHP)
        {
            HP=MaxHP;
        }
        else{
        HP=HP+5;
        }
}
double potdrinkM (double &HP,int b,string &name,int MaxHP)
{
   gr[b-1].name=" ";
        if (HP+10>MaxHP)
        {
            HP=MaxHP;
        }
        else{
        HP=HP+10;
        }
}
double potdrinkL (double &HP,int b,string &name,int MaxHP)
{
   gr[b-1].name=" ";
        if (HP+15>MaxHP)
        {
            HP=MaxHP;
        }
        else{
        HP=HP+15;
        }
}
void buypotsS (int &sidabras,string &name)
{
    int bp;
    cout<<"1. HP Potion (S)  Atstato 5 HP --- kaina 5 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>bp;
      switch(bp)
      {
        case 5 : buypotsSS(sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void buypotsSS (int &sidabras,string &name)
{
    int kk=0;
    for (int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        kk++;
    }
    if (gr[kk].name==" ")
    {
        if (sidabras>=5)
        {
            gr[kk].name="HP Potion (S)";
            sidabras=sidabras-5;
            cout<<"Nusipirkote HP Potion (S)"<<endl;
        }
    }
}
void buypotsM (int &sidabras,string &name)
{
    int bp;
    cout<<"1. HP Potion (M)  Atstato 10 HP --- kaina 9 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>bp;
      switch(bp)
      {
        case 5 : buypotsSM(sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void buypotsSM (int &sidabras,string &name)
{
    int kk=0;
    for (int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        kk++;
    }
    if (gr[kk].name==" ")
    {
        if (sidabras>=9)
        {
            gr[kk].name="HP Potion (M)";
            sidabras=sidabras-9;
            cout<<"Nusipirkote HP Potion (M)"<<endl;
        }
    }
}
void buypotsL (int &sidabras,string &name)
{
    int bp;
    cout<<"1. HP Potion (S)  Atstato 15 HP --- kaina 13 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>bp;
      switch(bp)
      {
        case 5 : buypotsSL(sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void buypotsSL (int &sidabras,string &name)
{
    int kk=0;
    for (int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        kk++;
    }
    if (gr[kk].name==" ")
    {
        if (sidabras>=13)
        {
            gr[kk].name="HP Potion (L)";
            sidabras=sidabras-13;
            cout<<"Nusipirkote HP Potion (L)"<<endl;
        }
    }
}
void gobneck (string &EQNecklace,string &name,int &AP,int b)
{
    EQNecklace=gr[b-1].name;
    gr[b-1].name=" ";
    AP=AP+2;
}
void eqarmor (string &EQArmor,string &name,int &DP,int b)
{
    EQArmor=gr[b-1].name;
    gr[b-1].name=" ";
    DP=DP+2;
}
void eqbatai (string &EQShoes,string &name,int &DP,int b)
{
    EQShoes=gr[b-1].name;
    if (EQShoes=="Nera")
    gr[b-1].name=" ";
    DP=DP+2;
}
void eqgloves (string &EQGloves,string &name,int &DP,int b)
{
    EQGloves=gr[b-1].name;
    gr[b-1].name=" ";
    DP=DP+2;
}
void eqhelmet(string &EQHelmet,string &name,int &DP,int b)
{
    EQHelmet=gr[b-1].name;
    gr[b-1].name=" ";
    DP=DP+2;
}
void eqbelt (string &EQBelt,string &name,int &AP,int b)
{
    EQBelt=gr[b-1].name;
    gr[b-1].name=" ";
    AP=AP+2;
}
void eqnecklace (string &EQNecklace,string &name,int &AP,int b)
{
    EQNecklace=gr[b-1].name;
    gr[b-1].name=" ";
    AP=AP+2;
}
void eqweapon (string &EQWEapon,string &name,int &AP,int b)
{
    EQWEapon=gr[b-1].name;
    gr[b-1].name=" ";
    AP=AP+2;
    cout<<"uzdetas " <<EQWEapon<<endl;
}
void salmas (int &sidabras,string &name)
{
    int salm;
    cout<<"1. Bronzos salmas  (+2 DP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>salm;
      switch(salm)
      {
        case 5 : bsalmas (sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void bsalmas (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Bronzos salmas"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Bronzos salmas";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void armoras (int &sidabras,string &name)
{
    int armor;
    cout<<"1. Bronzos sarvai  (+2 DP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>armor;
      switch(armor)
      {
        case 5 : barmor (sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void barmor (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Bronzos sarvus"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Bronzos sarvai";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void pirstines (int &sidabras,string &name)
{
    int pirst;
    cout<<"1. Bronzos pirstines  (+2 DP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>pirst;
      switch(pirst)
      {
        case 5 : bpirstines (sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void bpirstines (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Bronzos pirstines"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Bronzos pirstines";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void batai (int &sidabras,string &name)
{
    int batai;
    cout<<"1. Bronzos batai  (+2 DP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>batai;
      switch(batai)
      {
        case 5 : bbatai (sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void bbatai (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Bronzos batus"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Bronzos batai";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void ginklas (int &sidabras,string &name)
{
    int gink;
    cout<<"1. Liverto ginklas  (+2 AP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>gink;
      switch(gink)
      {
        case 5 : bginklas (sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void bginklas (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Liverto ginkla"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Liverto ginklas";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void necklace (int &sidabras,string &name)
{
    int neck;
    cout<<"1. Bronzos pakabukas  (+2 AP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>neck;
      switch(neck)
      {
        case 5 : bnecklace (sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void bnecklace (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Bronzos pakabuka"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Bronzos pakabukas";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void belt (int &sidabras,string &name)
{
    int belt;
    cout<<"1. Bronzos dirzas  (+2 DP)   --- kaina 10 sidabro"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"5. Pirkti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>belt;
      switch(belt)
      {
        case 5 : bbelt(sidabras,name);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 :
      break;
}
}
void bbelt (int &sidabras,string &name)
{
    int c=0;
    for(int i=0;i<10;i++)
    {
        if (gr[i].name==" ")
        {
            break;
        }
        c++;
    }
        if (gr[c].name==" ")
    {
        if (sidabras>=10)
        {
            cout<<"Nusipirkote Bronzos dirza"<<endl;
            sidabras=sidabras-10;
            gr[c].name="Bronzos dirzas";
        }
        else
        {
            cout<<"Neuztenka sidabro"<<endl;
        }
    }
}
void misijos (int gkills,int wkills,int mskills,int &sidabras)
{
    cout<<"Jusu misijos :"<<endl;
    cout<<"1.  Nukaukite 5 goblinus. Atlygis - 5 sidabro. ("<<gkills<<"/5)"<<endl;
    cout<<"2.  Nukaukite 10 goblinu. Atlygis - 5 sidabro. ("<<gkills<<"/10)"<<endl;
    cout<<"3.  Nukaukite 15 goblinu. Atlygis - 5 sidabro. ("<<gkills<<"/15)"<<endl;
    cout<<"4.  Nukaukite 5 vilkus. Atlygis - 6 sidabro. ("<<wkills<<"/5)"<<endl;
    cout<<"5.  Nukaukite 10 vilkus. Atlygis - 6 sidabro. ("<<wkills<<"/10)"<<endl;
    cout<<"6.  Nukaukite 15 vilkus. Atlygis - 6 sidabro. ("<<wkills<<"/15)"<<endl;
    cout<<"7.  Nukaukite 5 manshas. Atlygis - 7 sidabro. ("<<mskills<<"/5)"<<endl;
    cout<<"8.  Nukaukite 10 manshas. Atlygis - 7 sidabro. ("<<mskills<<"/10)"<<endl;
    cout<<"9.  Nukaukite 15 manshas. Atlygis - 7 sidabro. ("<<mskills<<"/15)"<<endl;
    cout<<"10. Nugalekite pasalio bosa Tungrad!"<<endl;
}
void difficulty (int &gbHP,int &wvHP,int &msHP,int &tungHP)
{
    cout<<"Pasirinkite zaidimo sunkuma"<<endl;
    cout<<"1. Lengvas"<<endl;
    cout<<"2. Vidutinis"<<endl;
    cout<<"3. Sunkus"<<endl;
    int pas;

    bool loopas=true;
    while (loopas==true)
    {cin>>pas;
       switch (pas)
    {
    case 1: loopas=false; break;
    case 2: gbHP=10,wvHP=30,msHP=60,tungHP=200; loopas=false; break;
    case 3: gbHP=30,wvHP=90,msHP=150,tungHP=300; loopas=false; break;
    default: cout<<"Pasirinkimo nera"<<endl; break;
    }
    }

}
void achievements (int gbHP,int gkills,int wvHP,int wkills,int msHP,int mskills,int lvl,string EQWEapon)
{
    cout<<"Jusu pasiekimai: "<<endl;
    cout<<"Pradejote zaidima!"<<endl;
    if (gbHP==5 && gkills>=1)
    {
        cout<<"Uzmusete savo pirmaji goblina!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (gbHP==5 && gkills>=5)
    {
        cout<<"Uzmusete 5 goblinus!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (gbHP==5 && gkills>=10)
    {
        cout<<"Uzmusete 10 goblinu!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (wvHP==10 && wkills>=1)
    {
        cout<<"Uzmusete savo pirmaji vilka!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (wvHP==10 && wkills>=5)
    {
        cout<<"Uzmusete 5 vilkus!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (wvHP==10 && wkills>=10)
    {
        cout<<"Uzmusete 10 vilku!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (msHP==15 && mskills>=1)
    {
        cout<<"Uzmusete savo pirmaja mansha!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (msHP==15 && mskills>=5)
    {
        cout<<"Uzmusete 5 manshas!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (msHP==15 && mskills>=10)
    {
        cout<<"Uzmusete 10 manshu!(Zaidimo sunkumas: lengvas)"<<endl;
    }
    if (gbHP==10 && gkills>=1)
    {
        cout<<"Uzmusete savo pirmaji goblina!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (gbHP==10 && gkills>=5)
    {
        cout<<"Uzmusete 5 goblinus!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (gbHP==10 && gkills>=10)
    {
        cout<<"Uzmusete 10 goblinu!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (wvHP==30 && wkills>=1)
    {
        cout<<"Uzmusete savo pirmaji vilka!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (wvHP==30 && wkills>=5)
    {
        cout<<"Uzmusete 5 vilkus!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (wvHP==30 && wkills>=10)
    {
        cout<<"Uzmusete 10 vilku!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (msHP==60 && mskills>=1)
    {
        cout<<"Uzmusete savo pirmaja mansha!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (msHP==60 && mskills>=5)
    {
        cout<<"Uzmusete 5 manshas!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (msHP==60 && mskills>=10)
    {
        cout<<"Uzmusete 10 manshu!(Zaidimo sunkumas: vidutinis)"<<endl;
    }
    if (gbHP==30 && gkills>=1)
    {
        cout<<"Uzmusete savo pirmaji goblina!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (gbHP==30 && gkills>=5)
    {
        cout<<"Uzmusete 5 goblinus!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (gbHP==30 && gkills>=10)
    {
        cout<<"Uzmusete 10 goblinu!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (wvHP==90 && wkills>=1)
    {
        cout<<"Uzmusete savo pirmaji vilka!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (wvHP==90 && wkills>=5)
    {
        cout<<"Uzmusete 5 vilkus!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (wvHP==90 && wkills>=10)
    {
        cout<<"Uzmusete 10 vilku!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (msHP==150 && mskills>=1)
    {
        cout<<"Uzmusete savo pirmaja mansha!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (msHP==150 && mskills>=5)
    {
        cout<<"Uzmusete 5 manshas!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (msHP==150 && mskills>=10)
    {
        cout<<"Uzmusete 10 manshu!(Zaidimo sunkumas: sunkus)"<<endl;
    }
    if (lvl>=2)
    {
        cout<<"Pakelete savo pirmaji lygi!"<<endl;
    }
    if (lvl>=5)
    {
        cout<<"Pakelete 5-taji lygi!"<<endl;
    }
    if (EQWEapon!="Rosar Greatsword")
    {
        cout<<"Uzsidejote nauja ginkla!"<<endl;
    }
}
double tung (double &HP,int &tungHP,int &AP,int &DP,int tungAP,int &tungkills,bool &loop,int p)
{
    cout<<"Atvykote i Tungrad temple"<<endl;
    cout<<"Ar tikrai esate pasiruoses susidurti su pasaulio bosu Tungrad?"<<endl;
    cout<<"Tungrad HP:"<<tungHP<<"   AP:"<<tungAP<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : tungkova (HP,tungHP,AP,DP,tungAP,tungkills,loop);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
double tungkova (double &HP,int &tungHP,int &AP,int &DP,int tungAP,int &tungkills,bool &loop)
{


    while (tungHP>0 && HP>0)
        {
            tungHP=tungHP-AP;
            if (tungHP>0)
            {
                HP=HP-(tungAP*(1-(0.03*DP)));
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (tungHP<1)
        {

            tungkills++;
            cout<<"Sveikiname nukovus Tungrad ir perejus zaidima!"<<endl;
            loop=false;
        }
}
void istorija ()
{
    cout<<"1855-ieji metai. Pasaulyje karaliauja monstrai ir paciame virsuje - Tungrad, pasaulio bosas."<<endl;
    cout<<"Zmonijai reikia didvyrio, galincio nukauti Tungrad ir isvaduoti is kanciu."<<endl;
}

void mapas ()
{
    std::string getFileContents (std::ifstream&);

    std::ifstream Reader ("map.txt");

    std::string Art = getFileContents (Reader);

    std::cout << Art << std::endl;

    Reader.close ();
}
double randomstats (int &lvl,int &MaxHP,double &HP,int &AP,int &DP,int &gbAP,int &gbHP,int &wvAP,int &wvHP,int &msAP,int &msHP,int &tungAP,int &tungHP)
{

    srand ( time(NULL) );
    ofstream out ("random.txt");
    for (int i=0;i<10;i++)
    {
    gr[i].randlvl = rand() % 15 + 1;
    gr[i].randMaxHP = rand() % 500 + 1;
    gr[i].randAP = rand() % 30 + 1;
    gr[i].randDP = rand() % 30 + 1;
    gr[i].randgbAP = rand() % 10 + 1;
    gr[i].randgbHP = rand() % 50 + 1;
    gr[i].randwvAP = rand() % 20 + 1;
    gr[i].randwvHP = rand() % 100 + 1;
    gr[i].randmsAP = rand() % 30 + 1;
    gr[i].randmsHP = rand() % 200 + 1;
    gr[i].randtungAP = rand() % 50 + 1;
    gr[i].randtungHP = rand() % 1000 + 1;
    out<<gr[i].randlvl<<" "<<gr[i].randMaxHP<<" "<<gr[i].randAP<<" "<<gr[i].randDP<<" "<<gr[i].randgbAP<<" "<<gr[i].randgbHP<<" "<<gr[i].randwvAP<<" "<<gr[i].randwvHP<<" "<<gr[i].randmsAP<<" "<<gr[i].randmsHP<<" "<<gr[i].randtungAP<<" "<<gr[i].randtungHP<<endl;

    }
    out.close();
    cout<<"Lygis HP AP DP GBAP GBHP WVAP WVHP MSAP MSHP TUNGAP TUNGHP"<<endl;
    std::string getFileContents (std::ifstream&);

    std::ifstream Reader ("random.txt");

    std::string Art2 = getFileContents (Reader);

    std::cout << Art2 << std::endl;
    cout<<endl;
    cout<<"Kuriuos status norite ikrauti"<<endl;
    int st;
    cin>>st;
    cout<<"Ar norite ikrauti status?"<<endl;
    cout<<"1. Taip"<<endl;
    cout<<"0. Ne"<<endl;
    int pasir;

    bool loopa=true;
    while (loopa==true)
    {cin>>pasir;
       switch (pasir)
    {
    case 1: statkeitimas(lvl,MaxHP,HP,AP,DP,gbAP,gbHP,wvAP,wvHP,msAP,msHP,tungAP,tungHP,st); loopa=false; break;
    case 0: loopa=false; break;
    default: cout<<"Pasirinkimo nera"<<endl; break;
    }
    Reader.close ();

}
}
double statkeitimas (int &lvl,int &MaxHP,double &HP,int &AP,int &DP,int &gbAP,int &gbHP,int &wvAP,int &wvHP,int &msAP,int &msHP,int &tungAP,int &tungHP,int st)
{

    lvl=gr[st-1].randlvl;
    MaxHP=gr[st-1].randMaxHP;
    AP=gr[st-1].randAP;
    DP=gr[st-1].randDP;
    gbAP=gr[st-1].randgbAP;
    gbHP=gr[st-1].randgbHP;
    wvAP=gr[st-1].randwvAP;
    wvHP=gr[st-1].randwvHP;
    msAP=gr[st-1].randmsAP;
    msHP=gr[st-1].randmsHP;
    tungAP=gr[st-1].randtungAP;
    tungHP=gr[st-1].randtungHP;
    HP=MaxHP;
}
std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";

    if (File)
    {
	while (File.good ())
	{
	    std::string TempLine;
	    std::getline (File , TempLine);
	    TempLine += "\n";

	    Lines += TempLine;
	}
	return Lines;
    }
    else
    {
	return "ERROR Zemelapis neegzistuoja.";
    }
}

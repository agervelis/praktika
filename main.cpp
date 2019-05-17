#include <string>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <stdlib.h>
#include <fstream>
using namespace std;
struct gear
    {
       string name;
       string EQHelmet;
       string EQArmor;
       string EQGloves;
       string EQShoes;
       string EQWEapon;
       string EQNecklace;
       string EQBelt;
    } gr[50];
void HUD (string zaidvardas,int HP,int MaxHP,int lvl,int AP,int DP,int sidabras);
void equipment (string EQHelmet,string EQArmor,string EQGloves,string EQShoes,string EQWEapon,string EQNecklace,string EQBelt);
void pagrindinis (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,int &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name,int &gkills,int &wkills,int &mskills);
void goblin (int &HP,int &gbHP,int &sidabras,int AP,int gbAP,int p,int DP,int &gkills);
void gbkova (int &HP,int &gbHP,int AP,int DP,int &sidabras,int gbAP,int &gkills);
void wolves (int &HP,int &gbHP,int &sidabras,int AP,int gbAP,int p,int DP,int &wkills);
void wvkova (int &HP,int &wvHP,int AP,int DP,int &sidabras,int wvAP,int &wkills);
void manshas (int &HP,int &msHP,int &sidabras,int AP,int msAP,int p,int DP,int &mskills);
void mskova (int &HP,int &msHP,int AP,int DP,int &sidabras,int msAP,int &mskills);
void misijos (int gkills,int wkills,int mskills,int &sidabras);
void potdrink (int &HP,int b,string &name);
void potdrinkL (int &HP,int b,string &name);
void potdrinkM (int &HP,int b,string &name);
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
void INVENTORYCHECK (int INV,string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,int &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name);
void inventorius (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,int &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name);
int main()
{
    string zaidvardas;
    int p,gkills=0,wkills=0,mskills=0;
    bool loop=true;
    string name;
        string EQHelmet="Nera";
       string EQArmor="Nera";
       string EQGloves="Nera";
       string EQShoes="Nera";
       string EQWEapon="Rosar Greatsword";
       string EQNecklace="Nera";
       string EQBelt="Nera";
    int MaxHP=100,HP=MaxHP,lvl=1,AP=1,DP=1,sidabras=0;
    int gbHP=5,gbAP=1;
    int wvHP=15,wvAP=3;
    int msHP=30,msAP=6;
   cout<<"Iveskite savo varda"<<endl;
   cin>>zaidvardas;
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
       HUD(zaidvardas,HP,MaxHP,lvl,AP,DP,sidabras);
   pagrindinis(EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name,gkills,wkills,mskills);
   }
    return 0;
}
void HUD (string zaidvardas,int HP,int MaxHP,int lvl,int AP,int DP,int sidabras)
{
    cout<<zaidvardas<<"  |HP:"<<HP<<"/"<<MaxHP<<"| Lygis:"<<lvl<<"| AP:"<<AP<<" |DP:"<<DP<<" |Sidabras: "<<sidabras<<endl;
}
void pagrindinis (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,int &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name,int &gkills,int &wkills,int &mskills)
{
        cout<<"1.  Inventorius"<<endl;
    cout<<"2.  Equipment"<<endl;
    cout<<"3.  Parduotuve"<<endl;
    cout<<"4.  Goblin cave (Rekomenduojamas AP (1-5))"<<endl;
    cout<<"5.  Wolves den (Rekomenduojamas AP (6-9))"<<endl;
    cout<<"6.  Manshas forest (Rekomenduojamas AP (10-14))"<<endl;
    cout<<"7.  Misijos"<<endl;
    cout<<"0. Iseiti"<<endl;
    cout<<"Iveskite pasirinkima"<<endl;
    cin>>p;
      switch(p)
      {
    case 1 : inventorius(EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 2 : equipment(EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt);
            break;
      case 3 : parduotuve (sidabras,name);
            break;
      case 4 : goblin(HP,gbHP,sidabras,AP,gbAP,p,DP,gkills);
            break;
      case 5 : wolves(HP,wvHP,sidabras,AP,wvAP,p,DP,wkills);
            break;
      case 6 : manshas(HP,msHP,sidabras,AP,msAP,p,DP,mskills);
            break;
      case 7 : misijos(gkills,wkills,mskills,sidabras);
            break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : loop=false;
            break;
      }
}
void inventorius (string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,int &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name)
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


      case 1 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 2 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 3 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 4 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 5 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 6 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 7 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 8 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 9 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
            break;
      case 10 : INVENTORYCHECK (INV,EQHelmet,EQArmor,EQGloves,EQShoes,EQWEapon,EQNecklace,EQBelt,p,loop,sidabras,HP,gbHP,AP,gbAP,DP,wvHP,wvAP,msHP,msAP,name);
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
void goblin (int &HP,int &gbHP,int &sidabras,int AP,int gbAP,int p,int DP,int &gkills)
{
    gbHP=5;
    cout<<"Atvykote i Goblin cave (Rekomenduojamas AP (1-5))"<<endl;
    cout<<"Goblinu HP:"<<gbHP<<"   AP:"<<gbAP<<endl;
    cout<<"Nugaledami goblinus gausite sidabro. Reti item drops: HP Potion (S)/Goblin Necklace"<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : gbkova(HP,gbHP,AP,DP,sidabras,gbAP,gkills);
            break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
void gbkova (int &HP,int &gbHP,int AP,int DP,int &sidabras,int gbAP,int &gkills)
{
int dmg=0;
int rng = rand() % 100 + 1;
    while (gbHP>0 && HP>0)
        {
            gbHP=gbHP-AP;
            if (gbHP>0)
            {
                HP=HP-(gbAP-(DP*0.01));
                dmg++;
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (gbHP<1)
        {
            gkills++;
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
          cout<<"Goblinas jums padare "<<dmg<<" zalos"<<endl;
          sidabras=sidabras+1;
        }

}
void wolves (int &HP,int &wvHP,int &sidabras,int AP,int wvAP,int p,int DP,int &wkills)
{
    wvHP=15;
    cout<<"Atvykote i Wolves den (Rekomenduojamas AP (6-9))"<<endl;
    cout<<"Vilku HP:"<<wvHP<<"   AP:"<<wvAP<<endl;
    cout<<"Nugaledami vilkus gausite sidabro. Reti item drops: HP Potion (M)/Wolves fang"<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : wvkova(HP,wvHP,AP,DP,sidabras,wvAP,wkills);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
void wvkova (int &HP,int &wvHP,int AP,int DP,int &sidabras,int wvAP,int &wkills)
{
int dmg=0;
int rng = rand() % 100 + 1;
    while (wvHP>0 && HP>0)
        {
            wvHP=wvHP-AP;
            if (wvHP>0)
            {
                HP=HP-(wvAP-(DP*0.01));
                dmg=dmg+3;
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (wvHP<1)
        {
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
          cout<<"Vilkas jums padare "<<dmg<<" zalos"<<endl;
          sidabras=sidabras+5;
        }

}
void manshas (int &HP,int &msHP,int &sidabras,int AP,int msAP,int p,int DP,int &mskills)
{
    msHP=15;
    cout<<"Atvykote i Manshas forest (Rekomenduojamas AP (10-15))"<<endl;
    cout<<"Manshu HP:"<<msHP<<"   AP:"<<msAP<<endl;
    cout<<"Nugaledami manshas gausite sidabro. Reti item drops: HP Potion (L)/Manshas totem"<<endl;
    cout<<"1. Kovoti"<<endl;
    cout<<"0. Gryzti"<<endl;
    cin>>p;
      switch(p)
      {
        case 1 : mskova(HP,msHP,AP,DP,sidabras,msAP,mskills);
        break;
      default : cout<<"Pasirinkto punkto nera"<<endl;
            break;
      case 0 : break;

      }
}
void mskova (int &HP,int &msHP,int AP,int DP,int &sidabras,int msAP,int &mskills)
{
int dmg=0;
int rng = rand() % 100 + 1;
    while (msHP>0 && HP>0)
        {
            msHP=msHP-AP;
            if (msHP>0)
            {
                HP=HP-(msAP-(DP*0.01));
                dmg=dmg+6;
            }


        }
        if (HP<1)
        {
            cout<<"Zaidejas mire"<<endl;
        }
        else if (msHP<1)
        {
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
          cout<<"Mansha jums padare "<<dmg<<" zalos"<<endl;
          sidabras=sidabras+10;
        }

}
void INVENTORYCHECK (int INV,string &EQHelmet,string &EQArmor,string &EQGloves,string &EQShoes,string &EQWEapon,string &EQNecklace,string &EQBelt,int p,bool &loop,int &sidabras,int &HP,int gbHP,int &AP,int gbAP,int &DP,int wvHP,int wvAP,int msHP,int msAP,string &name)
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
        case 1 : potdrink(HP,b,name);
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
        case 1 : potdrinkM(HP,b,name);
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
        case 1 : potdrinkL(HP,b,name);
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
void potdrink (int &HP,int b,string &name)
{
   gr[b-1].name=" ";
        if (HP+5>100)
        {
            HP=100;
        }
        else{
        HP=HP+5;
        }
}
void potdrinkM (int &HP,int b,string &name)
{
   gr[b-1].name=" ";
        if (HP+10>100)
        {
            HP=100;
        }
        else{
        HP=HP+10;
        }
}
void potdrinkL (int &HP,int b,string &name)
{
   gr[b-1].name=" ";
        if (HP+15>100)
        {
            HP=100;
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
    cout<<"1. Nukaukite 5 goblinus. Atlygis - 5 sidabro. ("<<gkills<<"/5)"<<endl;
    cout<<"2. Nukaukite 10 goblinu. Atlygis - 5 sidabro. ("<<gkills<<"/10)"<<endl;
    cout<<"3. Nukaukite 15 goblinu. Atlygis - 5 sidabro. ("<<gkills<<"/15)"<<endl;
    cout<<"4. Nukaukite 5 vilkus. Atlygis - 6 sidabro. ("<<wkills<<"/5)"<<endl;
    cout<<"5. Nukaukite 10 vilkus. Atlygis - 6 sidabro. ("<<wkills<<"/10)"<<endl;
    cout<<"6. Nukaukite 15 vilkus. Atlygis - 6 sidabro. ("<<wkills<<"/15)"<<endl;
    cout<<"7. Nukaukite 5 manshas. Atlygis - 7 sidabro. ("<<mskills<<"/5)"<<endl;
    cout<<"8. Nukaukite 10 manshas. Atlygis - 7 sidabro. ("<<mskills<<"/10)"<<endl;
    cout<<"9. Nukaukite 15 manshas. Atlygis - 7 sidabro. ("<<mskills<<"/15)"<<endl;

}

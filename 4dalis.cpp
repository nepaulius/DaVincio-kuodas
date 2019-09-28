#include "galvininkas.h"



char genRandom_raides_1()
{
     char simboliai[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int ilgis = sizeof(simboliai) - 1;


static unsigned long x=123456789, y=362436069, z=521288629;
         //period 2^96-1
unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

   t = x;
   x = y;
   y = z;
   z = t ^ x ^ y;

    return simboliai[z % ilgis];
}
std::string to_binary(std::string bitas)
{
    std::string bin = "";

    for (int i = 0; i <= bitas.size(); i++)
    {
        int val = int(bitas[i]);



        while (val > 0)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
    }

    return bin;
}

std::string ilgesnis(std::string pirmas, int atimtis)
{

        for(int i=0;i<atimtis;i++)
        {
            pirmas.insert(pirmas.begin(),'0');
        }
        return pirmas;


}
int vidurkis(std::vector <int>apsiskaiciuok)
{
    int suma=0;

    for(int i=0;i<apsiskaiciuok.size();i++)
    {
       suma=suma+apsiskaiciuok[i];
    }

    return suma/apsiskaiciuok.size();
}
std::string kardinalus_pokyciai_3(std::string tekstas)
{

   std::string pagrindas="!!!!!!!!!!!!!!!!!!!!!!!!";
    long long int raideliuSriuba=0;


    for(int i=0;i<tekstas.size();i++)
    {
        raideliuSriuba=raideliuSriuba+(int(tekstas[i])*(i+1));
    }

    std::string tarpinis=std::to_string(tekstas.size())+std::to_string(raideliuSriuba);

    pagrindas.erase(0,tarpinis.size());

    std::string pradzia=std::to_string(tekstas.size());

    std::string geras=pradzia+pagrindas;

    std::string raides=std::to_string(raideliuSriuba);

    geras.insert(geras.size()/2+1,raides);

    std::string suminis = std::bitset< 32 >(raideliuSriuba).to_string();

    for(int j=0;j<suminis.size();j++)
    {
        if(suminis[j]=='1')
           {
            for(int k=geras.size()/2+1;k>=0;k--)
                {
                    int pridedam=int(geras[k])+geras[k+1]%geras.size();
                    char a=pridedam;
                    geras[k]=a;

                }
           }
        else if(suminis[j]=='0')
           {
            for(int k=geras.size()/2+1;k<geras.size();k++)
                {
                    int pridedam2=int(geras[k])-geras[k-1]%geras.size();
                    char a2=pridedam2;
                    geras[k]=a2;
                }
            }
    }

    std::stringstream ss;
    std::string hashas;
    int16_t vertimas;

    for(int j=0;j<geras.size();j++)
    {
        vertimas=int(geras[j]);
        ss <<std::setfill ('0') << std::setw(sizeof(int))<< std::hex << vertimas;
        hashas=ss.str();
    }

     return hashas;

}
void ketvirta_dalis()
{

    int vienodumas=0;
    std::vector <int> tikrinimas;
    int kiek_1;

    std::string tekstas_1;
    std::string tekstas_2;

    std::cout<<"Iveskite kiek poru, kuriu 4 simboliai vienodi, 1 simbolis skirtingas : "<<std::endl;
    std::cin>>kiek_1;

    for(int a=0;a<kiek_1;a++)
    {
        for(unsigned int i = 0; i <4 ; ++i)
        {
            tekstas_1 += genRandom_raides_1();
        }

        tekstas_2=tekstas_1;

        for(int i=0;i<2;i++)
        {
            tekstas_1 += genRandom_raides_1();
            tekstas_2 += genRandom_raides_1();
        }


        std::string kodas_1=kardinalus_pokyciai_3(tekstas_1);
        std::string kodas_2=kardinalus_pokyciai_3(tekstas_2);

        std::string pvz1=to_binary(kodas_1);
        std::string pvz2=to_binary(kodas_2);

        int skirtumas=pvz1.size()-pvz2.size();

        if(skirtumas>0)
        {
            pvz2=ilgesnis(pvz2,skirtumas);
        }
        else if(skirtumas < 0)
        {
            skirtumas=skirtumas*(-1);
            pvz1=ilgesnis(pvz1,skirtumas);
        }


        for(int i=0;i<pvz1.size();i++)
        {
            if(pvz1[i]==pvz2[i])
            vienodumas++;
        }

        int procentas=vienodumas*100/pvz1.size();
        tikrinimas.push_back(procentas);


        vienodumas=0;
        procentas=0;
        tekstas_1.clear();
        tekstas_2.clear();
    }

    int simtukininkai=0;

    for(int i=0;i<tikrinimas.size();i++)
    {
        if(tikrinimas[i]==100)
        {
            simtukininkai++;
        }
    }

    std::cout<<"Minimalus procentu skaicius : "<<*min_element(tikrinimas.begin(),tikrinimas.end())<<std::endl;
    std::cout<<"Vidurkine procentu reiksme : "<<vidurkis(tikrinimas)<<std::endl;
    std::cout<<"Maksimalus procentu skaicius : "<<*max_element(tikrinimas.begin(),tikrinimas.end())<<std::endl;

    if(simtukininkai!=0)
    {
        std::cout<<"Skirtingu tekstu poru, kuriuose hashas vienodas : "<<std::endl;
        std::cout<<simtukininkai<<std::endl;
    }

}

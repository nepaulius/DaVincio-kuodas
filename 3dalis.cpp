#include "galvininkas.h"


char genRandom()
{
    char simboliai[] ="0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int ilgis = sizeof(simboliai) - 1;

    static unsigned long x=123456789, y=362436069, z=521288629;

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
std::string kardinalus_pokyciai_2(std::string tekstas)
{

    std::string pagrindas="!!!!!!!!!!!!!!!!!!!!!!!!";
    long long int raideliuSriuba=0;


    for(int i=0;i<tekstas.size();i++)
    {
        raideliuSriuba=raideliuSriuba+(int(tekstas[i])*(i+1));
    }

     if(raideliuSriuba==0)
            raideliuSriuba=1;

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
    return geras;
}

void trecia_dalis()
{

    int vienodi=0;
    int sutapimas=0;
    std::string tekstas_1;
    std::string tekstas_2;

    for(int a=0;a<10;a++)
    {
        for(unsigned int i = 0; i < 5; ++i)
        {
            tekstas_1 += genRandom();
            tekstas_2+= genRandom();
        }

    std::string kodas_1=kardinalus_pokyciai_2(tekstas_1);
    std::string kodas_2=kardinalus_pokyciai_2(tekstas_2);


        for(int j=0;j<kodas_1.size();j++)
        {
            if(int(kodas_1[j])==int(kodas_2[j]))
            {
                sutapimas++;
            }
        }

    if(sutapimas==24)
    {
        vienodi++;
    }

    tekstas_1.erase (tekstas_1.begin(), tekstas_1.end());
    tekstas_2.erase (tekstas_2.begin(), tekstas_2.end());
    sutapimas=0;

    }

    std::cout<<"Vienodu poru skaicius : "<<vienodi<<std::endl;
    std::cout<<"----------------------"<<std::endl;

}
#include "galvininkas.h"

std::string Validacija(std::string b)
{
    while(b.length()!=1 || !isalpha(b[0]) || b[0]!='r' && b[0]!='f' )
    {
        std::cout<<"Iveskite dar kart"<<std::endl;
        std::cout<<"Iveskite [r/f]: ";
        std::cin >> b;
    }

    return b;
}
char genRandom3(int keist)
{
  char simboliai[] ="0123456789ABCDEFabcdef";

    int ilgis = sizeof(simboliai) - 1;

    static unsigned long x=123456789, y=362436069, z=521288629;



    unsigned long t;

    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y+keist;

    return simboliai[z % ilgis];

}
std::string nuskaitymas(std::ifstream& a)
{
    std::string temp;
    std::string tekstas;

    while(getline(a,temp))
    {
        tekstas=tekstas+temp;
    }
    return tekstas;
}

std::vector <std::string> pradzia()
{

    std::string q;
    std::cout<<"Jei norite rasyti ranka (r), jei skaityti is failo (f) : "<<std::endl;
    std::cin>>q;
    std::string c=Validacija(q);

    std::vector <std::string> failai;

    if(c[0]=='r')
    {
        std::string tekstas;
        std::cout<<"Iveskite teksta : "<<std::endl;
        std::cin>>tekstas;
        failai.push_back(tekstas);
        return failai;
    }
    else if(c[0]=='f')
    {

        std::ifstream ifs("Vieno_simbolio_1.txt");
        failai.push_back(nuskaitymas(ifs));

        std::ifstream ifs1("Vieno_simbolio_2.txt");
        failai.push_back(nuskaitymas(ifs1));

        std::ifstream ifs2("Daug_simboliu_1.txt");
        failai.push_back(nuskaitymas(ifs2));

        std::ifstream ifs3("Daug_simboliu_2.txt");
        failai.push_back(nuskaitymas(ifs3));

        std::ifstream ifs4("DSS_2.txt");
        failai.push_back(nuskaitymas(ifs4));

        std::ifstream ifs5("DSS_1.txt");
        failai.push_back(nuskaitymas(ifs5));

        std::ifstream ifs6("Tuscias.txt");
        failai.push_back(nuskaitymas(ifs6));

        return failai;
    }
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

char genRandom_raides()
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

char genRandom(int keist)
{
  char simboliai[] ="0123456789ABCDEFabcdef";

    int ilgis = sizeof(simboliai) - 1;

    static unsigned long x=123456789, y=362436069, z=521288629;



    unsigned long t;

    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y+keist;

    return simboliai[z % ilgis];

}

char genRandom_2(int keist)
{
    char simboliai[] ="0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int ilgis = sizeof(simboliai) - 1;

    static unsigned long x=123456789+keist, y=362436069, z=521288629;



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
void antra_dalis()
{
    std::ifstream ifk("konstitucija.txt");
    std::string temp;
    std::string kodas;
    std::string tekstas;

    auto s = std::chrono::system_clock::now();

    while(getline(ifk, temp))
    {
        tekstas=temp;
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

     std::string tikr;
    unsigned int x;
    int golas=0;
    std::vector <int> KO;

    for(int p=0;p<hashas.size();p++)
    {
        if(hashas[p]=='f'||hashas[p]=='0'||hashas[p]=='a'||hashas[p]=='b')
            golas++;
        KO.push_back(static_cast<int>(hashas[p])*(p+1));
    }
    for(int k=0;k<KO.size();k++)
    {
tikr+=genRandom(KO[k]+golas);
    }

    }

    auto e = std::chrono::system_clock::now();

    std::chrono::duration<double> u = e - s;
    std::cout<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Visu konstitucijos.txt eiluciu hash'avimo laiko suma = "<< std::setprecision(4)<<std::fixed<<u.count()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"----------------------"<<std::endl;
    std::cout<<std::endl;

}




#include "galvininkas.h"
#include "2dalis.cpp"
#include "3dalis.cpp"

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

std::string kardinalus_pokyciai(std::string tekstas)
{
    std::cout<<"Teksto ilgis (kiek simboliu) = "<<tekstas.size()<<std::endl;
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


int main()
{

    std::vector <std::string> tekstai;
    tekstai=pradzia();
    std::string kodas;

    for(int i=0;i<tekstai.size();i++)
    {
         kodas=kardinalus_pokyciai(tekstai[i]);
             std::cout<<"Uzsifruotas tekstas : "<<kodas<<std::endl;
             std::cout<<"-----------------------"<<std::endl;
    }

    antra_dalis();
    trecia_dalis();


return 0;
}

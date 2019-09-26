#include "galvininkas.h"


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
    }

    auto e = std::chrono::system_clock::now();

    std::chrono::duration<double> u = e - s;
    std::cout<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Visu konstitucijos.txt eiluciu hash'avimo laiko suma = "<< std::setprecision(4)<<std::fixed<<u.count()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"----------------------"<<std::endl;
    std::cout<<std::endl;
}




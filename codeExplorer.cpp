#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <bitset>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <cmath>

std::string pradzia()
{
    char a;
    std::cout<<" Ar norite teksta rasyti ranka ar skaityti is failo (r - ranka, f - failas) ?"<<std::endl;
    std::cin>>a;

    if(a=='r')
    {
    std::string tekstas;
    std::cout<<"Iveskite teksta : "<<std::endl;
    std::cin>>tekstas;
    return tekstas;
    }
    else if(a=='f')
    {
 std::ifstream ifs("rasinelis.txt");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    return content;
  }
}
std::string kardinalus_pokyciai(std::string tekstas)
{
    std::string pagrindas="!!!!!!!!!!!!!!!!!!!!";
    int raideliuSriuba=0;

    for(int i=0;i<tekstas.size();i++)
    {
        raideliuSriuba=raideliuSriuba+(int(tekstas[i]));
    }

    std::string pradzia=std::to_string(tekstas.size());

    std::string geras=pradzia+pagrindas;

    std::string raides=std::to_string(raideliuSriuba);

    geras.insert(geras.size()/2+1,raides);
    std::string suminis = std::bitset< 24 >(raideliuSriuba).to_string();

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

    std::string tekstas=pradzia();

    std::string kodas=kardinalus_pokyciai(tekstas);

    std::cout<<"Tekstas : "<<tekstas<<std::endl;

    std::cout<<"Pakeistas tekstas : "<<kodas<<std::endl;

return 0;
}

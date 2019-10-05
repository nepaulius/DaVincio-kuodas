#include "galvininkas.h"
#include "2dalis.cpp"



std::string kardinalus_pokyciai(std::string tekstas)
{
    std::string pagrindas="!!!!!!!!!!!!!!!!!!";
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
tikr+=genRandom3(KO[k]+golas);
    }

    return tikr;
}
void dalis_2()
{
    std::ifstream ifk("konstitucija.txt");
    std::string temp;
    std::string kodas;
    std::string tekstas;

    auto s = std::chrono::system_clock::now();

    while(getline(ifk, temp))
        {
        tekstas=kardinalus_pokyciai(temp);
        }
        auto e = std::chrono::system_clock::now();

    std::chrono::duration<double> u = e - s;
    std::cout<<std::endl;
    std::cout<<std::setw(20)<<std::left<<"Visu konstitucijos.txt eiluciu hash'avimo laiko suma = "<< std::setprecision(4)<<std::fixed<<u.count()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"----------------------"<<std::endl;
    std::cout<<std::endl;
}
dalis_3()
{
    int vienodi=0;
    int sutapimas=0;
    std::string tekstas_1;
    std::string tekstas_2;
    int kiek;
    std::ofstream myfile;
    myfile.open ("5_skiringi.txt");



    std::cout<<"Iveskite kiek poru, kuriu 5 skirtingi simboliai : "<<std::endl;
    std::cin>>kiek;

    for(int a=0;a<kiek;a++)
    {
        for(unsigned int i = 0; i < 5; ++i)
        {
            tekstas_1 += genRandom_raides();
            tekstas_2+= genRandom_raides();
        }
        myfile<<tekstas_1<<" - "<<tekstas_2<<std::endl;


    std::string kodas_1=kardinalus_pokyciai(tekstas_1);
    std::string kodas_2=kardinalus_pokyciai(tekstas_2);


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

    std::cout<<"Vienodu poru skaicius  : "<<vienodi<<std::endl;
    std::cout<<"----------------------"<<std::endl;

  myfile.close();
}
dalis_4()
{
    int vienodumas=0;
    std::vector <int> tikrinimas;
    int kiek_1;
    std::ofstream myfile;
    myfile.open ("1_skiringas.txt");

    std::string tekstas_1;
    std::string tekstas_2;

    std::cout<<"Iveskite kiek poru, kuriu 4 simboliai vienodi, 1 simbolis skirtingas : "<<std::endl;
    std::cin>>kiek_1;

    for(int a=0;a<kiek_1;a++)
    {
        for(unsigned int i = 0; i <4 ; ++i)
        {
            tekstas_1 += genRandom_raides();
        }

        tekstas_2=tekstas_1;

        for(int i=0;i<1;i++)
        {
            tekstas_1 += genRandom_raides();
            tekstas_2 += genRandom_raides();
        }

        myfile<<tekstas_1<<" - "<<tekstas_2<<std::endl;

        std::string kodas_1=kardinalus_pokyciai(tekstas_1);
        std::string kodas_2=kardinalus_pokyciai(tekstas_2);

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


int main()
{

    std::vector <std::string> tekstai;
    tekstai=pradzia();
    std::string kodas;

    for(int i=0;i<tekstai.size();i++)
    {
         kodas=kardinalus_pokyciai(tekstai[i]);
             std::cout<<"Uzsifruotas tekstas : "<<kodas<<std::endl;
             std::cout<<"Uzsifruoto teksto ilgis : "<<kodas.size()<<std::endl;
             std::cout<<"-----------------------"<<std::endl;
    }
    dalis_2();
    dalis_3();
    dalis_4();



return 0;
}

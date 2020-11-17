#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <ctype.h>
#include <time.h>

using namespace std;


const int MAX_POKUSAJA=10;

struct Igrac{                                   //struktura za igralca
    string ime;                                 //ime igralca
    int ste;                                    //vpisno stevilka
    string geslo;                               //trenutno ugibano geslo
    char letter;                                //ugibanje crke
    time_t cas;                                 //potreben cas
}s;

int letterFill (char, string, string&);

const char *scenarij1 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **             \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";


const char *scenarij2 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";


const char *scenarij3 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |     \n"
        "       *        |     \n"
        "       *       /      \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";
const char *scenarij4 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |     \n"
        "       *        |     \n"
        "       *       | |     \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij5 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |=     \n"
        "       *        |     \n"
        "       *       / \     \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij6 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *       =|=     \n"
        "       *        |     \n"
        "       *       / \     \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";
const char *scenarij7 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *       =|=--  \n"
        "       *        |     \n"
        "       *       / \     \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij8 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *      -=|=--  \n"
        "       *        |     \n"
        "       *       / \     \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";
const char *scenarij9 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *     --=|=--  \n"
        "       *        |     \n"
        "       *       /     \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij10 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *     --=|=--  \n"
        "       *        |     \n"
        "       *       | |    \n"
        "       *              \n"
        "      * *  GAME OVER! \n"
        "     *   *            \n";

const char *scenariji[] = {scenarij1, scenarij2,scenarij4,scenarij5,scenarij6,scenarij7,scenarij8,scenarij9, scenarij10};


//preddefinirana gesla
string gesla[] =
{"led","dim","mir","tri","oda","taj","jad","dar","rit","knjiga","sto","olovka","jez","mak","racunar","ulje","macka","ptica","konj","zid","banana","so","majica","secer","stolica","casa","kuhinja","kuca","drvo","klupa","park","grad","drzava", "krofna","polje","auto","motor","struja","granica","ljubav","sreca","tuga","bol","bijeda","jabuka","stranac","hemijska","slika","brod","more","burek","hrana","mlijeko","kafa","stres","broj","dva","rijec","ime","prezime","adresa","laptop","skola","tabla","kreda","ucitelj","profesor","jelka","zvijezda","kugla","ukras","trokut","lopta","boja","crvena","zelena","zuta","roza","plava","modra","rijeka","camac","stan","cesta","nebo","mjesec","pjevanje","sviranje","gitara","orkestar","violina","opera","bubanj","hod","mobitel","kruska","sljiva","breskva","mandarina"};


int letterFill (char pogodak, string trijec, string &prijec)
{
    int i;
    int matches=0;
    int len=trijec.length();
    for (i = 0; i< len; i++)
    {

        if (pogodak == prijec[i])
            return 0;

        if (pogodak == trijec[i])
        {
            prijec[i] = pogodak;
            matches++;
        }
    }
    return matches;
}

int main ()
{
    cout<<"Unesi ime prvog igraca i vpisno stevilo"<<endl;
    Igrac p1;
    cin>>p1.ime;
    p1.ste=1;
    cout<<"Unesi ime drugog igraca"<<endl;
    Igrac p2;
    cin>>p2.ime;
    p2.ste=2;
    cout<<"Unesi ime treceg igraca"<<endl;
    Igrac p3;
    cin>>p3.ime;
    p3.ste=3;
    cout<<"Unesi ime cetvrtog igraca"<<endl;
    Igrac p4;
    cin>>p4.ime;
    p4.ste=4;
    cout<<"Unesi ime petog igraca"<<endl;
    Igrac p5;
    cin>>p5.ime;
    p5.ste=5;





    int pokusaji=0;

    //nakljucno izbiro gesla
    srand (time(NULL));
    int n=rand()% 100+1;
    p1.geslo=gesla[n];
    //slova u rijeci oznacena sa *
    string nepoznato(p1.geslo.length(),'*');

    cout << "Dobrodosli u visilice "<<p1.ime<<endl;
    cout << "Svako slovo je predstavljeno sa *"<<endl;
    cout << "Unesite samo jedno slovo po pokusaju"<<endl;
    cout << "Imate "<<" "<< MAX_POKUSAJA << " pokusaja da pogodite rijec"<<endl;

    //pocinje racunati vrijeme
    clock_t startTime = clock();

    while (pokusaji < MAX_POKUSAJA)
    {
        cout << "Unesi slovo: "<<endl;
        cout << "\n\n" <<nepoznato<<endl;
        cin >> p1.letter;
        //p1.letter = toupper(letter);

        //popuni rijec tacnim slovom
        if (letterFill(p1.letter, p1.geslo, nepoznato)==0)
        {
            cout << endl << "Netocan unos" << endl;
            pokusaji++;


            if(pokusaji==1){
                cout<<scenarij1;}
            if(pokusaji==2){
                cout<<scenarij2;}
            if(pokusaji==3){
                cout<<scenarij3;}
            if(pokusaji==4){
                cout<<scenarij4;}
            if(pokusaji==5){
                cout<<scenarij5;}
            if(pokusaji==6){
                cout<<scenarij6;}
            if(pokusaji==7){
                cout<<scenarij7;}
            if(pokusaji==8){
                cout<<scenarij8;}
            if(pokusaji==9){
                cout<<scenarij9;}
            if(pokusaji==10){
                cout<<scenarij10;}
        }

        else
        {
            cout << endl << "Tacan unos" << endl;
        }

        if (p1.geslo==nepoznato)
        {
            cout << p1.geslo << endl;
            cout << "Da to je tacna rijec!";
            break;
        }
    }

    if(pokusaji == MAX_POKUSAJA)
    {
        cout << "\nIzgubili ste" << endl;
        cout << "Rijec je : " << p1.geslo << endl;
    }
    //zavrsava sa racunanjem vremena
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken;
    cout<<"Vrijeme je "<<timeInSeconds;
    cin.ignore();
    cin.get();


    //igrac 2
    int pokusaji2=0;

    //nakljucno izbiro gesla
    srand (time(NULL));
    int n2=rand()% 100+1;
    p2.geslo=gesla[n2];
    //slova u rijeci oznacena sa *
    string nepoznato2(p2.geslo.length(),'*');

    cout << "Dobrodosli u visilice "<<p2.ime<<endl;
    cout << "Svako slovo je predstavljeno sa *"<<endl;
    cout << "Unesite samo jedno slovo po pokusaju"<<endl;
    cout << "Imate "<<" "<< MAX_POKUSAJA << " pokusaja da pogodite rijec"<<endl;

    clock_t startTime2 = clock();

    while (pokusaji2 < MAX_POKUSAJA)
    {
        cout << "Unesi slovo: "<<endl;
        cout << "\n\n" <<nepoznato2<<endl;
        cin >> p2.letter;
        //p1.letter = toupper(letter);

        //popuni rijec tacnim slovom
        if (letterFill(p2.letter, p2.geslo, nepoznato2)==0)
        {
            cout << endl << "Netocan unos" << endl;
            pokusaji2++;


            if(pokusaji2==1){
                cout<<scenarij1;}

            if(pokusaji2==2){
                cout<<scenarij2;}

            if(pokusaji2==3){
                cout<<scenarij3;}
            if(pokusaji2==4){
                cout<<scenarij4;}
            if(pokusaji2==5){
                cout<<scenarij5;}
            if(pokusaji2==6){
                cout<<scenarij6;}
            if(pokusaji2==7){
                cout<<scenarij7;}
            if(pokusaji2==8){
                cout<<scenarij8;}
            if(pokusaji2==9){
                cout<<scenarij9;}
            if(pokusaji2==10){
                cout<<scenarij10;}
        }

        else
        {
            cout << endl << "Tacan unos" << endl;
        }

        if (p2.geslo==nepoznato2)
        {
            cout << p2.geslo << endl;
            cout << "Da to je tacna rijec!";
            break;
        }
    }
    if(pokusaji2 == MAX_POKUSAJA)
    {
        cout << "\nIzgubili ste" << endl;
        cout << "Rijec je : " << p2.geslo << endl;
    }
    clock_t endTime2 = clock();
    clock_t clockTicksTaken2 = endTime2 - startTime2;
    double timeInSeconds2 = clockTicksTaken2;
    cout<<"Vrijeme je "<<timeInSeconds2;
    cin.ignore();
    cin.get();

    //igrac 3
    int pokusaji3=0;

    //nakljucno izbiro gesla
    srand (time(NULL));
    int n3=rand()% 100+1;
    p3.geslo=gesla[n3];
    //slova u rijeci oznacena sa *
    string nepoznato3(p3.geslo.length(),'*');

    cout << "Dobrodosli u visilice "<<p3.ime<<endl;
    cout << "Svako slovo je predstavljeno sa *"<<endl;
    cout << "Unesite samo jedno slovo po pokusaju"<<endl;
    cout << "Imate "<<" "<< MAX_POKUSAJA << " pokusaja da pogodite rijec"<<endl;

    clock_t startTime3 = clock();

    while (pokusaji3 < MAX_POKUSAJA)
    {
        cout << "Unesi slovo: "<<endl;
        cout << "\n\n" <<nepoznato3<<endl;
        cin >> p3.letter;
        //p1.letter = toupper(letter);

        //popuni rijec tacnim slovom
        if (letterFill(p3.letter, p3.geslo, nepoznato3)==0)
        {
            cout << endl << "Netacan unos" << endl;
            pokusaji3++;


            if(pokusaji3==1){
                cout<<scenarij1;}

            if(pokusaji3==2){
                cout<<scenarij2;}

            if(pokusaji3==3){
                cout<<scenarij3;}
            if(pokusaji3==4){
                cout<<scenarij4;}
            if(pokusaji3==5){
                cout<<scenarij5;}
            if(pokusaji3==6){
                cout<<scenarij6;}
            if(pokusaji3==7){
                cout<<scenarij7;}
            if(pokusaji3==8){
                cout<<scenarij8;}
            if(pokusaji3==9){
                cout<<scenarij9;}
            if(pokusaji3==10){
                cout<<scenarij10;}
        }

        else
        {
            cout << endl << "Tacan unos" << endl;
        }

        if (p3.geslo==nepoznato3)
        {
            cout << p3.geslo << endl;
            cout << "Da to je tacna rijec!";
            break;
        }
    }
    if(pokusaji3 == MAX_POKUSAJA)
    {
        cout << "\nIzgubili ste" << endl;
        cout << "Rijec je : " << p3.geslo << endl;
    }
    clock_t endTime3 = clock();
    clock_t clockTicksTaken3 = endTime3 - startTime3;
    double timeInSeconds3 = clockTicksTaken3;
    cout<<"Vrijeme je "<<timeInSeconds3;
    cin.ignore();
    cin.get();

    //igrac 4
    int pokusaji4=0;

    //nakljucno izbiro gesla
    srand (time(NULL));
    int n4=rand()% 100+1;
    p4.geslo=gesla[n4];
    //slova u rijeci oznacena sa *
    string nepoznato4(p4.geslo.length(),'*');

    cout << "Dobrodosli u visilice "<<p4.ime<<endl;
    cout << "Svako slovo je predstavljeno sa *"<<endl;
    cout << "Unesite samo jedno slovo po pokusaju"<<endl;
    cout << "Imate "<<" "<< MAX_POKUSAJA << " pokusaja da pogodite rijec"<<endl;

    clock_t startTime4 = clock();

    while (pokusaji4 < MAX_POKUSAJA)
    {
        cout << "Unesi slovo: "<<endl;
        cout << "\n\n" <<nepoznato4<<endl;
        cin >> p4.letter;
        //p1.letter = toupper(letter);

        //popuni rijec tacnim slovom
        if (letterFill(p4.letter, p4.geslo, nepoznato4)==0)
        {
            cout << endl << "Netocan unos" << endl;
            pokusaji4++;


            if(pokusaji4==1){
                cout<<scenarij1;}

            if(pokusaji4==2){
                cout<<scenarij2;}

            if(pokusaji4==3){
                cout<<scenarij3;}
            if(pokusaji4==4){
                cout<<scenarij4;}
            if(pokusaji4==5){
                cout<<scenarij5;}
            if(pokusaji4==6){
                cout<<scenarij6;}
            if(pokusaji4==7){
                cout<<scenarij7;}
            if(pokusaji2==8){
                cout<<scenarij8;}
            if(pokusaji4==9){
                cout<<scenarij9;}
            if(pokusaji4==10){
                cout<<scenarij10;}
        }

        else
        {
            cout << endl << "Tacan unos" << endl;
        }

        if (p4.geslo==nepoznato4)
        {
            cout << p4.geslo << endl;
            cout << "Da to je tacna rijec!";
            break;
        }
    }
    if(pokusaji4 == MAX_POKUSAJA)
    {
        cout << "\nIzgubili ste" << endl;
        cout << "Rijec je : " << p4.geslo << endl;
    }
    clock_t endTime4 = clock();
    clock_t clockTicksTaken4 = endTime - startTime;
    double timeInSeconds4 = clockTicksTaken;
    cout<<"Vrijeme je "<<timeInSeconds4;
    cin.ignore();
    cin.get();

    //igrac 5
    int pokusaji5=0;

    //nakljucno izbiro gesla
    srand (time(NULL));
    int n5=rand()% 100+1;
    p5.geslo=gesla[n5];
    //slova u rijeci oznacena sa *
    string nepoznato5(p5.geslo.length(),'*');

    cout << "Dobrodosli u visilice "<<p5.ime<<endl;
    cout << "Svako slovo je predstavljeno sa *"<<endl;
    cout << "Unesite samo jedno slovo po pokusaju"<<endl;
    cout << "Imate "<<" "<< MAX_POKUSAJA << " pokusaja da pogodite rijec"<<endl;

    clock_t startTime5 = clock();

    while (pokusaji5 < MAX_POKUSAJA)
    {
        cout << "Unesi slovo: "<<endl;
        cout << "\n\n" <<nepoznato5<<endl;
        cin >> p5.letter;
        //p1.letter = toupper(letter);

        //popuni rijec tacnim slovom
        if (letterFill(p5.letter, p5.geslo, nepoznato5)==0)
        {
            cout << endl << "Netocan unos" << endl;
            pokusaji5++;


            if(pokusaji5==1){
                cout<<scenarij1;}

            if(pokusaji5==2){
                cout<<scenarij2;}

            if(pokusaji5==3){
                cout<<scenarij3;}
            if(pokusaji5==4){
                cout<<scenarij4;}
            if(pokusaji5==5){
                cout<<scenarij5;}
            if(pokusaji5==6){
                cout<<scenarij6;}
            if(pokusaji5==7){
                cout<<scenarij7;}
            if(pokusaji5==8){
                cout<<scenarij8;}
            if(pokusaji5==9){
                cout<<scenarij9;}
            if(pokusaji5==10){
                cout<<scenarij10;}
        }

        else
        {
            cout << endl << "Tacan unos" << endl;
        }
        if (p5.geslo==nepoznato5)
        {
            cout << p5.geslo << endl;
            cout << "Da to je tacna rijec!";
            break;
        }
    }
    if(pokusaji5 == MAX_POKUSAJA)
    {
        cout << "\nIzgubili ste" << endl;
        cout << "Rijec je : " << p5.geslo << endl;
    }
    clock_t endTime5 = clock();
    clock_t clockTicksTaken5 = endTime5 - startTime5;
    double timeInSeconds5 = clockTicksTaken5;
    cout<<"Vrijeme je"<<timeInSeconds5;

    cin.ignore();
    cin.get();
    //broj pokusaja da se pogodi rijec
    cout<<"STATISTIKA"<<endl;
    cout<<p1.ime<<" "<<pokusaji<<" "<<timeInSeconds<<endl;
    cout<<p2.ime<<" "<<pokusaji2<<" "<<timeInSeconds2<<endl;
    cout<<p3.ime<<" "<<pokusaji3<<" "<<timeInSeconds3<<endl;
    cout<<p4.ime<<" "<<pokusaji4<<" "<<timeInSeconds4<<endl;
    cout<<p5.ime<<" "<<pokusaji4<<" "<<timeInSeconds5<<endl;

    if(pokusaji<pokusaji3&&pokusaji2&&pokusaji4&&pokusaji5){
        cout<<"Najbolji igrac je"<<p1.ime<<" 1";
    }
    else if(pokusaji2<pokusaji3&&pokusaji&&pokusaji4&&pokusaji5){
        cout<<"Najbolji igrac je"<<p2.ime<<" 2";
    }
    else if(pokusaji3<pokusaji&&pokusaji2&&pokusaji4&&pokusaji5){
        cout<<"Najbolji igrac je"<<p3.ime<<" 3";
    }
    else if(pokusaji4<pokusaji3&&pokusaji2&&pokusaji&&pokusaji5){
        cout<<"Najbolji igrac je"<<p4.ime<<" 4";
    }
    else if(pokusaji5<pokusaji3&&pokusaji2&&pokusaji4&&pokusaji){
        cout<<"Najbolji igrac je "<<p5.ime<<" 5";
    }
    else{
        cout<<"Rezultati su jednaki";
    }


    return 0;
}





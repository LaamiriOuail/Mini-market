#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int i,l,nombreAcheter=0,nbr,nbr1;
float Kg,facture;
string name,name_user,password;
string code[15],nvpassword[3],programmer[3],programmercode[3];
string nom[15],coder[1]= {"Hello world!"};
int sizecode,nbrprogrammer;
//Nombres des produits dans stock
int nbrlisteproduit;
//Tableaux des choix
string Liste_produit[100];
//Prix des produit dans stock
float Prix_produits[100];
//Liste des produit acheter
string Liste_Acheter[20];
//Prix des produit Acheter
float Prix_Acheter[20];
//Kg des produit Acheter
float kg[20];
//unite des product
float kg_stock[100];
//Liste des produit dans le stock
void listePoduitStock()
{
    if(nbrlisteproduit==0) cout<<"Stock vide ! \n";
    else for(i=0; i<nbrlisteproduit; i++) cout<<" "<<i+1<<"- "<<Liste_produit[i]<<" || Prix : "<<Prix_produits[i]<<" dh/kg"<<" || nombre de Kg dans les stock : "<<kg_stock[i]<<endl;
}
//File output statu employer
void File_output_Statu(string Message,int n)
{
    ofstream otfille("DataFille/Statu_employer.txt",ios::app);
    otfille<<__DATE__<<"\t\t\t"<<__TIME__<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<"                   "<<nom[n]<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<Message<<"\n\n\n"<<endl;
    otfille.close();
}
//File output statu programmer
void File_output_Statu_programmer(string Message,int n)
{
    ofstream otfille("DataFille/Statu_programmer.txt",ios::app);
    otfille<<__DATE__<<"\t\t\t"<<__TIME__<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<"                   "<<programmer[n]<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<Message<<"\n\n\n"<<endl;
    otfille.close();
}
//File output user acheter
void File_output_acheter(string path)
{
    ofstream otfille(path);
    otfille<<__DATE__<<"\t\t\t"<<__TIME__<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<"                   "<<name_user<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<"Produit Acheter"<<"\t\t"<<"Kg"<<"\t"<<"Dhs/Kg"<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    for(int i=0; i<nombreAcheter; i++) otfille<<Liste_Acheter[i]<<"\t\t\t"<<kg[i]<<"\t"<<Prix_Acheter[i]<<endl;
    otfille<<"---------------------------------------------------"<<endl;
    otfille<<"Totale : "<<facture<<" Dhs"<<endl;
    otfille<<"---------------------------------------------------\n\n\n"<<endl;
    otfille.close();
}
//File input nbr : sizecode nbrprogrammer nbrlisteproduit
void outputnbr()
{
    ofstream ofille("DataTable/nbr.txt",ios::out);
    ofille<<sizecode<<endl;
    ofille<<nbrprogrammer<<endl;
    ofille<<nbrlisteproduit<<endl;
    ofille.close();
}
//File input nbr sizecode nbrprogrammer nbrlisteproduit
void inputnbr()
{
    int T[3];
    int i=0;
    ifstream ifille("DataTable/nbr.txt",ios::in);
    while(ifille>>T[i]) i++;
    sizecode=T[0];
    nbrprogrammer=T[1];
    nbrlisteproduit=T[2];
    ifille.close();
}
//File output table string
void File_output_table_string(string T[],int n,string path)
{
    ofstream otfille(path,ios::out);
    for(int i=0; i<n; i++) otfille<<T[i]<<endl;
    otfille.close();
}
//File output table float
void File_output_table_float(float T[],int n,string path)
{
    ofstream ofille(path,ios::out);
    for(int i=0; i<n; i++) ofille<<T[i]<<endl;
    ofille.close();
}
//File input table string
void File_input_table_string(string T[],int n,string path)
{
    ifstream infille(path,ios::in);
    int i=0;
    while(infille>>T[i]) i++;
    infille.close();
}
//File input table float
void File_input_table_float(float T[],int n,string path)
{
    ifstream ifille(path,ios::in);
    int i=0;
    while(ifille>>T[i]) i++;
    ifille.close();
}
//Stock vide
void stockvide()
{
    if(nbrlisteproduit==0) cout<<"Stock vide ! \n\n";
}
//Liste des produit dans stock
void listePoduit()
{
    if(nbrlisteproduit==0) cout<<"Stock vide ! \n";
    else for(i=0; i<nbrlisteproduit; i++) cout<<" "<<i+1<<"- "<<Liste_produit[i]<<" || Prix : "<<Prix_produits[i]<<" dh/kg"<<endl;
}
//Ajouter un produite
void AjouterProduit()
{
    int i=-1;string n_a_m_e;
    cout<<"Entrer Nom du produit : ";
    cin>>n_a_m_e;
    for(int j=0;j<nbrlisteproduit;j++){
        if(Liste_produit[j]==n_a_m_e) i=j;
    }
    if(i!=-1) cout<<"Cette produit existe deja dans la liste des produit !!"<<endl;
    else{
    Liste_produit[nbrlisteproduit]=n_a_m_e;
    cout<<"Entrer prix du produit : ";
    cin>>Prix_produits[nbrlisteproduit];
    cout<<"Enter le nombre de Kg dans le stock : ";
    cin>>kg_stock[nbrlisteproduit];
    nbrlisteproduit++;
    }
}
//Suprimer un produit
void Suprime_Produit(int k,int j)
{
    if(j>=nbrlisteproduit) cout<<"Enter le numero d'un produit existe dans la liste des choix !! "<<endl;
    else{
    if(k==-1) nom[k]="Systeme";
    File_output_Statu("Supprimer produit : "+Liste_produit[j]+"\t prix : "+to_string(Prix_produits[j])+"Dhs/Kg",k);
    for(i=j; i<nbrlisteproduit; i++)
    {
        kg_stock[i]=kg_stock[i+1];
        Prix_produits[i]=Prix_produits[i+1];
        Liste_produit[i]=Liste_produit[i+1];
        kg_stock[i]=kg_stock[i+1];
    }
    nbrlisteproduit--;
    }
}
//Changer le prix d'une produite
void changerPrix(int j,int k)
{
    float x=Prix_produits[j];
    cout<<"Entrer la nouvelle prix du "<<Liste_produit[j]<<" : ";
    cin>>Prix_produits[j];
    File_output_Statu("Change prix produit : "+Liste_produit[j]+"\t prix avant : "+to_string(x)+" Dhs/Kg"+"\t prix apres : "+to_string(Prix_produits[j])+" Dhs/Kg",k);

}
//Acheter
void Acheter()
{
    do
    {
        cout<<" \nEntrer le nombre de produits que vous souhaitez acheter : ";
        cin>>nbr;
    }
    while(nbr<1 || nbr>nbrlisteproduit);
    for(i=0; i<nbr; i++)
    {
        cout<<"Entrer le produit "<<i+1<<" : ";
        cin>>l;
        cout<<"Nombre Kg : ";
        cin>>Kg;
        if(Kg>kg_stock[l-1]) cout<<"Dans le stock il existe uniquement "<<kg_stock[l-1]<<" de "<<Liste_produit[l-1]<<endl;
        else
        {
            kg_stock[l-1]-=Kg;
            kg[nombreAcheter]=Kg;
            Liste_Acheter[nombreAcheter]=Liste_produit[l-1];
            Prix_Acheter[nombreAcheter]=Prix_produits[l-1];
            nombreAcheter++;
            if(kg_stock[l-1]==0) Suprime_Produit(-1,l-1);
        }
        cout<<"-------------------------------------------------"<<endl;
    }
    for(i=0; i<nombreAcheter; i++) facture+=kg[i]*Prix_Acheter[i];
}
//Facture
void Facture()
{
    facture=0;
    if(nombreAcheter==0) cout<<"Acheter une produit s'il vous plait "<<endl;
    else
    {
        cout<<"----------------------------------------------------------"<<endl;
        for(i=0; i<nombreAcheter; i++)
        {
            cout<<"----------------------------------------------------------"<<endl;
            cout<<Liste_Acheter[i] <<" || Prix : "<<Prix_Acheter[i]<<" dh/Kg"<<" || Acheter : "<<kg[i]<<"Kg"<<endl;
            cout<<"----------------------------------------------------------"<<endl;
            facture+=kg[i]*Prix_Acheter[i];
        }
        cout<<"Total :           "<<facture<<" dh"<<endl;
    }
}
// Supprimer un produit deja acheter
void Supprime_Acheter()
{
    for(i=0; i<nombreAcheter; i++)
    {
        cout<<"----------------------------------------------------------"<<endl;
        cout<<" "<<i+1<<"- "<<Liste_Acheter[i] <<endl;
        cout<<"----------------------------------------------------------"<<endl;
    }
    cout<<" Entrer le produit qui est supprimer : ";
    cin>>nbr;
    for(i=nbr-1; i<nombreAcheter; i++)
    {
        Liste_Acheter[i]=Liste_Acheter[i+1];
        kg[i]=kg[i+1];
        Prix_Acheter[i]=Prix_Acheter[i+1];
    }
    nombreAcheter--;
    for(i=0; i<nombreAcheter; i++) facture+=kg[i]*Prix_Acheter[i];
}
//Changer nombre des Kg d'une prouit deja acheter
void Changer_Kg()
{
    for(i=0; i<nombreAcheter; i++)
    {
        cout<<"----------------------------------------------------------"<<endl;
        cout<<" "<<i+1<<"- "<<Liste_Acheter[i]<< "|| Kg : "<<kg[i] <<endl;
        cout<<"----------------------------------------------------------"<<endl;
    }
    cout<<" Entrer le numero du produit : ";
    cin>>nbr;
    cout<<" Entrer la nouvelle nombre des kg : ";
    cin>>kg[nbr-1];
    for(i=0; i<nombreAcheter; i++) facture+=kg[i]*Prix_Acheter[i];
}

//Ajouter un employer
void Ajouter_un_employer(int n)
{
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin.ignore(1,'\n');
    cout<<"NB : space noo"<<endl;
    cout<<"Nom of employer : ";
    getline(cin,nom[sizecode]);
    cout<<"Password of employer : ";
    getline(cin,code[sizecode]);
    cout<<"-----------------------------------------------------------------------"<<endl;
    sizecode++;
    File_output_Statu_programmer("Ajouter employer : "+nom[sizecode-1],n);
}
//Supprimer un employer
void supprimer_un_employer(int n,int m)
{
    File_output_Statu_programmer("Supprimer employer : "+nom[n],m);
    for(int i=n; i<sizecode; i++)
    {
        nom[i]=nom[i+1];
        code[i]=code[i+1];
    }
    sizecode--;
}
//Liste des employer
void liste_des_employer()
{
    for(int i=0; i<sizecode; i++)
        cout<<"\n"<<i+1<<"- " <<"Nom : "<<nom[i]<<"\t\tpassword : "<<code[i]<<endl;
}
void change_password_employer(int n)
{
    cout<<"Name : "<<nom[n]<<endl;
    cin.ignore(1,'\n');
    cout<<"Password : ";
    getline(cin,code[n]);
}


void changepassword(string Nom[],string Code[],int n)
{
    cout<<"------------------------------  "<<nom[n]<<"  ------------------------------"<<endl;
    cin.ignore(1,'\n');
    cout<<"NB : space noo\n"<<endl;
    cout<<"Current password : ";
    getline(cin,nvpassword[2]);
    cout<<"New password : ";
    getline(cin,nvpassword[0]);
    cout<<"Confirm new password : ";
    getline(cin,nvpassword[1]);
    cout<<"----------------------------------------------------------------"<<endl;
    while(nvpassword[0]!=nvpassword[1] || nvpassword[2]!=Code[n])
    {
        if(nvpassword[0]!=nvpassword[1] )
        {
            cout<<"\nthe two password are not equal ,try again \n"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
        if(nvpassword[2]!=Code[n])
        {
            cout<<"\nThe last password is inccorect\n"<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
        }
        cout<<"------------------------------  "<<nom[n]<<"  ------------------------------"<<endl;
        cout<<"Current password : ";
        cin>>nvpassword[2];
        cout<<"New password : ";
        cin>>nvpassword[0];
        cout<<"Confirm new password : ";
        cin>>nvpassword[1];
        cout<<"----------------------------------------------------------------"<<endl;
    }
    Code[n]=nvpassword[0];
    cout<<"\nThe password is chenged !"<<endl;
}
//Ajouter un programmers
void Ajouter_programmer()
{
    cin.ignore(1,'\n');
    cout<<"Name : ";
    getline(cin,programmer[nbrprogrammer]);
    cout<<"Code : ";
    getline(cin,programmercode[nbrprogrammer]);
    nbrprogrammer++;

}
//Supprimer un programmeur
void supprimer_programmeur(int n)
{
    File_output_Statu_programmer("Supprimer programmeur : "+nom[n],0);

    for(int i=n; i<nbrprogrammer; i++)
    {
        programmer[i]=programmer[i+1];
        programmercode[i]=programmercode[i+1];
    }
    if(nbrprogrammer>1) nbrprogrammer--;
}
//instruction fin programme
void instruction_fin()
{
    File_output_table_string(code,sizecode,"DataTable/code.txt");
    File_output_table_string(nom,sizecode,"DataTable/nom.txt");
    File_output_table_string(programmer,nbrprogrammer,"DataTable/programmer.txt");
    File_output_table_string(programmercode,nbrprogrammer,"DataTable/programmercode.txt");
    File_output_table_string(Liste_produit,nbrlisteproduit,"DataTable/listePoduit.txt");
    File_output_table_float(Prix_produits,nbrlisteproduit,"DataTable/Prix_produits.txt");
    File_output_table_float(kg_stock,nbrlisteproduit,"DataTable/Kg_stock.txt");
    outputnbr();
}
//instruction debut programme
void instruction_debut_programme()
{
    File_input_table_string(code,sizecode,"DataTable/code.txt");
    File_input_table_string(nom,sizecode,"DataTable/nom.txt");
    File_input_table_string(programmer,nbrprogrammer,"DataTable/programmer.txt");
    File_input_table_string(programmercode,nbrprogrammer,"DataTable/programmercode.txt");
    File_input_table_string(Liste_produit,nbrlisteproduit,"DataTable/listePoduit.txt");
    File_input_table_float(Prix_produits,nbrlisteproduit,"DataTable/Prix_produits.txt");
    File_input_table_float(kg_stock,nbrlisteproduit,"DataTable/Kg_stock.txt");
    inputnbr();
}
/*
    0 = Noir        8 = Gris
    1 = Bleu        9 = Bleu clair
    2 = Vert        A = Vert clair
    3 = Bleu-gris   B = Cyan
    4 = Rouge       C = Rouge clair
    5 = Violet      D = Violet clair
    6 = Jaune       E = Jaune clair
    7 = Blanc       F = Blanc brillant
*/








//The principale function
int main()
{
    instruction_debut_programme();
    system("color 0A");
    char choix,choix2,choix3;
    int nbr;
    stockvide();
    do
    {
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"                        Liste des choix                        "<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"  1 - User"<<endl;
        cout<<"  2 - Employer"<<endl;
        cout<<"  3 - Exit"<<endl;
        cout<<"---------------------------------------------------------------\n\n"<<endl;
        cout<<"Entrer leur choix : ";
        cin>>choix;
        system("cls");
//--------------------------------------------------------------------------
        switch(choix)
        {
        case '1':
            system("color 0B");
            cout<<"Enter your full name : ";
            cin.ignore(1,'\n');
            getline(cin,name_user);
            do
            {
                cout<<"\n\n---------------------------------------------------------------"<<endl;
                cout<<"                        Liste des choix                        "<<endl;
                cout<<"---------------------------------------------------------------"<<endl;
                cout<<" 1- Liste des produits "<<endl;
                cout<<" 2- Acheter "<<endl;
                cout<<" 3- Facture "<<endl;
                cout<<" 4- Supprime une produit deja acheter "<<endl;
                cout<<" 5- Changer nombres des Kg "<<endl;
                cout<<" 6- Rotour au menu precedent "<<endl;
                cout<<" 7- Exit "<<endl;
                cout<<"---------------------------------------------------------------\n\n"<<endl;
                cout<<" Entrer leur choix : ";
                cin>>choix2;
                system("cls");
                switch(choix2)
                {

//Afficher les produit existent dans le stock
                case '1':
                    system("color 0E");
                    do
                    {
                        listePoduit();

                        cout<<"\nEntrer * pour retour au menu precedent : ";
                        cin>>choix2;
                        system("cls");
                    }
                    while(choix2!='*');
                    break;
//Acheter un produit
                case '2':
                    system("color 0D");
                    do
                    {
                        listePoduit();
                        Acheter();
                        cout<<"\nEntrer * pour retour au menu precedent: ";
                        cin>>choix2;
                        system("cls");
                    }
                    while(choix2!='*');
                    break;
//Facture
                case '3':
                    system("color 0C");
                    do
                    {
                        Facture();
                        cout<<"\nEntrer * pour retour au menu precedent : ";
                        cin>>choix2;
                        system("cls");
                    }
                    while(choix2!='*');
                    break;
//Supprimeer un element deja acheter
                case '4':
                    system("color 0A");
                    do
                    {
                        Supprime_Acheter();
                        cout<<"\nEntrer * pour retour au menu precedent : ";
                        cin>>choix2;
                        system("cls");
                    }
                    while(choix2!='*');
                    break;
//changer nombre de Kg d'un produit deja acheter
                case '5':
                    system("color 0E");
                    do
                    {
                        listePoduit();
                        Changer_Kg();
                        cout<<"\nEntrer * pour retour au menu precedent ";
                        cin>>choix2;
                        system("cls");
                    }
                    while(choix2!='*');
                    break;
//Retour au menu precedent
                case '6' :
                    cout<<endl;
                    File_output_acheter("DataFille/FACTURE.txt");
                    File_output_acheter("DataFille/Facture2.txt");
                    nombreAcheter=0;
                    break;
//Exit le programme
                case '7':
                    choix='3';
                    File_output_acheter("DataFille/FACTURE.txt");
                    File_output_acheter("DataFille/Facture2.txt");
                    break;
                default :
                    cout <<"  "<<endl;
                    break;
                }
            }
            while(choix2!='6' && choix2!='7');
            break;
//--------------------------------------------------------------------------
        case '2':
            system("color 0C");
            if(sizecode==0)
            {
                cout<<"Salut Mensieur le directeur de cette mark "<<endl;
                cout<<"Enter your email : ";
                cin>>nom[sizecode];
                cout<<"Enter your password : ";
                cin>>code[sizecode];
                sizecode++;
                instruction_fin();
                system("cls");
            }
            else
            {
                do
                {
                    nbr=100;
                    if(sizecode==0)
                    {
                        cout<<"Liste vide des employer ! "<<endl;
                        choix2='6';
                        break;
                    }
                    else
                    {
                        cout<<"\n------------------------Login------------------------"<<endl;
                        cin.ignore(1,'\n');
                        cout<<"Name : ";
                        getline(cin,name);
                        cout<<"password : ";
                        getline(cin,password);
                        cout<<endl;
                        for(int i=0; i<sizecode; i++)
                            if(name==nom[i] && password==code[i])
                            {
                                nbr=i;
                                break;
                            }
                        system("cls");
                    }
                }
                while(nbr==100);
                while(choix2!='6' && choix2!='7')
                {
                    cout<<"\n\n---------------------------------------------------------------"<<endl;
                    cout<<"                        Liste des choix                        "<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<" 1- Liste des produits "<<endl;
                    cout<<" 2- Ajoutez un produit "<<endl;
                    cout<<" 3- Supprimer un produit "<<endl;
                    cout<<" 4- Changer le prix d'une produit "<<endl;
                    cout<<" 5- Change password "<<endl;
                    cout<<" 6- Rotour au menu precedent "<<endl;
                    cout<<" 7- Exit"<<endl;
                    cout<<"---------------------------------------------------------------\n\n"<<endl;
                    cout<<" \n\nEntrer leur choix : ";
                    cin>>choix2;
                    system("cls");
                    switch(choix2)
                    {
//Afficher les produit existent dans le stock
                    case '1':
                        system("color 0F");
                        do
                        {
                            listePoduitStock();
                            cout<<"\nEntrer * pour retour au menu precedent : ";
                            cin>>choix2;
                            system("cls");
                        }
                        while(choix2!='*');
                        break;
//Ajouter produit
                    case '2':
                        system("color 0A");
                        do
                        {
                            AjouterProduit();
                            File_output_Statu("Ajouter produit : "+Liste_produit[nbrlisteproduit-1]+"\t prix : "+to_string(Prix_produits[nbrlisteproduit-1])+"Dhs/Kg",nbr);
                            instruction_fin();
                            cout<<"\nEntrer * pour retour au menu precedent : ";
                            cin>>choix2;
                            system("cls");
                        }
                        while(choix2!='*');
                        break;
//Supprime produit
                    case '3':
                        system("color 0C");
                        do
                        {
                            if(nbrlisteproduit==0)
                            {
                                cout<<"Liste vide !"<<endl;
                            }
                            else
                            {
                                listePoduitStock();
                                cout<<"Entrer le numero du produit : ";
                                cin>>nbr1;
                                Suprime_Produit(nbr,nbr1-1);
                                instruction_fin();
                            }
                            cout<<"\nEntrer * pour retour au menu precedent : ";
                            cin>>choix2;
                            system("cls");
                        }
                        while(choix2!='*');
                        break;
//Changer le prix d'un produit
                    case '4':
                        system("color 0D");
                        do
                        {
                                listePoduitStock();
                                cout<<"Entrer le numero du produit : ";
                                cin>>nbr1;
                                changerPrix(nbr1-1,nbr);
                                instruction_fin();
                                cout<<"\nEntrer * pour retour au menu precedent : ";
                                cin>>choix2;
                                system("cls");
                        }while(choix2!='*');
                        break;
//Change password
                    case '5':
                        system("color 0E");
                        do
                        {
                            changepassword(nom,code,nbr);
                            File_output_Statu("Changer leur password !",nbr);
                            instruction_fin();
                            cout<<"\nEntrer * pour retour au menu precedent : ";
                            cin>>choix2;
                            system("cls");
                        }while(choix2!='*');
                        break;
//retour au menu precedent
                    case '6':
                        cout<<endl;
                        break;
                    //Exit le programme
                    case '7':
                        choix='3';
                        break;
                    default :
                        cout <<"Entre un numero existe dans Les choix : "<<endl;
                        break;
                    }
                }
            }
            break;
//----------------------------------------------------------------------------------------------------
        case '*':
            system("color 0E");
            if(nbrprogrammer==0)
            {
                cout<<"Salut Mensieur le directeur de cette mark "<<endl;
                cout<<"Enter your email : ";
                cin>>programmer[nbrprogrammer];
                cout<<"Enter your password : ";
                cin>>programmercode[nbrprogrammer];
                nbrprogrammer++;
            }
            do
            {
                nbr=100;
                cout<<"\n------------------------Login------------------------"<<endl;
                cin.ignore(1,'\n');
                cout<<"Name : ";
                getline(cin,name);
                cout<<"password : ";
                getline(cin,password);
                cout<<endl;
                for(int i=0; i<nbrprogrammer; i++)
                    if(name==programmer[i] && password==programmercode[i])
                    {
                        nbr=i;
                        break;
                    }
                system("cls");
            }
            while(nbr==100);
            do
            {
                cout<<"\n\n---------------------------------------------------------------"<<endl;
                cout<<"                        Liste des choix                        "<<endl;
                cout<<"---------------------------------------------------------------"<<endl;
                cout<<" 1- Liste des employer "<<endl;
                cout<<" 2- Ajoutez un employer "<<endl;
                cout<<" 3- Supprimer un employer "<<endl;
                cout<<" 4- Changer un password d'un employer "<<endl;
                cout<<" 5- Rotour au menu precedent "<<endl;
                cout<<" 6- Exit"<<endl;
                cout<<"---------------------------------------------------------------\n\n"<<endl;
                cout<<" \n\nEntrer leur choix : ";
                cin>>choix2;
                system("cls");
                switch(choix2)
                {
//Liste des employer
                case '1':
                    system("color 0F");
                    do
                    {
                        liste_des_employer();
                        cout<<"\nEntrer * pour retour au menu precedent : ";
                        cin>>choix2;
                        system("cls");
                    }while(choix2!='*');
                    break;
//Ajouter un employer par user
                case '2':
                    system("color 01");
                    do
                    {
                        Ajouter_un_employer(nbr);
                        instruction_fin();
                        cout<<"\nEntrer * pour retour au menu precedent : ";
                        cin>>choix2;
                        system("cls");
                    }while(choix2!='*');
                    break;
//Supprimer un employer par programmer
                case '3':
                    system("color 02");
                    do
                    {
                        if(sizecode==0)
                            {
                                cout<<"Liste vide ! "<<endl;
                                choix2='4';
                            }
                            else
                            {
                                liste_des_employer();
                                cout<<"Entrer le numero de employer : ";
                                cin>>nbr1;
                                supprimer_un_employer(nbr1-1,nbr);
                                instruction_fin();
                            }
                        cout<<"\nEntrer * pour retour au menu precedent : ";
                        cin>>choix2;
                        system("cls");
                    }while(choix2!='*');
                    break;
//Changer password d'un employer par programmer
                case '4':
                    system("color 05");
                    do
                    {
                        liste_des_employer();
                            cout<<"Entrer le numero de employer : ";
                            cin>>nbr1;
                            File_output_Statu_programmer("Changer password employer : "+nom[nbr1-1],nbr);
                            changepassword(nom,code,nbr1-1);
                            instruction_fin();
                        cout<<"Entrer * pour retour au menu precedent ";
                        cin>>choix2;
                        system("cls");
                    }while(choix2!='*');
                    break;
//-------------------------------------------------------------------------------------------------
                case '#':
                    system("color 0D");
                    do
                    {
                        nbr=100;
                        cout<<"\n------------------------Login------------------------"<<endl;
                        cin.ignore(1,'\n');
                        cout<<"Name : ";
                        getline(cin,name);
                        cout<<"password : ";
                        getline(cin,password);
                        cout<<endl;
                        if(name==programmer[0] && password==programmercode[0]) nbr=0;
                        system("cls");
                    }
                    while(nbr==100);
                    do
                    {
                        cout<<"\n\n----------------------------------------------------"<<endl;
                        cout<<"               Liste des Choix                      "<<endl;
                        cout<<"----------------------------------------------------"<<endl;
                        cout<<" 1-Liste des programer "<<endl;
                        cout<<" 2-Ajouter un programmeur "<<endl;
                        cout<<" 3-Supprimer un programmeur "<<endl;
                        cout<<" 4-Retour au menu precedent "<<endl;
                        cout<<"----------------------------------------------------"<<endl;
                        cout<<" Entrer leur choix : ";
                        cin>>choix2;
                        system("cls");
                        switch(choix2)
                        {
                        case '1':
                            system("color 0A");
                            if(nbrprogrammer==1) cout<<"Liste Vide "<<programmer[0]<<endl;
                            else
                                for(int i=1; i<nbrprogrammer; i++)
                                    cout<<i<<"- Name : "<<programmer[i]<<"\t\tPassword : "<<programmercode[i]<<endl;
                            break;
                        //Ajouter un programers
                        case '2':
                            system("color 0B");
                            do
                            {
                                Ajouter_programmer();
                                    File_output_Statu_programmer("Ajoutez programmeur : "+programmer[nbrprogrammer-1],0);
                                    instruction_fin();
                                cout<<"Entrer * pour retour au menu precedent : ";
                                cin>>choix2;
                                system("cls");
                            }
                            while(choix2!='*');
                            break;
                        //Supprimer un programers
                        case '3':
                            system("color 0C");
                            do
                            {
                                if(nbrprogrammer==1)
                                    {
                                        cout<<"Liste des programmeur vide !"<<endl;
                                        choix2='4';
                                    }
                                    else
                                    {
                                        for(int i=1; i<nbrprogrammer; i++)
                                            cout<<i<<"- Name : "<<programmer[i]<<"\t\tPassword : "<<programmercode[i]<<endl;
                                        cout<<"Entrer le numero de programmeur : ";
                                        cin>>nbr1;
                                        supprimer_programmeur(nbr1);
                                        instruction_fin();
                                    }
                                cout<<"Entrer * pour retour au menu precedent : ";
                                cin>>choix2;
                                system("cls");
                            }while(choix2!='*');
                            break;
                        case '4':
                            cout<<endl;
                            break;
                        default :
                            cout<<"Enter un numero exist dans les choix !!!"<<endl;
                            break;
                        }
                    }
                    while(choix2!='4');
                    break;
//retoue au menu precedent
                case '5':
                    cout<<endl;
                    break;
//Exit
                case '6':
                    choix='3';
                    break;
                }
            }
            while(choix2!='5' && choix2!='6');
            break;
        //case programmer
        case 'c':
            system("color 0E");
            do
            {
                nbr=100;
                cout<<"\n------------------------Login------------------------"<<endl;
                cin.ignore(1,'\n');
                cout<<"Name : ";
                getline(cin,name);
                cout<<"password : ";
                getline(cin,password);
                cout<<endl;
                if(name==coder[0] && password==coder[0]) nbr=0;
                system("cls");
            }
            while(nbr==100);
            do
            {
                if(nbrprogrammer!=0)
                {
                    cout<<"Liste des programmeur : "<<endl;
                    for(int i=0; i<nbrprogrammer; i++)
                    {
                        cout<<i+1<<"- Name : "<<programmer[i]<<"\t\tPassword : "<<programmercode[i]<<endl;
                    }
                }
                if(sizecode!=0)
                {
                    cout<<"Liste des Employer : "<<endl;
                    for(int i=0; i<sizecode; i++)
                    {
                        cout<<i+1<<"- Name : "<<nom[i]<<"\t\tPassword : "<<code[i]<<endl;
                    }
                }
                cout<<"\nEntrer * pour retour au menu precedent : ";
                cin>>choix2;
                system("cls");
            }
            while(choix2!='*');
            break;
        default :
            cout <<endl;
            break;
        }
    }
    while(choix!='3');
    instruction_fin();
    return 0;
}

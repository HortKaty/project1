#include "graphics.hpp"
#include "racs.h"
#include "amoba.h"
#include <iostream>

using namespace genv;

Amoba::Amoba()
{
    gout.open(700,700);
    ki_jon="Player1 jon";
    nyertes="";
    k= new StaticTextBox(50,50,150,40, ki_jon);
    p1= new StaticTextBox(280,50,190,40, "");

    widgets.push_back(k);
    widgets.push_back(p1);

    lepesszam=0;

    for(unsigned int i=0; i<30; i++)
        for(unsigned int j=0; j<30; j++)
        {
            racs *uj= new racs(100+j*15, 100+i*15, 15, 15, 30*i+j,  this);
            racsok.push_back(uj);
            widgets.push_back(uj);
        }
}
void Amoba::uj_lepes(int sorszam)
{
    //p1 lefele
    lepesszam++;
    if(racsok[sorszam]->getKi()=="1")
    {
        int i=30;
        int szamlalo=0;
        int szamolo=0;

            while(racsok[sorszam+i]->getKi()=="1")
            {

                if(sorszam+i+30<899)
                {
                    i+=30;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
            //p1 felfele
        i=30;
        if(sorszam>=30)
            while(racsok[sorszam-i]->getKi()=="1")
            {
                if(sorszam-i-30>0)
                {
                    i+=30;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        i=0;
        if(sorszam>=30)
            while(racsok[sorszam-i]->getKi()=="1")
            {
                if(sorszam-i-30>0)
                {
                    i+=30;
                    szamolo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4 || szamolo>=4)
        {
            nyertes="Player 1 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }
        //p1 jobbra
        i=1;
        szamlalo=0;

            while(racsok[sorszam+i]->getKi()=="1")
            {

                if(sorszam+i+1<899)
                {
                    i+=1;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
            //p1 balra
        i=1;
        if(sorszam>=1)
            while(racsok[sorszam-i]->getKi()=="1")
            {

                if(sorszam-i-1>0)
                {
                    i+=1;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4)
        {
            nyertes="Player 1 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }
        //p1 balra le
        i=29;
        szamlalo=0;
        szamolo=0;

            while(racsok[sorszam+i]->getKi()=="1")
            {

                if(sorszam+i+29<899)
                {
                    i+=29;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
        //p1 jobbra fel
        i=29;
        if(sorszam>=29)
            while(racsok[sorszam-i]->getKi()=="1")
            {

                if(sorszam-i-29>0)
                {
                    i+=29;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        i=0;
        if(sorszam>=29)
            while(racsok[sorszam-i]->getKi()=="1")
            {
                if(sorszam-i-29>0)
                {
                    i+=29;
                    szamolo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4 || szamolo>=4)
        {
            nyertes="Player 1 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }

            //p1 jobbra le
        i=31;
        szamlalo=0;
        szamolo=0;

            while(racsok[sorszam+i]->getKi()=="1")
            {

                if(sorszam+i+31<899)
                {
                    i+=31;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
        //p1 balra fel
        i=31;
        if(sorszam>=31)
            while(racsok[sorszam-i]->getKi()=="1")
            {

                if(sorszam-i-31>0)
                {
                    i+=31;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        i=0;
        if(sorszam>=31)
            while(racsok[sorszam-i]->getKi()=="1")
            {
                if(sorszam-i-31>0)
                {
                    i+=31;
                    szamolo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4 || szamolo>=4)
        {
            nyertes="Player 1 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }
        ki_jon="Player2 jon";
        k->settext(ki_jon);
    }
//p2 lefele
    if(racsok[sorszam]->getKi()=="2")
    {
        int i=30;
        int szamlalo=0;
        int szamolo=0;

            while(racsok[sorszam+i]->getKi()=="2")
            {

                if(sorszam+i+30<899)
                {
                    i+=30;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
            //p2 felfele
        i=30;
        if(sorszam>=30)
            while(racsok[sorszam-i]->getKi()=="2")
            {

                if(sorszam-i-30>0)
                {
                    i+=30;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        i=0;
        if(sorszam>=30)
            while(racsok[sorszam-i]->getKi()=="2")
            {
                if(sorszam-i-30>0)
                {
                    i+=30;
                    szamolo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4 || szamolo>=4)
        {
            nyertes="Player 2 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }
        //p2 jobbra
        i=1;
        szamlalo=0;

            while(racsok[sorszam+i]->getKi()=="2")
            {

                if(sorszam+i+1<899)
                {
                    i+=1;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
            //p2 balra
        i=1;
        if(sorszam>=1)
            while(racsok[sorszam-i]->getKi()=="2")
            {

                if(sorszam-i-1>0)
                {
                    i+=1;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4)
        {
            nyertes="Player 2 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }
        //p1 balra le
        i=29;
        szamlalo=0;
        szamolo=0;

            while(racsok[sorszam+i]->getKi()=="2")
            {

                if(sorszam+i+29<899)
                {
                    i+=29;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
        //p1 jobbra fel
        i=29;
        if(sorszam>=29)
            while(racsok[sorszam-i]->getKi()=="2")
            {

                if(sorszam-i-29>0)
                {
                    i+=29;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        i=0;
        if(sorszam>=29)
            while(racsok[sorszam-i]->getKi()=="2")
            {
                if(sorszam-i-29>0)
                {
                    i+=29;
                    szamolo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4 || szamolo>=4)
        {
            nyertes="Player 2 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }

            //p1 jobbra le
        i=31;
        szamlalo=0;
        szamolo=0;

            while(racsok[sorszam+i]->getKi()=="2")
            {

                if(sorszam+i+31<899)
                {
                    i+=31;
                    szamlalo++;
                    cout<<"haha"<<endl;
                }
                else
                    break;
            }
        //p1 balra fel
        i=31;
        if(sorszam>=31)
            while(racsok[sorszam-i]->getKi()=="2")
            {

                if(sorszam-i-31>0)
                {
                    i+=31;
                    szamlalo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        i=0;
        if(sorszam>=31)
            while(racsok[sorszam-i]->getKi()=="2")
            {
                if(sorszam-i-31>0)
                {
                    i+=31;
                    szamolo++;
                    cout<<"hege"<<endl;
                }
                else
                    break;
            }
        if(szamlalo>=4 || szamolo>=4)
        {
            nyertes="Player 2 nyert!";
            p1->settext(nyertes);
            for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
        }
        ki_jon="Player1 jon";
        k->settext(ki_jon);
    }
    if(lepesszam==400)
    {
        nyertes="Patthelyzet";
        p1->settext(nyertes);
        for(unsigned int i=0; i<racsok.size(); i++)
            racsok[i]->focuszos();
    }

}

string Amoba::getkovi()
{
    return ki_jon;
}

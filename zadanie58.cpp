/*zadanie 58 systemy liczbowe*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;
int dow_to_dec(string a, int b)
{
	int poczatek=0;
	if (a[0]=='-') poczatek=1;
	int p=1, s=0;
	for ( int i= a.size()-1; i>=poczatek; i--)
	{
		
		s+=(a[i]-'0')*p;
		p=p*b;
	}
	if (poczatek == 1 )  return s*-1;
	return s;
}
string dec_to_bin(int a)
{
	bool czyujemna=0;
	string s="";
	if (a<0) 
	{
		a*=-1;
		czyujemna = 1;
	}
	while(a>0)
	{
		s=char(a%2+48)+s;
		a/=2;
	}
	if (czyujemna==1) return "-"+s;
	return s;
}
void zadanie58()
{
	ifstream plik1, plik2, plik3;
	plik1.open("dane_systemy1.txt");
	plik2.open("dane_systemy2.txt");
	plik3.open("dane_systemy3.txt");
	string a1, a2, a3; 
	string b1, b2, b3;
	int zle=0, najmniejsza1=1000, najmniejsza2=1000, najmniejsza3=1000; 
	while (plik1>>a1 && plik1>>b1 && plik2>>a2 && plik2>>b2 && plik3>>a3 && plik3>>b3) 
	{
		if (dow_to_dec(b1,2)<najmniejsza1) najmniejsza1=dow_to_dec(b1,2);
		if (dow_to_dec(b2,4)<najmniejsza2) najmniejsza2=dow_to_dec(b2,4);
		if (dow_to_dec(b3,8)<najmniejsza3) najmniejsza3=dow_to_dec(b3,8);
		if (dow_to_dec(a1,2)%12!=0 && dow_to_dec(a2,4)%12!=0 && dow_to_dec(a3,8)%12!=0) zle++;
	}
	cout<<dec_to_bin(najmniejsza1)<<endl;
	cout<<dec_to_bin(najmniejsza2)<<endl;
	cout<<dec_to_bin(najmniejsza3)<<endl;
	cout<<zle;
}
void zadanie58cz2()
{
	ifstream plik1, plik2, plik3;
	plik1.open("dane_systemy1.txt");
	plik2.open("dane_systemy2.txt");
	plik3.open("dane_systemy3.txt");
	string a1, a2, a3; 
	string b1, b2, b3;
	bool czy_rekord=0;
	int rekord1=-100,rekord2=-100,rekord3=-100, licznik=0;
	while (plik1>>a1 && plik1>>b1 && plik2>>a2 && plik2>>b2 && plik3>>a3 && plik3>>b3) 
	{
		czy_rekord=false;
		if(dow_to_dec(b1,2)>rekord1) 
		{
			rekord1=dow_to_dec(b1,2);
			czy_rekord=true;
		}
		if(dow_to_dec(b2,4)>rekord2) 
		{	
			rekord2=dow_to_dec(b2,4);
			czy_rekord=true;
		}
		if(dow_to_dec(b3,8)>rekord3) 
		{
			rekord3=dow_to_dec(b3,8);
			czy_rekord=true;
		}
		if (czy_rekord == true) licznik++;
	}
	cout<<licznik;
}
void zadanie58cz3()
{
	ifstream plik1, plik2, plik3;
	plik1.open("dane_systemy1.txt");
	string a1; 
	string b1;
	int temperatury[1095];
	for (int i=0; i<1095; i++)
	{
		plik1>>a1; plik1>>b1;
		temperatury[i]=dow_to_dec(b1,2);
	}
	for (int i=0; i<5-1; i++)
	{
		cout<<"i: "<<i<<endl;
		for (int j=i+1; j<5; j++)
		{
			cout<<j<<endl;
		}
	}
}
int main()
{
	ifstream plik1, plik2, plik3;
	plik1.open("dane_systemy1.txt");
	string a1;
	string b1; 
	int temperatury[1095];
	for (int i=0; i<1095; i++)
	{
		plik1>>a1; plik1>>b1; 
		temperatury[i]=dow_to_dec(b1,2);	
	}
	int r, t1, t2;
	double skok,skoki[1095],maks=0;
	for (int i=0; i<1095; i++)
	{
		for (int j=i+1; j<1095; j++)
		{
			r = ceil(pow(temperatury[i]-temperatury[j],2));
			skok = r/abs(i-j);
			skoki[i]=skok;
			if (maks<skok) maks=skok; 
		}
	}
	cout<<"najwiekszy skok temperatury w staci pogodowej S1: "<<maks<<endl;
	
}


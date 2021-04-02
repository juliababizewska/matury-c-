#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int NWD(int a, int b)	
{
	while (b!=0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
void podpunkt1()
{
		ifstream plik; 
	plik.open("dane_ulamki.txt");
	double min=1000;
	double a, b, mina=1000, minb=1000; 
	for (int i=0; i<1000; i++)
	{
		plik>>a; plik>>b;
		//cout<<"a= "<<a<<"   b= "<<b<<"   a/b= "<<a/b<<endl ;
		if (min>(a/b)) 
		{
			mina=a;
			minb=b;
			min=mina/minb;
		}
		else if (min==(a/b))
		{
			if(minb>b)
			{
				mina=a;
				minb=b;
			}
		}
	}
	cout<<"65.1"<<endl;
	cout<<"ulamek o minimalnej wartosci: "<<mina<<"/"<<minb<<endl;
}
void podpunkt2()
{
	ifstream plik; 
	plik.open("dane_ulamki.txt");
	double min=1000;
	double a, b, ilosc=0; 
	for (int i=0; i<1000; i++)
	{
		plik>>a; plik>>b;
		if(NWD(a,b)==1) ilosc++;
	}
	cout<<"65.2"<<endl;
	cout<<"ilosc ulamkow zapisanych w postaci nieskracalnej: "<<ilosc<<endl;
}
void podpunkt3()
{
	ifstream plik; 
	plik.open("dane_ulamki.txt");
	double min=1000;
	double a, b, suma=0; 
	for (int i=0; i<1000; i++)
	{
		plik>>a; plik>>b; //licznik=a, mianownik=b
		int dzielnik=NWD(a,b);
		 a= a/dzielnik; 
		 suma=suma+a; 
	}
	cout<<"65.3"<<endl;
	cout<<"suma wszystkich licznikow ulamkow po skroceniu: "<<suma<<endl ;
}
void podpunkt4()
{
	ifstream plik; 
	plik.open("dane_ulamki.txt");
	double min=1000;
	long long suma=0;
	double b, a, mianownik=pow(2,2)*pow(3,2)*pow(5,2)*pow(7,2)*13; 
	for (int i=0; i<1000; i++)
	{
		plik>>a; plik>>b; //licznik=a, mianownik=b
		suma= suma + a * (mianownik/b);
	}
	cout<<"65.4"<<endl;
	cout<<"licznik ulamka sumy wszystkich ulamkow z pliku: "<<suma;

}
int main()
{
	podpunkt1();
	podpunkt2();
	podpunkt3();
	podpunkt4();

	
}

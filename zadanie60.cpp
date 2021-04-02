#include <iostream>
#include <fstream>
using namespace std;
int iledzielnikow(int a)
{
	int ile = 0;
	for (int i=1; i<=a; i++)
	{
		if (a%i==0) 
		{
			ile++;
		}
	}
	return ile;
}
void dzielniki(int a)
{
	cout<<"dzielniki liczby "<<a<<": "<<endl;
	for (int i=1; i<=a; i++)
	{
		if (a%i==0) 
		{
			cout<<i<<"   ";
		}
	} 
}
int NWD(int a, int b)
{
	while (a>0)
	{
		a=a%b;
		b=b-a;
	}
	return b; 
}
void czescpierwsza()
{
	ifstream liczby;
	liczby.open("liczby.txt");
	int liczba, ilemniejszych=0, przedostatnia=0, ostatnia=0 ;
	while (liczby>>liczba)
	{
		if (liczba<1000) 
		{
			przedostatnia =ostatnia;
			ostatnia = liczba ;
			ilemniejszych++;
			
		}
	}
	cout<<"ile jest liczb mniejszych od 1000?: "<<ilemniejszych<<endl<<"ostatnie dwie liczby mniejsze od 1000 w pliku: "<<ostatnia<<"   "<<przedostatnia;
}
void czescdruga()
{
		ifstream liczby;
	liczby.open("liczby.txt");
	int liczba ;
	while (liczby>>liczba) 
	{
		if(iledzielnikow(liczba)==18) dzielniki(liczba);
	}

}
int main()
{
	ifstream liczby;
	liczby.open("liczby.txt");
	int liczba, T[200] ;
		for(int i=0; i<200; i++)
		{
			liczby>>liczba; 
			T[i]=liczba;
		}
	for (int i=0; i<200; i++)
	{
		bool prawda = true; 
		for(int j=0; j<200; j++)
		{
			if (j==i) continue; 
			if (NWD(T[i], T[j])!=1)
			{
				prawda = false;
				break; 
			} 
		}
		if(prawda==true) cout<< T[i]<<endl; 
	}
	


}

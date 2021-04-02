#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;
int ileczynnikow(int a)
{
	int dzielnik=3, ile=0;
	while(a>1)
	{
		if (a%2==0) return 1;
		if(a%dzielnik==0) 
		{
			ile++;
			while(a%dzielnik==0)
			{
			a/=dzielnik;
			}
		}
		dzielnik++;
	}
	return ile;
}
string odwrotnosc(string a)
{
	string b;
	for (int i=a.size()-1; i>=0; i--)
	{
		b+=a[i];
	}
	return b;
}
bool czy_palindrom(string a)
{
	for(int i=a.size()-1; i>=0; i--)
	{
		if (a[a.size()-i-1] != a[i]) return false;
	}
	 return true;
}

int iloczyncyfr(int a)
{
	int iloczyn=1;
	while (a>0)
	{
		iloczyn*=a%10;
		a/=10;
	}
	return iloczyn;
}
void czesc1()
{
	ifstream liczby;
	liczby.open("liczby.txt");
	int listalicz[1000], trzyrozne=0, l;
	for (int i=0; i<1000; i++)
	{	
		int a;
		liczby>>a;
		listalicz[i]=a;	
	}
	for (int i=0; i<1000; i++)
	{
		l = ileczynnikow(listalicz[i]);
		if (l==3) trzyrozne++;
	}
	cout<<trzyrozne<<endl;
}
void czesc2()
{	
		ifstream liczby;
		liczby.open("liczby.txt");
		string a1, a2;
		int suma, ile=0;
		
	while (liczby>>a1)
	{
	
		a2= odwrotnosc(a1);
		int b1=atoi(a1.c_str());
		int b2=atoi(a2.c_str());
		suma = b1+b2;
		stringstream ss;
		ss<<suma;
		string suma1;
		ss>>suma1;
		if (czy_palindrom(suma1)) ile++;
	}
	cout<<"dla tylu liczb suma tej liczby i odwrocenia jej, jest palindromem: "<<ile<<endl;
}
int main()
{
	ifstream liczby;
	liczby.open("liczby.txt");
	int a1, a2,astring, T[9]={0};

	while (liczby>>a1)
	{
		int dlugosc, ile=0;
		stringstream ss;
		ss<<a1;
		string astring;
		ss>>astring;
		dlugosc=astring.size();
		while(dlugosc>1)
		{
			a2=iloczyncyfr(a1);
			ile++;
			a1=a2;
			stringstream ss;
			ss<<a2;
			string astring;
			ss>>astring;
			dlugosc=astring.size();
			
		}
		T[ile]++;
			
	}
	for (int i=1; i<=8; i++) cout<<"T["<<i<<"]"<<T[i]<<endl;
	
	
}

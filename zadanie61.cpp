//zadanie 61 
#include <iostream>
#include <fstream>
using namespace std;
bool czyarytmetyczny(int *T, int n)
{
	int roznica;
	roznica = T[1]-T[0];
	for (int i=2; i<n-1; i++)
	{
		if (T[i+1]-T[i]!= roznica) return false;
	}
	return true; 
	
}
int intruz(int *T, int n)
{
	int roznica[n];
	for (int i=0; i<n; i++)
	{
		roznica[i] = T[i+1]-T[i];
	}
	if (roznica[0]!= roznica[1] && roznica[1]==roznica[2]) return T[0];
	if (roznica[0] != roznica[2] && roznica[1] != roznica[2] && roznica[3]==roznica[2]) return T[1];
	for (int i=0; i+1<n; i++)
	{
		if (roznica[i] != roznica[0]) return T[i+1];
	}
}
bool czyszescian(int a)// liczby nie przekraczaj¹ miliona czyli najwiekszy szescian to 
// 100*100*100 
{
	for(int i=1; i<=100; i++)
	{
		if (i*i*i==a) return true;
	}
	return false;
}
void czescpierwsza()
{
	ifstream ciagi;
	ciagi.open("ciagi.txt");
	int liczba, ile=0, najwroznica=0;
	while(ciagi>>liczba)
	{
		int T[liczba];
		for(int i=0; i<liczba; i++)
		{
			ciagi>>T[i];
		}
		if (czyarytmetyczny(T,liczba)) 
		{
			ile++;
			if (T[1]-T[0]>najwroznica) najwroznica=T[1]-T[0];	
		}
	}
	cout<<"ile: "<<ile<<endl;
	cout<<"Najwroznica: "<<najwroznica<<endl;
}
void czescdruga()
{
	ifstream ciagi;
	ciagi.open("ciagi.txt");
	int liczba, ile=0, najwroznica=0, najwszescian=0;
	while(ciagi>>liczba)
	{
		int T[liczba];
		for(int i=0; i<liczba; i++)
		{
			ciagi>>T[i];
		}
		najwszescian=0;
		for(int i=0; i<liczba;i++)
		{
			if(czyszescian(T[i])) 
			{
				if (T[i]>najwszescian) najwszescian=T[i];
				break;
			}
		}
		if (najwszescian!=0) cout<<najwszescian<<endl;
	}
}

int main()
{
	ifstream bledne;
	bledne.open("bledne.txt");
	int liczba, ile=0, najwroznica=0, najwszescian=0;
	while(bledne>>liczba)
	{
		int T[liczba];
		for(int i=0; i<liczba; i++)
		{
			bledne>>T[i];
		}
		cout<<intruz(T, liczba)<<endl;

	}
}

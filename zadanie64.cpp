//zadanie 64
#include <iostream>
#include <fstream>
using namespace std;
const int o=500;
bool czyrewers(char T[][o], int m, int n) // 0=bialy 1=czarny
{
	int czarne=0, biale=0;
	char b=1, a=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (T[i][j]== '1') czarne++;
			else biale++;
 		}
	}
	if (czarne>biale) return true;
	else return false;
}
int ileczarnych(char T[][o], int m, int n)
{ 
	int czarne=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (T[i][j] == '1') czarne++;
 		}
	}
	return czarne;
}
void czescpierwsza()
{
	ifstream obrazki; 
	obrazki.open("dane_obrazki.txt");
	string b; 
	int rewers=0, m=20, n=20, maxczar=0; 
	for(int i=0; i<200; i++)
	{
		char T[m+1][o];
		for(int j=0; j<21; j++)
		{ 
			obrazki>>b;  
			for(int k=0; k<20; k++)
			{
				T[j][k]=b[k];
			}
			T[20][20];		
		}
		/*for(int j=0; j<m; j++)
		{
			for(int k=0; k<n; k++)
				{
					cout<<T[j][k];
				}
			cout<<endl;
		}
		cout<<endl;*/
		if (czyrewers(T,m,n)) 
		{
			rewers++;
			if (ileczarnych(T,m,n)>maxczar) maxczar=ileczarnych(T,m,n);	
		}
	}
	cout<<"tyle jest rewersow w pliku: "<<rewers<<endl;
	cout<<"najwiaksza liczba pikseli czarnych wystepujacych w jednym obrazku: "<<maxczar<<endl;	
}
void czescdruga()
{
	ifstream obrazki; 
	obrazki.open("dane_obrazki.txt");
	string b; 
	int rewers=0, m=20, n=20, maxczar=0; 
	for(int i=0; i<200; i++)
	{
		char T[20][20];
		for(int j=0; j<20; j++)
		{ 
			obrazki>>b;  
			for(int k=0; k<20; k++)
			{
				T[j][k]=b[k];
			}	
		}
		obrazki>>b;
		bool a=1;
		for (int j=0; j<10; j++)
		{
		
			for(int k=0; k<10; k++)
			{
				if (T[j][k]!=T[j][k+10] || T[j][k]!=T[j+10][k] || T[j][k]!=T[j+10][k+10]) 
				{
					a=0; 	
				}
			}
		}
			if (a==1) 
			{
			for(int j=0; j<m; j++)
			{
				for(int k=0; k<n; k++)
					{
						cout<<T[j][k];
					}
				cout<<endl;
			}
			cout<<endl;
			}
		

	}
}
void czesctrzecia()
{
		ifstream obrazki; 
	obrazki.open("dane_obrazki.txt");
	string b;  
	int naprawialny =0, poprawny=0, nienaprawialny=0, maks=0;
	for(int i=0; i<200; i++)
	{
		int wiersz=0, kolumna=0; //bledy w wiersach/kolumnie 
		bool bpoprawny = true; 
		char T[21][21];
		for(int j=0; j<21; j++)
		{ 
			obrazki>>b;  
			for(int k=0; k<21; k++)
			{
				T[j][k]=b[k];
				//cout<<T[j][k];
			}
			//cout<<endl; 
		}
		//cout<<endl; 
		//obrazki>>b;  
		for(int j=0; j<20; j++)
		{ 
			int jed1=0,  jed2=0; //jed1 - wiersze jed2 - kolumny  
			for(int k=0; k<20; k++)
			{
				if (T[j][k]=='1') jed1++;
				if (T[k][j]=='1') jed2++;
			}
			if ((jed1%2==0 && T[j][20]!='0') || (jed1%2==1 && T[j][20] !='1'))
			{
				wiersz++;	
				bpoprawny = false;
			}
			if ((jed2%2==0 && T[20][j]!='0') || (jed2%2==1 && T[20][j] !='1')) 
			{
				kolumna++;	
				bpoprawny = false; 	
			}
		}
		
		if (bpoprawny) poprawny++;
		else  
		{
			if ((kolumna<=1) && (wiersz<=1) ) naprawialny++;
			else nienaprawialny++;		
		}
		if (kolumna+wiersz>maks) maks=kolumna+wiersz; 
	
	}
	cout<<"poprawne: "<<poprawny<<endl;
	cout<<"naprawialne: "<<naprawialny<<endl;
	cout<<"nienaprawialne: "<<nienaprawialny<<endl;
	cout<<"najwieksza liczba bledow: "<<maks<<endl;

}
int main()
{
	ifstream obrazki; 
	obrazki.open("dane_obrazki.txt");
	string b;  
	bool bpoprawny=true;
	int x=-1, y=-1; //wspolrzedne bledu 
	for(int i=0; i<200; i++)
	{
		int wiersz=0, kolumna=0; //bledy w wiersach/kolumnie 
		bool bpoprawny = true; 
		char T[21][21];
		for(int j=0; j<21; j++)
		{ 
			obrazki>>b;  
			for(int k=0; k<21; k++)
			{
				T[j][k]=b[k];
				//cout<<T[j][k];
			}
			//cout<<endl; 
		}
		//cout<<endl; 
		//obrazki>>b;  
		for(int j=0; j<20; j++)
		{ 
			int jed1=0,  jed2=0; //jed1 - wiersze jed2 - kolumny  
			for(int k=0; k<20; k++)
			{
				if (T[j][k]=='1') jed1++;
				if (T[k][j]=='1') jed2++;
			}
			if ((jed1%2==0 && T[j][20]!='0') || (jed1%2==1 && T[j][20] !='1'))
			{
				bpoprawny = false;
				wiersz++;
				x=j+1;
				
			}
			if ((jed2%2==0 && T[20][j]!='0') || (jed2%2==1 && T[20][j] !='1')) 
			{
				bpoprawny = false;
				kolumna++;	
				y=j+1;
			}
			
			
		}
		if (bpoprawny == false)
		{
			if ((kolumna<=1) && (wiersz<=1) ) 
		{
		
			if (y>0) x=21; 
			cout<<"numer obrazka: "<<i+1<<" numer wiersza i kolumny wartosci blednej: "<<x<<" "<<y<<endl;
		}	
		}
	
		/*{
			if(kolumna+wiersz==2)
			{
				if (T[x][y]=='0') T[x][y]='1';
				else T[x][y]='0';
				cout<<"numer obrazka: "<<i+1<<" numer wiersz i kolumny wartosci blednej: "<<x<<" "<<y<<endl;
			}
			else if (kolumna+wiersz==1)
			{
			
				if (y==-1)
				{
					for(j=0; j<20; j++)
					{
						
					}
				}
			}
			
		}*/


	
	}

	return 0;
}


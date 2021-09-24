#include <iostream>
#include <iomanip> 
#include "Salesman.h"

#define N 5

using namespace std;

int main()
{
 setlocale(LC_ALL, "Russian");

 int d[N][N] = {    
	           {   INF,     8,      25,    INF,     4},   
               {   4,       INF,    19,    64,      80},  
               {   6,       12,     INF,   86,      53},  
               {   21,      54,     16,    INF,     12},  
               {   89,      70,     52,    17,      INF}  
               }; 
			   
int r[N];    
 
int s = salesman (            
                  N,          // [in]  количество городов 
                  (int*)d,    // [in]  массив [n*n] расстояний 
                  r           // [out] массив [n] маршрут 0 x x x x  
                 );

 cout << "-- Задача коммивояжера -- ";
 cout << endl << "-- количество  городов: " << N;
 cout << endl << "-- матрица расстояний : ";
 
 for(int i=0; i<N; i++)
 { 
    cout << endl;
    
	for(int j=0; j<N; j++)

       if (d[i][j] != INF) 
		   cout << setw(3) << d[i][j] << " ";

       else 
		   cout << setw(3) << "I" << " ";
 }
 
 cout << endl << "-- оптимальный маршрут: "; 
 
 for(int i=0; i<N; i++) 
	 cout << r[i] << "-->"; 
     cout << 0;
     cout << endl << "-- длина маршрута     : " << s;  
     cout << endl;
 
system("pause");
return 0;
}
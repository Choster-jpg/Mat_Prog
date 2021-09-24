#include "stdafx.h"

using namespace std;

void func_subset();
void func_combination();
void func_permutation();
void func_accomodation();
void boat5_6();

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int choice;
    bool stopFlag = true;

    while (stopFlag)
    {
        cout << "\n«адани€: \n"
            << "1. –азработать генератор подмножеств заданного множества\n"
            << "2. –азработать генератор сочетаний\n"
            << "3. –азработать генератор перестановок\n"
            << "4. –азработать генератор размещений\n"
            << "5. «адача об оптимальной загрузке судна с условием центровки\n"
    		<< "0. ¬ыход\n\n";

        cout << "ѕроверить задание є: "; cin >> choice; cout << endl << endl;
        switch (choice)
        {
            case 1: func_subset(); break;
            case 2: func_combination(); break;
            case 3: func_permutation(); break;
            case 4: func_accomodation(); break;
            case 5: boat5_6(); break;
            case 0: stopFlag = false; break;
            default:    break;
        }

    }

    system("pause");
    return 0;
}

void func_subset()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    cout << endl << " - √енератор множества всех подмножеств -";
    cout << endl << "»сходное множество: ";
    cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    cout << "}";
    cout << endl << "√енераци€ всех подмножеств  ";
    combi::subset s1(sizeof(AA) / 2);         // создание генератора   
    int  n = s1.getfirst();                // первое (пустое) подмножество    
    while (n >= 0)                          // пока есть подмножества 
    {
        cout << endl << "{ ";
        for (int i = 0; i < n; i++)
            cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        cout << "}";
        n = s1.getnext();                   // cледующее подмножество 
    };
    cout << endl << "всего: " << s1.count() << endl;
}
void func_combination()
{
    char  AA[][2] = { "A", "B", "C", "D", "E" };
    cout << endl << " --- √енератор сочетаний ---";
    cout << endl << "»сходное множество: ";
    cout << "{ ";

    for (int i = 0; i < sizeof(AA) / 2; i++)
        cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");

    cout << "}";
    cout << endl << "√енераци€ сочетаний ";
    combi::xcombination xc(sizeof(AA) / 2, 3);
    cout << "из " << xc.n << " по " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {
        cout << endl << xc.nc << ": { ";

        for (int i = 0; i < n; i++)
            cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

        cout << "}";
        n = xc.getnext();
    };
    cout << endl << "всего: " << xc.count() << endl;

}
void func_permutation()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    cout << endl << " --- √енератор перестановок ---";
    cout << endl << "»сходное множество: ";
    cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    cout << "}";
    cout << endl << "√енераци€ перестановок ";
    combi::permutation p(sizeof(AA) / 2);
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        cout << endl << setw(4) << p.np << ": { ";

        for (int i = 0; i < p.n; i++)

            cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

        cout << "}";

        n = p.getnext();
    };
    cout << endl << "всего: " << p.count() << endl;

}
void func_accomodation()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    cout << endl << " --- √енератор размещений ---";
    cout << endl << "»сходное множество: ";
    cout << "{ ";
    for (int i = 0; i < N; i++)

        cout << AA[i] << ((i < N - 1) ? ", " : " ");
    cout << "}";
    cout << endl << "√енераци€ размещений  из  " << N << " по " << M;
    combi::accomodation s(N, M);
    int  n = s.getfirst();
    while (n >= 0)
    {

        cout << endl << setw(2) << s.na << ": { ";

        for (int i = 0; i < 3; i++)

            cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");

        cout << "}";

        n = s.getnext();
    };
    cout << endl << "всего: " << s.count() << endl;

}

void boat5_6()
{
    int conteinersWeight[conteinersCount]{}; // вес
    int conteinerCost[conteinersCount]{};    // доход
	
    int*   minPlaceWeight;      // минимальный  вес 
    int*   maxPlaceWeight;      // максимальный вес
    short* choosedConteiners;   //выбранные контейнеры


    for (int i = 4; i<=8; ++i)
    {
        clock_t t_begin, t_end;
        minPlaceWeight = new int[i];
        maxPlaceWeight = new int[i];
        choosedConteiners = new short[i]{};
        for (int j = 0; j < i; ++j)
        {
            minPlaceWeight[j] = random(50, 120);
            maxPlaceWeight[j] = random(150, 850);
        }
        for (int j = 0; j < 8; ++j)
        {
	        conteinersWeight[j] = random(100, 200);
	        conteinerCost[j] = random(10, 100);
        }
    	
        t_begin = clock();
        int cc = boat_с(
            i,                   // [in]  количество мест дл€ контейнеров
            minPlaceWeight,   // [in]  максимальный вес контейнера на каждом  месте 
            maxPlaceWeight,   // [in]  минимальный вес контейнера на каждом  месте  
            conteinersCount,    // [in]  всего контейнеров  
            conteinersWeight,   // [in]  вес каждого контейнера  
            conteinerCost,      // [in]  доход от перевозки каждого контейнера   
            choosedConteiners     // [out] номера  выбранных контейнеров  
        );
        t_end = clock();
    	
        cout << endl << "- «адача о размещении контейнеров на судне -";
        cout << endl << "- общее количество контейнеров   : " << conteinersCount;
        cout << endl << "- количество мест дл€ контейнеров  : " << i;
        cout << endl << "- минимальный  вес контейнера  : ";
    	
        for (int j = 0; j < i; j++) 
            cout << setw(3) << minPlaceWeight[j] << " ";
    	
        cout << endl << "- максимальный вес контейнера  : ";
        for (int j = 0; j < i; j++) 
            cout << setw(3) << maxPlaceWeight[j] << " ";
    	
        cout << endl << "- вес контейнеров      : ";
        for (int j = 0; j < 8; j++) 
            cout << setw(3) << conteinersWeight[j] << " ";
    	
        cout << endl << "- доход от перевозки     : ";
        for (int j = 0; j < 8; j++) 
    		cout << setw(3) << conteinerCost[j] << " ";
    	
        cout << endl << "- выбраны контейнеры (0,1,...,m-1) : ";
        for (int j = 0; j < i; j++)
            cout << choosedConteiners[j] << " ";
    	
        cout << endl << "- доход от перевозки     : " << cc;
        cout << endl << "- затраченное врем€ на просчет: " << ((double)(t_end - t_begin)) / ((double)CLOCKS_PER_SEC) << " сек.";
        cout << endl << endl;

        delete[] minPlaceWeight;
        delete[] maxPlaceWeight;
        delete[] choosedConteiners;
    }
}
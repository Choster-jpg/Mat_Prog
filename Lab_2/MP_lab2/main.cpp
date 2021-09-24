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
        cout << "\n�������: \n"
            << "1. ����������� ��������� ����������� ��������� ���������\n"
            << "2. ����������� ��������� ���������\n"
            << "3. ����������� ��������� ������������\n"
            << "4. ����������� ��������� ����������\n"
            << "5. ������ �� ����������� �������� ����� � �������� ���������\n"
    		<< "0. �����\n\n";

        cout << "��������� ������� �: "; cin >> choice; cout << endl << endl;
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
    cout << endl << " - ��������� ��������� ���� ����������� -";
    cout << endl << "�������� ���������: ";
    cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    cout << "}";
    cout << endl << "��������� ���� �����������  ";
    combi::subset s1(sizeof(AA) / 2);         // �������� ����������   
    int  n = s1.getfirst();                // ������ (������) ������������    
    while (n >= 0)                          // ���� ���� ������������ 
    {
        cout << endl << "{ ";
        for (int i = 0; i < n; i++)
            cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        cout << "}";
        n = s1.getnext();                   // c�������� ������������ 
    };
    cout << endl << "�����: " << s1.count() << endl;
}
void func_combination()
{
    char  AA[][2] = { "A", "B", "C", "D", "E" };
    cout << endl << " --- ��������� ��������� ---";
    cout << endl << "�������� ���������: ";
    cout << "{ ";

    for (int i = 0; i < sizeof(AA) / 2; i++)
        cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");

    cout << "}";
    cout << endl << "��������� ��������� ";
    combi::xcombination xc(sizeof(AA) / 2, 3);
    cout << "�� " << xc.n << " �� " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {
        cout << endl << xc.nc << ": { ";

        for (int i = 0; i < n; i++)
            cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

        cout << "}";
        n = xc.getnext();
    };
    cout << endl << "�����: " << xc.count() << endl;

}
void func_permutation()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    cout << endl << " --- ��������� ������������ ---";
    cout << endl << "�������� ���������: ";
    cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    cout << "}";
    cout << endl << "��������� ������������ ";
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
    cout << endl << "�����: " << p.count() << endl;

}
void func_accomodation()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    cout << endl << " --- ��������� ���������� ---";
    cout << endl << "�������� ���������: ";
    cout << "{ ";
    for (int i = 0; i < N; i++)

        cout << AA[i] << ((i < N - 1) ? ", " : " ");
    cout << "}";
    cout << endl << "��������� ����������  ��  " << N << " �� " << M;
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
    cout << endl << "�����: " << s.count() << endl;

}

void boat5_6()
{
    int conteinersWeight[conteinersCount]{}; // ���
    int conteinerCost[conteinersCount]{};    // �����
	
    int*   minPlaceWeight;      // �����������  ��� 
    int*   maxPlaceWeight;      // ������������ ���
    short* choosedConteiners;   //��������� ����������


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
        int cc = boat_�(
            i,                   // [in]  ���������� ���� ��� �����������
            minPlaceWeight,   // [in]  ������������ ��� ���������� �� ������  ����� 
            maxPlaceWeight,   // [in]  ����������� ��� ���������� �� ������  �����  
            conteinersCount,    // [in]  ����� �����������  
            conteinersWeight,   // [in]  ��� ������� ����������  
            conteinerCost,      // [in]  ����� �� ��������� ������� ����������   
            choosedConteiners     // [out] ������  ��������� �����������  
        );
        t_end = clock();
    	
        cout << endl << "- ������ � ���������� ����������� �� ����� -";
        cout << endl << "- ����� ���������� �����������   : " << conteinersCount;
        cout << endl << "- ���������� ���� ��� �����������  : " << i;
        cout << endl << "- �����������  ��� ����������  : ";
    	
        for (int j = 0; j < i; j++) 
            cout << setw(3) << minPlaceWeight[j] << " ";
    	
        cout << endl << "- ������������ ��� ����������  : ";
        for (int j = 0; j < i; j++) 
            cout << setw(3) << maxPlaceWeight[j] << " ";
    	
        cout << endl << "- ��� �����������      : ";
        for (int j = 0; j < 8; j++) 
            cout << setw(3) << conteinersWeight[j] << " ";
    	
        cout << endl << "- ����� �� ���������     : ";
        for (int j = 0; j < 8; j++) 
    		cout << setw(3) << conteinerCost[j] << " ";
    	
        cout << endl << "- ������� ���������� (0,1,...,m-1) : ";
        for (int j = 0; j < i; j++)
            cout << choosedConteiners[j] << " ";
    	
        cout << endl << "- ����� �� ���������     : " << cc;
        cout << endl << "- ����������� ����� �� �������: " << ((double)(t_end - t_begin)) / ((double)CLOCKS_PER_SEC) << " ���.";
        cout << endl << endl;

        delete[] minPlaceWeight;
        delete[] maxPlaceWeight;
        delete[] choosedConteiners;
    }
}
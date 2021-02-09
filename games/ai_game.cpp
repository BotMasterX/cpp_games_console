#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int scor = 0;
char mat[21][21];
int mers[21][21];
int linie[4] = {1,0,-1,0};
int coloana[4] = {0,1,0,-1};
int poz_i, poz_j;
int poz2_i, poz2_j;
int poz3_i, poz3_j;
int poz4_i, poz4_j;
void afisare()
{
    for (int i = 0; i < 22; ++i)
        cout << '-';
    cout << '\n';
    for (int i = 0; i < 20; ++i)
    {
        cout << '|';
        for (int j = 0; j < 20; ++j)
            cout << mat[i][j];
        cout << '|';
        cout << '\n';
    }
    for (int i = 0; i < 22; ++i)
        cout << '-';
}

void initializare()
{
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            mat[i][j] = ' ';
    mat[poz_i][poz_j] = 'O';
    mat[poz2_i][poz2_j] = 'X';
    mat[poz3_i][poz3_j] = 'X';
    mat[poz4_i][poz4_j] = 'X';
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            mers[i][j] = 0;
}

int lee(int p_i,int p_j)
{
    queue <pair <int, int> > coada;
    coada.push({p_i,p_j});
    mers[p_i][p_j] = 1;
    while(!coada.empty())
    {
        int l = coada.front().first;
        int c = coada.front().second;
        coada.pop();
        for (int i = 0; i < 4; ++i)
        {
            int new_i = l + linie[i];
            int new_j = c + coloana[i];
            if(!(new_i > 19 || new_i < 0 || new_j < 0 || new_j > 19 || mers[new_i][new_j] != 0)){
                coada.push({new_i,new_j});
                mers[new_i][new_j] = 1 + mers[l][c];
            }
        }
    }
    int pasi = mers[poz_i][poz_j];
    for (int i = 0; i < 20; ++i)\
        for (int j = 0; j < 20; ++j)
            mers[i][j] = 0;

    return pasi;


}


int main()
{
    poz_i = 0;
    poz_j = 0;
    poz2_i = 19;
    poz2_j = 19;
     poz3_i = 0;
    poz3_j = 19;
     poz4_i = 19;
    poz4_j = 0;

    initializare();
    afisare();
    while(true)
    {
        char c;
        c = getch();
        if(c == 'w')
            poz_i = poz_i - 1;
        else if(c == 's')
            poz_i = poz_i + 1;
        else if(c == 'a')
            poz_j = poz_j - 1;
        else
            poz_j = poz_j + 1;

        if(poz_j > 19)
            poz_j = 0;
        else if(poz_j < 0)
            poz_j = 19;
        else if(poz_i > 19)
            poz_i = 0;
        else if(poz_i < 0)
            poz_i = 19;
        int minn = 123123;
        int perf_i,perf_j;
        int perf2_i,perf2_j;
        int perf3_i,perf3_j;
        for (int i = 0; i < 4; ++i)
        {

            int c = poz2_j + coloana[i];
            int l = poz2_i + linie[i];
            if(lee(l,c) < minn)
            {
                perf_i = l;
                perf_j = c;
                minn = lee(l,c);
            }
        }
        minn = 123123;
        for (int i = 0; i < 4; ++i)
        {

            int c = poz3_j + coloana[i];
            int l = poz3_i + linie[i];
            if(lee(l,c) < minn)
            {
                perf2_i = l;
                perf2_j = c;
                minn = lee(l,c);
            }
        }
        minn = 123123;
        for (int i = 0; i < 4; ++i)
        {

            int c = poz4_j + coloana[i];
            int l = poz4_i + linie[i];
            if(lee(l,c) < minn)
            {
                perf3_i = l;
                perf3_j = c;
                minn = lee(l,c);
            }
        }
        poz2_i = perf_i;
        poz2_j = perf_j;
         poz3_i = perf2_i;
        poz3_j = perf2_j;
         poz4_i = perf3_i;
        poz4_j = perf3_j;
        initializare();
        system("cls");
        afisare();
        if((poz_i == poz2_i && poz_j == poz2_j) || (poz_i == poz3_i && poz_j == poz3_j) || (poz_i == poz4_i && poz_j == poz4_j))
            break;
        scor++;
    }
    system("cls");
    cout << "ai murit";
    cout << '\n';
    cout << "scorul tau este: " << scor;
}

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

char mat[100][100];
int lim_i = 30, lim_j = 98;
bool dead = false;
int cap_i,cap_j;
int food_i,food_j;
int scor = 0;
vector <pair <int,int> > coada;


void erase()
{
    for (int i = 1; i <= lim_i; ++i)
        for (int j = 1; j <= lim_j; ++j)
        {
            bool ok = false;
            for (int k = 0; k < coada.size(); ++k)
                if(coada[k].first == i && coada[k].second == j)
                {
                    mat[i][j] = 'o';
                    ok = true;
                    break;
                }
            if(food_i == i && food_j == j)
                mat[i][j] = '$';
            else if(!ok)
                mat[i][j] = ' ';
        }
}

bool used()
{
    for (int i = 0; i < coada.size(); ++i)
        if(coada[i].first == food_i && coada[i].second == food_j)
            return false;
    return true;
}

void random_food()
{
    food_i = rand() % lim_i + 1;
    food_j = rand() % lim_j + 1;
    while(!used())
    {
        food_i = rand() % lim_i + 1;
        food_j = rand() % lim_j + 1;
    }
    mat[food_i][food_j] = '$';
}

void random_position()
{
    cap_i = rand() % lim_i + 1;
    cap_j = rand() % lim_j + 1;
    coada.push_back({cap_i,cap_j});
    mat[cap_i][cap_j] = 'o';

}
void init()
{
    for (int i = 1; i <= lim_i; ++i)
        for (int j = 1; j <= lim_j; ++j)
            mat[i][j] = ' ';
}


bool moving(char c)
{

    vector <pair<int,int> > coada2;
    for (int i = 0; i < coada.size(); ++i)
    {
        coada2.push_back({coada[i].first,coada[i].second});
    }

    if(c == 'w')
    {
        cap_i--;
    }
    else if(c == 'a')
    {
        cap_j--;
    }
    else if(c == 's')
    {
        cap_i++;
    }
    else if(c == 'd')
    {
        cap_j++;
    }
    coada[0].first = cap_i;
    coada[0].second = cap_j;
    for (int i = 1; i < coada.size(); ++i)
    {
        coada[i].first = coada2[i - 1].first;
        coada[i].second = coada2[i - 1].second;
    }
    if(cap_j < 1 || cap_j > lim_j || cap_i < 1 || cap_i > lim_i)
        return false;
    return true;
}


// DESIGN

void design()
{
    erase();
    for (int i = 1; i <= 49; ++i)
        cout << " ";
    for (int i = 1; i <= 100; ++i)
        cout << "-";

    int linie = 1;
    cout << "\n";
    while(linie <= lim_i)
    {
        int len = 48;
        if(linie == 1 || linie == 7 || linie == 13)
            cout << "s";
        else if(linie == 2 || linie == 8 || linie == 14)
            cout << "n";
        else if(linie == 3 || linie == 9 || linie == 15)
            cout << "a";
        else if(linie == 4 || linie == 10 || linie == 16)
            cout << "k";
        else if(linie == 5 || linie == 11 || linie == 17)
            cout << "e";

        else if(linie == 19)
        {
            string s = "Folositi-va de W,A,S,D pentru a merge pe tabla";
            cout << s;
            len = len - s.size() + 1;

        }
        else if(linie == 20)
        {
            cout << "Scor: " << scor;
            int cifre = 0;
            int scorr = scor;
            if(scor == 0)
                cifre++;
            while(scorr)
            {
                cifre++;
                scorr/=10;
            }
            len = len - (cifre + 6) + 1;
        }
        else
            len++;

        for (int i = 1; i <= len; ++i)
            cout << " ";
        cout << "|";
        for (int i = 1; i <= lim_j; ++i)
            cout << mat[linie][i];
        cout << "|";
        cout << "\n";
        linie++;
    }
    for (int i = 1; i <= 49; ++i)
    {
        cout << " ";
    }
    for (int i = 1; i <= 100; ++i)
        cout << "-";
    cout << "\n";
}
//

int main()
{
    init();
    random_position();
    random_food();
    char mem = 'w';
    char c;
    int time = 70;

    while(true)
    {
        system("cls");
        design();

        if(kbhit())
        {
            c = _getch();
            mem = c;
            c = NULL;
        }

        if(moving(mem))
        {
            if(cap_i == food_i && cap_j == food_j)
            {
                if(mem == 'a')
                {
                    coada.push_back({cap_i,cap_j+1});
                }
                else if(mem == 'w')
                {
                    coada.push_back({cap_i + 1,cap_j});
                }
                else if(mem == 's')
                {
                    coada.push_back({cap_i - 1,cap_j});
                }
                else if(mem =- 'd')
                {
                    coada.push_back({cap_i,cap_j-1});
                }
                mat[food_i][food_j] = ' ';
                random_food();
                scor++;
                time /= 2;
            }
        }
        else
        {
            system("cls");
            cout << "ai murit";
            return 0;
        }
        Sleep(time);
    }
}

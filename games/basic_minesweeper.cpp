#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin ("date.in");
int mat[10][10];
bool aux_mat[10][10];
int n,m,mines_count = 0;

void all_is_good()
{
    for (int i = 1; i <= n ;i++){
        for (int j = 1 ;j <= m ;j++)
        {
            if(mat[i][j] == -1)
                cout << "*" << " ";
            else
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool valid()
{
    for (int i = 1 ;i <= n ;i++)
        for (int j = 1 ;j <= m ;j++)
            if(mat[i][j] != -1 && aux_mat[i][j] == false)
                return false;
    return true;
}

void restart()
{
    for (int i = 1 ;i <= n ;i++)
        for (int j = 1 ;j <= m ;j++)
            aux_mat[i][j] = false;
}

void print()
{
    for (int i = 1 ;i <= n ;i++){
        for (int j = 1 ;j <= m ;j++)
        {
            if(aux_mat[i][j] == true)
            {
                if(mat[i][j] == -1){
                    cout << "*" << " ";
                }
                else
                    cout << mat[i][j] << " ";
            }
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

bool mines(int i ,int j)
{
    if(mat[i][j] == -1)
        return true;
    return false;
}

void minesweeper(int i ,int j ,int count)
{
    aux_mat[i][j] = true;
    print();
    if(mines(i ,j) == true)
        return;

    count++;
    if(aux_mat[i][j] == true && mines(i ,j) == false && count == n * m - mines_count)
        return;

    int x,y;
    cin >> x >> y;
    minesweeper(x ,y ,count);
}

void read()
{
    fin >> n >> m;
    for (int i = 1 ;i <= n ;i++)
        for (int j = 1 ;j <= m ;j++)
        {
            char c;
            fin >> c;
            if(c == '*'){
                mat[i][j] = -1;
                mines_count++;
            }
            else{
                int x = int(c) - 48;
                mat[i][j] = x;
            }
        }
}

int main()
{
    read();
    int ok = 1;

    while(ok)
    {
        int coord_i ,coord_j;
        cin >> coord_i >> coord_j;
        if(mat[coord_i][coord_j] != -1){
            minesweeper(coord_i ,coord_j ,0);
            if(valid())
                ok = 0;
            else{
                cout << endl << endl << "RESTART ALL" << endl;
                restart();
            }
        }
    }
    cout << endl << endl << "NICE" << endl << endl;
    all_is_good();
}

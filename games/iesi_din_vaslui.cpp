#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

char mat[10][10];
int line[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};
int lee_mat[12][22];
int total;
int level = 1;

bool obst[10][10];
queue <pair <int,int> > q;


void erase()
{
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      if(mat[i][j] != 'O' && mat[i][j] != 'V')
        mat[i][j] = ' ';
}
int lee(int i,int j, int n, int m)
{
  q.push(make_pair(i,j));
  lee_mat[i][j] = 1;
  while(!q.empty())
  {
    int line1 = q.front().first;
    int col1 = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++)
    {
        int i2 = line1 + line[k];
        int j2 = col1 + col[k];
        if(i2 >= 1 && i2 <= 10 && j2 >= 1 && j2 <= 10 && lee_mat[i2][j2] == 0)
        {
          lee_mat[i2][j2] = lee_mat[line1][col1] + 1;
          q.push(make_pair(i2,j2));
        }
    }
  }
  return lee_mat[n][m];
}

void put(int i, int j, int m, int n)
{
  mat[i][j] = 'O';
  mat[m][n] = 'X';
}

void init()
{
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      mat[i][j] = ' ';

  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      lee_mat[i][j] = 0;

  for (int i = 0; i < 12; i++)
    lee_mat[i][0] = lee_mat[i][11] = lee_mat[0][i] = lee_mat[11][i] = -1;

  while(!q.empty())
    q.pop();

  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
      obst[i][j] = false;
}
void draw()
{
cout << "LEVEL " << level << endl;
  cout << endl;
  int lin = 1;
  int col = 1;
  while(lin <= 10)
  {
    for (int i = 1; i <= 43; i++)
      cout << "-";
    cout << endl;
    for(int i = 1; i <= 10; i++)
      cout << " | " << mat[lin][col++];
    cout << " | " << endl;
    lin++;
    col = 1;
  }
  for (int i = 1; i <= 43; i++)
    cout << "-";
  cout << endl;

}

int main()
{
    system("Color 3");
    bool is_answer = false;
    string answer;
    cout << "DO YOU WANT OBSTACLES? WRITE YES!!!" << endl << endl;
    cin >> answer;
    for (int i = 0; i < answer.size(); i++)
        if(isalpha(answer[i]))
            if(islower(answer[i]))
                answer[i] = char(answer[i] - 32);
    if(answer == "YES")
      is_answer = true;
    int nr_obst = 0;
    if(is_answer == true)
      while(1)
      {
        cout << endl << "HOW MANY?" << endl;
        cin >> nr_obst;
        if(nr_obst > 50)
          cout << endl << "TO MANY..." << endl;
        else
          break;
      }
    srand(time(NULL));
    do
    {
        cout << "PRESS ENTER!!!" << endl;
    }while(cin.get() != '\n');

    system("cls");
    int generating_lin;
    int generating_col;
    int destination_i;
    int destination_j;

    while(level <= 100){

      while(1)
      {
        srand(time(NULL));

        while(1){
          generating_lin = rand() % 10 + 1;
          generating_col = rand() % 10 + 1;
          destination_i = rand() % 10 + 1;
          destination_j = rand() % 10 + 1;
          if(generating_lin == destination_i && generating_col == destination_j)
            continue;
          else
            break;
        }
        int n = 0;
        init();

          while(n < nr_obst){
              int obst_i, obst_j;
              while(1)
              {
                obst_i = rand() % 10 + 1;
                obst_j = rand() % 10 + 1;
                if(obst[obst_i][obst_j] == false && destination_i != obst_i && destination_j != obst_j && generating_lin != obst_i && generating_col != obst_j)
                {
                  mat[obst_i][obst_j] = 'V';
                  obst[obst_i][obst_j] = true;
                  lee_mat[obst_i][obst_j] = -1;
                  break;
                }
              }
              n++;
          }

        put(generating_lin,generating_col, destination_i, destination_j);
        total = lee(generating_lin,generating_col,destination_i,destination_j) - 1;
        if(total > 0)
          break;
      }

      draw();
      int moves = 0;
      int i_init = destination_i;
      int j_init = destination_j;
      bool dead = true;

      while(1 && moves < total)
      {
          char c;
          while(1)
          {
            cout << endl << "up = w , down = s , left = a , right = d (FARA CAPS) " << endl;
            c = getche();

            if(c == 'w' && i_init != 1 && mat[i_init - 1][j_init] == 'V'){
              system("cls");
              cout << "RIP";
              return 0;
            }
            else if(c == 's' && i_init != 10 && mat[i_init + 1][j_init] == 'V'){
              system("cls");
              cout << "RIP";
              return 0;
            }
            else if(c == 'a' && j_init != 1 && mat[i_init][j_init - 1] == 'V'){
              system("cls");
              cout << "RIP";
              return 0;
            }
            else if(c == 'd' && j_init != 10 && mat[i_init][j_init + 1] == 'V'){
              system("cls");
              cout << "RIP";
              return 0;
            }


            if(c == 'w' && i_init != 1){
              erase();
              mat[i_init - 1][j_init] = 'X';
              i_init--;
              break;
            }
            else if(c == 's' && i_init != 10){
              erase();
              mat[i_init + 1][j_init] = 'X';
              i_init++;
              break;
            }
            else if(c == 'a' && j_init != 1){
              erase();
              mat[i_init][j_init - 1] = 'X';
              j_init--;
              break;
            }
            else if(c == 'd' && j_init != 10){
              erase();
              mat[i_init][j_init + 1] = 'X';
              j_init++;
              break;
            }
            else
              cout << endl << "INVALIDE ACCES!" << endl;
          }
          if(i_init == generating_lin && j_init == generating_col){
            dead = false;
            break;
          }
          system("cls");

          draw();
          moves++;
      }
      if(dead)
      {
        system("cls");
        cout << "YOU LOSE";
        cout << endl;
        cout << "MORE ATENTION!!!" << endl;
        do
        {
            cout << "PRESS ENTER!!" << endl;
        }while(cin.get() != '\n');
        return 0;
      }
      level++;
      system("cls");
    }
      cout << endl << "GOOD JOB" << endl;
}

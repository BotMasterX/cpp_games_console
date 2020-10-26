// in lucru
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

char mat[10][20];
bool mat2[10][20] ={false};
int pos_i,pos_j;
bool dead = false;
int foods = 0;

bool take_food()
{
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 20; j++)
      if(mat[i][j] == '~')
        return false;
  return true;
}

bool defeat(int coordi, int coordj)
{
    if(coordi == 0 || coordi == 11 || coordj == 0 || coordj == 21 || mat2[coordi][coordj] == true)
        return true;
    return false;
}

void move_snake()
{
    char c;
    c = getche();
    if(c == 'w')
        if(defeat(pos_i - 1,pos_j) == true)
            dead = true;
        else
        {
            mat2[pos_i][pos_j] = false;
            mat[pos_i][pos_j] = ' ';
            pos_i--;
            mat2[pos_i][pos_j] = true;
            mat[pos_i][pos_j] = 'O';
        }
    else if(c == 'a')
        if(defeat(pos_i,pos_j - 1))
            dead = true;
        else
        {
            mat2[pos_i][pos_j] = false;
            mat[pos_i][pos_j] = ' ';
            pos_j--;
            mat2[pos_i][pos_j] = true;
            mat[pos_i][pos_j] = 'O';

        }
    else if(c == 's')
        if(defeat(pos_i + 1,pos_j))
            dead = true;
        else
        {
            mat2[pos_i][pos_j] = false;
            mat[pos_i][pos_j] = ' ';
            pos_i++;
            mat2[pos_i][pos_j] = true;
            mat[pos_i][pos_j] = 'O';

        }
    else if(c == 'd')
        if(defeat(pos_i,pos_j + 1))
            dead = true;
        else
        {
            mat2[pos_i][pos_j] = false;
            mat[pos_i][pos_j] = ' ';
            pos_j++;
            mat2[pos_i][pos_j] = true;
            mat[pos_i][pos_j] = 'O';
        }
}

void start()
{
  pos_i = rand() % 10 + 1;
  pos_j = rand() % 20 + 1;
  mat[pos_i][pos_j] = 'O';
  mat2[pos_i][pos_j] = true;
}

void init()
{
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 20; j++)
      mat[i][j] = ' ';
}

void draw()
{
  cout << "POINTS: " << foods;
  cout << endl;
  int col = 1;
  int lin = 1;
  while(lin <= 10)
  {
    cout << " ";
    if(lin == 1)
      for(int i = 1; i <= 43 * 2 - 3; i++)
        cout << "/";
        cout << endl;
    for (int i = 1; i <= 20; i++){
        if(i == 1)
            cout << " /| " << mat[lin][col++];
        else
            cout << " | " <<  mat[lin][col++];
    }
    cout << " |/" << endl;
    cout << " ";

    for (int i = 1; i <= 43 * 2 - 3; i++){
        if(i == 1 || i == 2)
            cout << "/";
        else if(i < 43 * 2 - 4)
            cout << "-";
        else
            cout << "/";
    }
    lin++;
    col = 1;
  }
    cout << endl << " ";
    for (int i = 1; i <= 43 * 2 - 3; i++)
        cout << "/";
    cout << endl;
}

int main()
{
    init();
    start();
    cout << "w - up, a - left, s - down, d - right" << endl;
    system("Color 3");
    do{
        cout << "PRESS ENTER!!!" << endl;
    }while(cin.get() != '\n');

    while(!dead)
    {
      int generating_i,generating_j;
      while(1)
      {
        generating_i = rand() % 10 + 1;
        generating_j = rand() % 20 + 1;
        if(mat2[generating_i][generating_j] == false)
        {
          mat[generating_i][generating_j] = '~';
          break;
        }
      }
      while(1)
      {
          system("cls");
          draw();
          move_snake();
          if(take_food() == true)
            break;
          if(dead == true)
          {
              system ("cls");
              cout << "YOU LOSE";
              return 0;
          }
      }
      foods++;
    }

}

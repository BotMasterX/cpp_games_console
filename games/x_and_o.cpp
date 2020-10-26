#include <bits/stdc++.h>
using namespace std;

char mat[9][9];
bool mat2[9][9];
char round_number;
bool round_player = true;
string name1;
string name2;

bool round_time(char c)
{
  if(round_number == c)
    return false;
  return true;
}

bool winner()
{
  bool ok = false;
  char character;
  for (int i = 1; i <= 3; i++)
  {
    char c = mat[i][1];
    int moves = 0;
    for (int j = 1; j <= 3; j++)
      if(mat[i][j] == c && mat[i][j] != ' ')
        moves++;

    if(moves == 3){
      ok = true;
    }
    moves = 0;
    if(i == 1)
    {
      moves = 0;
      for (int k = 1; k <= 3; k++)
        if(mat[k][k] == mat[i][1] && mat[k][k] != ' ')
          moves++;

      if(moves == 3){
        ok = true;
      }
      moves = 0;
    }

    if(i == 3)
    {
        if(mat[3][1] == mat[2][2] && mat[2][2] == mat[1][3] && mat[1][3] != ' '){
          ok = true;
        }
    }
  }

  for (int j = 1; j <= 3; j++)
  {
    char c = mat[1][j];
    int moves = 0;
    for (int i = 1; i <= 3; i++)
      if (mat[i][j] == c && mat[i][j] != ' ') {
        moves++;
      }
    if(moves == 3)
    {
      ok = true;
    }
  }


  if(ok)
    return true;
  return false;
}

bool interval(int i,int j)
{
  if(i <= 3 && i >= 1 && j >= 1 && j <= 3)
    return true;
  return false;
}

bool valid(int i,int j)
{
  if(mat2[i][j] == true)
    return false;
  else if(!interval(i,j))
    return false;
  return true;
}

void position(int i, int j)
{
  mat[i][j] = round_number;
  mat2[i][j] = true;
}

void init()
{
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      mat[i][j] = ' ';
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      mat2[i][j] = false;
}

void draw()
{
  int lin = 1;
  int col = 1;
  while(lin <= 3)
  {
    for (int i = 1; i <= 3; i++)
      cout << "-----";
    cout << endl;
    for (int i = 1; i <= 3; i++)
      cout << " | " << mat[lin][col++];
    cout << " | " << endl;
    lin++;
    col = 1;
  }
  for (int i = 1; i <= 3; i++)
    cout << "-----";
    cout << endl << endl << endl << endl;
}

int main()
{
  int pos = 0;
  init();
  bool win = false;
  system("Color 2");
  cout << "Player 1: ";
  getline(cin,name1);
  cout << endl;
  cout << "Player 2: ";
  getline(cin,name2);
  cout << endl;
  while(pos < 9)
  {
    system("cls");
    draw();
    int i,j;
    bool ok = false;
    while(1)
    {

      char c;
      cout << endl << "SELECT POSITION IN TABLE!!!" << endl;
      cin >> i >> j;
      cout << endl << "PUT X OR O: ";

      while(1)
      {
        cin >> c;
        if(c == 'X' || c == 'O')
          break;
        if(c == 'x' || c == 'o')
          cout << endl << "TRY CAPS PLS!" << endl;
        else
          cout << endl << "CAN YOU PUT X OR O?" << endl;
      }

      if(valid(i,j)){
        if(round_number == c)
          cout << endl <<  "ANOTHER ROUND!" << endl << endl;
        else
        {
          round_number = c;
          break;
        }
      }
      else if(!valid(i,j) && interval(i,j))
        cout << endl << "INVALIDE POSITION, TRY AGAIN!" << endl << endl;
      else if(!valid(i,j) && !interval(i,j))
        cout << endl << "INVALIDE POSITION, TRY AGAIN!" << endl << endl;
    }
    position(i,j);
    draw();

    pos++;
    if(winner())
    {
      win = true;
      system("cls");
      draw();
      cout << endl << endl;
      if(round_player)
        cout << endl << endl << "NICE!" << endl << "WINNER IS " << name1 << "!" << endl;
      else
        cout << endl << endl << "NICE!" << endl << "WINNER IS " << name2 << "!" << endl;

      break;
    }
    if(!win)
      system("cls");
    round_player = !round_player;
  }

  if(pos >= 9)
    cout << endl << endl << "UHH..." << endl << endl;
}

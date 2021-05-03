#include <iostream>
#include <stdlib.h>
using namespace std;

const char WIDTH = 20 , HEIGHT = 20;
unsigned char player = 5;
int posX = 1, posY = 1;
unsigned char action;

void playerAction();

struct enemies
{
    char symbol;
    bool active;
    int x;
    int y;
};

struct winroom
{
    char symbol;
    bool active;
    int x;
    int y;
};

unsigned char maze [HEIGHT][WIDTH] ={
{' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},  //0
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //1
{'#',' ','#',' ','#','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ','#'},  //2
{'#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#'},  //3
{'#','#','#','#','#','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ','#',' ','#'},  //4
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#',' ','#'},  //5
{'#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#'},  //6
{'#',' ','#','#','#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ',' ','#',' ','#'},  //7
{'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#'},  //8
{'#',' ','#','#','#','#','#','#','#',' ','#','#',' ','#','#',' ','#','#',' ','#'},  //9
{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#'},  //0
{'#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#'},  //1
{'#',' ','#',' ','#',' ',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#'},  //2
{'#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ','#'},  //3
{'#',' ','#',' ',' ',' ',' ','#','#',' ','#',' ',' ',' ','#','#',' ',' ',' ','#'},  //4
{'#',' ',' ','#','#','#',' ',' ','#',' ','#',' ','#',' ','#',' ',' ','#',' ','#'},  //5
{'#','#',' ',' ',' ',' ',' ','#','#',' ','#',' ','#',' ','#','#','#','#',' ','#'},  //6
{'#','#','#',' ','#','#','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},  //7
{'#',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#','#','#',' ','#','#',' ','#'},  //8
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},};//9
//0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   5   6   7   8   9

int main(){
    if (action == 'Q'|| 'q') {
        exit;
    }

    while (action != 'Q'|| 'q')
        {
        cout << "Control your player using WASD" << endl;
        cout << endl;

        maze [posX] [posY] = player;
        for(int y=0 ; y < HEIGHT; y++){
            cout << endl;
            for (int x=0 ; x < WIDTH ; x++){
                cout << maze[y][x];
            }
    //1st enemy
    enemies enemy1;
    enemy1.symbol = 'X';
    enemy1.active = true;
    enemy1.x = 3;
    enemy1.y = 6;
    maze[enemy1.y][enemy1.x] = enemy1.symbol;
    //2nd enemy
    enemies enemy2;
    enemy2.symbol = 'Y';
    enemy2.active = true;
    enemy2.x = 8;
    enemy2.y = 1;
    maze[enemy2.y][enemy2.x] = enemy2.symbol;
    //3rd enemy
    enemies enemy3;
    enemy3.symbol = 'Z';
    enemy3.active = true;
    enemy3.x = 17;
    enemy3.y = 6;
    maze[enemy3.y][enemy3.x] = enemy3.symbol;
        }
    //Win Room
    winroom Winner;
    Winner.symbol = 'W';
    Winner.active = true;
    Winner.x = 1;
    Winner.y = 19;
    maze[Winner.y][Winner.x] = Winner.symbol;


    playerAction();

    }
    return 0;
}

void playerAction (){
    cout << "\nAction";
    cin >> action;

    int prevposX=posX;
    int prevposY=posY;
    unsigned char space = {32};



    switch (action){
case 'a':
    ;
    if (maze [posX][posY-1] != '#'){
        posY--;
        cout << posX << ',' << posY << endl;
        maze [prevposX] [prevposY] = space;
    }
    system("cls");
    break;
case 'd':

    if (maze [posX][posY+1] != '#'){
        posY++;
    cout << posX << ',' << posY << endl;
    maze [prevposX] [prevposY] = space;
    }
    system("cls");
    break;
case 's':

    if(maze [posX+1][posY] != '#'){
        posX++;
    cout << posX << ',' << posY << endl;
    maze [prevposX] [prevposY] = space;
    }
    system("cls");
    break;
case 'w':

    if(maze [posX-1][posY] != '#'){
        posX--;
    cout << posX << ',' << posY << endl;
    maze [prevposX] [prevposY] = space;
    }
    system("cls");
    break;



default:
    cout << "Incorrect action!" << endl;
    break;

    }
}


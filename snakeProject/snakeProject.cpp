// snakeProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
using namespace std;


// INITIALIZING THE IMPORTANT COMPONENT
bool gameOver;
const int width = 30;
const int length = 25;
int x, y, fruitx, fruity, score;
vector<int> tailX;
vector<int> tailY;
int nTail;

enum eDirection
{
    STOP = 0,LEFT,RIGHT,UP,DOWN 
};
eDirection dir;


void setup() {
    gameOver = false;
    nTail = 0;
    dir = STOP;
    x = width / 2;
    y = length / 2;
    fruitx = rand() % width;  // rand function is used for taking random value.
    fruity = rand() % length;
    score = 0;
}
void draw() {
    system("cls"); //system() is used to give command to the system,and here we give "cls" command which is clear the screen.
    for (int i = 0; i < width+2;i++) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < length;i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == y && j == x) {
                cout << "O";
            }
            else {
                if (i ==fruity && j == fruitx)
                {
                    cout << "F";
                }
                else {
                
                    cout << " ";
                }
            }
            
            
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }
    cout << endl;
   
}

void input() {
    if (_kbhit()) { // _kbhit() is used to take input form the keyboard.
        switch (_getch()) { //_getch()
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void logic() {
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default: break;
    }
    if (x > width || x<0 || y>length || y < 0) {
        gameOver=true;
    }
    if (x == fruitx && y == fruity) {
        score +=10;
        fruitx = rand() % width;  // rand function is used for taking random value.
        fruity = rand() % length;
        nTail++;
    }
}

int main()
{
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        cout << "Score : "<<score;
    }
    return(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

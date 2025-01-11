#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};
const int width = 20;
const int height = 20;
int x,y,fruitX,fruitY;
int nTail;
int tailX[100],tailY[100];
int score;
eDirection dir;
void set_up(){
    gameOver = false;
    dir = STOP;
    x= width/2;
    y = height/2;
    fruitX = 1+(rand()%18);
    fruitY = 1+(rand()%18);
    score =0;

}
void draw(){
    system("cls");
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0 || j==width-1) cout<<"#";
            if(x==j && y==i) cout<<"O";
            else if(fruitX == j && fruitY == i) cout<<"F";
            else{
                bool print = false;
                for(int k=0;k<nTail;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print) cout<<" ";

                }

            }
            cout<<endl;
        }
        // cout<<endl;
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"score: "<<score<<endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }

    }
}
//move Oooo => down
// oo =>    o
// O        o
//          O
//int a array  H1[1,2,3,4] => H2[H1,1,2,3] => it is nothing but moving the values forward
void logic(){
    // if(x==0 || x>width || y==0 || y==height) gameOver = true;
    if(x<0) x=width-1;
    else if(x>=width) x=0;
    if(y<0) y = height-1;
    else if(y>=height) y=0;

    int  prevX = tailX[0],prevY= tailY[0];//1
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;//H1

    for(int i=1;i<nTail;i++){
        prev2X = tailX[i];//2,3
        prev2Y = tailY[i]; 
        tailX[i]= prevX;//1,2
        tailY[i]= prevY;
        prevX = prev2X;//2
        prevY = prev2Y;
    }

    switch(dir){
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
    }
    for(int i=0;i<nTail;i++){
        if(tailX[i]==x && tailY[i]==y){
            gameOver = true;
        }
    }
    if(x==fruitX && y == fruitY){
        score++;
        nTail++;
        fruitX = 1+(rand()%18);
        fruitY = 1+(rand()%18);
    }
}
int main(){
    set_up();
    while(!gameOver){
        draw();
        input();
        logic();
    }
    return 0;
}
#include "stdio.h"
#include "ctype.h" //for is_digit

#define NOBODY '|'

int playing = 1;
char* version = "1.0";
char desc[] = {
'0','1','2',
'3','4','5',
'6','7','8'
};

void print_desc(){
    for(int i=1;i<=9;i++){
        printf("%c ",desc[i-1]);
        if(i%3==0) printf("\n");
    }
}

void read_input(){
    char c;
    printf("Input your symbol:\n");
    scanf(" %c",&c);
    if(c=='q'){
        playing=0;
        return;
    }
    if(c!='x' && c!='o'){
        printf("Invalid symbol: %c\n",c);
        printf("Symbol should be x or o\n");
        return;
    }
    int position;
    printf("Input symbol's position:\n");
    scanf(" %d",&position);
    if (!(position>=0 && position<=8)){
        printf("Invalid position: %d\n",position);
        printf("Position should be number from 0 to 8\n");
        return;
    }
    desc[position]=c;
    print_desc();
}

void check_win(){
    //Check lines:
    char winner = NOBODY;
    for(int i=0;i<=6;i+=3){
        if (!isdigit(desc[i]) && desc[i]==desc[i+1] && desc[i+1]==desc[i+2]){
            winner=desc[i];
            break;
        }
    }
    //Check columns
    //0,3,6 1,4,7 2,5,8
    if (desc[0]==desc[3] && desc[3]==desc[6]){
        winner=desc[0];
    }
    if (desc[1]==desc[4] && desc[4]==desc[7]){
        winner=desc[1];
    }
    if (desc[2]==desc[5] && desc[5]==desc[8]){
        winner=desc[2];
    }
    //Check diagonals
    //0,4,8 2,4,6
    if (desc[0]==desc[4] && desc[4]==desc[8]){
        winner=desc[0];
    }
    if (desc[2]==desc[4] && desc[4]==desc[6]){
        winner=desc[2];
    }
    playing=(int)(winner==NOBODY);
    if(!playing){
        printf("The winner is %c\n",winner);
    }

}

void check_draw(){
    int draw = 1;
    for(int i=0;i<9;i++){
        if (desc[i]!='x' && desc[i]!='o'){
            //not draw
            draw=0;
            break; 
        }
    }
    if(draw){
        printf("Draw\n");
        playing=0;
    }
}

void check_result(){
    check_win();
    check_draw();
}

void play(){
    print_desc();
    while(playing){
        read_input();
        check_result();
    }
    printf("Goodbye\n");
    printf("Thank you for your playing!");
}

void instruction(){
    printf("This is classic Tic Tack Toe game\n");
    printf("You can use symbols 'x' and 'o'\n");
    printf("The position is a number between 0 and 8\n");
}

void about(){
    printf("Author: Marat Nagayev\n");
    printf("Version: %s\n",version);
    printf("License: GPL 2.0\n");
}

int main(){
    printf("Welcome to Tic Tack Toe!\n");
    printf("Menu\n");
    const char *menu[3] = {"Play","Instruction","About"};
    for (int i=0;i<3;i++) printf("%d - %s\n",i+1,menu[i]);
    int choise;
    scanf(" %d",&choise);
    if (choise==1){
        play();
    } else if (choise==2) {
        instruction();
    } else if (choise==3) {
        about();
    } else {
        printf("Invalid choise, choose option from menu\n");
    }
}
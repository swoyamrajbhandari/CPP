#include <iostream>
#include <cmath>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(){

    char spaces[9]  = {' ',' ',' ',' ',' ',' ',' ',' ',' ',};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running){
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for Playing!!\n";

    return 0;

}

void drawBoard(char *spaces){
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |      " << '\n';

}
void playerMove(char *spaces, char player){
    int number;
    do {
        std::cout << "Enter a marker (1 - 9): ";
        std::cin >> number;
        std::cin.clear();  //clears error flag
        //std::cin.ignore();   //discards unwanted characters from input buffer(i.e wrong data type in buffer)
        fflush(stdin);

        number --;    //(to account for array(0 - 8)
        if (spaces[number] == ' '){
            spaces[number] = player;
            break;

        }


    } while (number < 0 || number > 8 || (spaces[number] != ' ') );  //if we dont put the last condition then 
                                                                     //if number = any (0 - 8) and it's corresponding
                                                                     //space[number] has already been filled then
                                                                     //since number is between (0 - 8),it doesnt loop
                                                                     //only loops when number < 0 or number > 8

}

void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while (true){
        number = rand() % 9;
        if (spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }


}
bool checkWinner(char *spaces, char player, char computer){

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n"; 
    }
    else {
        return false;
    }
    return true;
}

bool checkTie(char *spaces){

    for (int i = 0; i < 9; i++){
        if (spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;

}
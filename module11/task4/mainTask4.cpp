#include <iostream>
#include <vector>
#include <string>



bool isAllowed (const char symbol)
{
    return (symbol == 'X' || symbol == 'O' || symbol == '.');
}

int symbolsQuanity ( const char gameField[][4], const char sign)             //Checks how many crosses or naught on the field
{
    int count = 0;
    for ( int i = 1; i <= 4; i ++ ){
        for (int j = 1; j <= 4; j++){
            if (gameField[i][j] == sign) count ++;
        }
    }
    return count;
}

int horizontalCheck (char const gameField [][4],char const winner)          //Checking the lower upper and middle lines   
{
    int count = 0,howMuchWonCount = 0;                      
    for  (int i = 1; i <= 4; i++){                   
        for ( int j = 1; j <= 4; j ++ ){
            if (gameField[i][j] == winner) count++;
        }

        (count == 3) ? howMuchWonCount++ : 0;
        count = 0;
    }
    return howMuchWonCount;
}

int verticalCheck (char const gameField [][4],char const winner)            //checking the right, left and middle sides    
{
    int count = 0,howMuchWonCount = 0;                        
    for  (int i = 1; i <= 4; i++){                          
        for ( int j = 1; j <= 4; j ++ ){
            if (gameField[j][i] == winner) count++;
        }

        (count == 3) ? howMuchWonCount++ : 0;
        count = 0;
    }
    return howMuchWonCount;
}

int diagonalesCheck (char const gameField [][4],char const winner)          //checking diagonals               
{
    int count = 0,howMuchWonCount = 0;
    for  (int i = 1; i <= 4; i++){                        //checking first diagonal         
        if (gameField[i][i] == winner) count++;
    }   
        (count == 3) ? howMuchWonCount++ : 0;
        count = 0; 

    int k = 3;
    for  (int i = 1; i <= 4; i++){                        //checking second diagonal          
        if (gameField[i][k] == winner) count++;
        k--;
    }
      
        (count == 3) ? howMuchWonCount++ : 0;
        count = 0;

    return howMuchWonCount;
}

bool winnerCheck (char const gameField [][4], char const  winner)     //That function can check winner, you need to enter his symbol        
{
    return (verticalCheck(gameField,winner) ||  horizontalCheck(gameField,winner) || diagonalesCheck(gameField,winner) );
}


int main()
{
    char gameField[4][4]; // I have created vector 4x4, because it's more convinient call need part of game field.
    std::cout << "If u aren't put naught or crosses on your cage, enter the dot \n";
    std::cout << "Please, enter your field (enter three character at a time, throught a space):\n";

    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 4; j++){
            std::cin >> gameField [i][j];
            if ( !isAllowed(gameField[i][j]) ){
                std:: cout << "One of entered symbols was wrong, enter new game field please: \n";
                i = 1, j = 0;
            }
        }
    }

    if (symbolsQuanity (gameField, 'X') != symbolsQuanity(gameField, 'O')                                          //Game logic check
      && symbolsQuanity (gameField, 'X') != symbolsQuanity(gameField, 'O') + 1){
        std::cout << "Incorrect";

    }else if (winnerCheck (gameField, 'X') && symbolsQuanity(gameField, 'O') == symbolsQuanity(gameField, 'X')     //Game logic check
      || winnerCheck (gameField, 'O') && symbolsQuanity(gameField, 'O') != symbolsQuanity(gameField, 'X')){
        std::cout << "Incorrect";
    
    }else if (horizontalCheck(gameField, 'X') + horizontalCheck(gameField, 'O')                                    //Double win check
      + verticalCheck(gameField, 'X') + verticalCheck(gameField, 'O') 
        + diagonalesCheck(gameField, 'X') + diagonalesCheck(gameField, 'O') > 1 ){
        std::cout << "Incorrect";

    }else if (winnerCheck (gameField, 'X')){      
        std::cout << "Petya won";

    }else if (winnerCheck(gameField, 'O') ){ 
        std::cout << "Vanya won";

    }else if (!winnerCheck (gameField, 'X') && !winnerCheck(gameField,'O') ){
        std::cout << "Nobody";
    }
}
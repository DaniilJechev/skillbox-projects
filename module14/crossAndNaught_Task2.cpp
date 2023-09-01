#include <iostream>
#include <vector>


void resultPrint (const char gameField[][4])
{
    for (int i = 1; i < 4; i ++){
        for (int j = 1; j < 4; j ++){
            std::cout << gameField[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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

    for (int i = 1; i < 4; i ++){
        for (int j = 1; j < 4; j ++){
            gameField[i][j] = '.';
        }
    }

    int x, y;
    char symbol, tmp = 'O';

    for (int i = 0; i < 9; i++){
        std::cout << "Enter the coordinates(x,y) and your symbol(X,O): ";
        std::cin >> x >> y;
        std::cin >> symbol;
        if ( !isAllowed(symbol) || (x > 4) || (y > 4) ||
         (x < 1) || (y < 1) || (symbol == tmp) || ('.' != gameField[y][x])){
            std:: cout << "One of entered symbols was wrong or coordinates, enter new game position and symbol please. \n";
            i --;
            }else{
                tmp = symbol;
                gameField[y][x] = symbol;
                resultPrint(gameField);

            if (symbolsQuanity (gameField, 'X') != symbolsQuanity(gameField, 'O')                                          //Game logic check
              && symbolsQuanity (gameField, 'X') != symbolsQuanity(gameField, 'O') + 1){
                std::cout << "\nIncorrect";
                return 0;

            }else if (winnerCheck (gameField, 'X') && symbolsQuanity(gameField, 'O') == symbolsQuanity(gameField, 'X')     //Game logic check
              || winnerCheck (gameField, 'O') && symbolsQuanity(gameField, 'O') != symbolsQuanity(gameField, 'X')){
                std::cout << "\nIncorrect";
                return 0;

            }else if (winnerCheck (gameField, 'X')){      
                std::cout << "\nPetya won";
                return 0;

            }else if (winnerCheck(gameField, 'O') ){ 
                std::cout << "\nVanya won";
                return 0;

            }else if (!winnerCheck (gameField, 'X') && !winnerCheck(gameField,'O') && (i == 9) ){
                std::cout << "\nNobody";
                return 0;
            }
        }
    }
}
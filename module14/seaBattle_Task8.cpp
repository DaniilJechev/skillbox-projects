#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>

void battlePrint (std::vector<std::vector<int>> const &field)   //field display during battle
{
    for (int i = 0; i < field.size() - 1; i ++){
        for (int j = 0; j < field[0].size() - 1; j ++){
            if (j == 1) j ++;
            if (i == 1) i ++;
            if (i == 0 && j == 0){
                std::cout << std::setw(5) << ' ';
            } else if (j == 0) {
                std::cout << std::setw(3) << field[i][j];                  //-1 = miss
            }else if (i == 0) {                                            //-2 = hit
                std::cout << std::setw(3) << char(field[i][j] + 64);
            }else if (field[i][j] != -2 && field[i][j] != -1) {
                std::cout << std::setw(3) << '.';
            }else if (field[i][j] == -1) {
                std::cout << std::setw(3) << 'o';
            }else std::cout << std::setw(3) << 'x';

            if (j == field[0].size() - 2 && i == 0){
                std::cout << "\n      ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            }else if (j == 0 && i > 0) std::cout <<" ┃";
                   
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void placeMentPrint (std::vector<std::vector<int>> const &field)                           //display of the field during the construction of ship
{
    for (int i = 0; i < field.size() - 1; i ++){
        for (int j = 0; j < field[0].size() - 1; j ++){
            if (j == 1) j ++;
            if (i == 1) i ++;
            if (i == 0 && j == 0){
                std::cout << std::setw(5) << ' ';
            } else if (j == 0) {
                std::cout << std::setw(3) << field[i][j];
            }else if (i == 0) {
                std::cout << std::setw(3) << char(field[i][j] + 64);
            }else if (field[i][j] == 0) {
                std::cout << std::setw(3) << '.';
            }else std::cout << std::setw(3) << field[i][j];
            if (j == field[0].size() - 2 && i == 0){
                std::cout << "\n      ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            }else if (j == 0 && i > 0) std::cout <<" ┃";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool circleCheck(std::vector<std::vector<int>> &field, int &x, int &y)
{
    for (int i = y - 1; i < y + 2; i ++){
        for (int j = x - 1; j < x + 2; j ++) 
            if (field[i][j]) return true;
    }
    return false;
}

bool isAllowed(std::vector<std::vector<int>> &field,int &size, int &x1, int &y1, int &x2, int &y2 )    //will check game rules
{
    if (!(( y1 > 1 && y1 <= 11 && x1 > 0 && x1 <= 11)
          && (y2 > 1 && y2 <= 11 && x2 > 0 && x2 <= 11))) return false;

    if (((y1 == y2) && ( abs(x1 - x2) == size))
          || ((x1 == x2) && ( abs(y1 - y2) == size))
          || ((y1 != y2) && (x1 != x2)
          || (x1 == x2 && y1 == y2))) return false;

        if (y1 == y2 && (x2 - x1) != size - 1 && x2 < x1 ){
            x2 -= (size - 1) + (x2 - x1);
        }else if (x1 == x2 && (y2 - y1) != size - 1 && y2 < y1) y2 -= (size - 1) + (y2 - y1);

        if (y2 < y1 && x1 == x2){
            std::swap(y1,y2);
        }else if (x2 < x1 && y1 == y2) std::swap(x1,x2);

        if (((y1 == y2) && (x2 - x1 + 1) > size)
          || ((x1 == x2) && ( (y2 - y1 + 1) > size))
          || ((y1 != y2) && (x1 != x2))
          || (x1 == x2 && y1 == y2)) return false;

    if (y1 == y2){
        if (x1 + size >= field.size()) return false;
        for (int i = x1; i < x1 + size ; i ++){
            if (circleCheck(field,i, y1 )) return false;
        }
    }else if ( x1 == x2 ){
        if (y1 + size >= field.size()) return false;
        for (int i = y1; i < y1 + size ; i ++){
            if (circleCheck(field, x1, i)) return false;
        }
    }
    return true;
}

void build (std::vector<std::vector<int>> &field,int &size, int &x1, int &y1, int &x2, int &y2)       //Build a ship
{
    if (y1 == y2){
        for (int i = x1; i < x1 + size; i ++){
            field[y1][i] = size;
        }
    }else for (int i = y1; i < y1 + size; i ++){
            field[i][x1] = size;
        }
}

void designations (std::vector<std::vector<int>> &field)              //designation for the field
{
    for (int i = 2; i < 12; i ++){
        field[0][i] = i - 1;
        field[i][0] = i - 1;
    }
}

bool shipBuilding (std::vector<std::vector<int>> &field,int &size, int &count, std::string const &player)            //That function will build a ship
{
    int x1, y1 = 0, x2, y2;
    char letter;
    if ( size < 5 ){
    std::cout <<"You need to arrange " << count << " ship with the size of " << size << " cell.\n(input coordinates)\n";

    placeMentPrint(field);

    for (;count > 0; count--){
        std::cout << "Input first coordinates ";
        std::cin >> letter >> y1;
        x1 = letter - 64;
        std::cout << "Input second coordinates ";
        std::cin >> letter >> y2;
        x2 = letter - 64;
        x1 ++, x2 ++, y1 ++, y2 ++;

        if (isAllowed(field, size, x1, y1, x2, y2)){
            build(field, size ,x1, y1, x2, y2);
        }else {
            std::cout << "Error, try again!!!\n";
            Sleep(650) , shipBuilding(field, size, count, player);
            return true;
        }
        placeMentPrint(field);
    }

    size += 1;
    count = 5 - size;
    shipBuilding(field, size, count, player);
    }
    return true;
}

bool shipBuilding_start (std::vector<std::vector<int>> &field, int &count, std::string const &player)                 // This function is designed to run (when ship size = 1)
{
    int x, y, size = 1;
    char letter;
    std::cout <<"You need to arrange " << count << " ship with the size of " << size << " cell.\n\n";

    for (;count > 0; count--){
        std::cout << "Input coordinates ";
        std::cin >> letter >> y;
        x = letter - 64;
        x ++ , y ++;
        if (( y > 1 && y <= 11 && x > 1 && x <= 11)
         && (field[y][x] == 0) && !circleCheck(field, x, y)){
            field[y][x] = size;
            placeMentPrint(field);
        }else {
            std::cout << "\nError, try again!!!\n";
            shipBuilding_start(field, count, player);
        }
        field[y][x] = size;
    }
   size += 1;
    count = 5 - size;
    return shipBuilding(field, size, count, player);
}

bool placeMent (std::vector<std::vector<int>> &field, std::string const &player)         //This function places ships (using helper functions)
{
    int count = 4;    //This variable shows the number of ships of a certain size not yet built.
    std::cout << "\n\n\n\n\n\n\n           You are a "<< player <<" player.\n";
    std::cout << "            Thats your field." << "\n                    |\n                    ↓\n";
    placeMentPrint(field);
    return shipBuilding_start(field, count, player);;
}



bool battleRules (int &x, int &y)      
{
    return (x < 2 || x > 12 || y < 2 || y > 12);
}

void paintAround (std::vector<std::vector<int>> &field, int &x, int &y)       //Аills the circle around the sunken ship
{
    for (int i = y - 1; i < y + 2; i ++){
        for (int j = x - 1; j < x + 2; j ++){
            field[i][j] = -1;
        }
    }
    field[y][x] = -2;
}

bool winCheck(std::vector<std::vector<int>> &field)
{
    for (int i = 2; i < field.size() - 1; i ++){
        for (int j = 2; j < field[0].size() - 1; j ++){
            if (field[i][j] > 0) return false;
        }
    }
    return true;
}

std::string direction (std::vector<std::vector<int>> &field, int &x, int &y)
{
    if (field[y][x - 1] > 0 || field[y][x - 1] == -2){
        x--;
        return "right";
    }else if (field[y - 1][x] > 0 || field[y - 1][x] == -2){
        y--;
        return "down";
    }
    return "notMoving";
}

void rightPaint (std::vector<std::vector<int>> &field, int &x, int &y)
{
    while (field[y][x] != -1){
            for (int i = y - 1; i < y + 2; i ++){
                for (int j = x - 1; j < x + 2; j ++){
                    if (field[i][j] != -2) field[i][j] = -1;
                }
            }
            x++;
        }
}

void downPaint (std::vector<std::vector<int>> &field, int &x, int &y)
{
    while (field[y][x] != -1){
            for (int i = y - 1; i < y + 2; i ++){
                for (int j = x - 1; j < x + 2; j ++){
                    if (field[i][j] != -2) field[i][j] = -1;
                }
            }
            y ++;
        }
}

bool shipDeath (std::vector<std::vector<int>> &field, int &x, int &y)  //will check ship on death and if he dies will paint
{
    field[y][x] = -2;
    int i , j, startX = x, startY = y;
    if (direction(field, x, y) == "right"){
        while (direction(field, x, y) != "notMoving") direction(field, x, y);       //If the check is successful , tracing begins
        for (int i = 0;;i++){
            if (field[y][x + i] == -1 || field[y][x + i] == 0) break;
            if (field[y][x + i] != -2) return false;
        }

        rightPaint(field, x, y);
        return true;

    }else if (direction(field, x, y) == "down"){
        while (direction(field, x, y) != "notMoving") direction(field, x, y);       //If the check is successful , tracing begins
        for (i = 0;;i++){
            if (field[y + i][x] == -1 || field[y + i][x] == 0) break;
            if (field[y + i][x] != -2) return false;
        }

        downPaint(field, x, y);
        return true;

    }else if (direction(field, x, y) == "notMoving"){
        if (field[y + 1][x] == -2){
            while (direction(field, x, y) != "notMoving") direction(field, x, y);     //Problem part of function
        for (i = 0;;i++){
            if (field[y + i][x] == -1 || field[y + i][x] == 0) break;
            if (field[y + i][x] != -2) return false;
        }

        downPaint(field, x, y);
        return true;

        }else if (field[y][x + 1] == -2){
            while (direction(field, x, y) != "notMoving") direction(field, x, y);       
        for (int i = 0;;i++){
            if (field[y][x + i] == -1 || field[y][x + i] == 0) break;
            if (field[y][x + i] != -2) return false;
        }

        rightPaint(field, x, y);
        return true;
        }
    }
    return false;
}

void move (std::vector<std::vector<int>> &field_1, std::string const p2)
{
    int x, y, startSize;
    char letter;
    battlePrint(field_1),Sleep(650);
    std::cout <<"You need to enter the hit coordinates\n";
    std::cout << "Input coordinates: ";
    for (;;){
        std::cin >> letter >> y;
        x = letter - 64;
        x++, y ++;
        if (battleRules(x, y) ){
            std::cout << "\nInvalid input\nInput coordinates again: ";
        }else break;
    }
    startSize = field_1[y][x];
    if (field_1[y][x] <= 0) {
        std::cout << "\nYou missed\n";
        Sleep(650);
        if (field_1[y][x] != -2) field_1[y][x] = -1;
        Sleep(800), battlePrint(field_1);
    }else{
        if (field_1[y][x] == 1){
            paintAround(field_1, x, y);
            field_1[y][x] = -2;
            if (winCheck(field_1)){
                battlePrint(field_1);
                std::cout << p2 << " Win!";
                return ;
            }else{
                Sleep(650);
                std::cout << "You sank the ship! And can move again.\n";
                Sleep(800), move(field_1,p2); //problem with recursion after input A1
            }
        }else{         //100% hit and ship size >= 2
            }if (startSize != 1){
                if (shipDeath(field_1, x, y)){     
                    Sleep(650);                             //after kill the ship if u miss next move u can move again (error need to be fixed)
                    if (winCheck(field_1)){ 
                        battlePrint(field_1);
                        std::cout << p2 << " Win!";
                        return ;
                    }else{
                    std::cout << "You sank the ship! And can move again.\n";
                    Sleep(800), move(field_1, p2);
                    }
                }else{
                    Sleep(650);
                    std::cout << "You hit! And can move again.\n";
                    Sleep(800), move(field_1,p2);
                }
            }
    }
}

int main ()
{
    std::vector <std::vector<int>> field_1 (13, std::vector <int>(13, 0));
    std::vector <std::vector<int>> field_2 (13, std::vector <int>(13, 0));
    std::string p1, p2;
    std::cout << "Enter first player name ";
    std::cin >> p1;
    std::cout << "Enter second player name ";
    std::cin >> p2;

    designations(field_1);
    designations(field_2);
    
    std::cout << "\nHello, this is a sea battle.\nFirst, you need to arrange your ships for two players.\n";
    std::cout << "Instructions: when entering coordinates, first enter the letter, after the number.\n\n";

    for (;;){
    if (placeMent(field_1, p1)) break;
    }

    Sleep(3000);
    
    for (;;){
    if (placeMent(field_2, p2)) break;
    }

    std::cout <<"\n\n\n\n\n\n\n\nLets start!\n";
    for (;;){
        Sleep(1200);
        std::cout << p1 << " is moving now.\n"; //Make a string with the name of the field
        move(field_2, p1);
        if(winCheck(field_2)) break;
        Sleep(1200);
        std::cout << p2 << " is moving now.\n";
        move(field_1, p2);
        if (winCheck(field_1)) break;
    }
    Sleep(400);
    std::cout << "\nThank for playing!";
}
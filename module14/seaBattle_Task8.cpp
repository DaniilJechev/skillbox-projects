#include <iostream>
#include <vector>
#include <iomanip>

void battlePrint (std::vector<std::vector<int>> const &field, std::string const )   //field display during battle
{
    for (int i ; i < field.size() ; i ++){
        for (int j = 0; j < field[0].size(); j ++){
            if (i == 0 && j == 0){
                std::cout << std::setw(4) << ' ';
            } else if (i == 0) {
                std::cout << std::setw(3) << field[i][j];
            }else if (j == 0) {
                std::cout << std::setw(3) << char(field[i][j] + 64);
            }else if (field[i][j] == 0) {
                std::cout << std::setw(3) << '.';
            }else std::cout << std::setw(3) << field[i][j];
            if (j == field[0].size() - 1 && i == 0){
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
    
    if (y2 < y1) std::swap(y1,y2);
    if (x2 < x1) std::swap(x1,x2);

    if (y1 == y2){
        for (int i = x1; i < x2 + 1; i ++){
            if (circleCheck(field,i, y1 )) return false;
        }
    }else if ( x1 == x2 ){ 
        for (int i = y1; i < y2 + 1; i ++){
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
    }else for (int i = y1; i < y2 + size - 1; i ++){
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

bool shipBuilding (std::vector<std::vector<int>> &field,int &size, int &count, std::string const player)            //That function will build a ship
{
    int x1, y1 = 0, x2, y2;
    char letter;
    if ( size < 6 ){
    std::cout <<"You need to arrange " << count << " ship with the size of " << size << " cell.\n(input coordinates)\n";
    placeMentPrint(field);

    for (;count > 0; count--){
        std::cout << "Input first coordinates ";
        std::cin >> letter >> y1;
        x1 = letter - 63;
        std::cout << "Input second coordinates ";
        std::cin >> letter >> y2;
        x2 = letter - 63;
        x1 ++, x2 ++, y1 ++, y2 ++;
        if (isAllowed(field, size, x1, y1, x2, y2)){
            build(field, size ,x1, y1, x2, y2);
        }else {
            std::cout << "Error, try again!!!\n";
            std::cout << "If you want to delete ALL YOUR FIELD and start building ships again, enter 'yes'.\nOtherwise, enter any other character:\n";
            std::string comand;
            std::cin >> comand;
            if (comand == "yes"){
                for (int i = 2 ; i < field.size() - 1 ; i ++){
                    for (int j = 2; j < field[0].size() - 1; j ++){
                        field[i][j] = 0;
                    }
                }
                return false;
            }
            shipBuilding(field, size, count, player);
        }
        placeMentPrint(field);
    }

    size += 1;
    count = 5 - size;
    shipBuilding(field, size, count, player);
    }
    return true;
}

bool shipBuilding_start (std::vector<std::vector<int>> &field, int &count, std::string const player)                 // This function is designed to run (when ship size = 1)
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

bool placeMent (std::vector<std::vector<int>> &field, std::string const player)         //This function places ships (using helper functions)
{
    int count = 4;    //This variable shows the number of ships of a certain size not yet built.
    std::cout << "           You are a "<< player <<" player.\n";
    std::cout << "            Thats your field." << "\n                    |\n                    ↓\n";
    placeMentPrint(field);
    return shipBuilding_start(field, count, player);;
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
    
    std::cout << "Hello, this is a sea battle.\nFirst, you need to arrange your ships for two players.\n\n";

    for (;;){
    if (placeMent(field_1, p1)) break;
    }

    for (;;){
    if (placeMent(field_2, p2)) break;
    }

    for (;;){
        std::cout <<"\n\n\n\n\n\n\nLets start!";
    }
}
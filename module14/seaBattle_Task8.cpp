#include <iostream>
#include <vector>
#include <iomanip>

void battlePrint (std::vector<std::vector<int>> const &field, std::string const )   //field display during battle
{
    for (int i = 0; i < field.size(); i ++){
        for (int j = 0; j < field[0].size(); j ++){
            if (i == 0 && j == 0){
                std::cout << std::setw(4) << ' ';
            } else if (i == 0 || j == 0) {
                std::cout << std::setw(3) << field[i][j];
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
    for (int i = 0; i < field.size(); i ++){
        for (int j = 0; j < field[0].size(); j ++){
            if (i == 0 && j == 0){
                std::cout << std::setw(5) << ' ';
            } else if (i == 0 || j == 0) {
                std::cout << std::setw(3) << field[i][j];
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

bool circleCheck(std::vector<std::vector<int>> &field, int &x, int &y)
{
    for (int i = x - 1; i < x + 1; i ++){
        for (int j = y - 1; j < y + 1; j ++) 
            if (field[i][j]) return false;
    }
    return true;
}

bool isAllowed(std::vector<std::vector<int>> &field,int &size, int &x1, int &y1, int &x2, int &y2 )    //will check game rules
{
    if (!(( y1 > 0 && y1 <= 10 && x1 > 0 && x1 <= 10)
          && (y2 > 0 && y2 <= 10 && x2 > 0 && x2 <= 10))) return false;

    if (((y1 == y2) && ( abs(x1 - x2) == size))
          || ((x1 == x2) && ( abs(y1 - y2) == size))
          || ((y1 != y2) && (x1 != x2))) return false;
    
    if (y2 < y1) std::swap(y1,y2);
    if (x2 < x1) std::swap(x1,x2);

    if (y1 == y2){
        for (int i = x1; i < x2 + 1; i ++){
            if (circleCheck(field,i,y1 )) return false;
        }
    }else if ( x1 == x2 ){ 
        for (int i = y1; i < y2 + 1; i ++){
            if (circleCheck(field, x2, i)) return false;
        }
    }else return false;
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

void shipBuilding (std::vector<std::vector<int>> &field,int &size, int &count)               //That function will build a ship
{
    int x1, y1 = 0, x2, y2;
    if ( size < 6 ){
    std::cout <<"You need to arrange " << count << " ship with the size of " << size << " cell.\n(input coordinates)\n";
    placeMentPrint(field);

    for (;count > 0; count--){
        std::cout << "Input first coordinates ";
        std::cin >> x1 >> y1;
        std::cout << "Input second coordinates ";
        std::cin >> x2 >> y2;
        if (isAllowed(field, size, x1, y1, x2, y2)){
            build(field, size ,x1, y1, x2, y2);
        }else {
            std::cout << "Error, try again\n";
            shipBuilding(field, size, count);
        }
        placeMentPrint(field);
        if (count <= 0 || size == 6) return;
    }

    size += 1;
    count = 5 - size;
    shipBuilding(field, size, count);
    }else return;
}

void shipBuilding_start (std::vector<std::vector<int>> &field, int &count)                 // This function is designed to run (when ship size = 1)
{
    int x, y, size = 1;
    std::cout <<"You need to arrange " << count << " ship with the size of " << size << " cell.\n(input coordinates)\n";
    placeMentPrint(field);

    for (;count > 0; count--){
        std::cout << "Input coordinates ";
        std::cin >> x >> y;
        if (( y > 0 && y <= 10 && x > 0 && x <= 10)
         && (field[y][x] == 0)){
            field[y][x] = size;
        }else {
            std::cout << "\nError, try again\n";
            shipBuilding_start(field, count);
        }
        field[y][x] = size;
        placeMentPrint(field);
    }
   size += 1;
    count = 5 - size;
    shipBuilding(field, size, count);
}

void designations (std::vector<std::vector<int>> &field)              //designation for the field
{
    for (int i = 1; i < 11; i ++){
        field[0][i] = i;
        field[i][0] = i;
    }
}

void placeMent (std::vector<std::vector<int>> &field, std::string const player )         //This function places ships (using helper functions)
{
    int count = 4;    //This variable shows the number of ships of a certain size not yet built.
    std::cout << "        You are a "<< player <<" player.\n";
    std::cout << "           Thats your field" << "\n                  |\n                  ↓\n";
    placeMentPrint(field);
    shipBuilding_start(field, count);
}

int main ()
{
    std::vector <std::vector<int>> field_1 (11, std::vector <int>(11, 0));
    std::vector <std::vector<int>> field_2 (11, std::vector <int>(11, 0));
    std::string p1, p2;
    std::cout << "Enter first player name ";
    std::cin >> p1;
    std::cout << "Enter second player name ";
    std::cin >> p2;

    designations(field_1);
    designations(field_2);
    
    std::cout << "Hello, this is a sea battle.\nFirst, you need to arrange your ships for two players.\n\n";

    placeMent(field_1, p1);
    placeMent(field_2, p2);

    for (;;){
        std::cout <<"\n\n\n\n\n\n\nLets start!";
    }
}
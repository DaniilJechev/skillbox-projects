#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstring>

enum sides{
    up = 1,
    down,
    left,
    right
};

struct position
{
    int cordX;
    int cordY;
};

struct character
{
    std::string name;
    int hp;
    int armor;
    int damage;
    int killCount = 0;
    struct position pos;
};

void mapPrint(std::vector<std::vector<std::string>>& map, character player) // this function show the person status to 
{
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[0].size(); j ++){
            if (map[i][j] == player.name){
                while (player.name.size() > 2) player.name.pop_back();
                std::cout << std::setw(3) << player.name;
            }else std::cout << std::setw(3) << map[i][j];
        }
        if (i == 1) std::cout << std::setw(27) << "YOUR PARAMETERS";
            else if (i == 2) std::cout << std::setw(92) << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
                else if (i == 4) std::cout << std::setw(18) << "HP = " << player.hp;
                    else if (i == 6) std::cout << std::setw(21) << "Armor = " << player.armor;
                        else if (i == 8) std::cout << std::setw(22) << "Damage = " << player.damage;
                            else if (i == 10) std::cout << std::setw(26) << "Kill count = " << player.killCount;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void randomPosition (character& personage, std::vector <std::vector<std::string>>& map)
{
    do{
        personage.pos.cordY = std::rand() % 20;
        personage.pos.cordX = std::rand() % 20;
    } while (map[personage.pos.cordY][personage.pos.cordY] != ".");
        
    map[personage.pos.cordY][personage.pos.cordX] = personage.name;
}

void randomEnemiesStats (character& personage){
    personage.hp = 50 + std::rand() % 101;
    personage.armor = std::rand() % 51;
    personage.damage = 15 + std::rand() % 16;
}

void personMoving (character& personage, std::vector <std::vector<std::string>>& map, bool mainCharacter = false)
{
    int command;
    if (mainCharacter){
        std::cout << std::endl << "Move commands: " << std::endl;
        std::cout << "up = 1\n"
                  << "down = 2\n"
                  << "left = 3\n"
                  << "right = 4\n"
                  << "Input nedeed command number: ";
        std::cin >> command;
    }else command = 1 + std::rand() % 4;

    map[personage.pos.cordY][personage.pos.cordX] = '.'; // remove character name from old pos
    if (command == sides::up){
        if (personage.pos.cordY != 0 && map[personage.pos.cordY - 1][personage.pos.cordX] == "."){
            personage.pos.cordY--;
        } 
    }else if (command == sides::down){
        if (personage.pos.cordY != 19 && map[personage.pos.cordY + 1][personage.pos.cordX] == "."){
            personage.pos.cordY++;
        }
    }else if (command == sides::left){
        if (personage.pos.cordX != 0 && map[personage.pos.cordY ][personage.pos.cordX - 1] == "."){
            personage.pos.cordX--;
        }
    }else if (command == sides::right){
        if (personage.pos.cordX != 19 && map[personage.pos.cordY][personage.pos.cordX + 1] == "."){
            personage.pos.cordX ++;
        }
    }
    map[personage.pos.cordY][personage.pos.cordX] = personage.name; // add the character name to new cell
}

void damageFunction (character& personage, std::vector<std::vector<std::string>>& map){

}

int main()
{
    character player;
    character enemy1 = {"#1"}, enemy2 = {"#2"}, enemy3 = {"#3"}, enemy4 = {"#4"}, enemy5 = {"#5"};
    std::vector <std::vector<std::string>> map(20, std::vector<std::string> (20, "."));

    std::srand(time(NULL));

    //main charachter constructor
    std::cout << "Now, you need to create your character: " << std::endl;
    std::cout << "Give him/her name (only two first letters will displayed on the screen): ";
    std::cin >> player.name;
    std::cout << std::endl << "HP = ";
    std::cin >> player.hp;
    std::cout << std::endl << "Damage = ";
    std::cin >> player.damage;
    std::cout << std::endl << "Armor = ";
    std::cin >> player.armor;
    std::cout << "Personage was created!" << std::endl;
    std::cout << "Thats your field: " << std::endl;

    // random positions
    randomPosition(player, map);
    randomPosition(enemy1, map);
    randomPosition(enemy2, map);
    randomPosition(enemy3, map);
    randomPosition(enemy4, map);
    randomPosition(enemy5, map);

    // random enemies stats
    randomEnemiesStats(enemy1);
    randomEnemiesStats(enemy2);
    randomEnemiesStats(enemy3);
    randomEnemiesStats(enemy4);
    randomEnemiesStats(enemy5);
    
    mapPrint(map, player);
    std::cout << "Let's start the battle!" << std::endl;
    while (true){
        personMoving(player, map, true);
        personMoving(enemy1, map);
        personMoving(enemy2, map);
        personMoving(enemy3, map);
        personMoving(enemy4, map);
        personMoving(enemy5, map);
        mapPrint(map, player);
    }
}
#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstring>
#include <fstream>

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

void randomPosition (std::vector <character>& personages, std::vector <std::vector<std::string>>& map)
{
    for (int i = 0; i < personages.size(); i ++){
        do{
            personages[i].pos.cordY = std::rand() % 20;
            personages[i].pos.cordX = std::rand() % 20;
        } while (map[personages[i].pos.cordY][personages[i].pos.cordY] != ".");
        
        map[personages[i].pos.cordY][personages[i].pos.cordX] = personages[i].name;
    }
}

void randomEnemiesStats (std::vector <character>& personages)
{
    for (int i = 1; i < personages.size(); i ++){
        personages[i].hp = 50 + std::rand() % 101;
        personages[i].armor = std::rand() % 51;
        personages[i].damage = 15 + std::rand() % 16;
    }
}

void damage(character& hitter, character& defender, std::vector<std::vector<std::string>>& map)
{
    defender.armor -= hitter.damage;
    if (defender.armor <= 0){
        defender.hp += defender.armor;
        defender.armor = 0;
        if (defender.hp <= 0){
            hitter.killCount++;
            defender.name = ".";
            map[defender.pos.cordY][defender.pos.cordX] = '.';
        }
    }
}

int sideDefiner (std::string& side)
{
    if (side == "w") return 1;
        else if (side == "s") return 2;
            else if (side == "a") return 3;
                else if (side == "d") return 4;
    return 0;
}


void saveProgress (std::vector <character>& personages, std::vector <std::vector<std::string>>& map, std::string& command)  
{
    // file plan: nameLen| name(string) | hp | armor | damage | killcount | pos.cordX | pos.cordY
    std::string fileName;
    std::cout << std::endl << "Enter the fileName of your save please: ";
    std::cin >> fileName;
    std::ofstream write_Save(fileName, std::ios::binary);
    while (!write_Save.is_open()){
        std::cout << std::endl << "Incorrect file name, try enter again: ";
        std::cin >> fileName;
        write_Save.open(fileName, std::ios::binary);
    }
    
    for (int i = 0; i < personages.size(); i++){
        int nameSize = personages[i].name.length();
        write_Save.write((char*)&nameSize, sizeof(nameSize));
        write_Save.write(personages[i].name.c_str(), nameSize);

        write_Save.write((char*)&personages[i].hp, sizeof(personages[i].hp));
        write_Save.write((char*)&personages[i].armor, sizeof(personages[i].armor));
        write_Save.write((char*)&personages[i].damage, sizeof(personages[i].damage));
        write_Save.write((char*)&personages[i].killCount, sizeof(personages[i].killCount));
        write_Save.write((char*)&personages[i].pos.cordX, sizeof(personages[i].pos.cordX));
        write_Save.write((char*)&personages[i].pos.cordY, sizeof(personages[i].pos.cordY));
    }

    std::cout << std::endl << "Progress is saved";
    write_Save.close();

    mapPrint(map, personages[0]);
    std::cout << std::endl << "Now, continue game and enter the which you want to go: ";
    std::cin >> command;
}

void loadProgress (std::vector <character>& personages, std::vector <std::vector<std::string>>& map, std::string& command)
{
    // file plan: nameLen| name(string) | hp | armor | damage | killcount | pos.cordX | pos.cordY
    std::string fileName;
    std::cout << std::endl << "Enter the fileName of your save please: ";
    std::cin >> fileName;
    std::ifstream saveF(fileName, std::ios::binary);
    while (!saveF.is_open()){
        std::cout << std::endl << "Incorrect file name, try enter again: ";
        std::cin >> fileName;
        saveF.open(fileName, std::ios::binary);
    }
    
    for (int i = 0; i < personages.size(); i++){
        int nameSize;
        saveF.read((char*)&nameSize, sizeof(nameSize));
        personages[i].name.resize(nameSize);
        saveF.read((char*)personages[i].name.c_str(), nameSize);
        saveF.read((char*)&personages[i].hp, sizeof(personages[i].hp));
        saveF.read((char*)&personages[i].armor, sizeof(personages[i].armor));
        saveF.read((char*)&personages[i].damage, sizeof(personages[i].damage));
        saveF.read((char*)&personages[i].killCount, sizeof(personages[i].killCount));
        saveF.read((char*)&personages[i].pos.cordX, sizeof(personages[i].pos.cordX));
        saveF.read((char*)&personages[i].pos.cordY, sizeof(personages[i].pos.cordY));
    }

    saveF.close();
    map.clear();
    map.resize(20);
    for (int i = 0; i < 20; i ++){
        for (int j = 0; j < 20; j++){
            map[i].push_back (".");
        }
    }

    for (int i = 0; i < personages.size(); i ++){
        map[personages[i].pos.cordY][personages[i].pos.cordX] = personages[i].name;
    }
    mapPrint(map, personages[0]);

    std::cout << std::endl << "Now, continue game and enter the which you want to go: ";
    std::cin >> command;
}

void personMoving (std::vector <character>& personages, std::vector <std::vector<std::string>>& map)
{
    int side;
    std::string command;
    for (int i = 0; i < personages.size(); i++){
        if (i == 0){ //player is in this position
            std::cout << std::endl << "Move commands: " << std::endl;
            std::cout << "up = w\n"
                      << "left = a\n"
                      << "down = s\n"
                      << "right = d\n"
                      << "(P.s. if u want to save your progress, enter save, or if u want to load your progress, press load)\n" 
                      << "Input nedeed command: ";
            std::cin >> command;
            std::cout << std::endl;
            if (command == "save") saveProgress(personages, map, command);
                else if (command == "load") loadProgress(personages, map, command);

            side = sideDefiner(command);
        }
        if (personages[i].name != "."){

            if (side == sides::up){
                if (personages[i].pos.cordY != 0){
                    if (map[personages[i].pos.cordY - 1][personages[i].pos.cordX] == "."){

                        map[personages[i].pos.cordY][personages[i].pos.cordX] = '.'; // remove character name from old pos
                        map[personages[i].pos.cordY - 1][personages[i].pos.cordX] = personages[i].name; // add the character name to new cell
                        personages[i].pos.cordY--;
                    }else{
                        if (!(map[personages[i].pos.cordY - 1][personages[i].pos.cordX][0] == '#' // checking, if two personages are enemies, damage function will not work
                             && map[personages[i].pos.cordY][personages[i].pos.cordX][0] == '#')){ 
                            
                            std::string defenderName = map[personages[i].pos.cordY - 1][personages[i].pos.cordX];
                            std::string hitterName = map[personages[i].pos.cordY][personages[i].pos.cordX];
                            int hitterVectorPos, defenderVectorPos;
                            if (defenderName[0] != '#'){
                                defenderVectorPos = 0;
                                hitterVectorPos = atoi(&hitterName[1]); // converting number in enemy name from string to int
                            }else{
                                hitterVectorPos = 0;
                                defenderVectorPos = atoi(&defenderName[1]); // same as int previous comment
                            }
                            damage (personages[hitterVectorPos], personages[defenderVectorPos], map);
                        }

                    }
                }
            }else if (side == sides::down){
                if (personages[i].pos.cordY != 19){
                    if (map[personages[i].pos.cordY + 1][personages[i].pos.cordX] == "."){

                        map[personages[i].pos.cordY][personages[i].pos.cordX] = '.';
                        map[personages[i].pos.cordY + 1][personages[i].pos.cordX] = personages[i].name;
                        personages[i].pos.cordY++;
                    }else{
                        if (!(map[personages[i].pos.cordY + 1][personages[i].pos.cordX][0] == '#'
                             && map[personages[i].pos.cordY][personages[i].pos.cordX][0] == '#')){ 
                            
                            std::string defenderName = map[personages[i].pos.cordY + 1][personages[i].pos.cordX];
                            std::string hitterName = map[personages[i].pos.cordY][personages[i].pos.cordX];
                            int hitterVectorPos, defenderVectorPos;
                            if (defenderName[0] != '#'){
                                defenderVectorPos = 0;
                                hitterVectorPos = atoi(&hitterName[1]);
                            }else{
                                hitterVectorPos = 0;
                                defenderVectorPos = atoi(&defenderName[1]);
                            }
                            damage (personages[hitterVectorPos], personages[defenderVectorPos], map);
                        }
                    }
                }
            }else if (side == sides::left){
                if (personages[i].pos.cordX != 0){
                    if (map[personages[i].pos.cordY][personages[i].pos.cordX - 1] == "."){
                    
                        map[personages[i].pos.cordY][personages[i].pos.cordX] = '.';
                        map[personages[i].pos.cordY][personages[i].pos.cordX - 1] = personages[i].name;
                        personages[i].pos.cordX--;
                    }else{
                        if (!(map[personages[i].pos.cordY][personages[i].pos.cordX - 1][0] == '#'
                             && map[personages[i].pos.cordY][personages[i].pos.cordX][0] == '#')){ 
                            
                            std::string defenderName = map[personages[i].pos.cordY][personages[i].pos.cordX - 1];
                            std::string hitterName = map[personages[i].pos.cordY][personages[i].pos.cordX];
                            int hitterVectorPos, defenderVectorPos;
                            if (defenderName[0] != '#'){ 
                                defenderVectorPos = 0;
                                hitterVectorPos = atoi(&hitterName[1]);
                            }else{
                                hitterVectorPos = 0;
                                defenderVectorPos = atoi(&defenderName[1]);
                            }
                            damage (personages[hitterVectorPos], personages[defenderVectorPos], map);
                        }
                    }
                }
            }else if (side == sides::right){
                    if (personages[i].pos.cordX != 19){
                    if (map[personages[i].pos.cordY][personages[i].pos.cordX + 1] == "."){

                        map[personages[i].pos.cordY][personages[i].pos.cordX] = '.';
                        map[personages[i].pos.cordY][personages[i].pos.cordX + 1] = personages[i].name;
                        personages[i].pos.cordX++;
                    }else{
                        if (!(map[personages[i].pos.cordY][personages[i].pos.cordX + 1][0] == '#'
                             && map[personages[i].pos.cordY][personages[i].pos.cordX][0] == '#')){ 
                            
                            std::string defenderName = map[personages[i].pos.cordY][personages[i].pos.cordX + 1];
                            std::string hitterName = map[personages[i].pos.cordY][personages[i].pos.cordX];
                            int hitterVectorPos, defenderVectorPos;
                            if (defenderName[0] != '#'){
                                defenderVectorPos = 0;
                                hitterVectorPos = atoi(&hitterName[1]);
                            }else{
                                hitterVectorPos = 0;
                                defenderVectorPos = atoi(&defenderName[1]);
                            }
                            damage (personages[hitterVectorPos], personages[defenderVectorPos], map);
                        }

                    }
                }
            }
        }
        command = 1 + std::rand() % 4;
    }
}

bool win_lose_Check (std::vector <character>& personages){
    if (personages[0].name == "."){
        std::cout << std::endl << "You lose :(";
        return false;
    }else{
        for (int i = 1; i < personages.size(); i ++){
            if (personages[i].name != ".") return true;
        }
        std::cout << std::endl << "You won!!!";
        return false;
    }
}


int main()
{
    character player;
    character enemy1 = {"#1"}, enemy2 = {"#2"}, enemy3 = {"#3"}, enemy4 = {"#4"}, enemy5 = {"#5"};
    std::vector <std::vector<std::string>> map(20, std::vector<std::string> (20, "."));
    std::vector <character> personages = {player, enemy1, enemy2, enemy3, enemy4, enemy5}; // This vector need for damage function in the future

    std::srand(time(NULL));

    //main charachter constructor
    std::cout << "Now, you need to create your character: " << std::endl;
    std::cout << "Give him/her name (only two first letters will displayed on the screen): ";
    std::cin >> personages[0].name;
    std::cout << std::endl << "HP = ";
    std::cin >> personages[0].hp;
    std::cout << std::endl << "Damage = ";
    std::cin >> personages[0].damage;
    std::cout << std::endl << "Armor = ";
    std::cin >> personages[0].armor;
    std::cout << "Personage was created!" << std::endl;
    std::cout << "Thats your field: " << std::endl;

    // random positions for all characters and random stats for enemies 
    randomPosition(personages, map);
    randomEnemiesStats(personages);
    
    mapPrint(map, personages[0]);
    std::cout << "Let's start the battle!" << std::endl;
    while (win_lose_Check(personages)){
        personMoving(personages, map);
        mapPrint(map, personages[0]);
    }
}
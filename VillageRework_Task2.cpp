#include <iostream>
#include <vector>

enum roomTypes{
    bedroom = 1,
    kitchen = 2,
    bathroom = 4,
    childrenRoom = 8,
    livingRoom = 16
};

enum buildingTypes{
    is_house = 1,
    is_garage = 2,
    is_buthHause = 4,
    is_barn = 8
};

//========Structures==========

struct room{
    int roomType = 0;
    int square;
};

struct floor{
    int ceilingHeight;
    std::vector <room> rooms;
};

struct house{
    bool chimneysStove = false;
    int square;
    std::vector <floor> floors;
};

struct garage
{
    int square;
};

struct buthHouse{
    int square;
    bool chimneyStave = false;
};

struct barn{
    int square;
};


struct territoty
{
    std::string name;
    float square;
    int buildings = 0;  // this num will be changed using enum Bilding types. 
    // This num will determine which bildings present on territory and wich are not (which values I'll use)
    struct house building_House;
    struct garage building_Garge;
    struct buthHouse building_ButhHouse;
    struct barn building_Barn;
};

struct villageTerritories
{
    std::vector <territoty> villageArea;
};

bool is_ValidType (int room_Now, floor& cur_floor, room& cur_room)
{
    for (int i = 0; i < cur_floor.rooms.size(); i ++){
        if (cur_floor.rooms[i].roomType & cur_room.roomType) return false;
    }

    return (room_Now == roomTypes::bedroom || room_Now == roomTypes::kitchen 
    || room_Now == roomTypes::bathroom || room_Now == roomTypes:: childrenRoom 
    || room_Now == roomTypes::livingRoom);
}


int main()
{
    int territoriesCount;
    villageTerritories village;
    territoty cur_territory;
    std::string answer;

    
    std::cout << "Enter the count of territories in your village: ";
    std::cin >> territoriesCount;

    for (int i = 1; i <= territoriesCount; i ++){
        std::cout << std::endl << "You need enter the information about " << i << " territory" << std::endl;
        
        //general information about Territroy
        std::cout << "Enter the number/name of your territory: ";
        std::cin >> cur_territory.name;
        std::cout << std::endl << "Enter the general square of all your territory (m²): ";
        std::cin >> cur_territory.square;

        //house block
        house cur_building_House;
        std::cout << std::endl << "Do you have a house on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_house;
            std::cout << std::endl << "Do you have a chimneys and stove into your house?(yes or no): "; 
            std::cin >> answer;
            if (answer == "yes") cur_building_House.chimneysStove = true;

            std::cout << std::endl << "Enter the square of your house (m²): "; 
            std::cin >> cur_building_House.square;
        } // house will be added to territory after receiving all inf about it

        //garage block
        garage cur_garage;
        std::cout << std::endl << "Do you have a garage on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_garage;
            std::cout << std::endl << "Enter the square of your garage (m²): "; 
            std::cin >> cur_garage.square;
            cur_territory.building_Garge = cur_garage;
        }

        //buthHouse block
        buthHouse cur_buthHouse;
        std::cout << std::endl << "Do you have a buthHouse on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_buthHause;
            std::cout << std::endl << "Do you have a chimneys and stove into your buthHouse?(yes or no): ";
            std::cin >> answer;
            if (answer == "yes") cur_buthHouse.chimneyStave = true;
            std::cout << std::endl << "Enter the square of your buthHouse (m²): "; 
            std::cin >> cur_buthHouse.square;
            cur_territory.building_ButhHouse = cur_buthHouse;
        }

        //barn block
        barn cur_barn;
        std::cout << std::endl << "Do you have a barn on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_barn;
            std::cout << std::endl << "Enter the square of your barn (m²): "; 
            std::cin >> cur_barn.square;
            cur_territory.building_Barn = cur_barn;
        }

        //house main information block
        if (cur_territory.buildings & buildingTypes::is_house){
            int floorCount;
            std::cout << std::endl << "Enter the count of floors into your hause: ";
            std::cin >> floorCount;
            while(floorCount < 1 || floorCount > 3){
                std::cout << std::endl << "Invalid number, try enter again: ";
                std::cin >> floorCount;
            }

            for (int i = 1; i <= floorCount; i ++ ){
                floor cur_floor;
                int roomCount;

                std::cout << std::endl << "You need to enter inf about " << i << " floor";
                std::cout << std::endl << "Enter celling height ";
                std::cin >> cur_floor.ceilingHeight;

                std::cout << std::endl << "Enter the room count: ";
                std::cin >> roomCount;
                while(roomCount < 1 || roomCount > 4){
                    std::cout << std::endl << "Invalid count, try enter again: ";
                    std::cin >> roomCount;
                }

                std::cout << "\n(Types cannot be repeated)\n"
                            << "Room type numbers:\n"
                            << std::string(15, '=') << std::endl 
                            << "1 - bedroom\n"
                            << "2 - kitchen\n"
                            << "4 - bathroom\n"
                            << "8 - childrenroom"
                            << "\n16 - livingroom\n"
                            << std::string(15, '=');

                for (int i = 1; i <= roomCount; i ++)
                {
                    room cur_room;
                    std::cout << std::endl << "Enter the " << i << " room type on your floor: ";
                    std::cin >> cur_room.roomType;

                    while(!is_ValidType(cur_room.roomType, cur_floor, cur_room)){
                        std::cout << std::endl << "Invalid room type, try enter again: ";
                        std::cin >> cur_room.roomType;
                    }

                    std::cout << std::endl << "Enter the square of current room: ";
                    std::cin >> cur_room.square;
                    cur_floor.rooms.push_back(cur_room);
                }
                cur_building_House.floors.push_back(cur_floor);
                //delete current floorInf
                cur_floor.ceilingHeight = 0;
                cur_floor.rooms.erase(cur_floor.rooms.begin(), cur_floor.rooms.end());
            }
            cur_territory.building_House = cur_building_House;
            //delete current house inf
            cur_building_House.chimneysStove = false;
            cur_building_House.floors.erase(cur_building_House.floors.begin(), cur_building_House.floors.end());
            cur_building_House.square = 0;
        }
        village.villageArea.push_back(cur_territory);
        //delete current territroy inf
        cur_territory.buildings = 0;
        cur_territory.name = "";
        cur_territory.square = 0;
    }
}
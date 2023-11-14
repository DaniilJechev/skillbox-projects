#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

struct bathHouse{
    int square;
    bool chimneyStove = false;
};


struct territoty
{
    std::string name;
    float square;
    int buildings = 0;  // this num will be changed using enum Bilding types. 
    // This num will determine which bildings present on territory and wich are not (which values I'll use)
    struct house building_House;
    struct bathHouse building_BathHouse;

    int garage_Square;
    int barn_Square;
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
        std::cout << std::endl << "Do you have a garage on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_garage;
            std::cout << std::endl << "Enter the square of your garage (m²): "; 
            std::cin >> cur_territory.garage_Square;
        }

        //bathHouse block
        bathHouse cur_bathHouse;
        std::cout << std::endl << "Do you have a bathHouse on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_buthHause;
            std::cout << std::endl << "Do you have a chimneys and stove into your bathHouse?(yes or no): ";
            std::cin >> answer;
            if (answer == "yes") cur_bathHouse.chimneyStove = true;
            std::cout << std::endl << "Enter the square of your bathHouse (m²): "; 
            std::cin >> cur_bathHouse.square;
            cur_territory.building_BathHouse = cur_bathHouse;
        }

        //barn block
        std::cout << std::endl << "Do you have a barn on your territory?(yes or no): ";
        std::cin >> answer;
        if (answer == "yes"){
            cur_territory.buildings += buildingTypes::is_barn;
            std::cout << std::endl << "Enter the square of your barn (m²): "; 
            std::cin >> cur_territory.barn_Square;
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

    // Start writing data
    std::ofstream file ("villageData.txt");
    file.setf(std::ios::boolalpha);
    bool temp;
    for (int i = 0; i < village.villageArea.size(); i ++){
        territoty* wr_Territroy = &village.villageArea[i];
        file << "Number of ground " << i + 1 << " - " << wr_Territroy->name << std::endl;
        
        temp = wr_Territroy->buildings & buildingTypes::is_barn; //Barn 
        file << "Barn = " << temp << '.';
        if (temp) file << " Square = " << wr_Territroy->barn_Square << std::endl;
            else file << std::endl;

        temp = wr_Territroy->buildings & buildingTypes::is_garage; //Garage 
        file << "Garage = " << temp << '.';
        if (temp) file << " Square = " << wr_Territroy->garage_Square << std::endl;
            else file << std::endl;

        temp = wr_Territroy->buildings & buildingTypes::is_buthHause; //BathHouse 
        file << "Bathhouse = " << temp << '.';
        if (temp){
            file << " Square = " << wr_Territroy->building_BathHouse.square;
            file << ". Chimneys and Stove = " << wr_Territroy->building_BathHouse.chimneyStove << std::endl;
        }else file << std::endl;
        
        temp = wr_Territroy->buildings & buildingTypes::is_house;  //House base inf
        file << "House = " << temp << '.';

        if(temp){
            file << " Square = " << wr_Territroy->building_House.square;
            file << ". Chimnyes and stove = " << wr_Territroy->building_House.chimneysStove << std::endl ;
            // Basic inf about home
            house* wr_House = &wr_Territroy->building_House;

            for (int i = 0; i < wr_House->floors.size(); i ++){
                floor* wr_Floor = &wr_House->floors[i];
                file << "---";
                file << std::endl << "Float " << i + 1 << ':' << std::endl;
                file << "Ceiling height = " << wr_Floor->ceilingHeight << std::endl;
                file << "Rooms: ";

                std::string string_rooms, temp;
                for (int i = 0; i < wr_Floor->rooms.size(); i ++){
                    if (wr_Floor->rooms[i].roomType & roomTypes::bathroom){
                        string_rooms += "buthroom ";
                    }else if (wr_Floor->rooms[i].roomType & roomTypes::bedroom){
                     string_rooms += "bedroom ";
                    }else if (wr_Floor->rooms[i].roomType & roomTypes::childrenRoom){
                        string_rooms += "childrenRoom ";
                    }else if (wr_Floor->rooms[i].roomType & roomTypes::kitchen){
                        string_rooms += "kitchen ";
                    }else if (wr_Floor->rooms[i].roomType & roomTypes::livingRoom) string_rooms += "livingRoom ";
                }
                
                std::stringstream stream_rooms (string_rooms); //I need stream to add the commas and dot into the string
                string_rooms = "";

                while (!stream_rooms.eof()){
                stream_rooms >> temp;
                temp.push_back(','), temp.push_back(' ');
                string_rooms += temp;
                temp = "";
                }
                string_rooms.erase(string_rooms.size() - 4);
                string_rooms.push_back('.');

                file << string_rooms << std::endl;

                string_rooms = "";
            }

        }else file << std::endl;
        if (i + 1 < village.villageArea.size()) file << std::endl << "========================" << std::endl;
    }
    file.close();
    // End
}
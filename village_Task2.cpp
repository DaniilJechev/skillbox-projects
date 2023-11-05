#include <iostream>
#include <fstream>
#include <sstream>

struct ground_Builds
{
    std::string groundNumber = "Not named";
    bool hause = false;
    bool garage = false;
    bool barn = false;
    bool buthHause = false;
    bool hause_chimneyStove = false;
    bool buthHause_chimneyStove = false;
};

struct ground_Square
{
    int general_area = 0;
    int hause = 0;
    int garage = 0;
    int barn = 0;
    int buthHouse = 0;
};

struct floor_Data
{
    int roomCount;
    int cellingHeight;
    int rooms_onFloor = 0;
};

enum roomTypes{
    bedroom = 1,
    kitchen = 2,
    bathroom = 4,
    childrenRoom = 8,
    livingRoom = 16
};

bool is_ValidType (int particularType)
{
    return (particularType == roomTypes::bedroom || particularType == roomTypes::kitchen 
    || particularType == roomTypes::bathroom || particularType == roomTypes:: childrenRoom 
    || particularType == roomTypes::livingRoom);
}

int main()
{
    int GroundesCount, floorsCount = 0;
    ground_Builds territory;
    ground_Square square;
    std::string answer;

    
    std::cout << "Enter the count of grounds in your village: ";
    std::cin >> GroundesCount;

    
    for (int i = 1; i <= GroundesCount; i ++){
        std::cout << std::endl << "You need enter the information about " << i << " ground" << std::endl;
        
        std::cout << "Enter the number of your ground: "; //home num
        std::cin >> territory.groundNumber;

        std::cout << std::endl << "Enter the square of all your territory (m²): "; //general square
        std::cin >> square.general_area;

        std::cout << std::endl << "Do you have a house on your territory?(yes or no): "; //availability of house
        std::cin >> answer;
        if (answer == "yes"){
            territory.hause = true;
            std::cout << std::endl << "Do you have a chimneys and stove into your house?(yes or no): "; 
            std::cin >> answer;
            if (answer == "yes") territory.hause_chimneyStove = true;

            std::cout << std::endl << "Enter the square of your house (m²): "; 
            std::cin >> square.hause;
        }
        
        std::cout << std::endl << "Do you have a garage on your territory?(yes or no): ";  //availability of garage
        std::cin >> answer;
        if (answer == "yes"){
            territory.garage = true;
            std::cout << std::endl << "Enter the square of your garage (m²): "; 
            std::cin >> square.garage;
        }

        std::cout << std::endl << "Do you have a barn on your territory?(yes or no): ";  //availability of garage
        std::cin >> answer;
        if (answer == "yes") {
            territory.barn = true;
            std::cout << std::endl << "Enter the square of your barn (m²): "; 
            std::cin >> square.barn;
        }
        
        std::cout << std::endl << "Do you have a buthHouse on your territory?(yes or no): ";  //availability of buthHouse
        std::cin >> answer;
        if (answer == "yes"){
            territory.buthHause = true;
            std::cout << std::endl << "Do you have a chimneys and stove into your buthHouse?(yes or no): ";
            std::cin >> answer;
            if (answer == "yes") territory.buthHause_chimneyStove = true;
            std::cout << std::endl << "Enter the square of your buthHouse (m²): "; 
            std::cin >> square.buthHouse;
        }
        
        //Writing of all known data into the file on this moment
        std::ofstream data ("villageData.txt", std::ios::app);
        data.setf(std::ios::boolalpha);
        data << "\nGround number is "<< territory.groundNumber << std::endl;

        data << "House = " << territory.hause;
        if (territory.hause){
            data << ". Square = " << square.hause;
            if (territory.hause_chimneyStove){
                data << ". Chimney and stove = " << territory.hause_chimneyStove << std::endl;
            }else data << std::endl;
        }

        data << "Garage = " << territory.garage << ". Square = " << square.garage << std::endl;
        data << "barn = " << territory.barn << ". Square = " << square.barn << std::endl;

        data << "Buthhouse = " << territory.buthHause;
        if (territory.buthHause){
            data << ". Square = " << square.buthHouse;
            if(territory.buthHause_chimneyStove){
                data << ". Chimney and stove = " << territory.buthHause_chimneyStove << std::endl;
            }else data << std::endl;
        }
        data.close();
        //End of writing

        if (territory.hause){
            std::cout << std::endl << "Enter the count of floors into your hause: ";
            std::cin >> floorsCount;
            while(floorsCount < 0 || floorsCount > 4){
                std::cout << std::endl << "Invalid number, try enter again: ";
                std::cin >> floorsCount;
            }
            
            std::ofstream floorInf ("villageData.txt", std::ios::app);
            floorInf << "HAUSE" << std::endl;
            floorInf << "Count of floors in this house = " << floorsCount << std::endl;

            floor_Data floor;
            int rooms_onFloor = 0, particularRoom;

            for (int i = 0; i < floorsCount; i ++ ){
                floorInf << std::string (10, '-') << std::endl << i + 1 << " floor:" << std::endl; 
                std::cout << std::endl << "Now u need to explain the parameters on the " << i + 1 << " floor";

                std::cout << std::endl << "Enter celling height ";
                std::cin >> floor.cellingHeight;

                std::cout << std::endl << "Enter the room count: ";
                std::cin >> floor.roomCount;
                while(floor.roomCount < 1 || floor.roomCount > 4){
                    std::cout << std::endl << "Invalid count, try enter again: ";
                    std::cin >> floor.roomCount;
                }

                // star writing
                floorInf << "Celling heigh = " << floor.cellingHeight << std::endl;
                floorInf << "Room Count = " << floor.roomCount << std::endl << "Rooms: ";
                //end writing

                std::cout << std::endl << "Types cannot be repeated" <<  std::endl << "Room type numbers:" << std::endl;
                std::cout << std::string(15, '=') << std::endl;
                std::cout <<  "1 - bedroom\n2 - kitchen\n4 - bathroom\n8 - childrenroom\n16 - livingroom" << std::endl;
                std::cout << std::string(15, '=');

                for (int i = 0; i < floor.roomCount; i ++)
                {
                    std::cout << std::endl << "Enter the " << i + 1 << " room type on your floor: ";
                    std::cin >> particularRoom;

                    while(!is_ValidType(particularRoom) || particularRoom & floor.rooms_onFloor){
                        std::cout << std::endl << "Invalid room type, try enter again: ";
                        std::cin >> particularRoom;
                    }

                    floor.rooms_onFloor += particularRoom;
                }

                // writing the rooms into the data file
                std::string string_rooms, temp;
                if (floor.rooms_onFloor & roomTypes::bathroom) string_rooms += "buthroom ";
                if (floor.rooms_onFloor & roomTypes::bedroom) string_rooms += "bedroom ";
                if (floor.rooms_onFloor & roomTypes::childrenRoom) string_rooms += "childrenRoom ";
                if (floor.rooms_onFloor & roomTypes::kitchen) string_rooms += "kitchen ";
                if (floor.rooms_onFloor & roomTypes::livingRoom) string_rooms += "livingRoom ";

                std::stringstream stream_rooms (string_rooms); //I need stream to add the commas and dot into the string
                string_rooms = "";

                while (!stream_rooms.eof()){
                    stream_rooms >> temp;
                    temp.push_back(','), temp.push_back(' ');
                    string_rooms += temp;
                    temp = "";
                }
                string_rooms.erase(string_rooms.size() - 4);
                string_rooms.push_back('.'), string_rooms.push_back('\n');

                floorInf << string_rooms;

                string_rooms = "";
                //end of writing

                floor.cellingHeight = 0;
                floor.roomCount = 0;
                floor.rooms_onFloor = 0;
            }
            floorInf << std::endl << std::string (50, '=');
            floorInf.close();
        }

    }

}
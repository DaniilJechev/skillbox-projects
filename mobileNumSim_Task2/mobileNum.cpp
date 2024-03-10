#include <iostream>
#include <vector>

using namespace std;

class Number{
    string number;
    string owner;

  public:
    static bool is_correct(string& number){
        if (number[0] == '+' && number.size() == 12){
            for (int i = 1; i < number.size(); i ++){
                if (number[i] < '0' || number[i] > '9') return false;
            }
            return true;
        }else return false;
    }

    void setNum(string& value){
        number = value;
    }

    string getNum(){
        return number;
    }

    void setOwner(string& value){
        owner = value;
    }

    string getOwner(){
        return owner;
    }
};


class Phone{
    vector<Number> addressBook;

//  private:
//    bool is_number_into(string& number){
//        for (Number& i : addressBook){
//            if (i.getNum() == number) return true;
//        }
//        return false;
//    }
//
//    bool is_owner_into(string& owner){
//        for (Number& i : addressBook){
//            if (i.getOwner() == owner) return true;
//        }
//        return false;
//    }
//
//    Number getNumber(string& value){
//        for (Number& i : addressBook){
//            if (i.getOwner() == value || i.getNum() == value) return i;
//        }
//    }

  public:
    void add(){
        Number curNum;
        string owner, number;

        cout << "\nEnter the name of number owner: ";
        cin >> owner;
        curNum.setOwner(owner);

        cout << "\nEnter number: ";
        while (true){
            cin >> number;
            if (!Number::is_correct(number)){
                cout << "\nNumber is incorrect.\n"
                        "Enter new number: ";
            }else break;
        }
        curNum.setNum(number);

        addressBook.push_back(curNum);
        cout << "\nContact added successfully\n";
    }

    void call(){
        string input;
        cout << "\nEnter the name or number of person you want to call: ";
        cin >> input;

        for (Number i : addressBook){
            if (i.getNum() == input || i.getOwner() == input){
                cout << "\nCALL: " << i.getNum() << endl;
                return;
            }
        }
        cout << "\nNo number and name in address book\n";
    }

    void sms(){
        string input;
        cout << "\nEnter the name or number of person you want to text: ";
        cin >> input;

        bool is_find = false;
        for (Number i : addressBook){
            if (i.getNum() == input || i.getOwner() == input){
                is_find = true;
                break;
            }
        }
        if (is_find){
            cout << "\nWrite message: ";
            cin.ignore();
            getline(cin, input);
            cout << "\nMessage sent successfully\n";
        }else cout << "\nNo number and name in address book\n";
    }
};

int main()
{
    string input;
    Phone* phone = new Phone();

    while (true){
        cout << "\nEnter the command: ";
        cin >> input;

        if (input == "add"){
            phone->add();
        }else if (input == "call"){
            phone->call();
        }else if (input == "sms"){
            phone->sms();
        }else if (input == "exit"){
            break;
        }else cout << "\nIncorrect command\n";
    }

    delete phone;
}
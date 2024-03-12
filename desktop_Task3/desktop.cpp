#include <iostream>

using namespace std;

struct dimensions{
    int width;
    int height;
};


class Window{
    dimensions winSize = {10, 10};
    pair <int, int> pos = make_pair(0, 50);

  private:
    bool is_acceptableSize(dimensions& size) const{
        return (size.width > 0 && size.width <= 80 - pos.first
            && size.height > 0 && size.height <= pos.second);
    }

    static bool is_acceptablePos(pair<int, int>& pos){
        return (pos.first >= 0 && pos.first <= 80
                && pos.second >= 0 && pos.second <= 50);
    }

    void setSize(dimensions& value){
        winSize = value;
    }

    void setPos(pair <int, int>& value){
        pos = value;
    }

  public:
    [[nodiscard]] dimensions getSize() const{
        return winSize;
    }

    [[nodiscard]] pair<int, int> getPos() const{
        return pos;
    }

    void resize(){
        dimensions newSize = {};
        cout << "\nEnter the newSize width and height: ";
        cin >> newSize.width >> newSize.height;
        if (is_acceptableSize(newSize)){
            setSize(newSize);
            cout << "\nScreen dimensions changed successfully\n";
            return;
        }cout << "\nIncorrect width or height\n";

    }

    void move (){
        pair <int, int> newWinPos = {};
        cout << "\nEnter new x and y coords: ";
        cin >> newWinPos.first >> newWinPos.second;
        if (is_acceptablePos(newWinPos)) {
            setPos(newWinPos);
            cout << "\nScreen moved to " << pos.first << ':' << pos.second << endl;
        }else cout << "\nIncorrect pos\n";
    }
};


class DeskTop{
    dimensions const deskTop = {80, 50};
    Window window;

public:
    void display() const{
        for (int i = deskTop.height; i >= -1; i --){
            for (int j = -1; j <= deskTop.width; j ++){
                if (i == -1 || i == deskTop.height) cout << '-';
                else if (j == -1 || j == deskTop.width) cout << '|';
                else if (i >= window.getPos().second - window.getSize().height
                      && i <= window.getPos().second
                      && j < window.getPos().first + window.getSize().width
                      && j >= window.getPos().first) cout << '1';
                else cout << '0';
            }
            cout << endl;
        }
    }

    void useMove(){
        window.move();
    }

    void useResize(){
        window.resize();
    }
};

int main()
{
    DeskTop* deskTop = new DeskTop();
    string input;
    while (true){
        cout << "\nEnter command: ";
        cin >> input;
        if (input == "move"){
            deskTop->useMove();
        }else if (input == "resize"){
            deskTop->useResize();
        }else if (input == "display"){
            deskTop->display();
        }else if (input == "close"){
            break;
        }else cout << "\nIncorrect command\n";
    }

    delete deskTop;
}
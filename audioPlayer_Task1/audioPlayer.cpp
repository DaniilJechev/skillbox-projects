#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class Track
{
    string name;
    int duration;
    tm release;

  public:
    void setName(string& value)
    {
        name = value;
    }

    void setRelease(tm value)
    {
        release = value;
    }

    void setDuration(int value)
    {
        duration = value;
    }

    string getName()
    {
        return name;
    }

    tm getRelease(){
        return release;
    }

    int getDuration()
    {
        return duration;
    }
};


class Player {
    Track allTracks[10];
    string curTrack;
    bool is_paused = false;

  private:
    bool is_availableTrack(string& name)
    {
        for (int i = 0; i < 10; i ++){
            if (allTracks[i].getName() == name) return true;
        }
        return false;
    }

    static void randRelease(tm* release){
        release->tm_year = rand() % 125;
        release->tm_yday = rand() % 365;
        release->tm_mon = rand() % 12;
        release->tm_mday = rand() % 30;
        mktime(release);
    }

  public:
    void setAllTracks() {
        string name = "track0";
        int duration;
        tm release;
        for (int i = 0; i < 10; i++) {
            name.pop_back();
            name.push_back(i + '0');
            allTracks[i].setName(name);

            randRelease(&release);
            allTracks[i].setRelease(release);

            duration = 50 + rand() % 200;
            allTracks[i].setDuration(duration);
        }
    }

    void play(string name)
    {
        if (name == curTrack){
            cout << "\nTrack is playing now\n";
            return;
        }else if (!is_availableTrack(name)){
                cout << "\nTrack not found\n";
        }else{
            curTrack = name;
            is_paused = false;
            int trackNum = atoi(&name[name.size() - 1]);
            tm release = allTracks[trackNum].getRelease();
            int duration = allTracks[trackNum].getDuration();

            cout << '\n' << "name: " << name << endl
                << put_time(&release, "release date(day:month:year): %d:%m:%Y") << endl
                << "duration: " << duration / 60 << ':' << duration % 60 << endl;
        }
    }

    void pause()
    {
        if (!curTrack.empty() && !is_paused) {
            cout << "\nsong is paused\n";
        }else cout << "\nnothing to pause\n";
        is_paused = true;
    }

    void continueTrack()
    {
        if (!curTrack.empty() && is_paused){
            cout << "\nsong continues\n";
        }else cout << "\nnothing to continue\n";
        is_paused = false;
    }

    void next()
    {
        string newTrack = "track0"; // mistake
        do{
            newTrack.pop_back();
            newTrack.push_back(rand() % 10 + '0');
        }while (newTrack == curTrack);
        play(newTrack);
    }

    void stop()
    {
        if (!curTrack.empty()) {
            cout << "\nsong is stopped\n";
        }else cout << "\nnothing to stop\n";
        curTrack = "";
    }
};

int main()
{
    srand(time(nullptr));
    Player* player = new Player();
    player->setAllTracks();
    string input = "";

    while (input != "exit"){
        cout << "\nEnter command: ";
        cin >> input;
        if (input == "play"){
            cout << "\nEnter song name: ";
            cin >> input;
            player->play(input);
        }else if(input == "pause") {
            player->pause();
        }else if (input == "continue"){
            player->continueTrack();
        }else if (input == "next"){
            player->next();
        }else if (input == "stop"){
            player->stop();
        }else cout << "\nWrong command\n";
    }

    delete player;
    player = nullptr;
}
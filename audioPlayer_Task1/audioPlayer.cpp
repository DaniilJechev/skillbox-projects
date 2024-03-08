#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Track
{
    string name;
    tm duration;
    tm release;

  public:
    void setName(string value)
    {
        name = value;
    }

    void setRelease(tm value)
    {
        release = value;
    }

    void setDuration(tm value)
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

    tm getDuration()
    {
        return duration;
    }
};


class Player {
    Track allTracks[10];
    string curTrack = "";
    bool is_paused = false;

  private:
    bool is_avaliableTrack(string name)
    {
        for (int i = 0; i < 10; i ++){
            if (allTracks[i].getName() == name) return true;
        }
        return false;
    }

  public:
    void setAllTracks() {
        string name = "track";
        tm duration;
        tm release;
        for (int i = 0; i < 10; i++) {
            name.push_back(i + '0');
            allTracks[i].setName(name);
            name.pop_back();

            release.tm_year = 100 + rand() % 25;
            release.tm_yday = rand() % 365;
            mktime(&release);
            allTracks[i].setRelease(release);

            duration.tm_min = rand() % 4;
            duration.tm_sec = rand() % 60;
            allTracks[i].setDuration(duration);
        }
    }

    void play(string name)
    {
        if (name == curTrack){
            cout << "\nTrack is playing now\n";
            return;
        }else if (!is_avaliableTrack(name)){
                cout << "\nTrack not found\n";
        }else{
            curTrack = name;
            is_paused = false;
            int trackNum = atoi(&name[name.size() - 1]);
            tm release = allTracks[trackNum].getRelease();
            tm duration = allTracks[trackNum].getDuration();

            cout << '\n' << "name: " << name << endl
                << put_time(&release, "release date: %d:%m:%y") << endl
                << put_time(&duration, "duration: %M:%S") << endl;
        }
    }

    void pause()
    {
        if (curTrack != "" && !is_paused) {
            cout << "\nsong is paused\n";
        }
        is_paused = true;
    }

    void continueTrack()
    {
        if (curTrack != "" && is_paused){
            cout << "\nsong continues\n";
        }
        is_paused = false;
    }

    void next()
    {
        string newTrack = "Track0";
        do{
            newTrack.pop_back();
            newTrack.push_back(rand() % 10 + '0');
        }while (newTrack == curTrack);
        curTrack = newTrack;
        play(curTrack);
    }

    void stop()
    {
        if (curTrack != "") {
            cout << "\nsong is stoped\n";
        }
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
// add operation "continue"

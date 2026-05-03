//Kursova rabota 253044 #24
#include <iostream>
#include <string>
using namespace std;



class Toy {
protected:
    string name;
    int productionYear;

public:
    Toy(string n, int y) : name(n), productionYear(y) {}
    Toy(int y) : name("Standard Toy"), productionYear(y) {}

    virtual ~Toy() = default;
    virtual void printInfo() const = 0;
    virtual void specialAction() = 0;
    void celebrateAnniversary() const {
        cout << name << " // " << (2026 - productionYear) << " years of service" << endl;
    }
};



class EducationalToy : public Toy {
protected:
    string subject;
    int numLessons;

public:
    EducationalToy(string n, int y, string sub, int nl) : Toy(n, y), subject(sub), numLessons(nl) {}
    EducationalToy(string sub) : Toy(1960), subject(sub), numLessons(80) {}

    void printInfo() const override {
        cout << name << " | Subject: " << subject << endl;
    }

    void trainPilots() const { cout << name << " trains Russian Pilots." << endl; }
    void conductLesson() const { cout << "Conducting lesson on " << subject << endl; }
    void specialAction() override { trainPilots(); }
};

class EntertainmentToy : public Toy {
protected:
    string theme;
    bool reinforced;

public:
    EntertainmentToy(string n, int y, string th, bool reinf) : Toy(n, y), theme(th), reinforced(reinf) {}
    EntertainmentToy(string th) : Toy(1960), theme(th), reinforced(true) {}

    void printInfo() const override {
        cout << name << " | Theme: " << theme << endl;
    }

    void conquerUniverse() { cout << name << " conquers the Universe." << endl; }
    void March() const { cout << "Marching into the Sky: " << name << "." << endl; }
    void specialAction() override { conquerUniverse(); }
};



class Puzzle : public EducationalToy {
protected:
    string difficulty;

public:
    Puzzle(string n, int y, string sub, int nl, string diff)
        : EducationalToy(n, y, sub, nl), difficulty(diff) {
    }
    Puzzle(string diff) : EducationalToy("Tetris"), difficulty(diff) {}

    void printInfo() const override {
        EducationalToy::printInfo();
        cout << "Difficulty: " << difficulty << endl;
    }

    void assemblePuzzle() { cout << "Assembling " << name << endl; }
    void achieveHighScore() const { cout << "High Score achieved on " << name << "." << endl; }
    void specialAction() override { achieveHighScore(); }
};

class ActionFigure : public EntertainmentToy {
protected:
    string heroName;
    string achievement;

public:
    ActionFigure(string n, int y, string th, bool reinf, string hn, string ach)
        : EntertainmentToy(n, y, th, reinf), heroName(hn), achievement(ach) {
    }
    ActionFigure(string hn) : EntertainmentToy("Action Figure"), heroName(hn), achievement("Hero") {}

    void printInfo() const override {
        EntertainmentToy::printInfo();
        cout << "Hero: " << heroName << endl;
    }

    void performsFirstSpaceflight() { cout << heroName << " performs First Spaceflight!" << endl; }
    void inspirePioneers() const { cout << "The Inspirator of Airforce Pioneers, " << heroName << "." << endl; }
    void specialAction() override { inspirePioneers(); }
};



class MiG31 : public EducationalToy {
protected:
    string role;

public:
    MiG31(string n, int y, string sub, int nl, string r)
        : EducationalToy(n, y, sub, nl), role(r) {
    }
    MiG31(string r) : EducationalToy("MiG-31"), role(r) {}

    void printInfo() const override {
        EducationalToy::printInfo();
        cout << "Role: " << role << endl;
    }

    void scramble() { cout << name << " scrambles to intercept target!" << endl; }
    void patrolSky() const { cout << name << " patrols Moscow Skies." << endl; }
    void specialAction() override { patrolSky(); }
};

class Vostok1 : public ActionFigure {
protected:
    string missionName;

public:
    Vostok1(string n, int y, string th, bool reinf, string hn, string ach, string miss)
        : ActionFigure(n, y, th, reinf, hn, ach), missionName(miss) {
    }
    Vostok1(string miss) : ActionFigure("Yuri Gagarin"), missionName(miss) {}

    void printInfo() const override {
        ActionFigure::printInfo();
        cout << "Mission: " << missionName << endl;
    }

    void launchIntoOrbit() { cout << "April 12, 1961: " << missionName << " launches into Space." << endl; }
    void returnToEarth() const { cout << missionName << " returned successfully!" << endl; }
    void specialAction() override { launchIntoOrbit(); }
};

int main() {
    cout << "============================================= KURSOVA RABOTA 253044 #24 ============================================\n\n";

    const int SIZE = 6;
    Toy* toys[SIZE];

    toys[0] = new Puzzle("Tetris", 1984, "Logic", 250, "Expert");
    toys[1] = new ActionFigure("Yuri Gagarin", 1965, "Space", true, "Yuri Gagarin", "First Human in Space");
    toys[2] = new EducationalToy("MiG-31 Simulator", 1981, "Military Aviation", 95);
    toys[3] = new EntertainmentToy("Vostok 1", 1961, "Space Conquest", true);
    toys[4] = new MiG31("MiG-31", 1981, "Interceptor", 110, "Air Defense");
    toys[5] = new Vostok1("Vostok Capsule", 1961, "Manned Spaceflight", true, "Yuri Gagarin", "Orbit", "Vostok 1");

    for (int i = 0; i < SIZE; i++) {
        cout << "Object Number " << (i + 1) << ":" << endl;
        toys[i]->printInfo();
        toys[i]->celebrateAnniversary();
        toys[i]->specialAction();           
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        delete toys[i];
    }

    cout << "\nProgram completed." << endl;
    return 0;
}
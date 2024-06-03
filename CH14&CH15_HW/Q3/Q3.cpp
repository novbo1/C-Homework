#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

namespace cs_creature {

    class Creature {
    private:
        int strength;           // how much damage this creature inflicts
        int hitpoints;          // how much damage this creature can sustain

    public:
        Creature() : strength(10), hitpoints(10) {}

        Creature(int newStrength, int newHitpoints)
            : strength(newStrength), hitpoints(newHitpoints) {}

        int getStrength() const { return strength; }
        int getHitpoints() const { return hitpoints; }

        int getDamage() const {
            int damage = (rand() % strength) + 1;
            cout << getSpecies() << " attacks for " << damage << " points!" << endl;
            return damage;
        }

        virtual string getSpecies() const { return "Creature"; }
    };

    class Human : public Creature {
    public:
        Human() : Creature() {}
        Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

        string getSpecies() const { return "Human"; }
    };

    class Elf : public Creature {
    public:
        Elf() : Creature() {}
        Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

        string getSpecies() const { return "Elf"; }

        int getDamage() const {
            int damage = Creature::getDamage();
            if ((rand() % 2) == 0) {
                cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
                damage *= 2;
            }
            return damage;
        }
    };

    class Demon : public Creature {
    public:
        Demon() : Creature() {}
        Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

        string getSpecies() const { return "Demon"; }

        int getDamage() const {
            int damage = Creature::getDamage();
            if (rand() % 4 == 0) {
                damage += 50;
                cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            }
            return damage;
        }
    };

    class Cyberdemon : public Demon {
    public:
        Cyberdemon() : Demon() {}
        Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

        string getSpecies() const { return "Cyberdemon"; }
    };

    class Balrog : public Demon {
    public:
        Balrog() : Demon() {}
        Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

        string getSpecies() const { return "Balrog"; }

        int getDamage() const {
            int damage = Demon::getDamage();
            int damage2 = (rand() % getStrength()) + 1;
            cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
            return damage + damage2;
        }
    };
} // namespace cs_creature

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cs_creature::Human h1;
    cs_creature::Elf e1;
    cs_creature::Cyberdemon c1;
    cs_creature::Balrog b1;

    cs_creature::Human h(20, 30);
    cs_creature::Elf e(40, 50);
    cs_creature::Cyberdemon c(60, 70);
    cs_creature::Balrog b(80, 90);

    cout << "default human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    cout << "default elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    cout << "non-default human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;

    cout << "Examples of human damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl << endl;
    }

    cout << "Examples of elf damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl << endl;
    }

    cout << "Examples of cyberdemon damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl << endl;
    }

    cout << "Examples of balrog damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl << endl;
    }

    return 0;
}

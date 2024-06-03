#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace cs_creature {

    class creature {
    private:
        int strength;
        int hitpoints;

    public:
        creature() : strength(10), hitpoints(10) {}
        creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}

        int getStrength() const { return strength; }
        int getHitpoints() const { return hitpoints; }
        void setStrength(int newStrength) { strength = newStrength; }
        void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

        string getSpecies() const { return "Creature"; }

        int getDamage() const {
            int damage = (rand() % strength) + 1;
            return damage;
        }
    };

    class demon : public creature {
    public:
        demon() : creature() {}
        demon(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints) {}

        int getDamage() const {
            int damage = creature::getDamage();
            cout << " attacks for " << damage << " points!" << endl;

            if (rand() % 4 == 0) {
                damage += 50;
                cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            }

            return damage;
        }
    };

    class human : public creature {
    public:
        human() : creature() {}
        human(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints) {}

        string getSpecies() const { return "Human"; }

        int getDamage() const {
            int damage = creature::getDamage();
            cout << "The human";
            damage = creature::getDamage();
            cout << " attacks for " << damage << " points!" << endl;
            return damage;
        }
    };

    class elf : public creature {
    public:
        elf() : creature() {}
        elf(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints) {}

        string getSpecies() const { return "Elf"; }

        int getDamage() const {
            int damage = creature::getDamage();
            cout << "The elf";
            if (rand() % 2 == 0) {
                cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
                damage *= 2;
            }
            cout << " attacks for " << damage << " points!" << endl;
            return damage;
        }
    };

    class cyberdemon : public demon {
    public:
        cyberdemon() : demon() {}
        cyberdemon(int newStrength, int newHitpoints) : demon(newStrength, newHitpoints) {}

        string getSpecies() const { return "Cyberdemon"; }

        int getDamage() const {
            cout << "The cyberdemon";
            return demon::getDamage();
        }
    };

    class balrog : public demon {
    public:
        balrog() : demon() {}
        balrog(int newStrength, int newHitpoints) : demon(newStrength, newHitpoints) {}

        string getSpecies() const { return "Balrog"; }

        int getDamage() const {
            cout << "The balrog";
            int damage = demon::getDamage();
            int damage2 = (rand() % getStrength()) + 1;
            cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
            damage += damage2;
            return damage;
        }
    };

}

int main() {
    srand(time(0));

    cs_creature::human h1;
    cs_creature::elf e1;
    cs_creature::cyberdemon c1;
    cs_creature::balrog b1;

    cs_creature::human h(20, 30);
    cs_creature::elf e(40, 50);
    cs_creature::cyberdemon c(60, 70);
    cs_creature::balrog b(80, 90);


    cout << "default human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    cout << "default elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    cout << "non-default human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    cout << "non-default cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    cout << "non-default balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    return 0;
}

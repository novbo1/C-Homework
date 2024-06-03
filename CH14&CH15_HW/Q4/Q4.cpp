#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace cs_creature {

    class Creature {
    private:
        int strength;       // how much damage this creature inflicts
        int hitpoints;      // how much damage this creature can sustain

    public:
        // Constructors
        Creature() : strength(10), hitpoints(10) {}
        Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}

        // Accessors
        int getStrength() const { return strength; }
        int getHitpoints() const { return hitpoints; }
        void setStrength(int newStrength) { strength = newStrength; }
        void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

        // Virtual functions
        virtual string getSpecies() const { return "Creature"; }
        virtual int getDamage() const;

    };

    class Human : public Creature {
    public:
        // Constructors
        Human() : Creature() {}
        Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

        // Overrides
        string getSpecies() const override { return "Human"; }
        int getDamage() const override;

    };

    class Elf : public Creature {
    public:
        // Constructors
        Elf() : Creature() {}
        Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

        // Overrides
        string getSpecies() const override { return "Elf"; }
        int getDamage() const override;

    };

    class Demon : public Creature {
    public:
        // Constructors
        Demon() : Creature() {}
        Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}

        // Overrides
        string getSpecies() const override { return "Demon"; }
        int getDamage() const override;

    };

    class Cyberdemon : public Demon {
    public:
        // Constructors
        Cyberdemon() : Demon() {}
        Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

        // Overrides
        string getSpecies() const override { return "Cyberdemon"; }
        int getDamage() const override;

    };

    class Balrog : public Demon {
    public:
        // Constructors
        Balrog() : Demon() {}
        Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}

        // Overrides
        string getSpecies() const override { return "Balrog"; }
        int getDamage() const override;

    };

    int Creature::getDamage() const {
        int damage = (rand() % strength) + 1;
        return damage;
    }

    int Human::getDamage() const {
        int damage = Creature::getDamage();
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }

    int Elf::getDamage() const {
        int damage = Creature::getDamage();
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        if (rand() % 2 == 0) {
            damage *= 2;
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        }
        return damage;
    }

    int Demon::getDamage() const {
        int damage = Creature::getDamage();
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        if (rand() % 4 == 0) {
            damage += 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }

    int Cyberdemon::getDamage() const {
        cout << "The " << getSpecies() << " attacks for ";
        return Demon::getDamage();
    }

    int Balrog::getDamage() const {
        int damage = Demon::getDamage();
        int damage2 = (rand() % Creature::getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
}

int main() {
    using namespace cs_creature;
    srand(time(0));

    Human h1;
    Elf e1;
    Cyberdemon c1;
    Balrog b1;

    Human h(20, 30);
    Elf e(40, 50);
    Cyberdemon c(60, 70);
    Balrog b(80, 90);

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

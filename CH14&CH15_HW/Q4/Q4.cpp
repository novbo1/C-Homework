#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace gameCreatures
{
	class creature
	{
	public:
		//Constructors
		creature() : strength(10), hitpoints(10) {}  //base
		creature(int strength ,int hitpoints) : strength(strength) , hitpoints(hitpoints) {}

		//Accessor & Mutator
		
		//To get private stats
		int getStrength() { return strength; }
		int getHitpoints() { return hitpoints; }
		
		//To set private stats
		void setStrength(int newStrength) { strength = newStrength; }
		void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

		//Virtual function 
		virtual string getSpecies() const { return "Creature"; }
		virtual int getDamage() const
		{
			// 0 < damage <= strength
			return (rand() % strength + 1);
		}

	private:
		//base stats
		int strength;
		int hitpoints;
	};

	/*  The rest classes doesn't need to write private, 
	since the creature(base class) already has it.  */
	class human : public creature
	{
	public:
		//Constructor for human
		human() : creature() {}
		human(int strength,int hitpoint) : creature(strength,hitpoint) {}

		//Overrides the virtual function
		string getSpecies() const override { return "Human"; }
		int getDamage() const override
		{
			//Human does same damage as creature
			int damage = creature::getDamage();
			cout << getSpecies() << " attacks for " << damage << " points!" << endl;
			return damage;
		}
	};

	class elf : public creature
	{
	public:
		//Constructor for elf
		elf() : creature() {}
		elf(int strength, int hitpoint) : creature(strength, hitpoint) {}

		//Overrides the virtual function
		string getSpecies() const override { return "Elf"; }
		int getDamage() const override
		{
			//basic
			int damage = creature::getDamage();
			cout << getSpecies() << " attacks for " << damage << " points!" << endl;
			//if meet requirement
			if (rand() % 10 == 0)
			{
				cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
				damage *= 2;
			}
			return damage;
		}
	};

	class demon : public creature
	{
	public:
		//Constructor for demon
		demon() : creature() {}
		demon(int strength, int hitpoint) : creature(strength, hitpoint) {}

		string getSpecies() const override { return "Demon"; }
		int getDamage() const override
		{
			//basic
			int damage = creature::getDamage();
			cout << getSpecies() << " attacks for " << damage << " points!" << endl;
			//if meet requirement
			if (rand() % 100 <5)
			{
				cout << "Demonic attack inflicts 50 additional damage points!" << endl;
				damage += 50;
			}
			return damage;
		}
	};

	class cyberDemon : public demon
	{
	public:
		//Constructor for Cyberdemon
		cyberDemon() : demon() {}
		cyberDemon(int strength, int hitpoint) : demon(strength, hitpoint) {}

		string getSpecies() const override { return "Cyberdemon"; }
		int getDamage() const override
		{
			int damage = demon::getDamage();
			cout << getSpecies() << " attacks for " << damage << " points!" << endl;

			return damage;
		}
	};

	class balrog : public demon
	{
	public:
		//Constructor for balrog
		balrog() : demon() {}
		balrog(int strength, int hitpoint) : demon(strength, hitpoint) {}

		string getSpecies() const override { return "balrog"; }
		int getDamage() const override
		{
			int damage1 = demon::getDamage();
			cout << getSpecies() << " attacks for " << damage1 << " points!" << endl;
			int damage2 = demon::getDamage();
			cout << getSpecies() << " speed attack inflicts " << damage2 << " additional damage points!" << endl;
			int damage;
			damage = damage1 + damage2;
			return damage;
		}
	};
}
using namespace gameCreatures;

void battleArena(creature&, creature&);

int main()
{
	//to setup rand
	srand(time(NULL));

	//declaration
	human h1;
	elf e1;
	balrog b1;
	cyberDemon c1;

	//test functions
	battleArena(h1, e1);
	battleArena(b1, c1);

	return 0;
}

void battleArena(creature& creature1, creature& creature2)
{
	int c1hP, c2hP, c1str, c2str;
	while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0)
	{
		c1hP = creature1.getHitpoints();
		c2hP = creature2.getHitpoints();

		cout << "Creature1 currently has " << c1hP << " hitpoints!" << endl;
		cout << "Creature2 currently has " << c2hP << " hitpoints!" << endl;

		c1str = creature1.getDamage();
		c2hP -= c1str;
		creature2.setHitpoints(c2hP);
		cout << "Creature2 now has " << c2hP << " hitpoints!" << endl;

		c2str = creature2.getDamage();
		c1hP -= c2str;
		creature1.setHitpoints(c1hP);
		cout << "Creature1 now has " << c1hP << " hitpoints!" << endl;
		cout << endl;
	}
	if (c1hP > 0 || c2hP > 0)
	{
		if (c1hP > c2hP)
		{
			cout << "Creature1 won the battle.\n" << endl;
		}
		else if (c1hP < c2hP)
		{
			cout << "Creature2 won the battle.\n" << endl;
		}
		else
		{
			cout << "Tie.\n" << endl;
		}
	}
	else
	{
		cout << "Tie.\n" << endl;
	}
}
	
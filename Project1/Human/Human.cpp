#include <iostream>
#include <string>
using namespace std;

void swap(int* a, int* b) {
	int* tmp = a;
	a = b;
	b = tmp;
}


class Character {
protected:
	string name;
	int hp;
	int attack;
	int weapon;
	friend class Warrior;
	friend class Dodger;

public:
	friend void swap(Character& a, Character& b);
	Character() = default;

	Character(string _name, int _hp, int _attack, int _weapon) : name(_name), hp(_hp), attack(_attack), weapon(_weapon){}

	Character(const Character& hum) {
		name = hum.name;
		hp = hum.hp;
		attack = hum.attack;
		weapon = hum.weapon;
	}
	
	//Character operator=(const Character& hum) {
	//	if (this != &hum) {
	//		Character tmp(hum);
	//		this->swap(tmp);
	//	}
	//	return *this;
	//}

	Character operator+(const Character& hum) {
		Character res(*this);
		res = res + hum;
		return res;
	}

	bool operator<(const Character& hum) {
		Character res(*this);
		if (res < hum) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(const Character& hum) {
		Character res(*this);
		if (res > hum) {
			return true;
		}
		else {
			return false;
		}
	}

	Character Attack(const Character& enemy) {
		Character result;
		result.hp = enemy.hp; 
		result.hp = result.hp - attack - weapon;
		return result;
	}

	void setAttack(int _attack) {
		attack = _attack;
	}

	int getAttack() {
		return attack;
	}
	int getWeapon() {
		return weapon;
	}
	int getHp() {
		return hp;
	}
	string getName() {
		return name;
	}
};


ostream& operator<<(ostream& out, Character hum)
{
	out << hum.getName() << hum.getHp() << hum.getAttack() << hum.getWeapon();
	return out;
}
bool operator==(Character hum, Character hum1) 
{
	return (hum.getAttack() == hum1.getAttack() && hum.getHp() == hum1.getHp() &&
		hum.getWeapon() == hum1.getWeapon());
}


class Warrior : Character {
protected:
	int armor;
public:

	Warrior() = default;

	Warrior(string _name, int _hp, int _attack, int _weapon,  int _armor) : Character(_name, _hp, _attack, _weapon), armor(_armor) {}

	Warrior(const Warrior& war) : Character(war.name, war.hp, war.attack, war.weapon) {
		armor = war.armor;
		name = war.name;
		hp = war.hp;
		weapon = war.weapon;
		attack = war.attack;
	}

	Warrior GetDamage(const Warrior& enemy) {
		Warrior result;
		int damage = enemy.attack + enemy.weapon;
		int diff = result.armor - damage;
		if (diff > 0) {
			result.armor -= damage;
		}
		else {
			result.hp -= diff;
		}
		return result;
	}

};



class Dodger : Character {
protected:
	int chance;
public:

	Dodger() = default;

	Dodger(string _name, int _hp, int _attack, int _weapon ,int _chance) : Character(_name, _hp, _attack, _weapon), chance(_chance) {}

	Dodger(const Dodger& dobbi) : Character(dobbi.name, dobbi.hp, dobbi.attack, dobbi.weapon) {
		chance = dobbi.chance;
		name = dobbi.name;
		hp = dobbi.hp;
		weapon = dobbi.weapon;
		attack = dobbi.attack;
	}

	Dodger GetDamage(const Dodger& enemy) {
		Dodger result;
		result.chance = rand() % 99 + 1;
		if (result.chance > 1 and result.chance <= 20) {
			return result;
		}
		else {
			result.hp = result.hp - enemy.attack - enemy.weapon;
			return result;
		}
	}

};


int main() {

}
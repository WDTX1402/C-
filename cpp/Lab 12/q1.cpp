#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

class Pokemon {
    private:
        string name;
        string sound;
        string type;
        int power;
        int speed;
    
    public:
        Pokemon(string name1, string sound1, string type1, int power1, int speed1) : name(name1), sound(sound1), type(type1), power(power1), speed(speed1){}

        string getName() {
            return name;
        }
        string getSound() {
            return sound;
        }
        string getType() {
            return type;
        }
        int getPower() {
            return power;
        }
        int getSpeed() {
            return speed;
        }
};

class WildPokemon : public Pokemon {
    private:
        int catchRate;
    public:
        WildPokemon(string name, string sound, string type, int power, int speed, int catchRate1)
            : Pokemon(name, sound, type, power, speed),
              catchRate(catchRate1) {} 

        int getCatchRate() {
            return catchRate;
        }

        bool attemptEscape() {
            int Rate = 100;
            int escapeRate = 100 - catchRate;
            vector<bool> vec_bool;
            
            for (int i = 1; i <= Rate; i++) {
                if (i <= escapeRate) {
                    vec_bool.push_back(true);
                } else {
                    vec_bool.push_back(false);
                }
            }

            srand(static_cast<unsigned int>(time(nullptr)));
            int randomNumber = rand() % 100 + 1;
            
            return vec_bool[randomNumber - 1];
        }
};


class PalPokemon : public Pokemon {
public:
    PalPokemon(string n, string s, string t, int p, int sp)
        : Pokemon(n, s, t, p, sp) {}
};


class Pokeball {
    private:
        string name;
        int efficiency;

    public:
        Pokeball(string n, int e) : name(n), efficiency(e) {}

        bool catchPokemon(WildPokemon &wildPokemon) {
            srand(time(nullptr));
            int random = (rand() % 100) + 1;
            int catchRate =  wildPokemon.getCatchRate() + efficiency;
            return catchRate > random;
        }
        string getName() { 
            return name; }

        int getEfficiency() { 
            return efficiency; }
};


class Berry {
    private:
        string name;
        int effectiveness;

    public:
        Berry(string n, int e) : name(n), effectiveness(e) {}
        void applyEffect(Pokeball& pb) {
            pb = Pokeball(pb.getName(), pb.getEfficiency() + effectiveness);
        }
};


class Player {
    private:
        vector<Pokeball> pokeballs;
        vector<PalPokemon> pals;
        Berry* optionalBerry;

    public:
        void addPokeball(const Pokeball& pb) {
            pokeballs.push_back(pb);
        }

        bool catchPokemon(WildPokemon& wp) {
            for (auto& pb : pokeballs) {
                if (optionalBerry != nullptr) {
                    Berry tempBerry = *optionalBerry;
                    tempBerry.applyEffect(pb);
                }

                if (pb.catchPokemon(wp)) {
                    pals.push_back(PalPokemon(wp.getName(), wp.getSound(), wp.getType(), wp.getPower(), wp.getSpeed()));
                    return true; 
                }
            }
            return false; 
        }
};


class World {
    private:
        vector<WildPokemon> wildPokemons;

    public:
        void addWildPokemon(const WildPokemon& wp) {
            wildPokemons.push_back(wp);
        }

        WildPokemon* explore() {
            if (!wildPokemons.empty()) {
                return &wildPokemons.front(); 
            }
            return nullptr;
        }
};

class GameTester {
public:
    static void runCatchTest() {
        Player player;
        Pokeball standardBall("Standard Ball", 50);
        Pokeball superBall("Super Ball", 70);
        WildPokemon pidgey("Pidgey", "Chirp", "Normal/Flying", 30, 60, 50);
        WildPokemon bulbasaur("Bulbasaur", "Growl", "Grass/Poison", 45, 45, 50);
    
        player.addPokeball(standardBall);
        player.addPokeball(superBall);


        cout << "Encounter a wild Pidgey!" << endl;
        if (player.catchPokemon(pidgey)) {
            cout << "Caught Pidgey!\nThe player successfully caught a Pokemon" << endl;
        } else {
            cout << "The Pokemon escaped!" << endl;
        }

        cout << "\nEncounter a wild Bulbasor!" << endl;
        if (player.catchPokemon(bulbasaur)) {
            cout << "Caught Bulbasaur!\nThe player successfully caught a Pokemon" << endl;
        } else {
            cout << "The Pokemon escaped!" << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); 
    GameTester::runCatchTest();
    return 0;
}
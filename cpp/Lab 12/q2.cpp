#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <algorithm>

using namespace std;

class Pokemon {
    public:
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
            int newCatchRate = catchRate - ((power / 10) + (speed / 10));
            newCatchRate = std::max(newCatchRate, 1);

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

        bool catchPokemon(WildPokemon& wp) {
            int successRate = efficiency - wp.getCatchRate() + (rand() % efficiency);
            return successRate > 50; 
        }

        string getName() { 
            return name; 
        }
        int getEfficiency() { 
            return efficiency; 
        }
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


class World {
    private:
        vector<WildPokemon> wildPokemons;

    public:
        void addWildPokemon(const WildPokemon& wp) {
            wildPokemons.push_back(wp);
        }

        // In the World class
        WildPokemon explore() {
            // This example assumes you have a pre-existing vector of WildPokemon objects.
            if (!wildPokemons.empty()) {
                int index = rand() % wildPokemons.size();
                return wildPokemons[index]; // Return a pointer to an existing object
            } else {
            return wildPokemons[0]; // No Pokemon encountered
        }

        
        }

};


class Player {
    private:
        vector<Pokeball> pokeballs;
        vector<PalPokemon> capturedPokemons;
        Berry* optionalBerry;

    public:
        void stockpilePokeballs() {
            string types[3] = {"Normal", "Strong", "Ultra"};
            for (int i = 0; i < 1; ++i) {
                int typeIndex = rand() % 3;
                int efficiency = (typeIndex + 1) * 30;
                pokeballs.push_back(Pokeball(types[typeIndex], efficiency));
            }
        }

        void exploreAndEncounter(World& world) {
            WildPokemon encounteredPokemonPtr = world.explore(); // explore() should return a pointer or nullptr
            if (encounteredPokemonPtr != world.wildPokemons[0]) { // Check if the pointer is not null
                // Dereference the pointer only if it's not null
                WildPokemon& encounteredPokemon = encounteredPokemonPtr;
                cout << "Encountered " << encounteredPokemon.getName() << endl;
                catchPokemon(encounteredPokemon);
            } else {
                cout << "Encountered nothing lol" << endl; 
            }
        }


        void showPokeballs() {
            for (auto& ball : pokeballs) {
                cout << ball.getName() << " with efficiency " << ball.getEfficiency() << endl;
            }
        }

        void showCapturedPokemons() {
            for (auto& pokemon : capturedPokemons) {
                cout << pokemon.getName() << " of type " << pokemon.getType() << endl;
            }
        }
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
                    capturedPokemons.push_back(PalPokemon(wp.getName(), wp.getSound(), wp.getType(), wp.getPower(), wp.getSpeed()));
                    return true; 
                }
            }
            return false; 
        }
};




class Game {
private:
    Player player;
    World world;

public:
     Game() {
        world.addWildPokemon(WildPokemon("NO", "NO", "NO", 0, 0, 0));
        world.addWildPokemon(WildPokemon("Pikachu", "Pika Pika!", "Electric", 35, 55, 45));
        world.addWildPokemon(WildPokemon("Charmander", "Char!", "Fire", 52, 65, 39));
        world.addWildPokemon(WildPokemon("Squirtle", "Squirtle Squirtle!", "Water", 48, 43, 44));
        world.addWildPokemon(WildPokemon("Bulbasaur", "Bulba!", "Grass", 49, 45, 49));
        world.addWildPokemon(WildPokemon("Eevee", "Eevee!", "Normal", 55, 50, 55));

    
        player.addPokeball(Pokeball("Normal Ball", 30));
        player.addPokeball(Pokeball("Strong Ball", 50));
        player.addPokeball(Pokeball("Ultra Ball", 70));

    }

    void run() {
        bool gameRunning = true;
        while (gameRunning) {
            cout << "Choose an action:" << endl;
            cout << "1. Add Pokeballs to stock" << endl;
            cout << "2. Walk" << endl;
            cout << "3. List Pokeballs" << endl;
            cout << "4. List caught Pokemon" << endl;
            cout << "5. Exit" << endl;
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    player.stockpilePokeballs();
                    break;
                case 2:
                    player.exploreAndEncounter(world);
                    break;
                case 3:
                    player.showPokeballs();
                    break;
                case 4:
                    player.showCapturedPokemons();
                    break;
                case 5:
                    gameRunning = false;
                    cout << "Exiting game." << endl;
                    break;
                default:
                    cout << "Invalid option. Please choose again." << endl;
                    break;
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
    Game game;
    game.run();
    return 0;
}
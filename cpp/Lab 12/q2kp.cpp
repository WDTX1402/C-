#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Pokemon {
protected:
    std::string name;
    std::string sound;
    std::string type;
    int power;
    int speed;

public:
    Pokemon(const std::string& name, const std::string& sound, const std::string& type, int power, int speed)
        : name(name), sound(sound), type(type), power(power), speed(speed) {}

    std::string getName() const { return name; }
    std::string getSound() const { return sound; }
    std::string getType() const { return type; }
    int getPower() const { return power; }
    int getSpeed() const { return speed; }
};

class WildPokemon : public Pokemon {
    int catchRate;

public:
    WildPokemon(const std::string& name, const std::string& sound, const std::string& type, int power, int speed, int catchRate)
        : Pokemon(name, sound, type, power, speed), catchRate(catchRate) {}

    int getCatchRate() const { return catchRate; }

    bool attemptEscape() const {
        std::vector<bool> vecChance;
        for (int i = 0; i < 100; ++i) {
            if (i < catchRate-(power/10)) {
                vecChance.push_back(false);
            } else {
                vecChance.push_back(true);
            }
        }
        return vecChance[rand() % 100];
    }

    bool operator==(const WildPokemon& other) const {
        // Compare the relevant attributes for equality
        return name == other.name;
        // You may need to compare other attributes as well
    }
};

class PalPokemon : public Pokemon {
public:
    PalPokemon(const std::string& name, const std::string& sound, const std::string& type, int power, int speed)
        : Pokemon(name, sound, type, power, speed) {}
};

class Pokeball {
    std::string name;
    int efficiency;

public:
    Pokeball(const std::string& name, int efficiency) : name(name), efficiency(efficiency) {}

    bool catchPokemon(const WildPokemon& pokemon) const {
        std::vector<bool> vecChance;
        for (int i = 0; i < 100; ++i) {
            if (i < pokemon.getCatchRate() -(pokemon.getPower()/10) + (efficiency/10)) {
                vecChance.push_back(true);
            } else {
                vecChance.push_back(false);
            }
        }
        return vecChance[rand() % 100];
    }

    std::string getName() const { return name; }
    int getEfficiency() const { return efficiency; }
    void setEfficiency(int eff) {
        efficiency = eff;
    }

};

class Berry {
    std::string name;
    int effectiveness;

public:
    Berry(const std::string& name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    void applyEffect(Pokeball& pokeball) const {
        pokeball.setEfficiency(pokeball.getEfficiency() + effectiveness);
    }

    std::string getName() const { return name; }
    int getEffectiveness() const { return effectiveness; }
};

class Player {
    vector<Pokeball> pokeballs;
    Berry* berry; // Optional berry

public:
    Player() : berry(nullptr) {}

    void addPokeball(const Pokeball& pokeball) {
        pokeballs.push_back(pokeball);
    }

    bool catchPokemon(const WildPokemon& pokemon) {
        if (pokeballs.empty()) {
            return false;
        } else {
            Pokeball pokeball = pokeballs[pokeballs.size()-1];
            pokeballs.pop_back();
            return pokeball.catchPokemon(pokemon);
        }
    }

    vector<Pokeball> getPokeballs() const { return pokeballs; }  

    void setBerry(Berry* berry) {
        this->berry = berry;
    }

    void sortPokeballsByEfficiency() {
        std::sort(pokeballs.begin(), pokeballs.end(), [](const Pokeball& a, const Pokeball& b) {
            return a.getEfficiency() < b.getEfficiency(); // Sorting in descending order
        });
    }

};

class World {
    vector<WildPokemon> wildPokemons;

public:
    void addWildPokemon(const WildPokemon& pokemon) {
        wildPokemons.push_back(pokemon);
    }

    WildPokemon getRandomPokemon() {
        int index = rand() % wildPokemons.size();
        return wildPokemons[index];
    }

    bool empty() {
        return wildPokemons.empty();
    }

    void removeCaughtPokemon(const WildPokemon& caughtPokemon) {
        for (auto it = wildPokemons.begin(); it != wildPokemons.end(); ++it) {
            if (*it == caughtPokemon) { // Assuming WildPokemon has appropriate comparison operators
                wildPokemons.erase(it);
                break; // Exit loop after erasing
            }
        }
    }
};

class Game {
    Player player;
    World world;
    vector<WildPokemon> CaughtPokemon;

public:
    Game() {
        // Populate the virtual world with five diverse wild Pokémon
        world.addWildPokemon(WildPokemon("Pikachu", "Pika Pika!", "Electric", 60, 80, 50));
        world.addWildPokemon(WildPokemon("Bulbasaur", "Bulba Bulba!", "Grass", 55, 70, 70));
        world.addWildPokemon(WildPokemon("Squirtle", "Squirtle Squirtle!", "Water", 65, 75, 50));
        world.addWildPokemon(WildPokemon("Charmander", "Char Char!", "Fire", 70, 65, 55));
        world.addWildPokemon(WildPokemon("Jigglypuff", "Jigglypuff Jigglypuff!", "Fairy", 45, 60, 80));

        // Populate available pokeballs
    }

    void start() {
        int pokeball;
        int encounter;
        bool play = true;
        while (play) {
            cout << "Choose an action:\n1. Add Pokeballs to stock\n2. Walk\n3. List pokeball\n4. List caught Pokemon\n5. Exit\n";
            int choice;
            cin >> choice;
            while (choice < 1 || choice > 5) {
                cout << "Invalid value. Please try again\n";
                cin >> choice;
            }
            
            switch(choice) {
                case 1:
                pokeball = rand() % 3;
                switch(pokeball) {
                    case 0:
                        player.addPokeball(Pokeball("Normal", 30));
                        break;
                    case 1:
                        player.addPokeball(Pokeball("Strong", 50));
                        break;
                    case 2:
                        player.addPokeball(Pokeball("Ultra", 70));
                        break;
                }
                player.sortPokeballsByEfficiency();
                break;
                
                case 2:
                encounter = rand() % 100;
                if (encounter < 25) {
                    WildPokemon pokemon = world.getRandomPokemon();
                    cout << "Encounter a wild " << pokemon.getName() << "!" << endl;
                    if (player.getPokeballs().empty()) {
                        cout << "You have no pokeball to catch" << endl;
                    } else {
                        if (player.catchPokemon(pokemon)) {
                            cout << "Caught " << pokemon.getName() << "!" << endl;
                            world.removeCaughtPokemon(pokemon);
                            if (world.empty()) {
                                cout << "You cacght all wild pokemon" << endl;
                                play = false; 
                            }
                            CaughtPokemon.push_back(pokemon);
                        } else {
                            cout << pokemon.getName() << " escape!" << endl;
                        }
                    }   
                } else {
                    cout << "No pokemon encounter on this walk" << endl;
                }
                break;

                case 3:
                cout << "Player's pokeballs: " << endl;
                for (Pokeball i: player.getPokeballs()) {
                    cout << i.getName() << " Pokeball" << "(Efficiency: " << i.getEfficiency() << ")" << endl;
                }
                break;

                case 4:
                cout << "Caught Pokemons: " << endl;
                for (WildPokemon i: CaughtPokemon) {
                    cout << i.getName() << endl;
                }
                break;

                case 5:
                play = false;
                break;
            }
        }

    }
};

int main() {
    srand(time(0)); // Seed random number generator

    Game game;
    game.start();

    return 0;
}
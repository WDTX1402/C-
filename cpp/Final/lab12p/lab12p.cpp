#include <iostream>
#include <string>

using namespace std;

class Pokemon {
    private:
        string name;
        string sound;
        string type;
        int power;
        int speed;
    
    public:
        Pokemon(string name, string sound, string type, int power, int speed) 
        : name(name), sound(sound), type(type), power(power), speed(speed){};

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
            : Pokemon(name, sound, type, power, speed),catchRate(catchRate)

}
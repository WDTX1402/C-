#include <iostream>
#include <vector>

using namespace std;

// class Fraction {
//     private:
//         int n;
//         int d;
    
//     public:
//         Fraction(int n = 0, int d = 1) : n(n), d(d) {};

//         friend ostream& operator<<(ostream& out, Fraction& f)  {
//             out << f.n << '/' << f.d;

//             return out;
//         }

//         friend istream& operator>>(istream& in, Fraction &f)  {
//             char plchdr;
//             in >> f.n >> plchdr >> f.d;
//             if (f.d == 0) {
//                 cout << "Error";
//             } 
//             return in;
//         }

//         Fraction operator+(const Fraction& other) const {
//                 return Fraction(n + other.n ,d + other.d);
//         }

//         Fraction operator-

// };


class Point {
    private:
        int ptx;
        int pty;

    public:

        friend istream& operator>>(istream& in, Point &p) {
            char lol;
            in >> p.ptx >> lol >> p.pty;

            return in;
        } 

        friend ostream& operator<<(ostream& out, const Point &p) {
            return out << p.ptx << ", " << p.pty;
        }
};

int main() {
    Point p;
    cout << "Enter points ";
    cin >> p;
    cout << endl;
    cout << p;


}

// class Pokemon {
//     private:
//         string name;
//         int speed;
    
//     public:
//         Pokemon(string n, int s) : name(n), speed(s) {}
        
// };


// class PalPokemon : public Pokemon {
//     private:
//         bool pal;
//     public:
//         PalPokemon(string n, int s, bool p) : Pokemon(n, s), pal(p) {}
// };


// class SpaceJunk {
//     private:
//     public:
//         virtual void shout() {
//             cout << "draw smth" << endl;
//         }      
// };

// class SpaceJunkies: public SpaceJunk {
//     public:
//         void shout() override {
//             cout << "Junkies" << endl;
//         }
// };

// class SpaceProbe : public SpaceJunk {
//     private:
//         int score = 10;
//     public:
//         void shout() override {
//             cout << "Probe" << endl;
//         }
//         int getScore() const{
//             return score;
//         }
// };  

// class ScreenMGR {
//     private:
//         vector<SpaceJunk*> junks;

//     public:
//         void ShowScreen() {
//             for (SpaceJunk* junk :junks) {
//                     junk->shout();
//             }
//         }
// };


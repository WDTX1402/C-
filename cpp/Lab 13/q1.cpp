#include <iostream>
#include <vector>

using namespace std;

// Base class
class SpaceObject {
public:
    virtual void draw() const {
        cout << "Drawing a generic space object.\n";
    }
    // virtual ~SpaceObject() {}
};

// Derived classes
class Martian : public SpaceObject {
public:
    void draw() const override {
        cout << "Drawing a Martian with red color.\n";
    }
};

class Venutian : public SpaceObject {
public:
    void draw() const override {
        cout << "Drawing a Venutian with green swirls.\n";
    }
};

class Plutonian : public SpaceObject {
public:
    void draw() const override {
        cout << "Drawing a Plutonian with a blue icy surface.\n";
    }
};

class SpaceShip : public SpaceObject {
public:
    void draw() const override {
        cout << "Drawing a SpaceShip with sleek silver design.\n";
    }
};

class LaserBeam : public SpaceObject {
public:
    void draw() const override {
        cout << "Drawing a LaserBeam with a bright red streak.\n";
    }
};

class Mercurian : public SpaceObject {
public:
    void draw() const override {
        cout << "Drawing a Mercurian with a shiny metallic surface.\n";
    }
};

// ScreenManager class
class ScreenManager {
    vector<SpaceObject*> objects;
public:
    ~ScreenManager() {
        for (auto* obj : objects) {
            delete obj;
        }
    }

    void addObject(SpaceObject* obj) {
        objects.push_back(obj);
    }

    void refreshScreen() {
        for (SpaceObject* obj : objects) {
            obj->draw();
        }
    }
};

// Main function to demonstrate functionality
int main() {
    ScreenManager manager;
    // Add objects to the manager and refresh the screen
    manager.addObject(new Martian());
    manager.addObject(new Venutian());
    manager.addObject(new Plutonian());
    manager.addObject(new SpaceShip());
    manager.addObject(new LaserBeam());

    // Demonstrate adding a Mercurian object
    manager.addObject(new Mercurian());

    manager.refreshScreen();

    return 0;
}

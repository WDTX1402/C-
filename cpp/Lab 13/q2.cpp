#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0; 
    virtual ~CarbonFootprint()  {} 
};

class Building : public CarbonFootprint {
    int numberOfOccupants;
    double energyConsumption; 
public:
    Building(int occupants, double energy) : numberOfOccupants(occupants), energyConsumption(energy) {}
    double getCarbonFootprint() const override {
        return numberOfOccupants * energyConsumption * 0.00029; 
    }
};

class Car : public CarbonFootprint {
    int milesTravelled;
    double fuelEfficiency; 
public:
    Car(double efficiency,int travelled ) : fuelEfficiency(efficiency),milesTravelled(travelled) {}
    double getCarbonFootprint() const override {
        return milesTravelled / fuelEfficiency * 8.887; 
    }
};

class ElectricCar : public Car {
    double batteryCapacity;
    double chargeEfficiency; 
public:
    ElectricCar(double efficiency,int travelled , double capacity, double chargeEff) : Car(efficiency,travelled), batteryCapacity(capacity), chargeEfficiency(chargeEff) {}
    double getCarbonFootprint() const override {
        return (batteryCapacity / chargeEfficiency) * 0.233; // kWh to tons of CO2 conversion factor
    }
};

class Factory : public CarbonFootprint {
    double productionHours;
    double energyPerHour; 
    double wastePerHour; 
    double wasteConversionFactor; 
public:
    Factory(double hours, double energy, double waste, double conversion) : productionHours(hours), energyPerHour(energy), wastePerHour(waste), wasteConversionFactor(conversion) {}
    double getCarbonFootprint() const override {
        return (productionHours * energyPerHour * 0.00029) + (productionHours * wastePerHour * wasteConversionFactor);
    }
};

class Bicycle : public CarbonFootprint {
    double manufacturingEmissions;
public:
    Bicycle(double emissions) : manufacturingEmissions(emissions) {}
    double getCarbonFootprint() const override {
        return manufacturingEmissions; 
    }
};


int main() {
    vector<CarbonFootprint*> objects;

    cout << "Enter building's energy consumption (kWh) and number of occupants: " << endl;
    int input1;
    int input2;
    cin >> input1 >> input2;
    cout << "Enter car's fuel consumption (miles/l) and distnace travelled (miles): " << endl;
    int input3;
    int input4;
    cin >> input3 >> input4;
    cout << "Enter Electric car's energy consumption (kWh) and charge efficiency (ratio): " << endl;
    int input5;
    int input6;
    cin >> input5 >> input6;
    objects.push_back(new Building(input1, input2));
    objects.push_back(new Car(input3, input4));
    objects.push_back(new ElectricCar(input3, input4, input5, input6));
    // objects.push_back(new Factory(2000, 500, 50, 0.02));
    // objects.push_back(new Bicycle(10));

    double totalFootprint = 0;
    for (const auto& obj : objects) {
        double footprint = obj->getCarbonFootprint();
        cout << "Carbon Footprint: " << footprint << " tons of CO2" << endl;
        totalFootprint += footprint;
    }

    for (auto& obj : objects) {
        delete obj;
    }
}

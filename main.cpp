#include <iostream>
#include "WeatherStation.h"

using namespace std;

int main() {
    try {
        WeatherStation ws("Lahti", 10);

        ws.addReading(22.5);
        ws.addReading(24.0);
        ws.addReading(26.3);
        ws.addReading(21.8);
        ws.addReading(25.7);

        cout << "Location: " << ws.getLocation() << endl;
        ws.printReadings();

        ws.sortReadings();

        float avg = ws.calculateAverage<float>();
        cout << "Average: " << avg << endl;

        int above = ws.countAbove(25.0);
        cout << "Readings above 25°C: " << above << endl;

        string filename = "lahti_readings.txt";
        ws.saveToFile(filename);
        cout << "Saved to file: " << filename << endl;

        // Load back
        WeatherStation ws2 = WeatherStation::loadFromFile(filename);
        cout << "\nReconstructed from file:\n";
        cout << "Location: " << ws2.getLocation() << endl;
        ws2.printReadings();

    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}



#include "WeatherStation.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

WeatherStation::WeatherStation(string loc, int cap)
    : location(loc), capacity(cap), count(0)
{
    readings = new float[capacity];
}

WeatherStation::~WeatherStation() {
    delete[] readings;
}

void WeatherStation::addReading(float value) {
    if (count >= capacity)
        throw runtime_error("Storage limit reached.");

    readings[count++] = value;
}

void WeatherStation::printReadings() const {
    cout << "Readings: ";
    for (int i = 0; i < count; i++)
        cout << readings[i] << " ";
    cout << endl;
}

void WeatherStation::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out)
        throw runtime_error("Failed to open file for writing.");

    out << location << endl;
    out << count << endl;

    for (int i = 0; i < count; i++)
        out << readings[i] << endl;

    out.close();
}

WeatherStation WeatherStation::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in)
        throw runtime_error("Failed to open file for reading.");

    string loc;
    int n;

    getline(in, loc);
    in >> n;

    WeatherStation ws(loc, n);

    for (int i = 0; i < n; i++) {
        float v;
        in >> v;
        ws.addReading(v);
    }

    in.close();
    return ws;
}

int WeatherStation::countAbove(float threshold) const {
    return count_if(readings, readings + count,
                    [threshold](float v){ return v > threshold; });
}

void WeatherStation::sortReadings() {
    sort(readings, readings + count);
}





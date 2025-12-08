#ifndef WEATHER_STATION_H
#define WEATHER_STATION_H

#include <string>

class WeatherStation {
private:
    std::string location;
    float* readings;
    int capacity;
    int count;

public:
    WeatherStation(std::string loc, int cap = 100);
    ~WeatherStation();

    void addReading(float value);
    void printReadings() const;

    template <typename T>
    T calculateAverage() const {
        if (count == 0)
            throw std::runtime_error("Cannot calculate average: no data.");
        
        T sum = 0;
        for (int i = 0; i < count; i++)
            sum += readings[i];
        return sum / count;
    }

    void saveToFile(const std::string& filename) const;

    static WeatherStation loadFromFile(const std::string& filename);

    int countAbove(float threshold) const;
    void sortReadings();

    std::string getLocation() const { return location; }
};

#endif


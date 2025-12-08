#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
   
    map<string, double> weather = {
        {"Monday", 5.5},
        {"Tuesday", 12.3},
        {"Wednesday", 18.7},
        {"Thursday", 9.9},
        {"Friday", 21.4},
        {"Saturday", 25.0},
        {"Sunday", 15.8}
    };

    map<string, char> conditions = {
        {"Monday", 'R'},    // Rainy
        {"Tuesday", 'C'},   // Cloudy
        {"Wednesday", 'S'}, // Sunny
        {"Thursday", 'R'},
        {"Friday", 'S'},
        {"Saturday", 'S'},
        {"Sunday", 'C'}
    };

    double sum = 0.0;
    string warmestDay;
    double warmestTemp = -1000.0; 

   
    for (auto &entry : weather) {
        string day = entry.first;
        double temp = entry.second;
        char cond = conditions[day];

        cout << day << ": " << temp << "°C, Condition: " << cond << " -> ";

        if (temp < 10)
            cout << "Cold";
        else if (temp <= 20)
            cout << "Ok";
        else
            cout << "Warm";

        cout << endl;

       
        sum += temp;

       
        if (temp > warmestTemp) {
            warmestTemp = temp;
            warmestDay = day;
        }
    }

  
    double avg = sum / weather.size();
    cout << "\nAverage temperature: " << avg << "°C" << endl;

    
    cout << "Warmest day: " << warmestDay << " with " << warmestTemp << "°C" << endl;

    return 0;
}

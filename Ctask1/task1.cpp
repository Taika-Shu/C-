#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // 1. Days of the week
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // 2. Temperature readings (example values)
    vector<double> temps = {5.5, 12.3, 18.7, 9.9, 21.4, 25.0, 15.8};

    // 3. Store warmest day (name + temperature) in a tuple
    tuple<string, double> warmestDay = {days[0], temps[0]};

    // 4. Loop through days and temperatures
    for (size_t i = 0; i < days.size(); ++i) {
        cout << days[i] << ": " << temps[i] << "°C -> ";

        // 5. Classify using if-else
        if (temps[i] < 10) {
            cout << "Cold";
        } else if (temps[i] <= 20) {
            cout << "Ok";
        } else {
            cout << "Warm";
        }
        cout << endl;

        // Update warmest day if needed
        if (temps[i] > get<1>(warmestDay)) {
            warmestDay = {days[i], temps[i]};
        }
    }

    // 6. Print warmest day
    cout << "\nWarmest day: " << get<0>(warmestDay)
         << " with " << get<1>(warmestDay) << "°C" << endl;

    return 0;
}

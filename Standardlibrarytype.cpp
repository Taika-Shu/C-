#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

int main() {
    string name = "Mira";
    vector<int> scores = {85, 90, 95};
    map<string,int> ageMap;

    // 填充 map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;

    // tuple
    tuple<string, int, bool> person = {"John", 40, true};

    // 输出 output
    cout << "Name: " << name << endl;
    cout << "First score: " << scores[0] << endl;
    cout << "Bob's age: " << ageMap["Bob"] << endl;
    cout << "Tuple name: " << get<0>(person) << endl;

    return 0;
}

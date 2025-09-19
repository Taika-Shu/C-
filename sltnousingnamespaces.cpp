#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>

int main() {
    std::string name = "Mira";
    std::vector<int> scores = {85, 90, 95};
    std::map<std::string,int> ageMap;

    // 填充 map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;

    // tuple
    std::tuple<std::string, int, bool> person = {"John", 40, true};

    // 输出
    std::cout << "Name: " << name << std::endl;
    std::cout << "First score: " << scores[0] << std::endl;
    std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;
    std::cout << "Tuple name: " << std::get<0>(person) << std::endl;

    return 0;
}

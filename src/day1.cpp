//
// Created by Megnath Ramesh on 2022-12-05.
//

#include "day1.h"
#include "vector"
#include "string"
#include <fstream>
#include "iostream"

std::vector<std::vector<int>> cal_breakdowns;
std::vector<int> total_calories;

int get_current_max() {
    int max_id = 0;

    for(int i = 1; i < total_calories.size(); i++) {
        if (total_calories[max_id] < total_calories[i]) {
            max_id = i;
        }
    }

    std::cout << "Reindeer with max calories: " << max_id << std::endl;
    std::cout << "Max calories: " << total_calories[max_id] << std::endl;

    return max_id;
}

void day1(int top_n) {
    std::string filename = "Data/Day1/input.txt";
    std::ifstream file(filename);
    std::string str;
    std::vector<int> *calorie_store = new std::vector<int>;
    int calories = 0;

    while (std::getline(file, str)) {
        if (str != "") {
            int cals = std::stoi(str);
            calorie_store->push_back(cals);
            calories += cals;
        } else {
            cal_breakdowns.push_back(*calorie_store);
            total_calories.push_back(calories);

            calorie_store = new std::vector<int>;
            calories = 0;
        }
    }

    int overall_total_calories = 0;

    for (int i = 0; i < top_n; i++) {
        int max_id = get_current_max();
        overall_total_calories += total_calories[max_id];
        total_calories.erase(total_calories.begin() + max_id);
        cal_breakdowns.erase(cal_breakdowns.begin() + max_id);
    }

    std::cout << "Overall Total Calories: " << overall_total_calories << std::endl;
}
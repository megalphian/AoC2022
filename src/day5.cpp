//
// Created by Megnath Ramesh on 2022-12-05.
//

#include "day5.h"

#include "vector"
#include <fstream>
#include <string>
#include <sstream>

#include "iostream"

class Stack {
    private:
        std::vector<char> column;
    public:
        Stack(std::vector<char> column) : column(column) {}

        char pop_crate() {
            char crate = column.back();
            if(column.size() > 0){
                column.pop_back();
                return crate;
            }
            return ' ';
        }

        void add_crate(char crate){
            column.push_back(crate);
        }
};

std::vector<std::vector<char>> input_stacks = {
        {'N','V','C','S'},
        {'S','N','H','J','M','Z'},
        {'D','N','J','G','T','C','M'},
        {'M','R','W','J','F','D','T'},
        {'H','F','P'},
        {'J','H','Z','T','C'},
        {'Z','L','S','F','Q','R','P','D'},
        {'W','P','F','D','H','L','S','C'},
        {'Z','G','N','F','P','M','S','D'}
};

std::vector<std::vector<int>> input_moves;
std::vector<Stack> all_stacks;

void read_input_moves() {
    std::ifstream file("Day5/moves.txt");
    std::string str;
    while (std::getline(file, str)) {
        std::vector<int> move;
        std::stringstream ss(str);
        std::string substr;
        while(std::getline(ss, substr, ',')) {
            move.push_back(std::stoi(substr));
        }
        input_moves.push_back(move);
    }
}

void create_all_stacks() {
    for(auto stack_chars: input_stacks) {
        std::reverse(stack_chars.begin(), stack_chars.end());
        Stack stack(stack_chars);
        all_stacks.push_back(stack);
    }
}

void conduct_move(std::vector<int> move, bool is_9001) {
    int start_id = move[1] - 1;
    int end_id = move[2] - 1;
    int count = move[0];
    std::vector<char> crane_buffer;
    for (int i = 0; i < count; i++) {
        char crate = all_stacks[start_id].pop_crate();
        if(crate != ' '){
            crane_buffer.push_back(crate);
        }
    }

    if(is_9001) {
        std::reverse(crane_buffer.begin(), crane_buffer.end());
    }

    for(char crate : crane_buffer) {
        all_stacks[end_id].add_crate(crate);
    }
}

void day5(bool is_9001) {
    read_input_moves();
    create_all_stacks();
    for (auto move: input_moves) {
        conduct_move(move, is_9001);
    }
    for (auto stack : all_stacks) {
        char crate = stack.pop_crate();
        std::cout<<crate;
    }
    std::cout<<std::endl;
}



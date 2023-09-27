#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

void read_automaton(const std::string& file_name, int& alphabet_size, int& state_count, int& s0, std::vector<int>& final_states, std::vector<std::vector<int>>& transitions) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_name << std::endl;
        return;
    }
    file >> alphabet_size;
    file >> state_count;
    file >> s0;

    int final_state_count;
    file >> final_state_count;

    final_states.resize(final_state_count);
    for (int i = 0; i < final_state_count; ++i) {
        file >> final_states[i];
    }

    int s, sp;
    char a;
    transitions.resize(state_count, std::vector<int>(alphabet_size, -1));
    while (file >> s >> a >> sp) {
        transitions[s][a - '0'] = sp;
    }

    file.close();
}

bool is_accepted_by_automaton(const std::string& w0, int s0, const std::vector<int>& final_states, const std::vector<std::vector<int>>& transitions) {
    int current_state = s0;
    for (char c : w0) {
        int idx = c - 'a';
        current_state = transitions[current_state][idx];
        if (current_state == -1) {
            return false;
        }
    }
    return std::find(final_states.begin(), final_states.end(), current_state) != final_states.end();
}

int main() {
    int alphabet_size, state_count, s0;
    std::vector<int> final_states;
    std::vector<std::vector<int>> transitions;

    read_automaton("automaton.txt", alphabet_size, state_count, s0, final_states, transitions);

    std::string w0;
    std::cout << "Enter w0: ";
    std::cin >> w0;

    if (is_accepted_by_automaton(w0, s0, final_states, transitions)) {
        std::cout << "The automaton can accept a word of the form w = w0w1." << std::endl;
    } else {
        std::cout << "The automaton cannot accept any word w = w0w1." << std::endl;
    }

    return 0;
}
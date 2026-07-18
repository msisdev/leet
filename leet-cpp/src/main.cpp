#include <iostream>
#include <string>

#include "problems/p0001_two_sum.hpp"
#include "problems/p0169_majority_element.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./build/leet_runner <problem_id>\n";
        std::cout << "Example: ./build/leet_runner 0001\n";
        std::cout << "Available: 0001, 0169\n";
        return 1;
    }

    std::string id = argv[1];

    if (id == "1") {
        id = "0001";
    } else if (id == "169") {
        id = "0169";
    }

    if (id == "0001") {
        run_p0001_demo();
        return 0;
    }

    if (id == "0169") {
        run_p0169_demo();
        return 0;
    }

    std::cout << "Unknown problem id: " << argv[1] << "\n";
    std::cout << "Available: 0001, 0169\n";
    return 1;
}

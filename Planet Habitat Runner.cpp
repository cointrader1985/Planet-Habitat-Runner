#include <iostream>
#include <cstdlib>
#include <ctime>

int eventRoll() {
    return std::rand() % 3;
}

void showState(int energy, int distance) {
    std::cout << "\n--- Travel Status ---\n";
    std::cout << "Energy: " << energy << "\n";
    std::cout << "Distance: " << distance << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int energy = 6;
    int distance = 0;

    std::cout << "=== Planet Habitat Runner ===\n";

    while (energy > 0 && distance < 60) {
        int move;

        std::cout << "\nChoose movement (1-3): ";
        std::cin >> move;

        int event = eventRoll();

        if (move == 1) {
            std::cout << "Slow travel through home base.\n";
            distance += 10;
        } else if (move == 2) {
            std::cout << "Urban apartment route selected.\n";
            distance += 15;
            energy -= 1;
        } else {
            std::cout << "Expanding toward earth exploration path.\n";
            distance += 20;
            energy -= 2;
        }

        if (event == 0)
            std::cout << "Stable environment detected.\n";
        else if (event == 1)
            std::cout << "Energy fluctuation observed.\n";
        else
            std::cout << "Optimal travel conditions.\n";

        showState(energy, distance);
    }

    std::cout << "\nJourney Finished\n";

    if (distance >= 60)
        std::cout << "Exploration successful!\n";
    else
        std::cout << "Travel ended early.\n";

    return 0;
}

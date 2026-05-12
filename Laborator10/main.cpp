#include <iostream>
#include "Array.h"

int main() {
    Array<int> arr(5);

    arr += 10;
    arr += 50;
    arr += 30;
    arr += 20;

    std::cout << "Elemente initiale: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.Sort();

    std::cout << "Dupa sortare: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    try {
        std::cout << "Incercam sa accesam indexul 100...\n";
        int invalid = arr[100];
    }
    catch (std::exception& e) {
        std::cout << "Exceptie prinsa: " << e.what() << "\n";
    }

    return 0;
}
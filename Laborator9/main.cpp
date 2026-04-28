#include <iostream>
#include "Map.h"

int main() {
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        std::cout << "Index: " << index << ", Key: " << key << ", Value: " << value << "\n";
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        std::cout << "Index: " << index << ", Key: " << key << ", Value: " << value << "\n";
    }

    Map<int, const char*> m2;
    m2[10] = "C++";
    m2[30] = "Poo";

    std::cout << m.Includes(m2) << "\n";

    m.Delete(20);
    std::cout << m.Count() << "\n";

    m.Clear();
    std::cout << m.Count() << "\n";

    return 0;
}
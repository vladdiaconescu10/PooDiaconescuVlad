#include <iostream>
#include "Tree.h" 
constexpr float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}

constexpr float operator"" _Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << "300 Kelvin = " << a << " Celsius\n";
    std::cout << "120 Fahrenheit = " << b << " Celsius\n\n";
    Tree<int> myTree;

    TreeNode<int>* root = myTree.add_node(nullptr, 10);
    TreeNode<int>* child1 = myTree.add_node(root, 20);
    TreeNode<int>* child2 = myTree.add_node(root, 5);

    myTree.add_node(child1, 50);
    myTree.add_node(child1, 15);

    std::cout << "Numar total de noduri: " << myTree.count() << "\n";

    TreeNode<int>* found = myTree.find(15);
    if (found) {
        std::cout << "Nodul cu valoarea 15 a fost gasit!\n";
    }

    myTree.sort(root);
    std::cout << "Dupa sortare, primul copil al radacinii este: " << root->children[0]->value << "\n";

    return 0;
}
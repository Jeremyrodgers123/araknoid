
#include <iostream>
#include "block.hpp"

using namespace std;

int main() {
    cout << "Building block...";
    auto block = Block(1, 1, 1, 1, 1, false);
    cout << "Complete.";
    return 0;
}

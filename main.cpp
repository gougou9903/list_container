// Small project aimed for learning more about C++ and STL

#include <iostream>
#include "list_implement.h"

int main() {
    // int a = -1;
    List<int> testList(-1);

    for (int i = 0; i <= 9; ++i) {
        testList.push_back(i);
    }

    for (int i = -1; i <= 9; ++i) {
        int temp = testList.getLastNodePointer()->getValue();
        std::cout << temp << std::endl;
    }
    return 0;
}

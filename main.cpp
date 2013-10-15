// Small project aimed for learning more about C++ and STL

#include <iostream>
#include "list_implement.h"

int main() {
    List<int> testList(25);

    for (int i = 1; i <= 9; ++i) {
        testList.push_back(2*i);
    }

    ListIterator<int> iter = testList.begin();

    for (int i = 0; i <= 9; ++i) {
        std::cout << (iter + i).getNodeValue() << std::endl;
    }
    return 0;
}

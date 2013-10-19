// Small project aimed for learning more about C++ and STL

#include <iostream>
#include "list_implement.h"

int main() {
    List<int> testList(0);

    for (int i = 1; i <= 9; ++i) {
        testList.push_back(i);
    }

    ListIterator<int> iter = testList.begin();

    try {
        for (int i = 0; i <= 20; ++i) {
            std::cout << (iter + i).getNodeValue() << std::endl;
        }
    }
    catch (int errorCode) {
        switch (errorCode) {
            case 0:
                std::cout << "Attempted to go outside the list" << std::endl;
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                std::cout << "All went well" << std::endl;
        }
    }

    std::cout << "End of test" << std::endl;

    return 0;
}

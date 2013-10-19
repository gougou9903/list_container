// Small project aimed for learning more about C++ and STL

#include <iostream>
#include "list_implement.h"

int main() {
    List<int> testList = List<int>();

    for (int i = 0; i <= 5; ++i) {
        testList.push_back(i);
    }

    ListIterator<int> iter = testList.begin();

    try {
        for (int i = 0; i <= 6; ++i) {
            std::cout << iter.getNodeValue() << std::endl;
            iter = ++iter;
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

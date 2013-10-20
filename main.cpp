// Small project aimed for learning more about C++ and STL

#include <iostream>
#include "list_implement.h"

int main() {
    List<int> testList = List<int>();
    List<int> scndList = List<int>();

    try {
        for (int i = 0; i <= 5; ++i) {
            testList.push_back(i);
        }

        for (int i = 6; i <= 15; ++i) {
            scndList.push_back(i);
        }

        testList.merge(scndList);
        // testList.pop_front();

        ListIterator<int> iter = testList.begin();
        // iter = testList.erase(iter - 5);

        long int listSize = testList.size();
        for (int i = 0; i <= listSize - 1; ++i) {
            std::cout << (iter + i).getNodeValue() << std::endl;
        }

        // testList.pop_back();
        // testList.clear();
    }
    catch (int errorCode) {
        switch (errorCode) {
            case 0:
                std::cout << "Attempted to go outside the list" << std::endl;
                break;
            case 1:
                std::cout << "Attempted to access non-exsistent node" << std::endl;
                break;
            case 2:
                std::cout << "Attempted to get iterator pointing to NULL" << std::endl;
                break;
        }
    }

    std::cout << "List contains " << testList.size() << " elements" << std::endl;

    std::cout << "End of test" << std::endl;

    return 0;
}

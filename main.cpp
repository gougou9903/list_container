// Small project aimed for learning more about templates and STL

#include <iostream>
#include "list_implement.h"

int main() {
    List<int> testList = List<int>();
    List<int> scndList = List<int>();

    static long int counter = 0;
    try {
        while (1) {
            for (int i = 0; i <= 1000000; ++i) {
                testList.push_back(i);
            }

            for (int i = 6; i <= 1500000; ++i) {
                scndList.push_front(i);
            }

            List<int>::Iterator iter = testList.begin();

            testList.splice(iter + 500, scndList);

            scndList.concat(testList);
            testList.concat(scndList);
            // // testList.pop_front();

            // iter = testList.erase(iter + 5);

            // long int listSize = testList.size();
            // for (int i = 0; i <= listSize - 1; ++i) {
            // std::cout << *(iter + i) << std::endl;
            // }

            testList.pop_back();
            testList.clear();
            ++counter;
            std::cout << "Cycle # " << counter << " done" << std::endl;
        }
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

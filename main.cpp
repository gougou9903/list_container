// Small project aimed for learning more about templates and STL

#include <iostream>
#include <exception>
#include "list.h"

int main() {
    static long int counter = 1;
    try {
        List<int> fstList   = List<int>();
        List<int> scndList  = List<int>();

        while (1) {
            for (int i = 0; i <= 1000000; ++i) {
                fstList.push_back(i);
            }

            for (int i = 6; i <= 1500000; ++i) {
                scndList.push_front(i);
            }

            List<int>::Iterator iter = fstList.begin();

            fstList.splice(++iter, scndList);
            scndList.concat(fstList);
            fstList.concat(scndList);

            fstList.pop_back();
            fstList.clear();
            std::cout << "Cycle # " << counter << " done" << std::endl;
            ++counter;
        }
    }
    catch (const Exception& error) {
        std::cout << error.getDescription()
                  << std::endl;
    }
    catch (const std::exception& error) {
        std::cout << "Standart exception caught: "
                  << error.what()
                  << std::endl;
    }
    catch (...) {
        std::cout << "Caught unknown exception"
                  << std::endl;
    }

    std::cout << "End of test" << std::endl;

    return 0;
}

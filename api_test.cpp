#include <iostream>
#include <exception>
#include <vector>
#include "api_test.h"

int main() {
    complete_test();
}

void complete_test() {
    try {
        test_size(100);
        test_push_front_and_front(10);
        test_push_back_and_back(10);
        test_concat(20);

        std::cout << "SUCCESS: All tests completed"
                  << std::endl;
    }
    catch (const Exception error) {
        std::cout << error.getDescription()
                  << std::endl;
    }
    catch (const std::exception& error) {
        std::cout << "Standart exception caught: "
                  << error.what()
                  << std::endl;
    }
}

void test_size(uint wantedSize) {
    List<int> testList = List<int>(wantedSize);
    uint actualSize = testList.size();

    if (wantedSize != actualSize) {
        throw Exception("ERROR - size test failed", __FILE__, __LINE__);
    }
}

void test_push_front_and_front(int pushValue) {
    const int dummyValue = 0;
    List<int> testList = List<int>();
    testList.push_front(dummyValue);
    testList.push_front(pushValue);

    int frontValue = testList.front();

    if (frontValue != pushValue) {
        throw Exception("ERROR - push_front and front tests failed", __FILE__, __LINE__);
    }
}

void test_push_back_and_back(int pushValue) {
    const int dummyValue = 0;
    List<int> testList = List<int>();
    testList.push_back(dummyValue);
    testList.push_back(pushValue);

    int backValue = testList.back();

    if (backValue != pushValue) {
        throw Exception("ERROR - push_back and back tests failed", __FILE__, __LINE__);
    }
}

void test_concat(uint initListSizes) {
    std::vector<int> firstVector(initListSizes),
                     secondVector(initListSizes);

    fillVectorWithRandomData(firstVector);
    fillVectorWithRandomData(secondVector);
    std::vector<int> concatedVector = makeConcatedVector(firstVector, secondVector);

    List<int> firstList     = makeListFromVector(firstVector);
    List<int> secondList    = makeListFromVector(secondVector);

    firstList.concat(secondList);


    uint concatedVectorSize = concatedVector.size();
    for (uint i = 0; i < concatedVectorSize; ++i) {
        if (firstList.front() != concatedVector[i]) {
            throw Exception("ERROR - concat test failed", __FILE__, __LINE__);
        }
        firstList.pop_front();
    }
}

void fillVectorWithRandomData(std::vector<int>& vect) {
    uint size = vect.size();
    for (uint i = 0; i < size; ++i) {
        vect[i] = rand();
    }
}

List<int> makeListFromVector(std::vector<int>& vect) {
    uint size = vect.size();
    List<int> list = List<int>();

    for (uint i = 0; i < size; ++i) {
        list.push_back(vect[i]);
    }

    return list;
}

std::vector<int> makeConcatedVector(std::vector<int>& vect1,
                                    std::vector<int>& vect2) {
    uint vect1size = vect1.size();
    uint vect2size = vect2.size();
    std::vector<int> concatedVect(vect1size + vect2size);

    for (uint i = 0; i < vect1size; ++i) {
        concatedVect[i] = vect1[i];
    }

    for (uint j = 0; j < vect2size; ++j) {
        concatedVect[vect1size + j] = vect2[j];
    }

    return concatedVect;
}

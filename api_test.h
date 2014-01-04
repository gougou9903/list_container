#include "list.h"

void complete_test();

void test_size(uint wantedSize);
void test_push_front_and_front(int pushValue);
void test_push_back_and_back(int pushValue);
void test_concat(uint initListSizes);

void fillVectorWithRandomData(std::vector<int>& vect);
List<int> makeListFromVector(std::vector<int>& vect);
std::vector<int> makeConcatedVector(std::vector<int>& vect1, std::vector<int>& vect2);

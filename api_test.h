#include "list.h"

void test_push_front_and_front(int pushValue);
void test_push_back_and_back(int pushValue);
void test_concat(uint initListSizes);
void test_empty();
void test_clear();
void test_size(uint wantedSize);

void test_iterator_deref_operator();
void test_iterator_pre_increment_operator();

std::vector<int> makeRandomVector();
List<int> makeListFromVector(std::vector<int>& vect);
std::vector<int> makeConcatedVector(std::vector<int>& vect1, std::vector<int>& vect2);

#include "list.h"

void test_push_front_and_front();
void test_push_back_and_back();
void test_concat();
void test_empty();
void test_clear();
void test_size();

std::vector<int> makeRandomVector();
List<int> makeListFromVector(std::vector<int>& vect);
std::vector<int> makeConcatedVector(std::vector<int>& vect1, std::vector<int>& vect2);
uint limitedPositiveRand();

void test_iterator_deref_operator();
void test_iterator_equal_unequal_operators();
void test_iterator_pre_increment_operator();
void test_iterator_pre_decrement_operator();

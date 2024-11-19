#include "s21_map_test.h"
#include "s21_binary_tree_test.h"
#include "s21_set_test.h"
#include "s21_list_test.h"
#include "s21_queue_test.h"
#include "s21_stack_test.h"
#include "s21_vector_tests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#ifndef S21_MAP_TEST
#define S21_MAP_TEST

#include <string>
#include <gtest/gtest.h>
#include "../containers/map/s21_map.h"


TEST(s21_map, test_init) {
//   std::pair<int, int> p = std::make_pair(1,2);
//   std::pair<int, int> p2 = std::make_pair(1,1);
//   std::cout << (p == p2) << '\n';
    // std::string s1 {"hello"};
  
    // bool result {s1 == "Hello"}; // false - строки различаются по регистру
    // result = s1 > std::string("helLo"); 
    // std::cout << result;

    s21::map<int, double> m;
    EXPECT_EQ(m.empty(), true);
    EXPECT_EQ(m.size(), 0U);
    EXPECT_EQ(m.max_size(), 0U);

    s21::map<int, double> m2{std::make_pair(1, 2.23), std::make_pair(2, 4.), std::make_pair(-1, 4.)};
}

TEST(s21_map, test_same_key){
    s21::map<int, double> m2{std::make_pair(1, 2.23), std::make_pair(1, 4.), std::make_pair(-1, 4.4)};
}

#endif
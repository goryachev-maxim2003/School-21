#ifndef S21_STACK_H
#define S21_STACK_H

#include <iostream>

#include "../list/s21_list.h"

namespace s21 {

template <class T>
class Stack {
 private:
  list<T> list_;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Stack() : list_(){};
  Stack(std::initializer_list<value_type> const &items) : list_(items) {}
  Stack(const Stack &q) : list_(q.list_){};
  Stack(Stack &&q) : list_(std::move(q.list_)){};
  ~Stack(){};
  Stack operator=(Stack &&q) {
    list_ = std::move(q.list_);
    return *this;
  };

  const_reference top() { return list_.back(); }

  bool empty() { return list_.empty(); }
  size_type size() { return list_.size(); }

  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_back(); }
  void swap(Stack &other) noexcept { list_.swap(other.list_); }
};
}  // namespace s21

#endif
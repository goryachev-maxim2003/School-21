#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <iostream>

#include "../list/s21_list.h"

namespace s21 {

template <class T>
class Queue {
 private:
  list<T> list_;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // member function
  Queue() : list_(){};
  Queue(std::initializer_list<value_type> const &items) : list_(items) {}
  Queue(const Queue &q) : list_(q.list_){};
  Queue(Queue &&q) : list_(std::move(q.list_)){};
  ~Queue(){};
  Queue operator=(Queue &&q) {
    list_ = std::move(q.list_);
    return *this;
  };

  // accesors
  const_reference front() { return list_.front(); }
  const_reference back() { return list_.back(); };

  bool empty() { return list_.empty(); }
  size_type size() { return list_.size(); }

  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_front(); }
  void swap(Queue &other) noexcept { list_.swap(other.list_); }
};
}  // namespace s21

#endif
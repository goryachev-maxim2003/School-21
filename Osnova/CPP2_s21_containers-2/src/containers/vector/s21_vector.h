#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace s21 {

template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector &operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

 private:
  value_type *arr;
  size_type arr_size;
  size_type arr_capacity;

  void clear_arr();
  void moving(vector &v);
};

// ========================================== IMPLEMENTATION

template <typename T>
vector<T>::vector() {
  arr = nullptr;
  arr_size = 0;
  arr_capacity = 0;
}

template <typename T>
vector<T>::vector(size_type n) {
  arr = new value_type[n]();
  arr_size = n;
  arr_capacity = n;
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  for (size_type i = 0; i < arr_size; ++i) {
    arr[i] = *(items.begin() + i);
  }
}

template <typename T>
vector<T>::vector(const vector &v) : vector(v.arr_size) {
  for (size_type i = 0; i < v.arr_size; ++i) {
    arr[i] = v.arr[i];
  }
}

template <typename T>
vector<T>::vector(vector &&v) {
  moving(v);
}

template <typename T>
vector<T>::~vector() {
  clear_arr();
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&v) {
  if (this != &v) {
    clear_arr();
    moving(v);
  }
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= arr_size) {
    throw std::out_of_range("Index out of bounds exception.");
  }
  return arr[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (pos >= arr_size) {
    throw std::out_of_range("Index out of bounds exception.");
  }
  return arr[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return arr[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return arr[arr_size - 1];
}

template <typename T>
T *vector<T>::data() {
  return arr;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return arr;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return arr + arr_size;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
  return arr;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
  return arr + arr_size;
}

template <typename T>
bool vector<T>::empty() {
  return arr_size == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return arr_size;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size < arr_capacity) {
    return;
  }
  vector<value_type> new_arr(size);
  new_arr.arr_size = arr_size;
  for (size_type i = 0; i < arr_size; ++i) {
    new_arr[i] = arr[i];
  }
  *this = std::move(new_arr);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return arr_capacity;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (arr_size == arr_capacity) {
    return;
  }
  vector<value_type> new_arr(arr_size);
  for (size_type i = 0; i < arr_size; ++i) {
    new_arr[i] = arr[i];
  }
  *this = std::move(new_arr);
}

template <typename T>
void vector<T>::clear() {
  arr_size = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  if (pos == end()) {
    push_back(value);
    pos = end();
    return --pos;
  }
  vector<value_type> new_arr(arr_size + 1);
  size_type i = 0, j = 0, index = pos - begin();
  while (i < arr_size) {
    if (j == index) {
      new_arr[j++] = value;
      continue;
    }
    new_arr[j++] = arr[i++];
  }
  *this = std::move(new_arr);
  return arr + index;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  if (arr == nullptr || arr_size == 0) {
    throw std::invalid_argument("Vector is empty.");
  }
  vector<value_type> new_arr(arr_size - 1);
  size_type i = 0, j = 0, index = pos - begin();
  while (i < arr_size) {
    if (i == index) {
      ++i;
      continue;
    }
    new_arr[j++] = arr[i++];
  }
  *this = std::move(new_arr);
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (arr_size + 1 <= arr_capacity) {
    arr[arr_size++] = value;
    return;
  }
  vector<value_type> new_arr(arr_size + 1);
  for (size_type i = 0; i < arr_size; ++i) {
    new_arr[i] = arr[i];
  }
  new_arr[arr_size] = value;
  *this = std::move(new_arr);
}

template <typename T>
inline void vector<T>::pop_back() {
  if (arr_size == 0) {
    throw std::invalid_argument("Vector is empty.");
  }
  --arr_size;
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(*this, other);
}

template <typename T>
void vector<T>::clear_arr() {
  delete[] arr;
  arr_size = arr_capacity = 0;
}

template <typename T>
void vector<T>::moving(vector &v) {
  arr_size = v.arr_size;
  arr_capacity = v.arr_capacity;
  arr = v.arr;

  v.arr_size = v.arr_capacity = 0;
  v.arr = nullptr;
}
}  // namespace s21
#endif  // S21_VECTOR_H
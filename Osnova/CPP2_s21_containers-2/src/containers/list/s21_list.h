#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace s21 {

template <typename T>
class list {
 private:
  struct Node {
    T data;
    Node *prev;
    Node *next;

    explicit Node(T data) {
      this->data = data;
      this->prev = nullptr;
      this->next = nullptr;
    }
  };
  Node *head;
  Node *tail;
  std::size_t list_size;

  void clear_nodes();
  void moving(list &l);

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;

  // Iterator
  template <typename value_type>
  class ListIterator {
    friend class list<value_type>;

   private:
    Node *node;
    Node *l_tail;

   public:
    ListIterator() { *node = *l_tail = nullptr; }

    ListIterator(Node *node) {
      this->node = node;
      this->l_tail = nullptr;
    }

    ListIterator(Node *node, Node *l_tail) {
      this->node = node;
      this->l_tail = l_tail;
    }

    reference operator*() { return node->data; }

    // Prefix
    ListIterator operator++() {
      node = node->next;
      return *this;
    }

    ListIterator operator--() {
      if (node == nullptr) {
        node = l_tail;
      } else {
        node = node->prev;
      }
      return *this;
    }

    // Postfix
    ListIterator operator++(int) {
      ListIterator tmp(*this);
      ++*this;
      return tmp;
    }

    ListIterator operator--(int) {
      ListIterator tmp(*this);
      --*this;
      return tmp;
    }

    bool operator==(ListIterator iter) { return node == iter.node; }

    bool operator!=(ListIterator iter) { return node != iter.node; }
  };

  // Const iterator
  template <typename value_type>
  class ListConstIterator : public ListIterator<value_type> {
   public:
    ListConstIterator(ListIterator<value_type> other)
        : ListIterator<value_type>(other) {}
    const_reference operator*() { return ListIterator<T>::operator*(); }
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = std::size_t;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  const_reference front();
  const_reference back();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();
};

// ========================================== IMPLEMENTATION

template <typename T>
list<T>::list() {
  head = nullptr;
  tail = nullptr;
  list_size = 0;
}

template <typename T>
list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (auto item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(const list &l) : list() {
  Node *current = l.head;
  for (size_type i = 0; i != l.list_size; ++i) {
    push_back(current->data);
    current = current->next;
  }
}

template <typename T>
list<T>::list(list &&l) {
  moving(l);
}

template <typename T>
list<T>::~list() {
  clear_nodes();
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  clear_nodes();
  moving(l);
  return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  return head->data;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  return tail->data;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(head);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(nullptr, tail);
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return iterator(head);
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return iterator(nullptr, tail);
}

template <typename T>
bool list<T>::empty() {
  return list_size == 0;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return list_size;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(Node) / 2;
}

template <typename T>
void list<T>::clear() {
  clear_nodes();
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (list_size == 0) {
    push_back(value);
    return begin();
  }
  Node *new_node = new Node(value);
  if (pos == nullptr) {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  } else if (pos.node == head) {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  } else {
    new_node->prev = pos.node->prev;
    new_node->next = pos.node;
    pos.node->prev->next = new_node;
    pos.node->prev = new_node;
  }
  list_size++;
  return iterator(new_node);
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (list_size == 0 || pos.node == nullptr) {
    throw std::invalid_argument("Invalid list or iterator.");
  }
  if (pos.node == head) {
    pop_front();
    return;
  }
  if (pos.node == tail) {
    pop_back();
    return;
  }
  pos.node->prev->next = pos.node->next;
  pos.node->next->prev = pos.node->prev;
  delete pos.node;
  list_size--;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  Node *node = new Node(value);
  if (list_size == 0) {
    head = node;
  } else {
    node->prev = tail;
    tail->next = node;
  }
  tail = node;
  list_size++;
}

template <typename T>
void list<T>::pop_back() {
  if (list_size == 0) {
    throw std::invalid_argument("List is empty.");
  }
  Node *old_tail = tail;
  if (list_size == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    old_tail->prev->next = nullptr;
    tail = old_tail->prev;
  }
  delete old_tail;
  list_size--;
}

template <typename T>
void list<T>::push_front(const_reference value) {
  Node *node = new Node(value);
  if (list_size == 0) {
    tail = node;
  } else {
    head->prev = node;
  }
  node->next = head;
  head = node;
  list_size++;
}

template <typename T>
void list<T>::pop_front() {
  if (list_size == 0) {
    throw std::invalid_argument("List is empty.");
  }
  Node *old_head = head;
  if (list_size == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    old_head->next->prev = nullptr;
    head = old_head->next;
  }
  delete old_head;
  list_size--;
}

template <typename T>
void list<T>::swap(list &other) {
  list<T> tmp = std::move(other);
  other = std::move(*this);
  *this = std::move(tmp);
}

template <typename T>
void list<T>::merge(list &other) {
  if (this == &other || other.list_size == 0) {
    return;
  }
  if (list_size == 0) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
      push_back(it.node->data);
    }
  } else {
    iterator it_other = other.begin();
    while (it_other != other.end()) {
      iterator it = begin();
      bool inserted = false;
      while (it != end()) {
        if (it.node->data >= it_other.node->data) {
          insert(it, it_other.node->data);
          inserted = true;
          break;
        }
        ++it;
      }
      if (!inserted) {
        push_back(it_other.node->data);
      }
      ++it_other;
    }
  }
  other.clear_nodes();
}

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  if (this == &other) {
    throw std::invalid_argument("Invalid list.");
  }
  for (iterator it = other.begin(); it != other.end(); ++it) {
    insert(pos, it.node->data);
  }
  other.clear_nodes();
}

template <typename T>
void list<T>::reverse() {
  Node *node = head;
  while (node != nullptr) {
    Node *tmp = node->prev;
    node->prev = node->next;
    node->next = tmp;
    node = node->prev;
  }
  Node *tmp = head;
  head = tail;
  tail = tmp;
}

template <typename T>
void list<T>::unique() {
  iterator first = begin();
  while (first != end()) {
    iterator second = first;
    ++second;
    if (second.node == nullptr) {
      break;
    }
    if (first.node->data == second.node->data) {
      erase(second);
    } else {
      ++first;
    }
  }
}

template <typename T>
void list<T>::sort() {
  if (list_size == 0) {
    return;
  }
  for (Node *l_ptr = head; l_ptr->next != nullptr; l_ptr = l_ptr->next) {
    for (Node *r_ptr = l_ptr->next; r_ptr != nullptr; r_ptr = r_ptr->next) {
      if (l_ptr->data > r_ptr->data) {
        T temp = l_ptr->data;
        l_ptr->data = r_ptr->data;
        r_ptr->data = temp;
      }
    }
  }
}

template <typename T>
void list<T>::clear_nodes() {
  Node *current = head;
  Node *next = nullptr;
  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }
  head = tail = nullptr;
  list_size = 0;
}

template <typename T>
void list<T>::moving(list &l) {
  head = l.head;
  tail = l.tail;
  list_size = l.list_size;

  l.head = nullptr;
  l.tail = nullptr;
  l.list_size = 0;
}
}  // namespace s21
#endif  // S21_LIST_H
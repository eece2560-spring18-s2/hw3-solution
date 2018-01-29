#ifndef CONTAINER_LINKED_LIST_H_
#define CONTAINER_LINKED_LIST_H_

#include "list.h"
#include "iterator.h"

namespace algdb {

template <typename T>
class LinkedListIterator;

template <typename T>
class Node {
 public:
  T value;
  Node<T> *next;

  Node() {
    next = NULL;
  }
};

template <typename T>
class LinkedList : public List<T>{
  friend class LinkedListIterator<T>;

 private:

  int len_;
  Node<T> *head_;

 public:
  LinkedList() {
    len_ = 0;
    head_ = NULL;
  }

  ~LinkedList() {
    Node<T> *curr = head_;
    Node<T> *next;
    while (curr != NULL) {
      next = curr->next;
      delete curr;
      curr = next;
    }
  }

  int Length() const override {
    return len_;
  };

  void Append(T item) override {
    Node<T> *new_node = new Node<T>();
    new_node->value = item;
    new_node->next = NULL;

    if (len_ == 0) {
      head_ = new_node;
    } else {
      Node<T> *curr_node_ = head_;
      for (int i = 0; i < len_ - 1; i++) {
        curr_node_ = curr_node_->next;
      }
      curr_node_->next = new_node;
    }
    len_++;
  }

  LinkedListIterator<T> *GetIterator() override {
    return new LinkedListIterator<T>(this);
  }

  void Insert(int index, T item) override {
    Node<T> *new_node = new Node<T>();
    new_node->value = item;

    Node<T> *prev = NULL;
    Node<T> *curr = head_;
    for (int i = 0; i < index; i++) {
      prev = curr;
      curr = curr->next;
    }

    if (prev == NULL) {
      new_node->next = head_;
      head_ = new_node;
    } else {
      new_node->next = prev->next;
      prev->next = new_node;
    }

    len_++;
  }

  T Delete(int index) override {
    Node<T> *prev = NULL;
    Node<T> *curr = head_;
    for (int i = 0; i < index; i++) {
      prev = curr;
      curr = curr->next;
    }

    if (prev == NULL) {
      head_ = curr->next;
    } else {
      prev->next = curr->next;
    }

    T value = curr->value;
    delete curr;

    len_--;

    return value;
  }

  T Get(int index) const override {
    Node<T> *curr = head_;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
    return curr->value;
  }

  void Set(int index, T item) {
    Node<T> *curr = head_;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }
    curr->value = item;
  }


};

template <typename T>
class LinkedListIterator : public Iterator<T>{
  LinkedList<T> *list_;
  Node<T> *prev_;
  Node<T> *next_;

 public:
  LinkedListIterator(LinkedList<T> *list) {
    list_ = list;
    next_ = list_->head_;
  };

  bool HasNext() const override {
    if (next_ != NULL) {
      return true;
    }
    return false;
  };

  T Next() override {
    T value = next_->value;
    prev_ = next_;
    next_ = next_->next;
    return value;
  };

  void Insert(T item) {
    Node<T> *new_node = new Node<T>();
    new_node->value = item;

    if (prev_ == NULL) {
      new_node->next = list_->head_;
      list_->head_ = new_node;
    } else {
      new_node->next = prev_->next;
      prev_->next = new_node;
    }
    list_->len_++;
  }
};

}

#endif
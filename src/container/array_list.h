#ifndef CONTAINER_ARRAY_LIST_H_
#define CONTAINER_ARRAY_LIST_H_

#include "list.h"
#include "iterator.h"

namespace algdb {

template <typename T>
class ArrayListIterator;

template <typename T>
class ArrayList : public List<T>{
  friend class ArrayListIterator<T>;

 private:
  int len_;
  int cap_;
  T * data_;

 public:
  ArrayList() {
    cap_ = 2;
    len_ = 0;
    data_ = new T[cap_];
  }

  ~ArrayList() {
    delete[] data_;
  }

  int Length() const override {
    return len_;
  };

  void Grow() {
    cap_ *= 2;
    T *new_data = new T[cap_];

    for (int i = 0; i < len_; i++) {
      new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
  }

  void Append(T item) override {
    if (cap_ == len_) {
      Grow();
    }

    data_[len_] = item;
    len_++;
  }

  ArrayListIterator<T> *GetIterator() override {
    return new ArrayListIterator<T>(this);
  }

  void Insert(int index, T item) override {
    if (cap_ == len_) {
      Grow();
    }

    int i = len_;
    while (i > index) {
      data_[i] = data_[i - 1];
      i--;
    }

    data_[index] = item;
    len_++;
  }

  T Delete(int index) override {
    T deleted = data_[index];
    for (int i = index; i < len_ - 1; i++) {
      data_[i] = data_[i + 1];
    }
    len_--;
    return deleted;
  }

  T Get(int index) const override {
    return data_[index];
  }

  void Set(int index, T item) {
    data_[index] = item;
  }

};

template <typename T>
class ArrayListIterator : public Iterator<T>{
  ArrayList<T> *list_;
  int curr_pos_;

 public:
  ArrayListIterator(ArrayList<T> *list) {
   list_ = list;
   curr_pos_ = 0;
  };

  bool HasNext() const override {
    if (list_->Length() > curr_pos_) {
      return true;
    }
    return false;
  };

  T Next() override {
    return list_->data_[curr_pos_++];
  };

  void Insert(T item) {
    if (list_->len_ == list_->cap_) {
      list_->Grow();
    }

    int i = list_->len_;
    while (i > curr_pos_) {
      list_->data_[i] = list_->data_[i - 1];
      i--;
    }
    list_->data_[curr_pos_] = item;
    list_->len_++;
  }
};

}

#endif  // CONTAINER_ARRAY_LIST_H
#ifndef CONTAINER_LIST_H_
#define CONTAINER_LIST_H_

namespace algdb {

template <typename T>
class Iterator;

template <typename T>
class List {
 public:

  virtual ~List() {}

  /**
   * Length returns the number of elements that is
   */
  virtual int Length() const = 0;

  virtual Iterator<T> *GetIterator() = 0;

  virtual void Append(T item) = 0;
  virtual void Insert(int index, T item) = 0;
  virtual T Delete(int index) = 0;
  virtual T Get(int index) const = 0;
  virtual void Set(int index, T item) = 0;
};

}

#endif  // CONTAINER_LIST_H
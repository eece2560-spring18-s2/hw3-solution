#ifndef CONTAINER_ITERATOR_H_
#define CONTAINER_ITERATOR_H_

namespace algdb {

template <typename T>
class Iterator {
 public:
  virtual ~Iterator() {}
  virtual bool HasNext() const = 0;
  virtual T Next() = 0;
  virtual void Insert(T item) = 0;
};

}

#endif  // CONTAINER_ITERATOR_H
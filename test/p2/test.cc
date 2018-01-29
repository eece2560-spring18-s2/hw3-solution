#include <iostream>
#include "container/array_list.h"
#include "sorter.h"
#include "merge_sorter.h"

#define EXPECT_EQ(act, exp) \
  if ((act) != (exp)) { \
    std::cout << __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << " " \
      << "expected " << exp << ", but get " << act << ".\n"; \
    return false;\
  }

class IntComparator : public algdb::Comparator<int> {
 public:
  bool Compare(int a, int b) {
    return a < b;
  }
};

bool TestSort() {
  algdb::ArrayList<int> list;
  algdb::MergeSorter<int> sorter;
  IntComparator comparator;

  list.Append(10);
  list.Append(9);
  list.Append(8);
  list.Append(7);
  list.Append(6);
  list.Append(5);
  list.Append(4);
  list.Append(3);
  list.Append(2);
  list.Append(1);

  sorter.Sort(&list, &comparator);

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i + 1, list.Get(i));
  }

  return true;
}

int main() {

  if (!TestSort()) {
    std::cout << "TestSort failed\n";
    return -1;
  }

  std::cout << "Test passed.\n";
}

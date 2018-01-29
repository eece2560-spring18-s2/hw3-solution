#include <iostream>

#include "database.h"
#include "group.h"
#include "timer.h"
#include "simple_sorter.h"
#include "merge_sorter.h"
#include "quick_sorter.h"

class GroupRatingComarator : public algdb::Comparator<algdb::Group *> {
 public:
  bool Compare(algdb::Group *a, algdb::Group *b) {
    return a->rating < b->rating;
  }
};

int main() {
  using namespace algdb;

  Database db;
  db.LoadData("../data");

  // Sort and benchmarking
  GroupRatingComarator comparator;
  Timer timer;
  Sorter<Group *> *sorter = new SimpleSorter<Group *>();
  // Sorter<Group *> *sorter = new MergeSorter<Group *>();
  // Sorter<Group *> *sorter = new QuickSorter<Group *>();
  timer.Start();
  sorter->Sort(db.groups, &comparator);
  double time = timer.End();
  delete sorter;
  std::cout << "Exec Time: " << time << "\n";

  // Print
  auto it = db.groups->GetIterator();
  while(it->HasNext()) {
    auto group = it->Next();
    group->Dump();
  }
  delete it;
}
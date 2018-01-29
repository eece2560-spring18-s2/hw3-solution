#include <iostream>

#include "database.h"
#include "group.h"
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

  GroupRatingComarator comparator;
  Sorter<Group *> *sorter = new QuickSorter<Group *>();
  sorter->Sort(db.groups, &comparator);
  delete sorter;

  auto it = db.groups->GetIterator();
  while(it->HasNext()) {
    auto group = it->Next();
    group->Dump();
  }
  delete it;
}
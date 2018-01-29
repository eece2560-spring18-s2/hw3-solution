#ifndef GROUP_H_
#define GROUP_H_

#include <string>
#include <stdint.h>

namespace algdb {

class Group {
 public:
  uint64_t group_id;
  uint32_t members;
  std::string group_name;
  uint32_t organizer_id;
  double rating;

  void Dump() {
    printf("Group: %s(%lu), %d members, rating %f\n",
      group_name.c_str(), group_id, members, rating);
  }
};

}

#endif
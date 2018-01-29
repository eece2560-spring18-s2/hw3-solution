#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include <stdint.h>

namespace algdb {

class Member {
 public:
  uint64_t member_id;
  float lat;
  float lon;
  std::string member_name;
};

}

#endif
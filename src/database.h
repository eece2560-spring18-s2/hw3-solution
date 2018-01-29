#ifndef DATABASE_H_
#define DATABASE_H_

#include "event.h"
#include "group.h"
#include "member.h"
#include "container/list.h"
#include "container/array_list.h"
#include "container/linked_list.h"

namespace algdb {

class Database{
  void LoadEventData(const std::string &event_file);
  void LoadMemberData(const std::string &member_file);
  void LoadGroupData(const std::string &group_file);

 public:
  ArrayList<Event *> *events;
  ArrayList<Member *> *members;
  ArrayList<Group *> *groups;

  Database();
  ~Database();
  void LoadData(const std::string &data_folder_path);
};

}

#endif  // DATABASE_H_
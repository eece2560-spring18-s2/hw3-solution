#include "database.h"

#include <iostream>
#include <string>

#include "csv_reader.h"

namespace algdb {

Database::Database() {
  events = new ArrayList<Event*>();
  members = new ArrayList<Member*>();
  groups = new ArrayList<Group*>();
}


Database::~Database() {
  auto it_event = events->GetIterator();
  while(it_event->HasNext()) {
      Event *event = it_event->Next();
      delete event;
  }
  delete it_event;
  delete events;

  auto it_members = members->GetIterator();
  while(it_members->HasNext()) {
      Member *member = it_members->Next();
      delete member;
  }
  delete it_members;
  delete members;

  auto it_groups = groups->GetIterator();
  while(it_groups->HasNext()) {
      Group *group = it_groups->Next();
      delete group;
  }
  delete it_groups;
  delete groups;
}

void Database::LoadEventData(const std::string &event_file) {
  CsvReader reader;
  reader.OpenFile(event_file.c_str());

  while(reader.NextEntry()) {
    Event *event = new Event();
    for (int j = 0; j < 48; j++) {
      std::string cell = reader.NextCell();
      switch (j) {
      case 0:
        event->event_id = cell;
        break;
      case 3:
        event->duration = std::stoull(cell);
        break;
      case 6:
        event->fee = std::stoi(cell);
        break;
      case 14:
        event->group_id = std::stoull(cell);
      case 47:
        event->yes_rsvp_count = std::stoi(cell);
        break;
      }
    }
    events->Append(event);
  }
  std::cout << events->Length() << " events information loaded.\n";
}

void Database::LoadMemberData(const std::string &member_file) {
  CsvReader reader;
  reader.OpenFile(member_file.c_str());

  uint64_t last_id = 0;
  Member *member;

  while(reader.NextEntry()) {
    uint64_t id = std::stoull(reader.NextCell());
    if (id != last_id) {
      last_id = id;
      member = new Member();
      members->Append(member);
      member->member_id = id;
      for (int j = 0; j < 13; j++) {
        std::string cell = reader.NextCell();
        switch (j) {
        case 5:
          member->lat = std::stod(cell);
          break;
        case 7:
          member->lon = std::stod(cell);
          break;
        case 8:
          member->member_name = cell;
          break;
        }
      }
    }
  }
  std::cout << members->Length() << " merber information loaded.\n";
}

void Database::LoadGroupData(const std::string &group_file) {
  CsvReader reader;
  reader.OpenFile(group_file.c_str());

  while(reader.NextEntry()) {
    Group *group = new Group();
    for (int j = 0; j < 36; j++) {
      std::string cell = reader.NextCell();
      switch (j) {
      case 0:
        group->group_id = std::stoull(cell);
        break;
      case 19:
        group->members = std::stoi(cell);
        break;
      case 20:
        group->group_name = cell;
        break;
      case 21:
        group->organizer_id = std::stoull(cell);
      case 29:
        group->rating = std::stof(cell);
        break;
      }
    }
    groups->Append(group);
  }
  std::cout << groups->Length() << " groups information loaded.\n";
}

void Database::LoadData(const std::string &data_folder_path) {
  LoadEventData(data_folder_path + "/events.csv");
  // LoadMemberData(data_folder_path + "/members.csv");
  LoadGroupData(data_folder_path + "/groups.csv");
}

}
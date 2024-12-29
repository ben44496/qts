#pragma once
#include <string>

using UserID = std::string;

class User {
  public:
    User() = default;
    User(std::string name) : name(name) {};
    std::string name = "";
    UserID id;
};

class Account {
    User owner = User();
};

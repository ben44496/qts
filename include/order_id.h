#pragma once
#include "order_types.h"

namespace QTS {

class OrderIDGenerator {
  public:
    static OrderIDGenerator* getInstance();
    int generateOrderID(const Order& order);

  private:
    OrderIDGenerator() = default;
    OrderIDGenerator(const OrderIDGenerator& other) = delete;
    OrderIDGenerator& operator=(const OrderIDGenerator& other) = delete;

    static OrderIDGenerator* instance;
};

}
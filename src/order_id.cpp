#include "order_id.h"

namespace OrderManagementSystem {

    OrderIDGenerator* OrderIDGenerator::getInstance() {
        if (instance == nullptr) {
            instance = new OrderIDGenerator();
        }
        return instance;
    }

    int OrderIDGenerator::generateOrderID(const Order& order) {
        return 0;
    }

    
}
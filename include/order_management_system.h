#pragma once
#include <unordered_map>
#include <unordered_set>
#include "order_types.h"
#include "strategy.h"
#include "account.h"

namespace QTS {

class OrderManagementSystem {
  public:
    OrderManagementSystem();
    OrderManagementSystem(const OrderManagementSystem& other);
    OrderManagementSystem& operator=(const OrderManagementSystem& other);

    std::weak_ptr<Strategy> add_strategy(const Strategy& strategy_info);
    std::weak_ptr<Order> add_order(std::weak_ptr<Order> order);
    std::weak_ptr<Order> cancel_order(OrderID order_id);
    std::weak_ptr<Order> get_order(OrderID order_id);
    std::weak_ptr<Strategy> get_strategy(StrategyID strategy_id);

  private:
    std::unordered_map<UserID, std::unordered_set<StrategyID>> author_strategies;
    std::unordered_map<StrategyID, Strategy> strategies;
};

}
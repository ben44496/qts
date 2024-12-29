#include "order_management_system.h"
#include "strategy.h"

namespace QTS {

OrderManagementSystem::OrderManagementSystem() {
    // TODO
}

// OrderManagementSystem::OrderManagementSystem(const OrderManagementSystem& other) {
//     // TODO
// }

// OrderManagementSystem& OrderManagementSystem::operator=(const OrderManagementSystem& other) {
//     // TODO
//     return *this;
// }

std::weak_ptr<Strategy> OrderManagementSystem::add_strategy(const Strategy& strategy_info) {
    // std::shared_ptr<Strategy> strategy_ptr = std::make_shared<Strategy>(strategy_info);
    // strategies[strategy_info.id] = strategy_ptr;
    // return strategy_ptr;
    return std::weak_ptr<Strategy>();
}

std::weak_ptr<Order> OrderManagementSystem::add_order(std::weak_ptr<Order> order) {
    // std::shared_ptr<Order> order_ptr = std::make_shared<Order>(std::move(order));
    // orders[order_ptr->get_order_id()] = order_ptr;
    // return order_ptr;
    return std::weak_ptr<Order>();
}

std::weak_ptr<Order> OrderManagementSystem::cancel_order(OrderID order_id) {
    // auto order = orders.find(order_id);
    // if (order != orders.end()) {
    //     order->second->set_status(Status::CANCELED);
    //     return order->second;
    // }
    // return std::weak_ptr<Order>();
    return std::weak_ptr<Order>();
}

std::weak_ptr<Order> OrderManagementSystem::get_order(OrderID order_id) {
    // auto order = orders.find(order_id);
    // if (order != orders.end()) {
    //     return order->second;
    // }
    // return std::weak_ptr<Order>();
    return std::weak_ptr<Order>();
}

std::weak_ptr<Strategy> OrderManagementSystem::get_strategy(StrategyID strategy_id) {
    // auto strategy = strategies.find(strategy_id);
    // if (strategy != strategies.end()) {
    //     return strategy->second;
    // }
    // return std::weak_ptr<Strategy>();
    return std::weak_ptr<Strategy>();
}

} // namespace OrderManagementSystem


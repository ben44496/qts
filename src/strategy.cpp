#include "strategy.h"
#include <spdlog/spdlog.h>

namespace QTS {

std::weak_ptr<Order> Strategy::send_create_order(Ticker ticker, YesNo yes_no, BuySell buy_sell, uint64_t price, uint64_t quantity, Timestamp expiration_time, bool is_market_order) {
    std::shared_ptr<Order> order_ptr = std::make_shared<Order>(get_id(), price, quantity, expiration_time, is_market_order, yes_no, buy_sell, Status::RESTING, ticker);
    spdlog::info("Order sent to OMS: TODO");
    orderid_order_map_[order_ptr->get_order_id()] = order_ptr;
    ticker_order_map_[ticker].push_back(order_ptr);
    oms->add_order(order_ptr);
    return order_ptr;
}

void Strategy::error_create_order() {
    spdlog::error("Order creation failed: TODO");
}

std::weak_ptr<Order> Strategy::ack_create_order() {
    spdlog::info("Order created: TODO");
    return std::weak_ptr<Order>();
}

std::weak_ptr<Order> Strategy::cancel_order(OrderID order_id) {
    oms->cancel_order(order_id);

    spdlog::info("Order {} canceled", order_id);
    return std::weak_ptr<Order>();
}

}
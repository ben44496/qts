
#include <iostream>
#include <vector>

#include "order_types.h"
#include "account.h"
#include "strategy.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace QTS;

void basic_logfile_example()
{
    try 
    {
        auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

int main() {
    // basic_logfile_example();
    spdlog::info("Welcome to spdlog!");
    User user = User("Ben");
    StrategyInfo si = StrategyInfo("mm", "description", StrategyType::MARKET_MAKING, "id", "version", "account_owner_id");
    std::shared_ptr<OrderManagementSystem> oms = std::make_shared<OrderManagementSystem>(); 
    QTS::Strategy mm(user, si, oms);

    // std::shared_ptr<Order> order = std::make_shared<Order>(mm.get_id(), 50, 1000, 0, false, YesNo::YES, BuySell::BUY, Status::RESTING, "ticker");
    // std::cout << "Order: " << *order << std::endl;

    std::weak_ptr<Order> order = mm.send_create_order("ticker", YesNo::YES, BuySell::BUY, 50, 1000, 0, false);
    if (order.lock()) {
        std::cout << "Order: " << *order.lock() << std::endl;
    }
    return 0;
}
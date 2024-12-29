#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "order_types.h"
#include "account.h"
#include "order_management_system.h"

using StrategyID = std::string;
using AccountId = std::string;

namespace QTS
{
  class OrderManagementSystem;

  enum StrategyType
  {
    UNINITIALIZED,
    ARBITRAGE,
    MARKET_MAKING,
    HEDGING,
    OTHER,
    MOMENTUM,
  };

  class StrategyInfo
  {
  public:
    StrategyInfo(const std::string &name, std::string description, StrategyType strategy_type, std::string id, std::string version, AccountId account_owner_id) : name(name), description(description), strategy_type(strategy_type), id(id), version(version), account_owner_id(account_owner_id) {};

    std::string name = "";
    std::string description = "";
    StrategyType strategy_type = StrategyType::UNINITIALIZED;
    std::string id = "";
    std::string version = "";
    AccountId account_owner_id = AccountId();
  };

  struct Trade
  {
    uint64_t price = 0;
    uint64_t quantity = 0;
    Timestamp executed_time = 0;
    bool is_taker = false;
    YesNo yes_no = YesNo::UNINITIALIZED;
    BuySell buy_sell = BuySell::UNINITIALIZED;
    Ticker ticker = Ticker();
    StrategyID strategy_id = StrategyID();
  };

  class Strategy
  {
  public:
    Strategy(User owner, StrategyInfo si, const std::shared_ptr<OrderManagementSystem> &oms) : owner(owner), strategy_info(si) {};
    // Strategy(const Strategy &other) = delete;
    // Strategy &operator=(const Strategy &other) = delete;

    // Add
    std::weak_ptr<Order> send_create_order(Ticker ticker, YesNo yes_no, BuySell buy_sell, uint64_t price, uint64_t quantity, Timestamp expiration_time, bool is_market_order);
    void error_create_order();
    std::weak_ptr<Order> ack_create_order();
    std::weak_ptr<Order> cancel_order(OrderID order_id);

    // Getters
    std::string get_name() const { return strategy_info.name; }
    std::string get_description() const { return strategy_info.description; }
    StrategyType get_strategy_type() const { return strategy_info.strategy_type; }
    std::string get_id() const { return strategy_info.id; }
    std::string get_version() const { return strategy_info.version; }
    std::string get_account_owner_id() const { return strategy_info.account_owner_id; }

  private:
    StrategyInfo strategy_info;
    std::unordered_map<OrderID, std::shared_ptr<Order>> orderid_order_map_;
    std::unordered_map<Ticker, std::vector<std::weak_ptr<Order>>> ticker_order_map_;
    std::vector<std::shared_ptr<Trade>> trades;
    int pnl = 0;
    StrategyID strategy_id = StrategyID();
    User owner;

    std::shared_ptr<OrderManagementSystem> oms;
  };

}
#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <memory>

#include <fmt/core.h>
#include <fmt/format.h>

using Timestamp = time_t;
using Ticker = std::string;
using MPID = std::string;
using OrderID = std::string;
using Attribution = std::string;
using Tag = std::string;

using StrategyID = std::string;


namespace QTS {
  
class Strategy;

enum class BuySell {
    SELL,
    BUY,
    UNINITIALIZED
};

enum class YesNo {
    NO,
    YES,
    UNINITIALIZED
};

enum class Status {
    RESTING,
    CANCELLED,
    FILLED,
    UNINITIALIZED
};


class TickerInfo {
  public:
    TickerInfo() = default;

    // Getters
    std::string get_ticker() const { return ticker; }
    std::string get_name() const { return name; }
    std::string get_exchange() const { return exchange; }
    std::string get_country() const { return country; }
    std::string get_currency() const { return currency; }

  private:
    Ticker ticker = "";
    std::string name = "";
    std::string exchange = "";
    std::string country = "";
    std::string currency = "";
};


class KalshiEventTickerInfo : public TickerInfo {
  public:
    KalshiEventTickerInfo(const std::string& series, const std::string& event, const std::string& market, const std::string& strike, const Timestamp& expiry) : series(series), event(event), market(market), strike(strike), expiry(expiry) {};
    KalshiEventTickerInfo(const KalshiEventTickerInfo& other) : series(other.series), event(other.event), market(other.market), strike(other.strike), expiry(other.expiry) {};
    KalshiEventTickerInfo& operator=(const KalshiEventTickerInfo& other) {
        series = other.series;
        event = other.event;
        market = other.market;
        strike = other.strike;
        expiry = other.expiry;
        return *this;
    }

    // Getters
    std::string get_series() const { return series; }
    std::string get_event() const { return event; }
    std::string get_market() const { return market; }

    std::string get_strike() const { return strike; }
    Timestamp get_expiry() const { return expiry; }

  private:
    std::string series = "";
    std::string event = "";
    std::string market = "";

    std::string strike = "";
    Timestamp expiry;
};


class Order {
  public:
    Order() = default;
    Order(StrategyID strategy_id, uint64_t price, uint64_t quantity, Timestamp expiration_time, bool is_market_order, YesNo yes_no, BuySell buy_sell, Status status, Ticker ticker);
    Order(const Order& other) = delete;
    Order& operator=(const Order& other) = delete;

    // Getters
    StrategyID get_strategy_id() const { return strategy_id; }
    std::string get_order_id() const { return order_id; }
    uint64_t get_price() const { return price; }
    uint64_t get_quantity() const { return quantity; }
    Timestamp get_created_time() const { return created_time; }
    Timestamp get_last_modified_time() const { return last_modified_time; }
    Timestamp get_expiration_time() const { return expiration_time; }
    bool get_market_order() const { return is_market_order; }
    YesNo get_yes_no() const { return yes_no; }
    BuySell get_buy_sell() const { return buy_sell; }
    Status get_status() const { return status; }
    Ticker get_ticker() const { return ticker; }

  private:
    StrategyID strategy_id;
    OrderID order_id = "";
    uint64_t price = -1;
    uint64_t quantity = -1;

    Timestamp created_time = 0;
    Timestamp last_modified_time = 0;
    Timestamp expiration_time = 0;

    bool is_market_order = false;
    YesNo yes_no = YesNo::UNINITIALIZED;
    BuySell buy_sell = BuySell::UNINITIALIZED;
    Status status = Status::UNINITIALIZED;
    Ticker ticker = Ticker();

    Attribution attribution;
    // std::vector<Tag> tags;
};

// TODO: Change these to using fmt library
std::ostream& operator<<(std::ostream& os, const BuySell& status);
std::ostream& operator<<(std::ostream& os, const YesNo& status);
std::ostream& operator<<(std::ostream& os, const Status& status);
std::ostream& operator<<(std::ostream& os, const Order& order);



}

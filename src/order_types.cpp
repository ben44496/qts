#include "order_types.h"
#include "order_id.h"
#include <iostream>
#include <fmt/format.h>

namespace QTS
{

    Order::Order(StrategyID strategy_id, uint64_t price, uint64_t quantity, Timestamp expiration_time, bool is_market_order, YesNo yes_no, BuySell buy_sell, Status status, Ticker ticker)
        : strategy_id(strategy_id),
          price(price),
          quantity(quantity),
          expiration_time(expiration_time),
          is_market_order(is_market_order),
          yes_no(yes_no),
          buy_sell(buy_sell),
          status(status), ticker(ticker)
    {
        // order_id = OrderIDGenerator::getInstance()->generateOrderID(*this); // TODO
        created_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    std::ostream &operator<<(std::ostream &os, const BuySell &status)
    {
        switch (status)
        {
        case BuySell::SELL:
            os << "SELL";
            break;
        case BuySell::BUY:
            os << "BUY";
            break;
        case BuySell::UNINITIALIZED:
            os << "<UNINITIALIZED>";
            break;
        default:
            os << "<INVALID>";
            break;
        }
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const YesNo &status)
    {
        switch (status)
        {
        case YesNo::NO:
            os << "NO";
            break;
        case YesNo::YES:
            os << "YES";
            break;
        case YesNo::UNINITIALIZED:
            os << "<UNINITIALIZED>";
            break;
        default:
            os << "<INVALID>";
            break;
        }
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const Status &status)
    {
        switch (status)
        {
        case Status::RESTING:
            os << "RESTING";
            break;
        case Status::CANCELLED:
            os << "CANCELLED";
            break;
        case Status::FILLED:
            os << "FILLED";
            break;
        case Status::UNINITIALIZED:
            os << "<UNINITIALIZED>";
            break;
        default:
            os << "<INVALID>";
            break;
        }
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const Order &order)
    {
        os << "Order(\"" << order.get_ticker() << "\", " << order.get_yes_no() << ", side=" << order.get_buy_sell() << ", price=" << order.get_price() << ", quantity=" << order.get_quantity() << ", status=" << order.get_status() << ")";
        return os;
    }


    // auto format_as(Order o) { return fmt::underlying(o); }

}
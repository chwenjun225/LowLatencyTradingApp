#pragma once 
#include <cstdint>
#include <limits>
#include "macros.h"

// Define the OrderId type to indentify order, which is uint64_t, and 
// corresponding orderIdTostring() method to log it. Also add a OrderId_INVALID 
// sentinel method to signify invalid values 
namespace Common {
    // Defining some limits and constraints
    constexpr size_t LOG_QUEUE_SIZE = 8 * 1024 * 1024;

    // Constants used across the ecosystem to represent upper bounds on various containers.
    // Trading instruments / TickerIds from [0, ME_MAX_TICKERS]. 
    constexpr size_t ME_MAX_TICKERS = 8; 

    // Max size of lock free queues used to transfer client requests, client responses and 
    // market updates between components. 
    constexpr size_t ME_MAX_CLIENT_UPDATES = 256 * 1024; 
    constexpr size_t ME_MAX_MARKET_UPDATES = 256 * 1024; 

    // Max tradinng clients. 
    constexpr size_t ME_MAX_NUM_CLIENTS = 256; 

    // Max number of orders per trading client. 
    constexpr size_t ME_MAX_ORDER_IDS  = 1024 * 1024; 

    // Max price level depth in the order books. 
    constexpr size_t ME_MAX_PRICE_LEVELS = 256;

    // Define OrderId type - to identify orders
    typedef uint64_t OrderId;
    constexpr auto OrderId_INVALID = std::numeric_limits<OrderId>::max(); 
    inline auto orderIdToString(OrderId order_id) -> std::string {
        if (UNLIKELY(order_id == OrderId_INVALID)) {
            return "INVALID"; 
        }
        return std::to_string(order_id); 
    }

    // Define TickerId type - to identify trading instruments
    typedef uint32_t TickerId;
    constexpr auto TickerId_INVALID = std::numeric_limits<TickerId>::max();
    inline auto tickerIdToString(TickerId ticker_id) -> std::string {
        if (UNLIKELY(ticker_id == TickerId_INVALID)) {
            return "INVALID";
        }
        return std::to_string(ticker_id); 
    }

    // Define ClientId type - for the exchange to identify different clients
    typedef uint32_t ClientId;
    constexpr auto ClientId_INVALID = std::numeric_limits<ClientId>::max();
    inline auto clientIdToString(ClientId client_id) -> std::string {
        if (UNLIKELY(client_id == ClientId_INVALID)) {
            return "INVALID";
        }
        return std::to_string(client_id);
    }

    // Define Price type - to hold prices for instruments
    typedef int64_t Price;
    constexpr auto Price_INVALID = std::numeric_limits<Price>::max(); 
    inline auto priceToString(Price price) -> std::string {
        if (UNLIKELY(price == Price_INVALID)) {
            return "INVALID";
        }
        return std::to_string(price);
    }

    // Define Quantity type - to hold quantity values for orders 
    typedef uint32_t Qty;
    constexpr auto Qty_INVALID = std::numeric_limits<Qty>::max(); 
    inline auto qtyToString(Qty qty) -> std::string {
        if (UNLIKELY(qty == Qty_INVALID)) {
            return "INVALID";
        }
        return std::to_string(qty); 
    }

    // Define Priority type - to capture the position of an order in the First In First Out 
    typedef uint64_t Priority; 
    constexpr auto Priority_INVALID = std::numeric_limits<Priority>::max(); 
    inline auto priorityToString(Priority priority) -> std::string {
        if (UNLIKELY(priority == Priority_INVALID)) {
            return "INVALID";
        }
        return std::to_string(priority);
    }

    // Define Side type - to signify the side (buy/sell) of an order 
    enum class Side : int8_t {
        INVALID = 0, 
        BUY = 1, 
        SELL = -1 
    }; 
    inline auto sideToString(Side side) -> std::string {
        switch (side) {
            case Side::BUY:
                return "BUY";
            case Side::SELL: 
                return "SELL";
            case Side::INVALID:
                return "INVALID";
        }
        return "UNKNOWN";
    }
}
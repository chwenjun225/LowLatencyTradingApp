#pragma once 
#include <sstream>
#include "common/types.h"
#include "common/lf_queue.h"

using namespace Common; 
namespace Exchange {
    // Represents the type / action in the market update message.
    enum class MarketUpdateType : uint8_t {
        INVALID = 0, 
        ADD = 1, 
        MODIFY = 2, 
        CANCEL = 3, 
        TRADE = 4 
    }; 
    inline std::string marketUpdateTypeToString(MarketUpdateType type) {
        switch (type) {
            case MarketUpdateType::ADD:
                return "ADD";
            case MarketUpdateType::MODIFY:
                return "MODIFY";
            case MarketUpdateType::CANCEL:
                return "CANCEL";
            case MarketUpdateType::TRADE:
                return "TRADE";
            case MarketUpdateType::INVALID:
                return "INVALID";
        }
        return "UNKNOWN";
    }

    // These structures go over the wire / network, so the binary 
    // structures are packed to remove system dependent extra padding.
    #pragma pack(push, 1)

    // Market update structure used internally by the matching engine.
    struct MEMarketUpdate {
        MarketUpdateType type_ = MarketUpdateType::INVALID;

        OrderId order_id_ = OrderId_INVALID;
        TickerId ticker_id_ = TickerId_INVALID; 
        Side side_ = Side::INVALID;
        Price price_ = Price_INVALID;
        Qty qty_ = Qty_INVALID;
        Priority priority_ = Priority_INVALID;

        auto toString() const {
            std::stringstream ss;
            ss << "MEMarketUpdate"
                << " ["
                << " type:" << marketUpdateTypeToString(type_)
                << " ticker:" << tickerIdToString(ticker_id_)
                << " oid:" << orderIdToString(order_id_)
                << " side:" << sideToString(side_)
                << " qty:" << qtyToString(qty_)
                << " price:" << priceToString(price_)
                << " priority:" << priorityToString(priority_)
                << "]";
            return ss.str();
        }
    }; 
    
    #pragma pack(pop)
        typedef Common::LFQueue<Exchange::MEMarketUpdate> MEMarketUpdateLFQueue;
}
// - `inline` giúp giảm chi phí gọi hàm bằng các sao chép
// trục tiếp mã của hàm tại vị trí gọi vì thực hiện lời gọi
// hàm. Điều này hữu dụng khi hàm nhỏ, và lời gọi hàm nhiều
// lần có thể làm chậm chương trình 
// - Cải thiện khả năng tối ưu hóa: Trình biên dịch có thể 
// tận dụng các tối ưu hóa khách khi hàm được mở rộng trực 
// tiếp tại nơi nó được gọi. 

#pragma once

#include <sstream>

#include "common/types.h"

using namespace Common;

namespace Exchange {
#pragma pack(push, 1)
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
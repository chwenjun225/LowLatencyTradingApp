#pragma once 
#include <sstream>
#include "common/types.h"
#include "common/lf_queue.h"

using namespace Common;

namespace Exchange {
    enum class ClientRequestType : uint8_t {
        INVALID = 0, 
        NEW = 1, 
        CANCEL = 2 
    }; 
    inline std::string clientRequestTypeToString(ClientRequestType type) {
        switch (type) {
            case ClientRequestType::NEW: 
                return "NEW";
            case ClientRequestType::CANCEL: 
                return "CANCEL";
            case ClientRequestType::INVALID: 
                return "INVALID";
        }
        return "UNKNOWN";
    }
    // These structures go over the wire/network, so the library structures are packed to 
    // remove system depend extra padding.
    #pragma pack(push, 1)

    // Client request structure used internally by the matching engine.
    struct MEClientRequest {
        ClientRequestType type_ = ClientRequestType::INVALID;
        ClientId client_id_ = ClientId_INVALID;
        TickerId ticker_id_ = TickerId_INVALID; 
        OrderId order_id_ = OrderId_INVALID; 
        Side side_ = Side::INVALID; 
        Price price_ = Price_INVALID; 
        Qty qty_ = Qty_INVALID; 
        
        auto toString() const {
            std::stringstream ss; 
            ss << "MEClientRequest"
                << " ["
                << "type:" << clientRequestTypeToString(type_)
                << " client:" << clientIdToString(client_id_)
                << " ticker:" << tickerIdToString(ticker_id_)
                << " oid:" << orderIdToString(order_id_)
                << " side:" << sideToString(side_)
                << " qty:" << qtyToString(qty_)
                << " price:" << priceToString(price_)
                << "]";
            return ss.str();
        }
    }; 
    
    // Undo the packed binary structure directive moving forward.
    #pragma pack(pop)
        // Lock free queues of matching engine client order request messages.
        typedef LFQueue<MEClientRequest> ClientRequestLFQueue; 
}
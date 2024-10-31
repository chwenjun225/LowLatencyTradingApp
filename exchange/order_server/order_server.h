#pragma once

#include <functional>

#include "common/thread_utils.h"
#include "common/macros.h"
#include "common/tcp_server.h"

#include "order_server/client_request.h"
#include "order_server/client_response.h"
#include "order_server/fifo_sequencer.h"

namespace Exchange {
    class OrderServer {
        private:
            const std::string iface_;
            const int port_ = 0;
            ClientResponseLFQueue *outgoing_responses_ = nullptr;
            volatile bool run_ = false;
            std::string time_str_;
            Logger logger_;
            std::array<size_t, ME_MAX_NUM_CLIENTS> cid_next_outgoing_
            seq_num_;
            std::array<size_t, ME_MAX_NUM_CLIENTS> cid_next_exp_seq_
            num_;
            std::array<Common::TCPSocket *, ME_MAX_NUM_CLIENTS> cid_tcp_
            socket_;
            Common::TCPServer tcp_server_;
            FIFOSequencer fifo_sequencer_;
    }
}
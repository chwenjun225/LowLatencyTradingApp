#pragma once

#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <fcntl.h>

#include "macros.h"

#include "logging.h"

namespace Common {
    struct SocketCfg {
        std::string ip_;
        std::string iface_;
        int port_ = -1;
        bool is_udp = false;
        bool is_listening = false;
        bool needs_so_timestamp_ = false;

        auto toString() const {
            std::stringstream ss;
            ss << "SocketCfg[ip:" << ip_
            << " iface:" << iface_
            << " port:" << port_
            << " is_udp:" << is_udp
            << " is listening:" << is_listening
            << " needs_SO_timestamp_" << needs_so_timestamp_
            << "]";

            return ss.str();
        }
    };
    // Represents the maximum number of pending/unaccepted TCP connections
    constexpr int MaxTCPServerBacklog = 1024;
    // Convert interface name "eth0" to ip "123.123.123.123"
    inline auto getIfaceIP(const std::string &iface) -> std::string {
        char buf[NI_MAXHOST] = {'\0'};
        ifaddrs *ifaddr = nullptr;

        if (getifaddrs(&ifaddr) != -1) {
            for (ifaddrs *ifa = ifaddr; ifa; ifa=ifa->ifa_next) {
                if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET && iface == ifa->ifa_name) {
                    getnameinfo(ifa->ifa_addr, sizeof(sockaddr_in), buf, sizeof(buf), NULL, 0, NI_NUMERICHOST);
                    break;
                }
            }
            freeifaddrs(ifaddr);
        }
        return buf;
    }
    // Sockets will not block on read, but instead return immediately if data is not available
    inline auto setNonBlocking(int fd) -> bool {
        const auto flags = fcntl(fd, F_GETFL, 0);
        if (flags & O_NONBLOCK)
            return true;
        return (fcntl(fd, F_SETFL, flags | O_NONBLOCK) != -1);

    }
}

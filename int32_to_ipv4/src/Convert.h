#ifndef CONVERT_H
#define CONVERT_H

#include <string>

std::string uint32_to_ip(u_int32_t ip)
{
    u_int32_t byte1 { ip >> 24 };
    
    u_int32_t byte2 { (ip >> 16) & 0xff };

    u_int32_t byte3 { (ip >> 8) & 0xff };

    u_int32_t byte4 { ip & 0xff };

    return { std::to_string(byte1) + "." + std::to_string(byte2) + "." + std::to_string(byte3) + "." + std::to_string(byte4) };
}

#endif
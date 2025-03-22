#pragma once

namespace Utility {
    constexpr std::string delimiter{";##;"};

    std::vector<std::string> Split(const std::string& _str, const std::string& _delimiter);

    bool to_bool(const std::string& _str);

    std::vector<uint32_t>& acceptableKeys();
}
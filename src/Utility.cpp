#include "Utility.h"
#include <imgui.h>

std::vector<std::string> Utility::Split(const std::string& _str, const std::string& _delimiter) {
    std::vector<std::string> result;
    std::string str = _str;

    while (str.length() != 0) {
        int index = str.find(_delimiter);
        if (index == std::string::npos) {
            result.push_back(str);
            break;
        }

        std::string found = str.substr(0, index);
        str.erase(0, index + _delimiter.length());

        result.push_back(found);
    }

    return result;
}

bool Utility::to_bool(const std::string& _str) {
    return _str == "1";
}

std::vector<uint32_t>& Utility::acceptableKeys() {
    static std::vector<uint32_t> s_acceptableKeys;
    if (!s_acceptableKeys.empty())
    {
        return s_acceptableKeys;
    }

    s_acceptableKeys.push_back(ImGuiKey_None);

    // match mod key first
    s_acceptableKeys.push_back(ImGuiMod_Ctrl);
    s_acceptableKeys.push_back(ImGuiMod_Shift);
    s_acceptableKeys.push_back(ImGuiMod_Alt);
    s_acceptableKeys.push_back(ImGuiMod_Super);
    s_acceptableKeys.push_back(ImGuiMod_Shortcut);
    s_acceptableKeys.push_back(ImGuiMod_Mask_);

    static std::unordered_set<uint32_t> keyBlackList = { ImGuiKey_MouseLeft,
        ImGuiKey_MouseRight,
        ImGuiKey_MouseMiddle,
        ImGuiKey_MouseX1,
        ImGuiKey_MouseX2,
        ImGuiKey_MouseWheelX,
        ImGuiKey_MouseWheelY,
        ImGuiKey_LeftCtrl,
        ImGuiKey_LeftShift,
        ImGuiKey_LeftAlt
    };

    // match other key later
    for (uint32_t key = ImGuiKey_NamedKey_BEGIN; key < ImGuiKey_NamedKey_END; ++key) {
        if (keyBlackList.contains(key)) {
            continue;
        }
        s_acceptableKeys.push_back(key);
    }

    return s_acceptableKeys;
}

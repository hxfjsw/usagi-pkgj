#pragma once

#include <algorithm>
#include <iterator>
#include <string_view>

namespace title_names
{
struct Entry
{
    std::string_view titleid;
    const char* name;
};

// Simplified Chinese display names keyed by catalog title ID, in ID order.
inline constexpr Entry entries[] = {
#include "title_names.inc"
};

inline const char* find(std::string_view titleid)
{
    const auto entry = std::lower_bound(
            std::begin(entries),
            std::end(entries),
            titleid,
            [](const Entry& item, std::string_view id)
            { return item.titleid < id; });
    return entry != std::end(entries) && entry->titleid == titleid
            ? entry->name
            : "";
}
}

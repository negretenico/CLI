module;
#include <filesystem>
#include <ranges>
import Types;
module Filter;
Types::DirectoryEntries Filter::filter_by_is_directory(
    const Types::DirectoryEntries &entries) {
    return entries | std::views::filter([](const auto &entry) {
               return entry.is_directory();
           }) |
           std::ranges::to<Types::DirectoryEntries>();
}

Types::DirectoryEntries Filter::filter_by_is_regular_file(
    const Types::DirectoryEntries &entries) {
    return entries | std::views::filter([](const auto &entry) {
               const auto &name = entry.path().filename().string();
               return entry.is_regular_file() && name.starts_with(".") == false;
           }) |
           std::ranges::to<Types::DirectoryEntries>();
}

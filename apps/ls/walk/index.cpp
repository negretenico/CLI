module;
#include <filesystem>
#include <ranges>
module Walk;
Walk::DirectoryEntries Walk::path(const fs::path &path) {
    return fs::directory_iterator(path) |
           std::views::filter([](const auto &entry) {
               bool is_non_hidden =
                   entry.path().filename().string().starts_with(".") == false;
               return is_non_hidden &&
                      (entry.is_directory() || entry.is_regular_file());
           }) |
           std::ranges::to<Walk::DirectoryEntries>();
}
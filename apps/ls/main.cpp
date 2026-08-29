#include <filesystem>
#include <print>
#include <ranges>
import Walk;
int main(int argc, char *argv[]) {
    Walk::DirectoryEntries entries =
        Walk::path(std::filesystem::current_path());
    for (const auto &entry : entries) {
        std::print("{}\n", entry.path().filename().string());
    }
    return 0;
}
#include <filesystem>
#include <print>
#include <ranges>
import Walk;
import Types;
int main(int argc, char *argv[]) {
    Types::DirectoryEntries entries =
        Walk::path(std::filesystem::current_path());
    for (const auto &entry : entries) {
        std::print("{}\n", entry.path().filename().string());
    }
    return 0;
}
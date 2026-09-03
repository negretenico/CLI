module;
#include <filesystem>
#include <vector>
export module Types;

export namespace Types {
namespace fs = std::filesystem;
using DirectoryEntry = fs::directory_entry;
using DirectoryEntries =
    std::vector<DirectoryEntry, std::allocator<DirectoryEntry>>;
}  // namespace Types
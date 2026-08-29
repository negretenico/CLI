module;
#include <filesystem>
#include <vector>
export module Walk;

export namespace Walk {
namespace fs = std::filesystem;
using DirectoryEntries =
    std::vector<fs::directory_entry, std::allocator<fs::directory_entry>>;
DirectoryEntries path(const fs::path &path);
}  // namespace Walk

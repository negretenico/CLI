module;
#include <filesystem>
import Types;
export module Walk;

export namespace Walk {
namespace fs = std::filesystem;
Types::DirectoryEntries path(const fs::path &path);
}  // namespace Walk

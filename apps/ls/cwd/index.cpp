module;
#include <filesystem>
#include <ranges>
import Types;
module CWD;
Types::DirectoryEntries CWD::get(){
  return std::filesystem::directory_iterator(std::filesystem::current_path()) | std::ranges::to<Types::DirectoryEntries>();
}

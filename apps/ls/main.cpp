#include <filesystem>
#include <print>
#include <ranges>
import CWD;
import Filter;
import Types;
int main(int argc, char *argv[]) {
  const auto& working_dir = CWD::get();
  auto filtered_entires = Filter::filter_by_is_directory(working_dir);
  for( auto dir: filtered_entires ){
    std::print("{}\n",dir.path().filename().string());
  }
  return 0;
}

module;
#include <filesystem>
import Types;
export module Filter;

/**
lets defin what our interface should look like, what we really want at first
is a functino that takes in a vectory of directoyr entries and returns a view of
the filtered directory entries, we can then use this function in our walk module
to filter the directory entries before returning them to the user

here what I want to say is I have a namespace that has a private tempalte
fucntion that takes in a vector of directoyr entyr but I have concret
implmentiaons taht are passing in the predicts.

so sometihgn like

template<typename T>
DirectoryEntries filter(const DirectoryEntries &entries, T predicate){
    return std::views::filter(entries, predicate);
}
then we say someting like


DirectoryEntries filter_by_is_directory(const DirectoryEntries &entries){
    return filter(entries, [](const auto &entry){ return entry.is_directory();
});
}

*/

export namespace Filter {
Types::DirectoryEntries filter_by_is_directory(
    const Types::DirectoryEntries &entries);
Types::DirectoryEntries filter_by_is_regular_file(
    const Types::DirectoryEntries &entries);
}  // namespace Filter
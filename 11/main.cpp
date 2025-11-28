#include <filesystem>
#include <iostream>
#include <regex>

namespace fs = std::filesystem;

int main(int argc, char const* argv[]) {
    if (argc < 3) return 0;
    auto path = fs::current_path() /= argv[1];
    if (exists(path) && is_directory(path)) {
        for (const auto& entry : fs::recursive_directory_iterator(path)) {
            if (is_directory(entry.path())) continue;
            if (argc == 5) {
                std::regex pattern;
                try {
                    pattern = std::regex(argv[3], std::regex::extended);
                } catch (const std::regex_error& e) {
                    std::cerr << "Invalid regex pattern: " << e.what() << "\n";
                    return 1;
                }
                if (std::regex_match(static_cast<std::string>(entry.path().filename()), pattern)) {
                    fs::rename(entry.path(),
                               entry.path().parent_path() /= argv[4]);
                }

            } else {
                if (entry.path().filename() == argv[2]) {
                    fs::rename(entry.path(),
                               entry.path().parent_path() /= argv[3]);
                }
            }
        }
    }
    return 0;
}

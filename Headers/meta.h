//
// Created by ghost64 on 2/26/25.
//

#ifndef META_H
#define META_H

#ifndef OS_DETAILS

/* Define OS based on the users current running system */
#ifdef _WIN32
#define OS "OS: Windows x86_64"
#elif __linux__ or __posix__ or __unix__ or __APPLE__
#define OS "OS: Linux or similar derivitive"
#endif

#endif

#ifndef USER_DETAILS

/* As usual, define per system */
#ifdef _WIN32
#define PROX "USERPROFILE"
#define USER "USERNAME"
#else
#define PROX "HOME"
#define USER "USER"
#endif

#endif

/* Main loop */
#include <string>

namespace meta {
    // Tested
    inline std::string detectOS() {
        return OS;
    }

    // Tested
    inline std::string getUserDetails() {
        const char* _home = std::getenv(PROX);
        const char* _uname = std::getenv(USER);

        const std::string details_H = _home ? _home: "Could not ID $HOME...\n";
        const std::string details_U = _uname ? _uname : "Could not ID $USER...\n";

        return "Home: " + details_H + " // User: " + details_U;
    }
}

#endif //META_H

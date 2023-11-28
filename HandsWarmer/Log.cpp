#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>

class Log {
private:
    std::ofstream logFile;

    std::string getCurrentDate() {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        std::stringstream ss;
        ss << ltm.tm_mday << "." << (ltm.tm_mon + 1) << "." << (1900 + ltm.tm_year);
        return ss.str();
    }

    template<typename T>
    void process(std::stringstream& ss, T&& t) {
        ss << std::forward<T>(t);
    }

    template<typename T, typename... Args>
    void process(std::stringstream& ss, T&& t, Args&&... args) {
        ss << std::forward<T>(t);
        process(ss, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void log(const std::string& type, Args&&... args) {
        if (logFile.is_open()) {
            std::stringstream ss;
            ss << type << ": ";
            process(ss, std::forward<Args>(args)...);
            std::string logMessage = ss.str();
            std::cout << logMessage << std::endl; // Output to console
            logFile << logMessage << std::endl;  // Write to file
        }
    }

public:
    Log() {
        std::string filename = "LOG I " + getCurrentDate() + " I " + std::to_string(0) + ".txt";
        logFile.open(filename, std::ios::out | std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    template<typename... Args>
    void startLog(Args&&... args) {
        log("\\/ ======= START ======= \\ \n", std::forward<Args>(args)...);
    }

    template<typename... Args>
    void errorLog(Args&&... args) {
        log("ERROR", std::forward<Args>(args)...);
    }

    template<typename... Args>
    void warningLog(Args&&... args) {
        log("WARNING", std::forward<Args>(args)...);
    }

    template<typename... Args>
    void infoLog(Args&&... args) {
        log("INFO", std::forward<Args>(args)...);
    }

    template<typename... Args>
    void endLog(Args&&... args) {
        log("\\/ ======== END ========= \\ \n", std::forward<Args>(args)...);
    }

    ~Log() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

#include "Log.h"

Log::Log() {
    std::string filename = "LOG I " + getCurrentDate() + " I " + std::to_string(0) + ".txt";
    logFile.open(filename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

std::string Log::getCurrentDate() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    std::stringstream ss;
    ss << ltm.tm_mday << "." << (ltm.tm_mon + 1) << "." << (1900 + ltm.tm_year);
    return ss.str();
}

Log::~Log() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

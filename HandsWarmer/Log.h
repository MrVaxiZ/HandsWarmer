#ifndef LOG_H
#define LOG_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Log {
private:
    std::string getCurrentTime();
    std::string getCurrentDate();
    std::ofstream logFile;

    template<typename T>
    void process(std::stringstream& ss, T&& t);

    template<typename T, typename... Args>
    void process(std::stringstream& ss, T&& t, Args&&... args);

    template<typename... Args>
    void log(const std::string& type, Args&&... args);

public:
    Log();
    ~Log();

    template<typename... Args>
    void startLog(Args&&... args);

    template<typename... Args>
    void errorLog(Args&&... args);

    template<typename... Args>
    void warningLog(Args&&... args);

    template<typename... Args>
    void infoLog(Args&&... args);

    template<typename... Args>
    void endLog(Args&&... args);
};

#include "Log.inl"

#endif // LOG_H

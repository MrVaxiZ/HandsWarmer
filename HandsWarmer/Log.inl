// Log.inl

template<typename T>
void Log::process(std::stringstream& ss, T&& t) {
    ss << std::forward<T>(t);
}

template<typename T, typename... Args>
void Log::process(std::stringstream& ss, T&& t, Args&&... args) {
    ss << std::forward<T>(t);
    process(ss, std::forward<Args>(args)...);
}

template<typename... Args>
void Log::log(const std::string& type, Args&&... args) {
    if (logFile.is_open()) {
        std::stringstream ss;
        ss << type << ": ";
        process(ss, std::forward<Args>(args)...);
        std::string logMessage = ss.str();
        std::cout << logMessage << std::endl;  // Output to console
        logFile << logMessage << std::endl;    // Write to file
    }
}

template<typename... Args>
void Log::startLog(Args&&... args) {
    log("\\/ ======= START ======= \\ \n", std::forward<Args>(args)...);
}

template<typename... Args>
void Log::errorLog(Args&&... args) {
    log("ERROR", std::forward<Args>(args)...);
}

template<typename... Args>
void Log::warningLog(Args&&... args) {
    log("WARNING", std::forward<Args>(args)...);
}

template<typename... Args>
void Log::infoLog(Args&&... args) {
    log("INFO", std::forward<Args>(args)...);
}

template<typename... Args>
void Log::endLog(Args&&... args) {
    log("\\/ ======== END ========= \\ \n", std::forward<Args>(args)...);
}

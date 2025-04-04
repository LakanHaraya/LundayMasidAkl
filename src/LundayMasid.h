#pragma once
#include <Arduino.h>

class LundayMasid {
public:
    // Severity levels batay sa RFC 5424
    static const uint8_t EMERGENCY = 0;
    static const uint8_t ALERT     = 1;
    static const uint8_t CRITICAL  = 2;
    static const uint8_t ERROR     = 3;
    static const uint8_t WARNING   = 4;
    static const uint8_t NOTICE    = 5;
    static const uint8_t INFO      = 6;
    static const uint8_t DEBUG     = 7;

    LundayMasid(Stream &stream);

    void log(uint8_t level, const char *message);
    void setMinimumLevel(uint8_t level); // <<<< New: Set minimum log level
    void flush();

    // Macros para sa shorthand methods
    #define DEFINE_LOG_METHOD(NAME, LEVEL) \
        void NAME(const char *message) { log(LEVEL, message); }

    // Magagamit ang mga shorthand methods na ito
    DEFINE_LOG_METHOD(emergency, EMERGENCY)
    DEFINE_LOG_METHOD(alert, ALERT)
    DEFINE_LOG_METHOD(critical, CRITICAL)
    DEFINE_LOG_METHOD(error, ERROR)
    DEFINE_LOG_METHOD(warning, WARNING)
    DEFINE_LOG_METHOD(notice, NOTICE)
    DEFINE_LOG_METHOD(info, INFO)
    DEFINE_LOG_METHOD(debug, DEBUG)

private:
    Stream *_stream;
    uint8_t _filterLevel = DEBUG;  // <<<< New: Default to most verbose

    const char *levelToText(uint8_t level);
};
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

    // Shorthand methods para sa bawat severity level
    void emergency(const char *message);
    void alert(const char *message);
    void critical(const char *message);
    void error(const char *message);
    void warning(const char *message);
    void notice(const char *message);
    void info(const char *message);
    void debug(const char *message);

private:
    Stream *_stream;

    const char *levelToText(uint8_t level);
};
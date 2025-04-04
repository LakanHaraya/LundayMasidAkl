#include "LundayMasid.h"

LundayMasid::LundayMasid(Stream &stream) {
    _stream = &stream;
}

void LundayMasid::log(uint8_t level, const char *message) {
    _stream->print("[");
    _stream->print(levelToText(level));
    _stream->print("] ");
    _stream->println(message);
}

// Shorthand methods for each severity level
void LundayMasid::emergency(const char *message) {
    log(EMERGENCY, message);
}

void LundayMasid::alert(const char *message) {
    log(ALERT, message);
}

void LundayMasid::critical(const char *message) {
    log(CRITICAL, message);
}

void LundayMasid::error(const char *message) {
    log(ERROR, message);
}

void LundayMasid::warning(const char *message) {
    log(WARNING, message);
}

void LundayMasid::notice(const char *message) {
    log(NOTICE, message);
}

void LundayMasid::info(const char *message) {
    log(INFO, message);
}

void LundayMasid::debug(const char *message) {
    log(DEBUG, message);
}

const char *LundayMasid::levelToText(uint8_t level) {
    switch (level) {
        case EMERGENCY: return "KAGIPITAN";
        case ALERT:     return "ALERTO";
        case CRITICAL:  return "KRITIKAL";
        case ERROR:     return "KAMALIAN";
        case WARNING:   return "BABALA";
        case NOTICE:    return "PANSIN";
        case INFO:      return "IMPO";
        case DEBUG:     return "DALISAP";
        default:        return "DI-BATID";
    }
}

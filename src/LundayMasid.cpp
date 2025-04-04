#include "LundayMasid.h"

LundayMasid::LundayMasid(Stream &stream) {
    _stream = &stream;
}

void LundayMasid::setMinimumLevel(uint8_t level) {
    _filterLevel = level;
}

void LundayMasid::log(uint8_t level, const char *message) {
    if (level > _filterLevel) return;  // <<< Pansala: balewalain kung mababa sa bingit

    _stream->print("[");
    _stream->print(levelToText(level));
    _stream->print("] ");
    _stream->println(message);
}

void LundayMasid::flush() {
    _stream->flush();
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

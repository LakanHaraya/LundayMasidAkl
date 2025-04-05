#include "LundayMasid.h"

LundayMasid::LundayMasid(Stream &stream, uint8_t facillity) {
    _stream = &stream;
    _facility = facillity;
}

void LundayMasid::setMinimumLevel(uint8_t level) {
    _filterLevel = level;
}

void LundayMasid::log(uint8_t level, const char *message) {
    if (level > _filterLevel) return;  // <<< Pansala: balewalain kung mababa sa bingit

    int pri = computePRI(_facility, level);

    // Output format: <PRI>[TIMESTAMP][LEVEL] message
    _stream->print("<");
    _stream->print(pri);
    _stream->print(">");
    _stream->print("[");        // Placeholder for timestamp
    _stream->print(millis());   // Placeholder for timestamp
    _stream->print("ms]");        // Placeholder for timestamp
    _stream->print("[");
    _stream->print(levelToText(level));
    _stream->print("] ");
    _stream->println(message);
}

void LundayMasid::flush() {
    _stream->flush();
}

const char *LundayMasid::levelToText(uint8_t level) const {
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

const char *LundayMasid::facilityToText(uint8_t facility) const {
    switch (facility) {
        case FACILITY_USER:     return "TAGAGAMIT";
        case FACILITY_SYSTEM:   return "SISTEMA";
        case FACILITY_INTERNAL: return "PANLOOB";
        case FACILITY_LOCAL0:   return "NABEGASYON";
        case FACILITY_LOCAL1:   return "ANGKLA";
        case FACILITY_LOCAL2:   return "KONTROLER LIPAD";
        case FACILITY_LOCAL3:   return "KOMUNIKASYON";
        case FACILITY_LOCAL4:   return "LAKAS";
        case FACILITY_LOCAL5:   return "PANDAMA";
        case FACILITY_LOCAL6:   return "KALIGTASAN";
        case FACILITY_LOCAL7:   return "KATUWANG";
        default:                return "DI-BATID";
    }
}

int LundayMasid::computePRI(uint8_t facility, uint8_t severity) {
    return (facility * 8) + severity;
}

// Getter functions
uint8_t LundayMasid::getFilterLevel() const {
    return _filterLevel; 
}

uint8_t LundayMasid::getFacility() const {
    return _facility;   
}

const char* LundayMasid::getFilterLevelText() const {
    return levelToText(_filterLevel);  // Returns human-readable text for the current filter level
}

const char* LundayMasid::getFacilityText() const {
    return facilityToText(_facility);  // Returns human-readable text for the current facility
}
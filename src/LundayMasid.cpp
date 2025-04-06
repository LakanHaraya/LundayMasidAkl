#include "LundayMasid.h"

LundayMasid::LundayMasid(Stream &stream, uint8_t facility) {
    _stream = &stream;
    _facility = facility;
}

void LundayMasid::setMinimumLevel(uint8_t level) {
    _filterLevel = level;
}

void LundayMasid::log(uint8_t level, const char *message) {
    if (level > _filterLevel) return;  // <<< Pansala: balewalain kung mababa sa bingit

    int pri = computePRI(_facility, level);

    // Output format: <PRI>[TIMESTAMP][FACILITY][LEVEL] message
    _stream->print("<");
    _stream->print(pri);
    _stream->print(">");
    _stream->print(" [");  
    _stream->print(millis());  
    _stream->print("ms]");      
    _stream->print(" [");
    _stream->print(facilityToText(_facility));
    _stream->print("] ");
    _stream->print("[");
    _stream->print(levelToText(level));
    _stream->print("] ");
    _stream->println(message);
}

void LundayMasid::flush() {
    _stream->flush();
}

void LundayMasid::setFacility(uint8_t facility) {
    _facility = facility;
}

const char *LundayMasid::levelToText(uint8_t level) const {
    switch (level) {
        case EMERGENCY: return "KAGI";
        case ALERT:     return "ALRT";
        case CRITICAL:  return "KRIT";
        case ERROR:     return "MALI";
        case WARNING:   return "BALA";
        case NOTICE:    return "PNSN";
        case INFO:      return "IMPO";
        case DEBUG:     return "DALI";
        default:        return "DBTD";
    }
}

const char *LundayMasid::facilityToText(uint8_t facility) const {
    switch (facility) {
        case FACILITY_USER:     return "TGGA";
        case FACILITY_SYSTEM:   return "SIST";
        case FACILITY_INTERNAL: return "LOOB";
        case FACILITY_LOCAL0:   return "NABE";
        case FACILITY_LOCAL1:   return "ANGK";
        case FACILITY_LOCAL2:   return "KNTR";
        case FACILITY_LOCAL3:   return "KOMU";
        case FACILITY_LOCAL4:   return "LKAS";
        case FACILITY_LOCAL5:   return "DAMA";
        case FACILITY_LOCAL6:   return "KALI";
        case FACILITY_LOCAL7:   return "KATU";
        default:                return "DBTD";
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
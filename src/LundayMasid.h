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

    // Facility codes para sa LundayHangin (pinasadyang proyekto)
    static const uint8_t FACILITY_USER     = 1;   // User-level messages (Operasyon ng sasakyan)
    static const uint8_t FACILITY_SYSTEM   = 3;   // System-level messages (Hardware issues, system status)
    static const uint8_t FACILITY_INTERNAL = 5;   // Internal system diagnostics (Debugging, low-level status)
    static const uint8_t FACILITY_LOCAL0   = 16;  // Custom subsystem: Navigation system
    static const uint8_t FACILITY_LOCAL1   = 17;  // Custom subsystem: Anchor system
    static const uint8_t FACILITY_LOCAL2   = 18;  // Custom subsystem: Flight controller (main)
    static const uint8_t FACILITY_LOCAL3   = 19;  // Custom subsystem: Communication/Telemetry
    static const uint8_t FACILITY_LOCAL4   = 20;  // Custom subsystem: Power management
    static const uint8_t FACILITY_LOCAL5   = 21;  // Custom subsystem: Sensors
    static const uint8_t FACILITY_LOCAL6   = 22;  // Custom subsystem: Safety and fail-safe
    static const uint8_t FACILITY_LOCAL7   = 23;  // Custom subsystem: Auxiliary functions (e.g., camera, lighting)

    LundayMasid(Stream &stream, uint8_t facility = FACILITY_LOCAL0);

    void log(uint8_t level, const char *message);
    void setMinimumLevel(uint8_t level);
    void flush();

    // Shorthand methods
    #define DEFINE_LOG_METHOD(NAME, LEVEL) \
        void NAME(const char *message) { log(LEVEL, message); }

    DEFINE_LOG_METHOD(emergency, EMERGENCY)
    DEFINE_LOG_METHOD(alert, ALERT)
    DEFINE_LOG_METHOD(critical, CRITICAL)
    DEFINE_LOG_METHOD(error, ERROR)
    DEFINE_LOG_METHOD(warning, WARNING)
    DEFINE_LOG_METHOD(notice, NOTICE)
    DEFINE_LOG_METHOD(info, INFO)
    DEFINE_LOG_METHOD(debug, DEBUG)

    // Getter functions

    uint8_t getFilterLevel() const;
    uint8_t getFacility() const;
    const char* getFilterLevelText() const;
    const char* getFacilityText() const;

private:
    Stream *_stream;
    uint8_t _filterLevel = DEBUG;
    uint8_t _facility;

    const char *levelToText(uint8_t level) const;
    const char *facilityToText(uint8_t facility) const;
    int computePRI(uint8_t facility, uint8_t severity);
};
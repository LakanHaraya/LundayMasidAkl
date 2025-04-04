#include <LundayMasid.h>

LundayMasid logger(Serial);

void setup() {
    Serial.begin(115200);
    logger.info("Sinisimulan ang paglalagak...");
    logger.flush();  // Magbulos ng saloy upang tiyakin na ang mga lagak ay agarang ipinadala sa Serial Monitor
}

void loop() {
    // Tuluyang maglagak at magbulos
    logger.debug("Kasalukuyang dinadalisap...");
    logger.flush();
    delay(1000);
}

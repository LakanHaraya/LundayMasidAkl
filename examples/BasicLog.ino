#include <LundayMasid.h>

LundayMasid logger(Serial);

void setup() {
    Serial.begin(115200);
    logger.info("Maligayang Pagdating sa LundayMasid!");
}

void loop() {
    logger.debug("Ito ay dalisapang mensahe.");
    delay(1000);
}

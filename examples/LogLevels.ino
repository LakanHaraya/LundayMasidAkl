#include <LundayMasid.h>

LundayMasid logger(Serial);

void setup() {
    Serial.begin(115200);
    logger.emergency("Ito ay mensaheng kagipitan!");
    logger.alert("Ito ay mensaheng alerto.");
    logger.critical("Ito ay mensaheng kritikal.");
    logger.error("Ito ay mensaheng kamalian.");
    logger.warning("Ito ay mensaheng babala.");
    logger.notice("Ito ay mensaheng pansin.");
    logger.info("Ito ay mensaheng impormasyon.");
    logger.debug("Ito ay mensaheng dalisap.");
}

void loop() {
    // Walang tuluyang paglagak dito, ipinakikita lamang ang magkakaibang antas
}

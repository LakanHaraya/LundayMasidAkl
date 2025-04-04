#include <LundayMasid.h>

LundayMasid logger(Serial);

void setup() {
    Serial.begin(115200);

    // Itakda ang pinakamababang antas sa WARNING
    logger.setMinimumLevel(LundayMasid::WARNING); // <<<< Subukan: palitan ito sa NOTICE o ERROR  

    logger.emergency("Antas Kagipitan: dapat mailimbag");
    logger.alert("Antas Alerto: dapat mailimbag");
    logger.critical("Antas Kritikal: dapat mailimbag");
    logger.error("Antas Kamalian: dapat mailimbag");
    logger.warning("Antas Babala: dapat mailimbag");
    logger.notice("Antas Pansin: HINDI dapat mailimbag");
    logger.info("Antas Impo: HINDI dapat mailimbag");
    logger.debug("Antas Dalisap: HINDI dapat mailimbag");
}

void loop() {
    // Ang mga lagak na may kalubhaan na mas mataas pa sa WARNING ay hindi dapat mailimbag
}

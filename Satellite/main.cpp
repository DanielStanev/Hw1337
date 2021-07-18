#include <iostream>
#include <string>
#include <fstream>
#define GroundStationOutputChannel cout

struct EIData {
    uint16_t radiationCount;
    uint16_t latchupEventsCount;
};

int main() {
    const std::string TELEMETRY_RECIEVER_INPUT_CHANNEL = "inputDataAntenna.txt";
    std::ifstream telemetryInputAntennaReceiverChannel;

    return 0;
}
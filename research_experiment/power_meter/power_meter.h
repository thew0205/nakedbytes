struct PZEM004Tv30Data
{
    const char *id;
    float voltage;
    float current;
    float power;
    float energy;
    float freq;
    float pf;
    uint16_t alarms;
    const char *timestamp;
};
enum TypePower
{
    Health,
    Munitions,
    Invisibility,
    None
};

struct Power
{
    TypePower type;
    int value;
    float time;

    Power() : type(TypePower::None), value(0), time(0.0f) {}
};
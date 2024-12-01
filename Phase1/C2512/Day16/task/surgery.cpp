#include "Surgery.h"

Surgery::Surgery(string p_SurgeryID, int p_Duration)
{
    SurgeryID = p_SurgeryID;
    Duration = p_Duration;
}

bool Surgery::Equals(const Surgery& other)
{
    return (Duration == other.Duration);
}

bool Surgery::NotEquals(const Surgery& other)
{
    return (Duration != other.Duration);
}

bool Surgery::GreaterThan(const Surgery& other)
{
    return (Duration > other.Duration);
}

bool Surgery::GreaterThanEquals(const Surgery& other)
{
    return (Duration >= other.Duration);
}

bool Surgery::LessThan(const Surgery& other)
{
    return (Duration < other.Duration);
}

bool Surgery::LessThanEquals(const Surgery& other)
{
    return (Duration <= other.Duration);
}

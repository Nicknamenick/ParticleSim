#ifndef PARTICLELIFE_PARTICLETYPES_H
#define PARTICLELIFE_PARTICLETYPES_H

#include <cstdint>
#include <string>
#include <utility>
#include "Interaction.h"


class ParticleType {
public:
    std::string name;
    uint32_t color;
    float size;
    float mass;
    Interaction* interactions;

    ParticleType(
        std::string name,
        const uint32_t color,
        const float size,
        const float mass,
        Interaction* interactions = nullptr
    ) :
    name(std::move(name)),
    color(color),
    size(size),
    mass(mass),
    interactions(interactions) {}

};

#endif //PARTICLELIFE_PARTICLETYPES_H

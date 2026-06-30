#ifndef PARTICLELIFE_INTERACTION_H
#define PARTICLELIFE_INTERACTION_H

class ParticleType;

class Interaction {
public:
    ParticleType* typeA;
    ParticleType* typeB;
    float multiplier;

    Interaction(ParticleType* typeA, ParticleType* typeB, float multiplier)
        : typeA(typeA), typeB(typeB), multiplier(multiplier) {}
};

#endif //PARTICLELIFE_INTERACTION_H

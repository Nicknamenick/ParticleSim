#ifndef PARTICLELIFE_PARTICLE_H
#define PARTICLELIFE_PARTICLE_H

#include <string>
#include "../utils/Point.h"
#include "../utils/Vector.h"
#include "../particles/ParticleTypes.h"

#define MIN_X 0.0f
#define MAX_X 800.0f
#define MIN_Y 0.0f
#define MAX_Y 600.0f

class Particle {
public:
    Point position;
    Vector velocity;
    ParticleType* type;

    Particle(
    Point position,
    Vector velocity,
    ParticleType* type
    ) : position(position), velocity(velocity), type(type) {}

    void updatePosition(const float deltaTime) {
        position.move(this->velocity * deltaTime);

        if (position.x <= MIN_X) {
            position.x = MIN_X;
            velocity.x = -velocity.x;
        }
        else if (position.x >= MAX_X) {
            position.x = MAX_X;
            velocity.x = -velocity.x;
        }

        if (position.y <= MIN_Y) {
            position.y = MIN_Y;
            velocity.y = -velocity.y;
        }
        else if (position.y >= MAX_Y) {
            position.y = MAX_Y;
            velocity.y = -velocity.y;
        }
    }

    std::string toString() const noexcept;
    void drawParticle() const;
};

#endif //PARTICLELIFE_PARTICLE_H

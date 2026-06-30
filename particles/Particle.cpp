#include "Particle.h"
#include "raylib.h"

std::string Particle::toString() const noexcept {
    return "Particle: " + type->name + " at " + position.toString() + " with velocity " + velocity.toString();
}

void Particle::drawParticle() const {
    const Color color = {
        static_cast<unsigned char>((type->color >> 16) & 0xFF),
        static_cast<unsigned char>((type->color >> 8) & 0xFF),
        static_cast<unsigned char>(type->color & 0xFF),
        255
    };
    DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), type->size, color);
}

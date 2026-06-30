#include "Simulation.h"

#include <random>
#include <cmath>
#include <iostream>
#include "../utils/Point.h"
#include "../utils/Vector.h"
#include "../particles/Particle.h"
#include "../particles/GlobalTypes.h"

#define MAX_FORCE_MAGNITUDE 1000.0f
#define DECAY_FACTOR 0.05f
#define FORCE_FACTOR 50.0f
#define NEAR_DISTANCE 400.0f

void Simulation::addParticle(const Particle& particle) {
    particles.push_back(particle);
}

const std::vector<Particle> &Simulation::getParticles() const {
    return particles;
}

std::vector<Particle> Simulation::getNearParticles(const Particle &particle, float units) const {
    std::vector<Particle> nearParticles;
    for (const auto& p : particles) {
        if (&p != &particle && particle.position.distanceTo(p.position) <= units) {
            nearParticles.push_back(p);
        }
    }
    return nearParticles;
}

std::string Simulation::toString() const noexcept {
    std::string result = "Simulation with " + std::to_string(particles.size()) + " particles:\n";
    for (const auto& particle : particles) {
        result += particle.toString() + "\n";
    }
    return result;
}

void Simulation::spawnParticles(const int count, ParticleType *type, const float speedRangeMin, const float speedRangeMax,
    const float minX, const float maxX, const float minY, const float maxY) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution speedDist(speedRangeMin, speedRangeMax);
    std::uniform_real_distribution angleDist(0.0f, 2.0f * static_cast<float>(M_PI));
    std::uniform_real_distribution xDist(minX, maxX);
    std::uniform_real_distribution yDist(minY, maxY);

    for (int i = 0; i < count; ++i) {
        float speed = speedDist(gen);
        float angle = angleDist(gen);
        Vector velocity(speed * cos(angle), speed * sin(angle));
        Point spawnPosition(xDist(gen), yDist(gen));
        Particle newParticle(spawnPosition, velocity, type);
        addParticle(newParticle);
    }
}

void Simulation::drawAll() const {
    for (const auto& particle : particles) {
        particle.drawParticle();
    }
}

void Simulation::update(const float deltaTime) {
const float nearDistanceSq = NEAR_DISTANCE * NEAR_DISTANCE;

#pragma omp parallel for
    for (size_t i = 0; i < particles.size(); ++i) {
        auto& particle = particles[i];

        for (size_t j = 0; j < particles.size(); ++j) {
            if (i == j) continue;
            const auto& other = particles[j];

            Vector direction = {other.position.x - particle.position.x, other.position.y - particle.position.y};
            float distSq = direction.x * direction.x + direction.y * direction.y;

            if (distSq > nearDistanceSq || distSq <= 0.0001f) continue;

            float distance = std::sqrt(distSq);

            for (auto& interaction : Interactions::allInteractions) {
                if ((interaction->typeA == particle.type && interaction->typeB == other.type)){

                    float forceMagnitude = interaction->multiplier * std::exp(-DECAY_FACTOR * distance) * FORCE_FACTOR;

                    // Clamping
                    if (forceMagnitude > MAX_FORCE_MAGNITUDE) forceMagnitude = MAX_FORCE_MAGNITUDE;
                    else if (forceMagnitude < -MAX_FORCE_MAGNITUDE) forceMagnitude = -MAX_FORCE_MAGNITUDE;

                    Vector normalizedDirection = direction / distance;
                    Vector force = normalizedDirection * forceMagnitude * (particle.type->mass * other.type->mass);

                    particle.velocity = particle.velocity + force * deltaTime;
                }
            }
        }
    }

    for (auto& particle : particles) {
        particle.velocity = particle.velocity * 0.95f;
        particle.updatePosition(deltaTime);
    }
}
#ifndef PARTICLELIFE_SIMULATION_H
#define PARTICLELIFE_SIMULATION_H

#include <vector>
#include <string>

class Particle;
class ParticleType;
class Point;

class Simulation {
private:
    std::vector<Particle> particles;

public:
    Simulation() = default;

    void addParticle(const Particle& particle);
    void update(float deltaTime);
    void spawnParticles(int count, ParticleType *type,
                        float speedRangeMin, float speedRangeMax,
                        float minX, float maxX, float minY, float maxY);

    [[nodiscard]] const std::vector<Particle>& getParticles() const;
    [[nodiscard]] std::string toString() const noexcept;

    void drawAll() const;
    [[nodiscard]] std::vector<Particle> getNearParticles(const Particle &particle, float units) const;
};


#endif //PARTICLELIFE_SIMULATION_H

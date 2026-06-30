#ifndef PARTICLELIFE_GLOBALTYPES_H
#define PARTICLELIFE_GLOBALTYPES_H

#include "ParticleTypes.h"
#include <vector>
/*
namespace Types{
    inline auto Red = ParticleType("Red", 0xFF0000, 3.0f, 2.5f);
    inline auto Green = ParticleType("Green", 0x00FF00, 3.0f, 1.0f);
    inline auto Blue = ParticleType("Blue", 0x0000FF, 3.0f, 0.3f);
}
namespace Interactions {
    inline auto RedRed = Interaction(&Types::Red, &Types::Red, 1.0f);
    inline auto GreenGreen = Interaction(&Types::Green, &Types::Green, -0.8f);
    inline auto BlueBlue = Interaction(&Types::Blue, &Types::Blue, -3.0f);

    inline auto RedGreen = Interaction(&Types::Red, &Types::Green, 1.5f);
    inline auto GreenRed = Interaction(&Types::Green, &Types::Red, -0.23f);
    inline auto RedBlue = Interaction(&Types::Red, &Types::Blue, 1.8f);
    inline auto BlueRed = Interaction(&Types::Blue, &Types::Red, -1.5f);
    inline auto GreenBlue = Interaction(&Types::Green, &Types::Blue, -0.8f);
    inline auto BlueGreen = Interaction(&Types::Blue, &Types::Green, -1.5f);

    inline const std::vector allInteractions = {
        &RedRed, &GreenGreen, &BlueBlue,
        &RedGreen, &GreenRed,
        &RedBlue, &BlueRed,
         &BlueGreen
    };
}
 */
namespace Types{
    inline auto Red = ParticleType("Red", 0xFF0000, 2.5f, 2.0f);
    inline auto Green = ParticleType("Green", 0x00FF00, 2.0f, 4.0f);
    inline auto Blue = ParticleType("Blue", 0x0000FF, 2.0f, 0.5f);
}
namespace Interactions {
    inline auto RedRed = Interaction(&Types::Red, &Types::Red, 0.2f);
    inline auto GreenGreen = Interaction(&Types::Green, &Types::Green, -0.5f);
    inline auto BlueBlue = Interaction(&Types::Blue, &Types::Blue, -3.0f);

    inline auto BlueRed = Interaction(&Types::Blue, &Types::Red, -1.0f);
    inline auto BlueGreen = Interaction(&Types::Blue, &Types::Green, -3.5f);

    inline auto RedBlue = Interaction(&Types::Red, &Types::Blue, 0.0f);
    inline auto RedGreen = Interaction(&Types::Red, &Types::Green, 0.0f);

    inline auto GreenBlue = Interaction(&Types::Green, &Types::Blue, -1.0f);
    inline auto GreenRed = Interaction(&Types::Green, &Types::Red, -1.0f);

    inline const std::vector allInteractions = {
        &RedRed, &GreenGreen, &BlueBlue,
        &RedGreen, &GreenRed,
        &RedBlue, &BlueRed,
         &BlueGreen
    };
}

#endif //PARTICLELIFE_GLOBALTYPES_H

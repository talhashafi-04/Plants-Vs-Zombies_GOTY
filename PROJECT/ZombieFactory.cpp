#include "ZombieFactory.h"

ZombieFactory* ZombieFactory::instance = nullptr;

ZombieFactory* ZombieFactory::getInstance() {
    if (ZombieFactory::instance == nullptr) {
        ZombieFactory::instance = new ZombieFactory();
    }
    return ZombieFactory::instance;
}

ZombieFactory::ZombieFactory() { cout << "Zombie Factory\n";
}

Zombie* ZombieFactory::createZombie(std::string zombieName) {
    if (zombieName == "SimpleZombie") {
        return new SimpleZombie();
    }
    else if (zombieName == "FootballZombie") {
        return new FootballZombie();
    }
    else if (zombieName == "FlyingZombie") {
        return new FlyingZombie();
    }
    else if (zombieName == "DancingZombie") {
        return new DancingZombie();
    }


    else if (zombieName == "DolphinRiderZombie") {
        return new DolphinRiderZombie();

    }
}
ZombieFactory::~ZombieFactory() {
    // Destructor
    delete ZombieFactory::instance;
}
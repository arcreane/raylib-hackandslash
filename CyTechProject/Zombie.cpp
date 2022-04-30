#include "Zombie.h"

Zombie::Zombie(Rectangle rec, bool o, Map* m)
{
    pos_dim = rec;
    orientation = o;
    _p = getClosestPlatform(m);
    this->type = "Zombie";
}

float Zombie::getDistance(Platform* p)
{
    return sqrt(pow(p->getPosition().x + this->pos_dim.x, 2) + pow(p->getPosition().y + this->pos_dim.y, 2));
}

Platform* Zombie::getClosestPlatform(Map* m)
{
    std::vector<Platform> pltfms = m->getPlatforms();
    Platform* result = nullptr;
    int resultDistance = 10000.0;
    for (int i; i < pltfms.size(); i++) {
        if (this->getDistance(&pltfms[i]) < resultDistance) {
            result = &pltfms[i];
            resultDistance = this->getDistance(&pltfms[i]);
        }
    }
    return result;
}

void Zombie::pathMob(Joueur player)
{
    if (this->orientation) {
        this->setX(this->getX() + 1);
        if (this->getX() > this->_p->getXDroite()) {
            this->setOrientation(false);
        }
    }
    else {
        this->setX(this->getX() - 1);
        if (this->getX() < this->_p->getPosition().x) {
            this->setOrientation(true);
        }
    }
}

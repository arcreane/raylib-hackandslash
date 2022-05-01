#include "Zombie.h"

Zombie::Zombie(Rectangle rec, bool o, Map* m)
{
    pos_dim = rec;
    _m = m;
    orientation = o;
    this->getClosestPlatform(_m);
    this->type = "zombie";
}

Zombie::Zombie(Rectangle rec, bool o, Platform p, Map* m) {
    pos_dim = rec;
    orientation = o;
    _m = m;
    _p = p;
    this->type = "zombie";
    isAlive = true;
}

void Zombie::setMob(Rectangle rec)
{
    this->pos_dim = rec;
}


float Zombie::getDistance(Platform p)
{
    return sqrt(pow(p.getXd() - this->getX(), 2) + pow(p.getY() - this->getY(), 2));
}

void Zombie::getClosestPlatform(Map* m)
{
    std::vector<Platform> pltfms = m->getPlatforms();
    int result = 0;
    int resultDistance = 10000.0;
    for (int i = 0; i < pltfms.size(); i++) {
        float dist = this->getDistance(pltfms[i]);
        if (dist < resultDistance) {
            result = i;
            resultDistance = dist;
        }
    }
    Rectangle tmp = pltfms[result].getRectangle();
    _p.setPlatform(tmp);
}

void Zombie::pathMob(Joueur player)
{
    if (this->orientation) {
        this->setX(this->getX() + 1);
        if (this->getXDroite() > this->_p.getXDroite()) {
            this->setOrientation(false);
        }
    }
    else {
        this->setX(this->getX() - 1);
        if (this->getX() < this->_p.getPosition().x) {
            this->setOrientation(true);
        }
    }

    if (!(this->getYBas() <= this->_p.getYBas() && this->getYBas() >= this->_p.getY())) {
        this->setY(this->getY() + 1);
    }
}

Mob* Zombie::copy() {
    return (new Zombie(this->pos_dim, this->orientation, this->_p, this->_m));
}

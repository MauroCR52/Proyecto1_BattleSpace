#ifndef PROYECTO1_BATTLESPACE_COLLECTOR_H
#define PROYECTO1_BATTLESPACE_COLLECTOR_H

#include "Bullet.h"


class Bullet;

class Collector {
private:
    Bullet* Chead;
    int size;

public:
    Collector();
    virtual ~Collector();
    void insertNode(Bullet* bullet);
    int getSize();
    Bullet* giveNode();
};


#endif //PROYECTO1_BATTLESPACE_COLLECTOR_H

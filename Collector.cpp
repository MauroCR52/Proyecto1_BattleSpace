//
// Created by mauluna52 on 6/04/23.
//

#include "Collector.h"
using namespace std;
Collector::Collector() {
    Chead = nullptr;
    size = 0;
}

void Collector::insertNode(Bullet *bullet) {
    if (Chead == nullptr){
        Chead = bullet;
        size++;
        return;
    } else{
        bullet->next = Chead;
        Chead = bullet;
        size++;
    }

}

Collector::~Collector() {

}

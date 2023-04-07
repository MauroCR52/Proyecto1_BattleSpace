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

int Collector::getSize() {
    return size;
}

Bullet *Collector::giveNode() {
    if (Chead == nullptr){
        return nullptr;
    } else{
        Bullet* nodeToGive = Chead;
        Chead = Chead->next;
        nodeToGive->next = nullptr;
        size--;
        return nodeToGive;
    }

}

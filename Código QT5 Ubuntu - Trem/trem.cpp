#include "trem.h"
#include <QtCore>

QMutex mutex[7];

Trem::Trem(int ID, int x, int y) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    incrementoVelocidade = 5;
}

void Trem::run() {
    while (true) {
        switch (ID) {
        case 1: // Trem 1
            this->incrementoVelocidade = 5;
            if (x == 420 && y == 30) {
                if (mutex[0].tryLock()) {
                    if (mutex[2].tryLock()){
                        x += this->incrementoVelocidade;
                    }
                    else {
                        this->incrementoVelocidade = 0;
                        mutex[0].unlock();
                    }
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 330 && y == 150){
                if (mutex[1].tryLock()){
                    x -= this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 450 && y == 150){
                x -= this->incrementoVelocidade;
                mutex[0].unlock();
            }
            else if (x == 290 && y == 150){
                x -= this->incrementoVelocidade;
                mutex[2].unlock();
            }
            else if (x == 190 && y == 130){
                x -= this->incrementoVelocidade;
                mutex[1].unlock();
            }
            else if (y == 30 && x < 460) {
                x += incrementoVelocidade;
            }
            else if (x == 460 && y < 150) {
                y += incrementoVelocidade;
            }
            else if (x > 190 && y == 150) {
                x -= incrementoVelocidade;
            }
            else {
                y -= incrementoVelocidade;
            }
            emit updateGUI(ID, x, y);
            break;

        case 2: // Trem 2
            this->incrementoVelocidade = 5;
            if (x == 510 && y == 150) {
                if (mutex[0].tryLock()) {
                    x -= this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 730 && y == 130){
                if (mutex[4].tryLock()){
                    y += this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 580 && y == 150){
                if (mutex[3].tryLock()){
                    x -= this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 520 && y == 150){
                mutex[4].unlock();
                x -= this->incrementoVelocidade;
            }
            else if (x == 460 && y == 130){
                mutex[3].unlock();
                y -= this->incrementoVelocidade;
            }
            else if (x == 480 && y == 30){
                x += this->incrementoVelocidade;
                mutex[0].unlock();
            }
            else if (y == 30 && x < 730) {
                x += incrementoVelocidade;
            }
            else if (x == 730 && y < 150) {
                y += incrementoVelocidade;
            }
            else if (x > 460 && y == 150) {
                x -= incrementoVelocidade;
            }
            else {
                y -= incrementoVelocidade;
            }
            emit updateGUI(ID, x, y);
            break;
        case 3:
            this->incrementoVelocidade = 5;
            if (x == 160 && y == 150) {
                if (mutex[1].tryLock()) {
                    if (mutex[5].tryLock()){
                        x += this->incrementoVelocidade;
                    }

                    else {
                        this->incrementoVelocidade = 0;
                        mutex[1].unlock();
                    }
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 310 && y == 170){
                y += this->incrementoVelocidade;
                mutex[1].unlock();
            }
            else if (x == 280 && y == 270){
                x -= this->incrementoVelocidade;
                mutex[5].unlock();
            }
            else if (y == 150 && x < 310) {
                x += incrementoVelocidade;
            }
            else if (x == 310 && y < 270) {
                y += incrementoVelocidade;
            }
            else if (x > 80 && y == 270) {
                x -= incrementoVelocidade;
            }
            else {
                y -= incrementoVelocidade;
            }
            emit updateGUI(ID, x, y);
            break;
        case 4:
            this->incrementoVelocidade = 5;
            if (x == 340 && y == 270){
                if (mutex[5].tryLock()){
                    x -= this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 310 && y == 170){
                if (mutex[2].tryLock()){
                    y -= this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 430 && y == 150){
                if (mutex[3].tryLock()){
                    if (mutex[6].tryLock()){
                        x += this->incrementoVelocidade;
                    }
                    else {
                        mutex[3].unlock();
                        this->incrementoVelocidade = 0;
                    }
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 550 && y == 170){
                mutex[3].unlock();
                y += this->incrementoVelocidade;
            }
            else if (x == 490 && y == 150){
                mutex[2].unlock();
                x += this->incrementoVelocidade;
            }
            else if (x == 330 && y == 150){
                mutex[5].unlock();
                x += this->incrementoVelocidade;
            }
            else if (x == 520 && y == 270){
                mutex[6].unlock();
                x -= this->incrementoVelocidade;
            }
            else if (y == 150 && x < 550) {
                x += incrementoVelocidade;
            }
            else if (x == 550 && y < 270) {
                y += incrementoVelocidade;
            }
            else if (x > 310 && y == 270) {
                x -= incrementoVelocidade;
            }
            else {
                y -= incrementoVelocidade;
            }
            emit updateGUI(ID, x, y);
            break;
        case 5:
            this->incrementoVelocidade = 5;
            if (x == 550 && y == 170){
               if (mutex[4].tryLock()){
                   x -= this->incrementoVelocidade;
               }
               else {
                   this->incrementoVelocidade = 0;
               }
            }
            else if (x == 580 && y == 270){
                if (mutex[6].tryLock()){
                    x -= this->incrementoVelocidade;
                }
                else {
                    this->incrementoVelocidade = 0;
                }
            }
            else if (x == 580 && y == 150){
                mutex[6].unlock();
                x += this->incrementoVelocidade;
            }
            else if (x == 760 && y == 150){
                mutex[4].unlock();
                x += this->incrementoVelocidade;
            }
            else if (y == 150 && x < 780) {
                x += incrementoVelocidade;
            }
            else if (x == 780 && y < 270) {
                y += incrementoVelocidade;
            }
            else if (x > 550 && y == 270) {
                x -= incrementoVelocidade;
            }
            else {
                y -= incrementoVelocidade;
            }
            emit updateGUI(ID, x, y);
            break;

        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int novaVelocidade) {
    velocidade = novaVelocidade;
}

int Trem::getX() {
    return x;
}

void Trem::setX(int x) {
    this->x = x;
}

int Trem::getY() {
    return y;
}

void Trem::setY(int y) {
    this->y = y;
}

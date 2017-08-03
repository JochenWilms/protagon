#include "world_handler.h"

World_handler::World_handler(int NrOfHealthpacks,int NrOfEnemies)
{
    world = new World();
    world_tiles = world->createWorld(":/maze1.png");
    enemies = world->getEnemies(NrOfEnemies);
    healthpacks= world->getHealthPacks(NrOfHealthpacks);
    protagon= world->getProtagonist();
    //set qpixmap
    wall = std::make_shared<QPixmap>(":/wall.png");
    grass = std::make_shared<QPixmap>(":/grass.png");
    protagon_front = std::make_shared<QPixmap>(":/protagon_front.png");
    enemy = std::make_shared<QPixmap>(":/zombie.png");
    health = std::make_shared<QPixmap>(":/health.png");

    FindStartPosition();
}

void World_handler::FindStartPosition()
{
     int i= 0;
     while(world_tiles.at(i)->getValue()== INFINITY){
         i++;
     }
     //i++;
     protagon->setPos(world_tiles.at(i)->getXPos(),world_tiles.at(i)->getXPos());
}


void World_handler::Move_up()
{
    int place = world->getCols()*(protagon->getYPos()-1)+protagon->getXPos();
    if(world_tiles.at(place)->getValue()!= INFINITY){
         protagon->setPos(protagon->getXPos(),protagon->getYPos()-1);
    }
}

void World_handler::Move_down()
{
    int place = world->getCols()*(protagon->getYPos()+1)+protagon->getXPos();
    if(world_tiles.at(place)->getValue()!= INFINITY){
         protagon->setPos(protagon->getXPos(),protagon->getYPos()+1);
    }
}

void World_handler::Move_left()
{
    int place = world->getCols()*(protagon->getYPos())+protagon->getXPos()-1;
    if(world_tiles.at(place)->getValue()!= INFINITY){
         protagon->setPos(protagon->getXPos()-1,protagon->getYPos());
    }
}

void World_handler::Move_right()
{
    int place = world->getCols()*(protagon->getYPos())+protagon->getXPos()+1;
    if(world_tiles.at(place)->getValue()!= INFINITY){
         protagon->setPos(protagon->getXPos()+1,protagon->getYPos());
    }
}

//getters
std::shared_ptr<QPixmap> World_handler::getPixmapOfTile(int x, int y)
{
    int place = world->getCols()*(y)+x;
    if(world_tiles.at(place)->getValue()== INFINITY){
        return wall;
    }else{
        return grass;
    }
}

std::shared_ptr<QPixmap> World_handler::getPixmapOfProtagon()
{
    return protagon_front;
}

std::shared_ptr<QPixmap> World_handler::getPixmapOfenemy()
{
    return enemy;
}

std::shared_ptr<QPixmap> World_handler::getPixmapOfhealthpack()
{
    return health;
}

int World_handler::getXPosProtagon()
{
    return protagon->getXPos();
}

int World_handler::getYPosProtagon()
{
    return protagon->getYPos();
}

int World_handler::getXPosEnemy(int i)
{
    int place = world->getCols()*(enemies.at(i)->getYPos())+enemies.at(i)->getXPos();
    while(world_tiles.at(place)->getValue()== INFINITY){
          place++;
    }
    enemies.at(i)->setXPos(world_tiles.at(place)->getXPos());
    enemies.at(i)->setYPos(world_tiles.at(place)->getYPos());
    return enemies.at(i)->getXPos();
}

int World_handler::getYPosEnemy(int i)
{
    int place = world->getCols()*(enemies.at(i)->getYPos())+enemies.at(i)->getXPos();
    while(world_tiles.at(place)->getValue()== INFINITY){
          place++;
    }
    enemies.at(i)->setXPos(world_tiles.at(place)->getXPos());
    enemies.at(i)->setYPos(world_tiles.at(place)->getYPos());

    return enemies.at(i)->getYPos();
}

int World_handler::getXPosHealthpack(int i)
{
    int place = world->getCols()*(healthpacks.at(i)->getYPos())+healthpacks.at(i)->getXPos();
    while(world_tiles.at(place)->getValue()== INFINITY){
          place++;
    }
    healthpacks.at(i)->setXPos(world_tiles.at(place)->getXPos());
    healthpacks.at(i)->setYPos(world_tiles.at(place)->getYPos());

    return healthpacks.at(i)->getXPos();
}

int World_handler::getYPosHealthpack(int i)
{
    int place = world->getCols()*(healthpacks.at(i)->getYPos())+healthpacks.at(i)->getXPos();
    while(world_tiles.at(place)->getValue()== INFINITY){
          place++;
    }
    healthpacks.at(i)->setXPos(world_tiles.at(place)->getXPos());
    healthpacks.at(i)->setYPos(world_tiles.at(place)->getYPos());

    return healthpacks.at(i)->getYPos();
}




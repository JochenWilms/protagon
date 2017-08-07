#include "world_handler.h"


World_handler::World_handler(int NrOfHealthpacks,int NrOfEnemies)
{
    world = new World();

    for(auto & tile : world->createWorld(":/maze1.png")){
            std::shared_ptr<Tile> t = std::move(tile);
            world_tiles.push_back(t);
        }

        for(auto & enemy : world->getEnemies(NrOfEnemies)){
            std::shared_ptr<Enemy> e =  std::move(enemy);
            enemies.push_back(e);
        }

        for(auto & health : world->getHealthPacks(NrOfHealthpacks)){
            std::shared_ptr<Tile> h = std::move(health);
            healthpacks.push_back(h);
        }

    protagon = std::move(world->getProtagonist());

    //set qpixmap
    wall = std::make_shared<QPixmap>(":/wall.png");
    grass = std::make_shared<QPixmap>(":/grass.png");
    grass_walked = std::make_shared<QPixmap>(":/grasswalked.png");
    protagon_front = std::make_shared<QPixmap>(":/protagon_front.png");
    enemy = std::make_shared<QPixmap>(":/zombie.png");
    health = std::make_shared<QPixmap>(":/health.png");
    path = std::make_shared<QPixmap>(":/grasswalked.png");

    FindStartPosition();
}

QQueue<int> World_handler::convertPath(std::shared_ptr<Node> path){

    QQueue<int> queue;

    //reverse the path so you can go from start to end
    while(path->getParentNode() != NULL){

        int dir = 0;
        auto previous = path->getParentNode()->getTile();

        if (path->getTile()->getXPos() < previous->getXPos())
            dir = 1; //left
        else if(path->getTile()->getXPos() > previous->getXPos())
            dir = 2; //right

        if (path->getTile()->getYPos() < previous->getYPos())
            dir = 3; //up
        else if(path->getTile()->getYPos() > previous->getYPos())
            dir = 4; //down

        queue.prepend(dir);

        path = path->getParentNode();
    }

    return queue;

}

std::vector<std::shared_ptr<Enemy> > World_handler::getEnemies() const
{
    return enemies;
}

void World_handler::setEnemies(const std::vector<std::shared_ptr<Enemy> > &value)
{
    enemies = value;
}

std::vector<std::shared_ptr<Tile> > World_handler::getHealthpacks() const
{
    return healthpacks;
}

void World_handler::setHealthpacks(const std::vector<std::shared_ptr<Tile> > &value)
{
    healthpacks = value;
}

std::vector<std::shared_ptr<Tile> > World_handler::getAdjacentTiles(int xPos, int yPos)
{
    std::vector <std::shared_ptr<Tile> > adjacentTiles;
    int col = world->getCols();
    int row = world->getRows();

    int dir = 0;
    while(dir < 4)
    {
        std::shared_ptr<Tile> tile;

        std::shared_ptr<Tile> t = std::move(tile);

        switch(dir)
        {
            case 0: //"right"

               if(xPos < col)
                   tile = world_tiles.at(xPos + 1 + (yPos * col));

               break;

            case 1: // "down"

               if(yPos < row)
                    tile = world_tiles.at( xPos + ((yPos + 1) * col) );

               break;

            case 2: // "left"

               if(xPos > 0)
                    tile = world_tiles.at( xPos - 1 + (yPos * col) );

               break;

            case 3: //"up"

               if(yPos > 0)
                    tile = world_tiles.at( xPos + ((yPos - 1) * col));

               break;

        }

        if(tile != NULL)
        {

            if(std::isfinite(tile->getValue()))
                adjacentTiles.push_back(tile);

        }

        dir++;

    }

    return adjacentTiles;

}


std::shared_ptr<Tile> World_handler::FindStartPosition()
{
     int i= 0;
     while(world_tiles.at(i)->getValue()== INFINITY){
         i++;
     }
     //i++;
     std::shared_ptr<Tile> firstTile = world_tiles.at(i);
     protagon->setPos(firstTile->getXPos(),firstTile->getXPos());
     return firstTile;

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

std::shared_ptr<QPixmap> World_handler::getPixmapOfgrassWalked()
{
    return grass_walked;
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

std::shared_ptr<QPixmap> World_handler::getPixmapOfPath()
{
    return path;
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

int World_handler::getWorldcols()
{
    return world->getCols();
}




#ifndef WORLD_HANDLER_H
#define WORLD_HANDLER_H
#include <QtGui>
#include "world.h"
#include <QPixmap>
#include "node.h"


class World_handler
{
public:
    World_handler(int healthpacks,int enemies);
    std::shared_ptr<Tile> FindStartPosition();

    void Move_up();
    void Move_down();
    void Move_left();
    void Move_right();

    //position getters
    std::shared_ptr<QPixmap> getPixmapOfTile(int x, int y);
    std::shared_ptr<QPixmap> getPixmapOfgrassWalked();
    std::shared_ptr<QPixmap> getPixmapOfProtagon();
    std::shared_ptr<QPixmap> getPixmapOfenemy();
    std::shared_ptr<QPixmap> getPixmapOfhealthpack();

    int getXPosProtagon();
    int getYPosProtagon();

    int getXPosEnemy(int i);
    int getYPosEnemy(int i);

    int getXPosHealthpack(int i);
    int getYPosHealthpack(int i);

    int getWorldcols();

    QQueue<int> convertPath(std::shared_ptr<Node> path);
    std::vector<std::shared_ptr<Enemy> > getEnemies() const;
    void setEnemies(const std::vector<std::shared_ptr<Enemy> > &value);
    std::vector<std::shared_ptr<Tile> > getHealthpacks() const;
    void setHealthpacks(const std::vector<std::shared_ptr<Tile> > &value);
    std::vector<std::shared_ptr<Tile> > getAdjacentTiles(int xPos, int yPos);

    std::shared_ptr<QPixmap> getPixmapOfPath();
private:
    World *world ;
    std::vector<std::shared_ptr<Tile>> world_tiles;
    std::vector<std::shared_ptr<Enemy>> enemies ;
    std::vector<std::shared_ptr<Tile>> healthpacks;
    std::shared_ptr<Protagonist> protagon;
    std::shared_ptr<QPixmap> wall;
    std::shared_ptr<QPixmap> grass;
    std::shared_ptr<QPixmap> grass_walked;
    std::shared_ptr<QPixmap> protagon_front;
    std::shared_ptr<QPixmap> health;
    std::shared_ptr<QPixmap> enemy;
    std::shared_ptr<QPixmap> path;
};

#endif // WORLD_HANDLER_H

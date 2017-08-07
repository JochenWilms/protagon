#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <QQueue>
#include <QLinkedList>
#include <memory>
#include "node.h"
#include <string>
#include "world_handler.h"

using namespace std;

class Pathfinder
{
public:
    Pathfinder(std::shared_ptr<World_handler> scenemodel);
    std::shared_ptr<Node> planPath(std::shared_ptr<Tile> t1, std::shared_ptr<Tile> t2);

    double calcDistance(std::shared_ptr<Tile> t1, std::shared_ptr<Tile> t2);
    std::vector<std::shared_ptr<Node>> createNext(std::shared_ptr<Node> node, std::shared_ptr<Tile> tile);

    bool myComp(Node n1, Node n2);
    double manhattanDistance(std::shared_ptr<Tile> t1, std::shared_ptr<Tile> t2);

    string makePathSnippet(std::shared_ptr<Tile> t);
    string lastPathSnippet(std::shared_ptr<Node> n);

    void goThroughOpenlist(std::shared_ptr<Node> nextNode);

    std::shared_ptr<Tile> nextHealthPack(std::shared_ptr<Tile> currentPosition);
    std::shared_ptr<Enemy> nextEnemy(std::shared_ptr<Tile> currentPosition);
private:
    QQueue<Node> openlist;
    QQueue<Node> closedlist;
    std::shared_ptr<World_handler> model;
};



#endif // PATHFINDER_H

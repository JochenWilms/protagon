#ifndef NODE_H
#define NODE_H

#include "world.h"
#include <memory>
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    Node();
    Node(const Node &obj);
    Node(std::shared_ptr<Tile> tile, std::shared_ptr<Node> parent, double moveCost, double estimationH, string pathSnippet);

    std::shared_ptr<Tile> getTile() const;
    void setTile(const std::shared_ptr<Tile> value);

    std::shared_ptr<Node> getParentNode() const;
    void setParentNode(const std::shared_ptr<Node> value);

    double getEstimationH() const;
    void setEstimationH(double value);

    double getMoveCost() const;
    void setMoveCost(double value);

    string getPath() const;
    void setPath(const string &value);

    double getFcost() const;

private:
    std::shared_ptr<Tile> tile;
    std::shared_ptr<Node> parentNode;
    double moveCost;
    double estimationH;
    string path;

};

#endif // NODE_H

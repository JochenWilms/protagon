#include "node.h"



Node::Node()
{
}

Node::Node(const Node &obj)
{
    parentNode = obj.getParentNode();
    moveCost = obj.getMoveCost();
    estimationH = obj.getEstimationH();
    tile = obj.getTile();
    path = obj.getPath();
}

Node::Node(std::shared_ptr<Tile> newtile, std::shared_ptr<Node> parent, double move, double h, string pathSnippet)
{
    tile = newtile;
    parentNode = parent;
    moveCost = move;
    estimationH = h;

    setPath(parent->getPath() + pathSnippet);
}

std::shared_ptr<Tile> Node::getTile() const
{
    return tile;
}

std::shared_ptr<Node> Node::getParentNode() const
{
    return parentNode;
}

double Node::getEstimationH() const
{
    return estimationH;
}

void Node::setEstimationH(double value)
{
    estimationH = value;
}

double Node::getMoveCost() const
{
    return moveCost;
}

void Node::setMoveCost(double value)
{
    moveCost = value;
}

string Node::getPath() const
{
    return path;
}

void Node::setPath(const string &value)
{
    path = value;
}


double Node::getFcost() const
{
    return getMoveCost() + getEstimationH();
}


void Node::setParentNode(std::shared_ptr<Node> value)
{
    parentNode = value;
}

void Node::setTile(const std::shared_ptr<Tile> value)
{
    tile = value;
}



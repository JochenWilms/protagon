#include "pathfinder.h"
#include "world.h"

Pathfinder::Pathfinder(std::shared_ptr<World_handler> scenemodel)
{
    model = scenemodel;
}

std::shared_ptr<Node> Pathfinder::planPath(std::shared_ptr<Tile> t1, std::shared_ptr<Tile> t2)
{
    //create root node and add it to open list
    Node initNode;
    initNode.setTile( t1);
    double heuristic = manhattanDistance(t1, t2);
    initNode.setEstimationH(heuristic);
    initNode.setMoveCost(0.0);
    initNode.setPath(makePathSnippet(t1));

    openlist.append(initNode);

    //look for the lowest F cost in open list
    bool goal = false;
    std::shared_ptr<Node> bestNode;

    while(!openlist.empty()){

        bestNode = std::make_shared<Node>(openlist.dequeue());

        //check if you reached the goal tile
        if(*(bestNode->getTile()) == *t2){
            goal = true;
            break;
        }

        //switch it to the closed list
        closedlist.append(*bestNode);

        //create adjecent nodes
        std::vector<std::shared_ptr<Node>> nextNodes = createNext(bestNode , t2);

        //go through these nodes to compare with the open list
        //http://www.policyalmanac.org/games/aStarTutorial.htm
        for(auto nextNode: nextNodes){

           Pathfinder::goThroughOpenlist(nextNode);

        }

    }

    if(goal)
      return bestNode;

    else
        return NULL;

}


void Pathfinder::goThroughOpenlist(std::shared_ptr<Node> nextNode){

    int toDelete = -1;
    int dest = 0;

    for( int i=0 ; i < openlist.size() ; i++){

        std::shared_ptr<Node> cNode = std::make_shared<Node>(openlist.at(i));

        string snippet = lastPathSnippet(nextNode);
        string path = cNode->getPath();

        //look if the node is found in a path in openlist
        if(path.find(snippet) != -1){

            std::shared_ptr<Node> cmpNode = cNode;

            do{
                if(nextNode->getTile() == cmpNode->getTile()){

                    //nextNode is better than node in openlist
                    if( nextNode->getMoveCost() < cNode->getMoveCost() )
                        toDelete = i;

                    //nextNode is worse
                    else
                        return;

                }

                cmpNode = cmpNode->getParentNode();

            } while(cmpNode != NULL );
        }


        if(nextNode->getFcost() >= cNode->getFcost())
            dest = i;

    }

    if(toDelete != -1)
        openlist.removeAt(toDelete);

    //push created node to the right place in the open list
    openlist.insert(dest, *nextNode);

}

std::vector<std::shared_ptr<Node>> Pathfinder::createNext(std::shared_ptr<Node> givenNode, std::shared_ptr<Tile> endTile)
{
    std::shared_ptr<Tile> currentTile = givenNode->getTile();
    std::vector<std::shared_ptr<Tile>> adjentTiles = model->getAdjacentTiles(currentTile->getXPos(), currentTile->getYPos());
    std::vector<std::shared_ptr<Node>> nextNodes;

    while(!adjentTiles.empty())
    {
        std::shared_ptr<Tile> newTile = adjentTiles.back();

        string pathSnippet = makePathSnippet(newTile);

        //ignore tile that is already in closed list
        bool found = false;
        for(auto & node : closedlist){
            string path = node.getPath();
            if (path.find(pathSnippet) != -1){
               found = true;
               break;
            }
        }

        if( found ){
            adjentTiles.pop_back();
            continue;
        }

        //make the new node with its parameters
        double movecost = currentTile->getValue();
        double hcost = manhattanDistance(currentTile,endTile);

        std::shared_ptr<Node> newnode (new Node(newTile, givenNode, movecost, hcost, pathSnippet));


        nextNodes.push_back(newnode);
        adjentTiles.pop_back();
    }

    return nextNodes;
}


string Pathfinder::makePathSnippet(std::shared_ptr<Tile> t){

   return '-' + to_string(t->getXPos()) + ':' + to_string(t->getYPos()) ;

}

string Pathfinder::lastPathSnippet(std::shared_ptr<Node> n){

    string str = n->getPath();
    std::size_t found = str.find_last_of("-");
    return str.substr(found);
}



double Pathfinder::calcDistance(std::shared_ptr<Tile> t1, std::shared_ptr<Tile> t2)
{

    int x1 = t1->getXPos();
    int y1 = t1->getYPos();

    int x2 = t2->getXPos();
    int y2 = t2->getYPos();

    double dist = sqrt((x2-x1)*(y2-y1));

    return dist;

}

double Pathfinder::manhattanDistance(std::shared_ptr<Tile> t1, std::shared_ptr<Tile> t2)
{
    int D = 1;

    int x1 = t1->getXPos();
    int y1 = t1->getYPos();

    int x2 = t2->getXPos();
    int y2 = t2->getYPos();

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    int manhattan = D * (dx + dy);

    return manhattan;

}

std::shared_ptr<Enemy> Pathfinder::nextEnemy(std::shared_ptr<Tile> currentPosition){

    std::vector<std::shared_ptr<Enemy>> enemies = model->getEnemies();

    int i = 0;
    int minDist = -1;
    int location = -1;

    for(std::shared_ptr<Enemy> enemy: enemies){

        if(!enemy->getDefeated()){

            int dist = manhattanDistance(currentPosition, enemy);

            if( minDist == -1 || dist < minDist ){
                minDist = dist;
                location = i;
            }
        }

        i++;
    }

    if(location != -1)
        return enemies.at(location);

    else
        return NULL;
}


std::shared_ptr<Tile> Pathfinder::nextHealthPack(std::shared_ptr<Tile> currentPosition){

    std::vector<std::shared_ptr<Tile>> healthPacks = model->getHealthpacks();

    int i = 0;
    int minDist = -1;
    int location = -1;

    for(std::shared_ptr<Tile> health: healthPacks){


        int dist = manhattanDistance(currentPosition, health);

        if( minDist == -1 || dist < minDist ){
            minDist = dist;
            location = i;
        }

        i++;
    }

    if(location != -1)
        return healthPacks.at(location);

    else
        return NULL;
}




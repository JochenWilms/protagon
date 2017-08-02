#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "world.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QKeyEvent>
#include <QEvent>
#include "world_handler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DisplayTiles();
    void DisplayCharacters();
protected:
    void resizeEvent(QResizeEvent* event);
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *Object, QEvent *Event);
private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene* scene;

    std::shared_ptr<World_handler> world;
    unsigned long int tilesneededy;
    unsigned long int tilesneededx;
    const int scale = 50;
    QPen pen;
    QBrush brush;
    QGraphicsPixmapItem* protagonPix;
    int maxCol;
    int minCol;
    int maxRow;
    int minRow;
    const int NrOfhealtpacks = 10;
    const int NrOfenemies = 1;
};

#endif // MAINWINDOW_H

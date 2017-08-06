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
#include <QScrollBar>
#include <QMouseEvent>


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
    void KeepProtagonCentered();
    void showPath();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent* event);
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *Object, QEvent *Event);

private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene* scene;
    QScrollBar* Yscroll;
    QScrollBar* Xscroll;

    std::shared_ptr<World_handler> world;
    std::vector<QGraphicsPixmapItem*> world_pixmaps;
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
    const int NrOfenemies = 20;
};

#endif // MAINWINDOW_H

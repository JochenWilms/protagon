#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    view = new QGraphicsView();
    ui->setupUi(this);
    this->installEventFilter(this);

    this->setMouseTracking(true);
    scene = new QGraphicsScene(this);
    Yscroll=ui->graphicsView->verticalScrollBar();
    Xscroll =ui->graphicsView->horizontalScrollBar();
    Yscroll->setValue(scale);
    Xscroll->setValue(scale);
    world = std::make_shared<World_handler>(NrOfhealtpacks,NrOfenemies);

    this->setFocus();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    DisplayTiles();
    DisplayCharacters();

    QWidget *dummyWidget = new QWidget();
    QFormLayout *formLayout = new QFormLayout;
    QProgressBar *bar1 = new QProgressBar();
    QProgressBar *bar2 = new QProgressBar();
    bar1->setValue(100);
    bar2->setValue(100);
    formLayout->addRow("&Health:", bar1);
    formLayout->addRow("&Energy:", bar2);
    dummyWidget->setLayout(formLayout);
    scene->addWidget(dummyWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::DisplayTiles(){
    //display tiles

        for(unsigned long int j =0;j<500; j++) {
            for(unsigned long int i =0;i<500; i++) {
                QGraphicsPixmapItem* pix = scene->addPixmap(*(world->getPixmapOfTile(i,j)));
                pix->setPos(i*scale,j*scale);
                world_pixmaps.push_back(pix);
            }
        }


}

void MainWindow::DisplayCharacters(){

    //display protagon
    protagonPix = scene->addPixmap(*(world->getPixmapOfProtagon()));
    protagonPix->setFlag(QGraphicsItem::ItemIsMovable);
    protagonPix->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    protagonPix->setPos(world->getXPosProtagon()*scale,world->getYPosProtagon()*scale);
    showPath();
    //Display health
    for(int i=0;i<NrOfhealtpacks;i++){
        QGraphicsPixmapItem* pix = scene->addPixmap(*(world->getPixmapOfhealthpack()));
        pix->setPos(world->getXPosHealthpack(i)*scale,world->getYPosHealthpack(i)*scale);
    }
    //display enemies
    for(int i=0;i<NrOfenemies;i++){
        QGraphicsPixmapItem* pix = scene->addPixmap(*(world->getPixmapOfenemy()));
        pix->setPos(world->getXPosEnemy(i)*scale,world->getYPosEnemy(i)*scale);
    }

}

void MainWindow::KeepProtagonCentered()
{
    Yscroll->setValue((world->getYPosProtagon()*scale)-(this->height()/2));
    Xscroll->setValue((world->getXPosProtagon()*scale)-(this->width()/2));
}

void MainWindow::showPath()
{
    QGraphicsPixmapItem* pix = world_pixmaps.at(world->getYPosProtagon()*world->getWorldcols()+world->getXPosProtagon());
    pix->setPixmap(*(world->getPixmapOfgrassWalked()));

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouse moved";
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->graphicsView->resize(this->width(),this->height());
    tilesneededx = (ui->graphicsView->width()/scale);
    tilesneededy = (ui->graphicsView->height()/scale);
}


bool MainWindow::eventFilter(QObject *Object, QEvent *Event)
{

  if (Event->type() == QEvent::KeyPress)
  {
    QKeyEvent *KeyEvent = (QKeyEvent*)Event;

    switch(KeyEvent->key())
    {
    case Qt::Key_Up:                               // up
        //test comment
       world->Move_up();
       KeepProtagonCentered();
       qDebug() << "You typed up";
        break;
    case Qt::Key_Down:                               // down
        world->Move_down();
        KeepProtagonCentered();
        qDebug() << "You typed down";
        break;
    case Qt::Key_Left:                               // left
         world->Move_left();
         KeepProtagonCentered();
        qDebug() << "You typed left";
        break;
    case Qt::Key_Right:                               // right
        world->Move_right();
        KeepProtagonCentered();
        qDebug() << "You typed right";
        break;
    case Qt::Key_Z:                               // up
        world->Move_up();
        KeepProtagonCentered();
       qDebug() << "You typed z ";
        break;
    case Qt::Key_S:                               // down
         world->Move_down();
         KeepProtagonCentered();
        qDebug() << "You typed s ";
        break;
    case Qt::Key_Q:                               // left
         world->Move_left();
         KeepProtagonCentered();
        qDebug() << "You typed q ";
        break;
    case Qt::Key_D:                               // right
         world->Move_right();
         KeepProtagonCentered();
       qDebug() << "You typed d";
        break;
    case Qt::Key_Space:                               // right
         KeepProtagonCentered();

       qDebug() << "You typed spacebar";
        break;
    }
    //DisplayTiles();
    protagonPix->setPos(world->getXPosProtagon()*scale,world->getYPosProtagon()*scale);
    showPath();
    return true;
  }

  if (Event->type() == QEvent::MouseButtonPress){
       QMouseEvent *mouseEvent = static_cast< QMouseEvent* >( Event );
      qDebug() << "mouse clicked";
      qDebug() << mouseEvent->pos();
      return true;

  }

  return QObject::eventFilter(Object,Event);
}

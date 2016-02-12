#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapfield.h"
#include "maplife.h"

MapField **map = new MapField*[10000];
maplife *life = new maplife();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->mapView->setScene(scene);
    scene->setSceneRect(0,0,400,400);
    QPen mypen = QPen(Qt::red);
    int size = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            int x=i*4;
            int y=j*4;
            map[size]=new MapField(x,y);
            scene->addItem(map[size]);
            size++;
        }
    }
}

MainWindow::~MainWindow(){
    delete ui;
    delete map;
    delete life;
}

void MainWindow::on_menu_quit_triggered(){
    delete ui;
    delete map;
    delete life;
    quick_exit(0);
}

void MainWindow::on_menu_New_Game_triggered(){
    life->zero_day();
    QString day_label = life->set_label();
    ui->day_label->setText(day_label);
}

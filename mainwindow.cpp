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
    ui->start_button->setCheckable(true);
    scene = new QGraphicsScene(this);
    ui->mapView->setScene(scene);
    scene->setSceneRect(0,0,400,400);
    QPen mypen = QPen(Qt::red);
    int size = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            int y=i*4;
            int x=j*4;
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

void MainWindow::display(){
    ui->plant_number->display(life->quantity(1));
    ui->herb_number->display(life->quantity(3));
    ui->carn_number->display(life->quantity(5));
    scene->update(0,0,400,400);
}

void MainWindow::on_menu_quit_triggered(){
    delete ui;
    delete map;
    delete life;
    quick_exit(0);
}

void MainWindow::on_menu_New_Game_triggered(){
    life->zero_day();
    life->zero_field();
    QString day_label = life->set_label();
    ui->day_label->setText(day_label);
    for(int i=0; i<10000; i++){
        map[i]->set_field(0);
    }
    display();
}

void MainWindow::on_menu_Random_triggered(){
    for(int i=0; i<10000; i++){
        map[i]->random_field(i, life);
    }
    display();
}

void MainWindow::on_menu_Clear_Map_triggered(){
    for(int i=0; i<10000; i++){
        map[i]->set_field(0);
    }
    life->zero_field();
    display();
}

void MainWindow::on_start_button_toggled(bool checked){/*to będzie więcej robiło :P*/
    if(checked){
        ui->day_label->setText("START");
    }
    else{
        ui->day_label->setText("PAUSE");
    }
}

void MainWindow::on_stop_button_clicked(){
    ui->start_button->setChecked(false);
    on_menu_Clear_Map_triggered();
}

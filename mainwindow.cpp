#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapfield.h"
#include "maplife.h"
#include <iostream>

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
    ui->mapView->isInteractive();
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
    ui->plant_number->display(life->quantity(plant_v));
    ui->herb_number->display(life->quantity(herb_v));
    ui->carn_number->display(life->quantity(carn_v));
    scene->update(0,0,400,400);
}

int MainWindow::creat_number(int x, int y){
    int i=(y-1)/4;
    int j=x/4;
    i=100*i+j;
return i;
}

field_value MainWindow::creat_type(){
    switch (ui->spiece_choose->currentIndex()) {
    case 0:
        return land_v;
        break;
    case 1:
        return plant_v;
        break;
    case 2:
        return herb_v;
        break;
    case 3:
        return carn_v;
        break;
    }
    return land_v;
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
        map[i]->set_field(land_v);
    }
    display();
}

void MainWindow::on_menu_Random_triggered(){
    life->zero_field();
    for(int i=0; i<10000; i++){
        map[i]->random_field(i, life);
    }
    display();
}

void MainWindow::on_menu_Clear_Map_triggered(){
    for(int i=0; i<10000; i++){
        map[i]->set_field(land_v);
    }
    life->zero_field();
    display();
}

void MainWindow::on_start_button_toggled(bool checked){/*to będzie więcej robiło :P*/
    if(checked){
        ui->start_button->setText("PAUSE");
    }
    else{
        ui->start_button->setText("START");
    }
}

void MainWindow::on_stop_button_clicked(){
    ui->start_button->setChecked(false);
    on_menu_Clear_Map_triggered();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        QPoint remapped = ui->mapView->mapFromParent(event->pos());
        remapped.setY(remapped.y()-40);
        if ( ui->mapView->rect().contains(remapped)){
            map[creat_number(remapped.x(),remapped.y())]->set_field(creat_type());
            display();
        }
    }
}

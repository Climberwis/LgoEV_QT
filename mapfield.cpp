#include "mapfield.h"
#include <iostream>

MapField::MapField(int x, int y){
    land=QBrush(Qt::white);
    plant=QBrush(Qt::green);
    herbivore=QBrush(Qt::blue);
    carnivore=QBrush(Qt::red);
        value=0;
        life=0;
        moved=0;
        setPos(mapToParent(x,y));
}

QRectF MapField::boundingRect() const{
    return QRect(0,0,4,4);
}

void MapField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF fieldCreat = boundingRect();
        if(value == 0){
            painter->fillRect(fieldCreat,land);
            painter->drawRect(fieldCreat);
        }
        if(value == 1){
            painter->fillRect(fieldCreat,plant);
            painter->drawRect(fieldCreat);
        }
        if(value == 3){
            painter->fillRect(fieldCreat,herbivore);
            painter->drawRect(fieldCreat);
        }
        if(value == 5){
            painter->fillRect(fieldCreat,carnivore);
            painter->drawRect(fieldCreat);
        }
}

void MapField::random_field(int i, maplife *lif){
    int z = (qrand()%51)/10;
    if(z==0 || z == 2){
        life=0;
        value=0;
    }
    else if(z==1 || z == 4){
        life=100;
        value=1;
    }
    else if(z==3 && i%8){
        life=60;
        value=3;
    }
    else if(z==5 && i%2){
        life=50;
        value=5;
    }
    lif->count_field(value);
    moved=0;
}

void MapField::set_field(field_value i){//takie cuś?
    switch (i) {
    case land_v:
        life=0;
        break;
    case plant_v:
        life=100;
        break;
    case herb_v:
        life=60;
        break;
    case carn_v:
        life=50;
        break;
    default:
        break;
    }
    value=i;
    moved=0;
}

int MapField::f_value(){
    return value;
}

MapField::~MapField(){
}

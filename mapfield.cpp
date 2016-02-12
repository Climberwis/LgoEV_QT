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

MapField::~MapField(){
}

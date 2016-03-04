#include "mapfield.h"
#include <iostream>

MapField::MapField(int x, int y){
    land=QBrush(Qt::white);
    plant=QBrush(Qt::green);
    herbivore=QBrush(Qt::blue);
    carnivore=QBrush(Qt::red);
    pos_x = x; pos_y = y;
    setPos(mapToParent(x,y));
#ifdef DEBUG
    cout << "MapField c-tor pos_x" << pos_x << " pos_y " << pos_y << endl;
#endif // DEBUG
}

QRectF MapField::boundingRect() const{
    return QRect(0,0,4,4);
}

void MapField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF fieldCreat = boundingRect();
        if(value == land_v){
            painter->fillRect(fieldCreat,land);
            painter->drawRect(fieldCreat);
        }
        if(value == plant_v){
            painter->fillRect(fieldCreat,plant);
            painter->drawRect(fieldCreat);
        }
        if(value == herb_v){
            painter->fillRect(fieldCreat,herbivore);
            painter->drawRect(fieldCreat);
        }
        if(value == carn_v){
            painter->fillRect(fieldCreat,carnivore);
            painter->drawRect(fieldCreat);
        }
}

void MapField::random_field(int i){
    int z = (qrand()%51)/10;
    if(z==0 || z == 2){
        life=0;
        value=land_v;
    }
    else if(z==1 || z == 4){
        life=100;
        value=plant_v;
    }
    else if(z==3 && i%8){
        life=60;
        value=herb_v;
    }
    else if(z==5 && i%2){
        life=50;
        value=carn_v;
    }
    moved=no;
}

void MapField::set_field(field_value i){
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
    moved=no;
}

void MapField::set_life(int i){
    life = i;
}

void MapField::set_moved(if_moved i){
    moved = i;
}

field_value MapField::v_value(){
    return value;
}

int MapField::v_life(){
    return life;
}

if_moved MapField::v_moved(){
    return moved;
}

void MapField::decr_life(int i){
    life-=i;
}

MapField::~MapField(){
#ifdef DEBUG
    cout << "MapField d-tor pos_x" << pos_x << " pos_y " << pos_y << endl;
#endif // DEBUG
}

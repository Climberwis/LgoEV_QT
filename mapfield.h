#ifndef MAPFIELD_H
#define MAPFIELD_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include "maplife.h"
#include "header.h"

class MapField : public QGraphicsItem{

public:
    MapField(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~MapField();
    void random_field(int i);
    void set_field(field_value i);
    field_value f_value();
    void f_moved(if_moved i);
    void decr_life(int i);
    int f_life();

private:
    field_value value = land_v;
    int         pos_x, pos_y;
    if_moved    moved = no;
    double      life = 0;
    QBrush      land, plant, herbivore, carnivore;
};

#endif // MAPFIELD_H

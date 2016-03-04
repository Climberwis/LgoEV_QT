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
    void set_life(int i);
    void set_moved(if_moved i);
    field_value v_value();
    int v_life();
    if_moved v_moved();
    void decr_life(int i);

private:
    field_value value = land_v;
    int         pos_x, pos_y;
    if_moved    moved = no;
    double      life = 0;
    QBrush      land, plant, herbivore, carnivore;
};

#endif // MAPFIELD_H

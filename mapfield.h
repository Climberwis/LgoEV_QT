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
    void random_field(int i, maplife *lif);
    void set_field(field_value i);
    int f_value();

private:
    field_value value = land_v;
    int 	moved = 0, pos_x, pos_y;
    double	life = 0;
    QBrush land, plant, herbivore, carnivore;
};

#endif // MAPFIELD_H

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
    field_value value;
    int 	moved;
    double	life;
    QBrush land, plant, herbivore, carnivore;
};

#endif // MAPFIELD_H

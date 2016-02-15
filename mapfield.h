#ifndef MAPFIELD_H
#define MAPFIELD_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class MapField : public QGraphicsItem{

public:
    MapField(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~MapField();
    void random_field(int i);
    void set_field(int i);


private:
    int 	value, moved;
    double	life;
    QBrush land, plant, herbivore, carnivore;
};

#endif // MAPFIELD_H

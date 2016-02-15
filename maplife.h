#ifndef MAPLIFE_H
#define MAPLIFE_H

#include <QGraphicsScene>

class maplife{

public:
    maplife();
    void zero_day();
    QString set_label();
    int size; // jeszcze zobaczę czy potrzebne

private:
    int n_xy, day_timer, plant_quant, herb_quant, carn_quant;
};

#endif // MAPLIFE_H

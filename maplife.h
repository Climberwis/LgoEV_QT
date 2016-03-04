#ifndef MAPLIFE_H
#define MAPLIFE_H

#include <QGraphicsScene>
#include "header.h"

class maplife{

public:
    maplife();
    void zero_day();
    void next_day();
    QString set_label();
    void count_field(field_value value);
    int quantity(field_value value);
    void zero_field();
    int l_day();

private:
    int n_xy, day_timer, plant_quant, herb_quant, carn_quant;
};

#endif // MAPLIFE_H

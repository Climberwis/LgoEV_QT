#ifndef MAPLIFE_H
#define MAPLIFE_H

#include <QGraphicsScene>
#include "header.h"

class maplife{

public:
    maplife();
    void zero_day();
    void next_day();
    int v_day();
    QString set_label();
    void count_field(field_value value);\
    void zero_field();
    int quantity(field_value value);

private:
    int day_timer = 0 , plant_quant = 0, herb_quant = 0, carn_quant = 0;
};

#endif // MAPLIFE_H

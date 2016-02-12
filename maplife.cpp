#include "maplife.h"

maplife::maplife(){
    n_xy=100;
    size=n_xy*n_xy;
    day_timer = 0;
}

void maplife::zero_day(){
    day_timer = 0;
}

QString maplife::set_label(){
    QString label="Day no. ";
    QString day = QString::number(day_timer);
    label += day;
    return label;
}

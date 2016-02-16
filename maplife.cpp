#include "maplife.h"

maplife::maplife(){
    n_xy=100;
    size=n_xy*n_xy;
    day_timer = 0;
    plant_quant=0;
    herb_quant=0;
    carn_quant=0;
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

void maplife::count_field(int value){
    switch (value) {
    case 0:
        break;
    case 1:
        plant_quant++;
        break;
    case 3:
        herb_quant++;
        break;
    case 5:
        carn_quant++;
        break;
    }
}

int maplife::quantity(field_value value){
    switch (value) {
    case land_v:
        break;
    case plant_v:
        return plant_quant;
        break;
    case herb_v:
        return herb_quant;
        break;
    case carn_v:
        return carn_quant;
        break;
    }
    return 0;
}

void maplife::zero_field(){
    plant_quant=0;
    herb_quant=0;
    carn_quant=0;
}

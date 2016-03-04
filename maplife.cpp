#include "maplife.h"

maplife::maplife(){
}

void maplife::zero_day(){
    day_timer = 0;
}

void maplife::next_day(){
    day_timer++;
}

int maplife::v_day(){
    return day_timer;
}

QString maplife::set_label(){
    QString label="Day no. ";
    QString day = QString::number(day_timer);
    label += day;
    return label;
}

void maplife::count_field(field_value value){
    switch (value) {
    case land_v:
        break;
    case plant_v:
        plant_quant++;
        break;
    case herb_v:
        herb_quant++;
        break;
    case carn_v:
        carn_quant++;
        break;
    }
}

void maplife::zero_field(){
    plant_quant=0;
    herb_quant=0;
    carn_quant=0;
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

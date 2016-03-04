#include "fun_header.h"
#include "header.h"
#include "mapfield.h"
#include <QGraphicsItem>

int losuj_pole(int i){
    int j = (qrand()%8);
    if(j<3){
        if(i==99 && j == 2) j = 9900;
        else if(i<=99) j = 9899+i+j;
        else if(!(i%100) && j == 0) j = i-1;
        else if(!((i+1)%100) && j == 2) j = i-199;
        else j = i-101+j;
    }
    else if(j==3){
        if(!(i%100)) j =i+99;
        else j=i-1;
    }
    else if(j==4){
        if(!((i+1)%100 )) j =i-99;
        else j=i+1;
    }
    else if(i>=9900 && j==6) j = i - 9900;
    else if(j==6) j=i+100;
    else if(j==5 || j == 7){
        if(i==9800 && j == 6) j = 9999;
        else if(i==9999 && j == 7) j = 1;
        else if(i==9900 && j == 5) j = 99;
        else if(i>=9900) j = i-9906+j;
        else if(!(i%100) && j == 5) j = i + 199;
        else if(!((i+1)%100) && j == 7) j = i + 1;
        else j = i+94+j;
    }
    return j;
}

void compare(MapField **map, int i, int j){
    if(map[j]->v_value() == land_v){
        map[j]->set_field(map[i]->v_value());
        map[j]->set_moved(yes);
        map[j]->set_life(map[i]->v_life());
        map[i]->set_field(land_v);
    } else if(map[i]->v_value()==map[j]->v_value()){
        if(map[i]->v_life()>=100 && map[j]->v_life()>=100){
            int l = losuj_pole(i);
                if(map[l]->v_value()==land_v || map[l]->v_value()==plant_v){
                    map[l]->set_field(map[i]->v_value());
                    map[l]->set_life((0.33*(map[i]->v_life()+map[j]->v_life())));
                    map[i]->set_life((0.66*map[i]->v_life()));
                    map[j]->set_life((0.66*map[j]->v_life()));
                } else return;
            } else return;
        } else if(abs(map[j]->v_value()-map[i]->v_value()) == 2){
            if(map[j]->v_value()<map[i]->v_value()) map[j]->set_field(map[i]->v_value());
            map[j]->set_life(map[j]->v_life()+map[i]->v_life());
            map[i]->set_field(land_v);
        } else if(abs(map[j]->v_value()-map[i]->v_value()) == 4){
            if(map[i]->v_moved() == no){
                map[i]->set_moved(yes);
                j = losuj_pole(i);
                compare(map, i, j);
            } else return;
        }
    map[i]->set_moved(yes);
}

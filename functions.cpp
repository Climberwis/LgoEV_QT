#include "header.h"
#include <QGraphicsItem>

int losuj_pole(int i){
    int j = (qrand()%8);
    if(j<3){
        if(i<=99) j = 9899+i+j;
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

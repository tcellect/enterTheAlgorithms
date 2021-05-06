//
//  main.c
//  modularC
//
//  Created by Deniss Orlov on 01.05.2021.
//

#include <stdio.h>

struct Rectangle {
    int hight;
    int width;
};

void initializeRect(struct Rectangle *r, int *h, int *w){
    r->hight = *h;
    r->width = *w;
}

void whatRect(int *h, int *w){
    printf("enter hight\n");
    scanf("%d", h);
    printf("enter width\n");
    scanf("%d", w);
}

int perimeter(struct Rectangle *r){
    return 2*(r->hight+r->width);
}

int area(struct Rectangle *r){
    return r->hight*r->width;
}

int main(int argc, const char * argv[]) {
    
    // allocate memory
    int hight; int width;
    struct Rectangle r;
    
    // ask for user input
    whatRect(&hight, &width);
    
    // create certain rectangle
    initializeRect(&r, &hight, &width);
    int per = perimeter(&r);
    int ar = area(&r);
    
    // show the result
    printf("hight=%d\nwidth=%d\nperimeter=%d\narea=%d\n", r.hight, r.width, per, ar);
    
    return 0;
}

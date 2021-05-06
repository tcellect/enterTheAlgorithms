//
//  main.cpp
//  classCPP
//
//  Created by Deniss Orlov on 01.05.2021.
//

#include <iostream>

struct Rectangle {
    int hight = 0;
    int width = 0;

    void whatRect(){
        printf("enter hight\n");
        scanf("%d", &hight);
        printf("enter width\n");
        scanf("%d", &width);
    }

    int perimeter(){
        return 2*(hight+width);
    }

    int area(){
        return hight*width;
    }
};

int main(int argc, const char * argv[]) {
    
    // allocate memory
    Rectangle r = {10, 20};
    
    // ask for user input
    r.whatRect();
    
    // access certain behaviour
    int per = r.perimeter();
    int ar = r.area();
    
    // show the result
    printf("hight=%d\nwidth=%d\nperimeter=%d\narea=%d\n", r.hight, r.width, per, ar);
    
    return 0;
}


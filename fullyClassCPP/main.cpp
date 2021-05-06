//
//  main.cpp
//  fullyClassCPP
//
//  Created by Deniss Orlov on 01.05.2021.
//

#include <iostream>

class Rectangle {
private:
        int hight = 0;
        int width = 0;
public:
    // this->higth will refer to current object
    Rectangle (int h, int w) {
        hight = h;
        width = w;
    };
    
    int getHight(){
        return hight;
    }
    
    int getWidth(){
        return width;
    }
    
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
    ~Rectangle(){
        printf("destrooooy\n");
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
    printf("hight=%d\nwidth=%d\nperimeter=%d\narea=%d\n", r.getHight(), r.getWidth(), per, ar);
    
    return 0;
}

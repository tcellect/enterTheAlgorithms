//
//  main.cpp
//  genericClassCPP
//
//  Created by Deniss Orlov on 01.05.2021.
//

#include <iostream>

template<class T>
class Rectangle {
private:
        T hight = 0;
        T width = 0;
public:
    Rectangle (T h, T w);
    T getHight();
    T getWidth();
    void whatRect();
    T perimeter();
    T area();
    ~Rectangle(){
        printf("destrooooy\n");
    }
};

template<class T>
Rectangle<T>::Rectangle(T h, T w){
    this->hight = h;
    this->width = w;
}

template<class T>
T Rectangle<T>::area(){
    return hight*width;
};

template<class T>
T Rectangle<T>::getWidth(){
    return width;
}

template<class T>
T Rectangle<T>::getHight(){
    return hight;
}

template<class T>
T Rectangle<T>::perimeter(){
    return 2*(hight+width);
}

template<class T>
void Rectangle<T>::whatRect(){
    printf("enter hight\n");
    scanf("%d", &hight);
    printf("enter width\n");
    scanf("%d", &width);
}

int main(int argc, const char * argv[]) {
    
    // allocate memory
    Rectangle<int> r = {10, 20};
    
    // ask for user input
    r.whatRect();
    
    // access certain behaviour
    int per = r.perimeter();
    int ar = r.area();
    
    // show the result
    printf("hight=%d\nwidth=%d\nperimeter=%d\narea=%d\n", r.getHight(), r.getWidth(), per, ar);
    
    return 0;
}

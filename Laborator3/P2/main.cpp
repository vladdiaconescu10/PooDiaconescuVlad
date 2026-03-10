#include <iostream>
#include "Canvas.h"
using namespace std;


int main() {
    Canvas canvas(25, 60); 

    canvas.DrawRect(2, 2, 20, 8, '#');


    canvas.FillRect(25, 2, 40, 8, '@');


    canvas.DrawCircle(15, 10, 8, 'O');
    

    canvas.FillCircle(45, 15, 10, '*');
    

    canvas.Print();
    return 0;
}
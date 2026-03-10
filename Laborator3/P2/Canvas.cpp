#include "Canvas.h" 
#include <iostream>

using namespace std;


Canvas::Canvas(int width, int height)
{
    this->coloane = width; 
    this->linii = height; 
    this->matrix = new char* [linii];
    for (int i = 0; i < linii; i++)
        this->matrix[i] = new char[coloane];

    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < linii; i++)
        delete[] this->matrix[i];
    delete[] this->matrix;
}

void Canvas::Clear()
{
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < coloane && y >= 0 && y < linii) {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; x++) {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }
    for (int y = top; y <= bottom; y++) {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            SetPoint(x, y, ch);
        }
    }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int cx = 0;
    int cy = ray;
    int d = 3 - 2 * ray; 

    while (cy >= cx) {
        
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x + cx, y - cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x - cy, y - cx, ch);

        cx++;
        if (d > 0) {
            cy--;
            d = d + 4 * (cx - cy) + 10;
        }
        else {
            d = d + 4 * cx + 6;
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    
    for (int i = y - ray; i <= y + ray; i++) {
        for (int j = x - ray; j <= x + ray; j++) {

            int dx = j - x;
            int dy = i - y;

            if ((dx * dx) + (dy * dy) <= (ray * ray)) {
                SetPoint(j, i, ch);
            }
        }
    }
}
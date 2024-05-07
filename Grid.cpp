#include "Grid.hpp"
#include <iostream>
using namespace std;

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}

Grid::Grid(int rows, int cols, int width, int height)
{
    this->rows = rows;
    this->cols = cols;
    this->sizeX = width / cols;
    this->sizeY = height / rows;

    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }

    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Grid::drawTo(RenderWindow &window)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(this->sizeX, this->sizeY));
            rect.setOutlineColor(Color::White);
            rect.setPosition(Vector2f(j * this->sizeX, i * this->sizeY));
            rect.setOutlineThickness(1);

            if (tablero[j][i] == 0)
            {
                rect.setFillColor(Color(51, 51, 51));
            }
            if (tablero[j][i] == 1)
            {
                rect.setFillColor(Color(Color ::Cyan));
            }
            window.draw(rect);
        }
    }
    // this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Grid::click(int x, int y)
{
    int indeX = x / this->sizeX;
    int indexY = y / this->sizeY;
    cout << indeX << "," << indexY << endl;
    if (tablero[indeX][indexY] == 0)
    {
        tablero[indeX][indexY] = 1;
    }
    else
    {
        tablero[indeX][indexY] = 0;
    }
}
 
void Grid::update()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {

int vecinos = this->vecinos(i,j);

if (this -> tablero [i][j] == 0 && vecinos == 3 ) {
    this->next[i][j] = 1;
}
if (this -> tablero [i][j] == 1 && vecinos > 3 ) {
    this->next[i][j] = 0;
}
if (this -> tablero [i][j] == 1 && vecinos < 3 ) {
    this->next[i][j] = 1;
}
if (this -> tablero [i][j] == 1 && vecinos == 1 || vecinos < 1 ) {
    this->next[i][j] = 0;
}

            /*if (this->tablero[i][j] == 1)
            {
                if (j == this->cols - 1)
                {
                    this->next[i][j] = 1;
                }
                else
                {
                    if (this->tablero[i][j + 1] == 0)
                    {
                        this->next[i][j] = 0;
                        this->next[i][j + 1] = 1;
                    }
                    else
                    {
                        this->next[i][j] = 1;
                    }
                    /// next[i][j + 1] = 1;
                }
            } */
        }
    }
    this->tablero = this->next;
}

int Grid ::vecinos(int i, int j)
{
    
    int numero = 0;
    if (this->tablero[i][j + 1] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i][j - 1] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i + 1][j] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i - 1][j] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i + 1][j + 1] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i + 1][j - 1] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i - 1][j + 1] == 1)
    {
        numero = numero + 1;
    }
    if (this->tablero[i - 1][j - 1] == 1)
    {
        numero = numero + 1;
    }
    return numero;
}
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

typedef std::vector<int> Vect;
typedef std::vector<Vect> Mtrx;

struct Item
{
    int weight;
    int value;
};

typedef std::vector<Item> Items;

void print(Items & _i);
Mtrx solveKnapsack(Items & _items, int _max_weight);
Items bestItems(Items & _items, Mtrx & _m);
void initZero(Mtrx & _m, int _rows, int _cols);
void print(Mtrx & _m);

int main(int/* _argc*/, char ** /* _argv*/)
{
    try
    {
        {
            int max_weight = 7;

            Items items =
            {
                {1, 1},
                {3, 4},
                {4, 5},
                {5, 7}
            };
            std::cout << " * Max weight: " << max_weight
                      << ", items:" << std::endl;
            print(items);

            auto weights = solveKnapsack(items, max_weight);
            std::cout << " solution:" << std::endl;
            print(weights);
            auto best_items = bestItems(items, weights);
            std::cout << " best items:" << std::endl;
            print(best_items);
        }
        std::cout << std::endl << std::endl << std::endl;
        {
            int max_weight = 7;

            Items items =
            {
                {5, 7},
                {4, 5},
                {3, 4},
                {1, 1}
            };
            std::cout << " * Max weight: " << max_weight
                      << ", items:" << std::endl;
            print(items);

            auto weights = solveKnapsack(items, max_weight);
            std::cout << " solution:" << std::endl;
            print(weights);
            auto best_items = bestItems(items, weights);
            std::cout << " best items:" << std::endl;
            print(best_items);
        }
        std::cout << std::endl << std::endl << std::endl;
        {
            int max_weight = 10;

            Items items =
            {
                {1, 02},
                {2, 02},
                {3, 05},
                {4, 04},
                {5, 10}
            };

            std::cout << " * Max weight: " << max_weight
                      << ", items:" << std::endl;
            print(items);

            auto weights = solveKnapsack(items, max_weight);
            std::cout << " solution:" << std::endl;
            print(weights);
            auto best_items = bestItems(items, weights);
            std::cout << " best items:" << std::endl;
            print(best_items);
        }
    }
    catch(std::exception const & _ex)
    {
        std::cerr << "Error: " << _ex.what() << std::endl;
        throw;
    }

    return 0;
}

Mtrx solveKnapsack(Items & _items, int _max_weight)
{
    const int n_rows = _items.size() + 1;
    const int n_cols = _max_weight + 1;

    Mtrx weights;
    initZero(weights, n_rows, n_cols);
    int row, col, val_1, val_2;
    Item * item;

    for(row = 1; row < n_rows; ++row)
    {
        item = &  _items[row - 1];
        for(col = 1; col < n_cols; ++col)
        {
            val_1 = weights[row - 1][col];

            if(col < item->weight)
            {
                weights[row][col] = val_1;
            }
            else
            {
                val_2 = item->value + weights[row - 1][col - item->weight];
                if(val_1 > val_2)
                {
                    weights[row][col] = val_1;
                }
                else
                {
                    weights[row][col] = val_2;
                }
            }
        }
    }

    return weights;
}

Items bestItems(Items & _items, Mtrx & _m)
{
    Items best_items;
    const int last_row = _m.size() - 1;
    const int last_col = _m[last_row].size() - 1;

    int last_best_value = _m[last_row][last_col];
    int col = last_col;
    int row = last_row;

    while(row > 0 && col != 0)
    {
        if(last_best_value == _m[row - 1][col])
        {
            --row;
            continue;
        }

        best_items.push_back(_items[row - 1]);
        col = col - _items[row - 1].weight;
        --row;
        last_best_value = _m[row][col];
    }

    return best_items;
}


void initZero(Mtrx & _m, int _rows, int _cols)
{
    _m.assign(_rows, Vect(_cols, 0));
}

void print(Items & _i)
{
    std::cout << "   weight, value"  << std::endl;
    for(auto i = _i.begin(); i != _i.end(); ++i)
    {
        std::cout << "        " << i->weight << ", " << i->value <<
                  std::endl;
    }
}

void print(Mtrx & _m)
{
    for(auto i = _m.begin(); i != _m.end(); ++i)
    {
        std::cout << "   ";
        for(auto j = i->begin(); j != i->end(); ++j)
        {
            std::cout << std::setw(4) << (*j);
        }
        std::cout << std::endl;
    }
}

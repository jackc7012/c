#pragma once
#include "public.h"

// 2043
class StockPrice {
public:
    StockPrice() : minPrice(INT_MAX), maxPrice(0)
    {
        stockPrice.clear();
    }

    void update(int timestamp, int price)
    {
        if (stockPrice.find(timestamp) == stockPrice.end()) {
            if (price < minPrice) {
                minPrice = price;
            }
            if (price > maxPrice) {
                maxPrice = price;
            }
            stockPrice[timestamp] = price;
        } else {
            stockPrice[timestamp] = price;
            maxPrice = 0;
            minPrice = INT_MAX;
            for (auto iter = stockPrice.begin(); iter != stockPrice.end(); ++iter) {
                if (iter->second < minPrice) {
                    minPrice = iter->second;
                }
                if (iter->second > maxPrice) {
                    maxPrice = iter->second;
                }
            }
        }
    }

    int current()
    {
        auto iter = --stockPrice.end();
        return iter->second;
    }

    int maximum()
    {
        return maxPrice;
    }

    int minimum()
    {
        return minPrice;
    }

private:
    map<int, int> stockPrice;
    unsigned int minPrice;
    unsigned int maxPrice;
};

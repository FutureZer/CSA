#ifndef HW_2_RND_H
#define HW_2_RND_H

#include "stdlib.h"
#include "time.h"

// Генератор случайных чисел в диапазоне от 1 до 20
class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация случайного числа в заданном диапазоне
    int Get() {
        return rand() % (last - first + 1) + first;
    }
private:
    int first;
    int last;
};

#endif //HW_2_RND_H

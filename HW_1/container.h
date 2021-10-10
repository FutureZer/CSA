#ifndef __container__
#define __container__

#include "cryptographer.h"

struct container {
    int max_len = 2000;
    int cur_len;
    message* arr;
};

// Инициализация контейнера
void Initialization(container &c, message* arr);

// инициализация контейнера
void Initialization(container &c);

// Очистка контейнера
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void Enter(container &c, std::ifstream &in);

// Случайный ввод в контейнер
void RndEnter(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Withdraw(container &c, std::ofstream &out);

// Вычисляет среднее значение кодов строу в контейнере
double AverageCode(container &c);

#endif
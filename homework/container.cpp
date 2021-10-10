#include "container.h"

// Инициализация контейнера с количеством объектов, заданным пользователем
void Initialization(container &cont, int size) {
    cont.arr = new message[size];
    cont.cur_len = 0;
}

// Инициализация с количеством объектов по умолчанию
void Initialization(container &cont) {
    cont.arr = new message[cont.max_len];
    cont.cur_len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &cont) {
    cont.cur_len = 0;
}

// Ввод содержимого контейнера из указанного потока
void Enter(container &cont, std::ifstream &in) {
    while(!in.eof()) {
        message mes;
        Enter(mes, in);
        cont.arr[cont.cur_len++] = mes;
    }
}

// Случайный ввод содержимого контейнера
void RndEnter(container &cont, int size) {
    while (cont.cur_len < size) {
        message mes;
        RndEnter(mes);
        cont.arr[cont.cur_len++] = mes;
    }
}

// Вывод содержимого контейнера в указанный поток
void Withdraw(container &cont, std::ofstream &out) {
    out << "Container contains " << cont.cur_len << " elements:\n";
    for (int i = 0; i < cont.cur_len; ++i) {
        out << i + 1 << ".";
        Withdraw(cont.arr[i], out);
    }
}

// Поиск среднего значения кода в сообщениях контейнера
double Average(container &cont) {
    double code_sum = 0;
    for (int i = 0; i < cont.cur_len; ++i) {
        code_sum += GetMessageCode(cont.arr[i]);
    }
    return code_sum / cont.cur_len;
}

// Убирает все элементы, коды которых меньше среднего
void AverageRemove(container &cont) {
    container new_cont;
    Initialization(new_cont);
    double aver = Average(cont);
    for (int i = 0; i < cont.cur_len; ++i) {
        if (GetMessageCode(cont.arr[i]) >= aver) {
            new_cont.arr[new_cont.cur_len++] = cont.arr[i];
        }
    }
    cont = new_cont;
}
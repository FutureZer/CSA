//
// Created by ASUS on 17.10.2021.
//

#ifndef HW_2_CONTAINER_H
#define HW_2_CONTAINER_H

#include "crypter.h"
#include "stdio.h"

class Container {
private:
    static const int max_len = 2000;
    Crypter **messages = new Crypter *[max_len];
    int curr_index = 0;
public:
    // Инициадизация контейнера через файл
    Container(FILE *fp);

    // Инициализация контейнера случайными сообщениями
    Container(int size);

    // Запись информации обо всех сооющениях в файл
    void FileWrite(FILE *fp);

    // Находит среднее значение кода по всем сообщениям
    double AverageCode();

    // Удаляет из контейнера все сообщения, код которых меньше среднего
    void AverageRemove();

    // Освобождает ресурсы
    void Clear();
};

#endif //HW_2_CONTAINER_H

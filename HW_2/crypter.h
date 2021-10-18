#ifndef HW_2_CRYPTER_H
#define HW_2_CRYPTER_H

#include "stdio.h"
#include "rnd.h"

class Crypter {
private:
    static const int max_len = 2000;
    static const int possible_symb = 62;
    char text[max_len];
    // Массивы попарного шифрования
    const char symb[possible_symb] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g',
                                      'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
                                      'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w',
                                      'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    const char crypt[possible_symb] = {'R', 'r', '2', '3', 'S', 's', 'T', 'u', 'U', 't', 'V', 'W', 'v', 'w',
                                       '0', 'b', 'B', '9', 'c', 'y', 'z', 'C', 'X', 'Y', 'Z', 'x', 'F', 'f', 'I', 'i',
                                       'A', 'G', 'g', 'a', 'P', 'q', 'p', 'Q', 'j', 'k', 'K', 'J', 'L', 'M', 'N', 'n',
                                       'l', 'm', 'D', 'd', 'E', 'e', '5', '4', '1', 'O', '6', '7', 'o', 'H', 'h', '8'};
public:
    // Инициализация шифровальщика
    Crypter(char *text);

    // Инициализация шифровальщика случайным сообщением
    Crypter();

    // Запись зашифрованной информации в файл
    void FileWrite(FILE *fp);

    // Шифрование по паре
    char *PairCrypt();

    // Шифрование сдвигом кода символа на случайное число
    char *ShiftCrypt();

    // Шифрование заменой каждого символа текста на его код
    char *NumericCrypt();

    // Получает код сообщения, которое зависит от
    double GetTextCode();
};


#endif //HW_2_CRYPTER_H

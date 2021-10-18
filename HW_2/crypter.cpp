#include "crypter.h"
#include "string.h"

// Глобальные переменные для генерации случайных сообщений
Random space = Random(0, 20);
Random letter = Random(0, 62);
Random interval = Random(3, 50);

// Инициализация сообщения
Crypter::Crypter(char *text) {
    for (int i = 0; i < strlen(text) + 1; ++i) {
        this->text[i] = text[i];
    }
}

// Случайная инициализация сообщения
Crypter::Crypter() {
    int interval_val = interval.Get();
    for (int i = 0; i < interval_val; ++i) {
        if (space.Get() == 1) {
            text[i] = ' ';
        } else {
            text[i] = symb[letter.Get()];
        }
    }
    text[interval_val] = 0;
}

// Запись в файл сообщение и его зашифрованные формы
void Crypter::FileWrite(FILE *fp) {
    char code[15];
    _itoa_s(GetTextCode(), code, 10);
    fprintf(fp, " Message text: ");
    fprintf(fp, text);
    fprintf(fp, "\n");
    fprintf(fp, " Message code: ");
    fprintf(fp,  code);
    fprintf(fp, "\n");
    fprintf(fp, "   Pair crypt: ");
    fprintf(fp, PairCrypt());
    fprintf(fp, "\n");
    fprintf(fp, "  Shift crypt: ");
    fprintf(fp, ShiftCrypt());
    fprintf(fp, "\n");
    fprintf(fp, "Numeric crypt: ");
    fprintf(fp, NumericCrypt());
    fprintf(fp, "\n");

}

// Шифрование по паре
char *Crypter::PairCrypt() {
    char new_mess[max_len];
    for (int i = 0; i < strlen(text); ++i) {
        for (int j = 0; j < possible_symb; ++j) {
            if (text[i] == ' ') {
                new_mess[i] = ' ';
                break;
            }
            if (symb[j] == text[i]) {
                new_mess[i] = crypt[j];
                break;
            }
        }
    }

    new_mess[strlen(text)] = 0;
    return new_mess;
}

// Шифрование сдвигом кода символа на случайное число
char *Crypter::ShiftCrypt() {
    char new_mess[max_len];
    int shift = space.Get() - 10;
    for (int i = 0; i < strlen(text); ++i) {
        new_mess[i] = text[i] + shift;
    }
    new_mess[strlen(text)] = 0;
    return new_mess;
}

// Шифрование заменой каждого символа текста на его код
char *Crypter::NumericCrypt() {
    char new_mes[max_len * 3];
    int new_index = 0;
    int code;
    char buffer[100];
    for (int i = 0; i < strlen(text); ++i) {
        code = (int) text[i];
        while (code > 0) {
            int num;
            if (code / 100 > 0) {
                num = code / 100;
                code %= 100;
            } else if (code / 10 > 0) {
                num = code / 10;
                code %= 10;
            } else {
                num = code;
                code = 0;
            }
            _itoa_s(num, buffer, 10);
            if (buffer[0] != 0) {
                new_mes[new_index++] = buffer[0];
            }
        }
    }
    new_mes[new_index++] = 0;
    return new_mes;
}

double Crypter::GetTextCode() {
    double sum = 0;
    for (int i = 0; i < strlen(text); ++i) {
        sum += (int)text[i];
    }
    return sum / strlen(text);
}

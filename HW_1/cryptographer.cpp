#include "cryptographer.h"
#include "time.h"
#include "stdlib.h"

//--------------------------------------------------
// Важно! 62 это длина массива всех возможных символов в сообщении
// (не включая пробел и переход на новую строку)
//--------------------------------------------------

// Ввод текста через файл
void Enter(message &mes, std::ifstream &in) {
    std::string message;
    std::string part;
    if (in.is_open()) {
        while (in >> part && part != "!") {
            message += part + " ";
        }
    }
    mes.text = message;
}

// Ввод случайного сообщения
void RndEnter(message &mes) {
    int len = (rand() % 200) + 3;
    for (int i = 0; i < len; ++i) {
        if (rand() % 5 == 0) {
            mes.text += " ";
        }
        mes.text += mes.symb[rand() % 62];
    }
}

// Вывод полученного сообщения
void Withdraw(message &mes, std::ofstream &out) {
    out << " Text: " << mes.text << "\n"
        << "   Text code: " << GetMessageCode(mes) << "\n"
        << "   Pair crypt: " << PairCrypt(mes) << "\n"
        << "   Shift crypt: " << ShiftCrypt(mes) << "\n"
        << "   Numeric crypt: " << NumericCrypt(mes) << "\n";
}

// Шифрует каждую букву с индексом i в соответствие с парой с индексом i
std::string PairCrypt(message &mes) {
    std::string crypt;
    for (int i = 0; i < mes.text.length(); ++i) {
        for (int j = 0; j < 62; ++j) {
            if (mes.text[i] == ' ') {
                crypt += mes.text[i];
                break;
            } else if (mes.text[i] == mes.symb[j]) {
                crypt += mes.crypt[j];
                break;
            }
        }
    }
    return crypt;
}

// Шифрует строку по сдвигу кода каждого символа на значение shift
std::string ShiftCrypt(message &mes) {
    int shift = rand() % 16;
    std::string crypt;
    for (int i = 0; i < mes.text.length(); ++i) {
        crypt += (char)((int)mes.text[i] + shift);
    }
    return crypt;
}

// Заменяет каждый символ строки на код символа
std::string NumericCrypt(message &mes) {
    std::string crypt;
    for (int i = 0; i < mes.text.length(); ++i) {
        int temp = mes.text[i];
        crypt += std::to_string(temp);
    }
    return crypt;
}

// Получает код текста как значение каждго символа строки деленное, на кол-во символов в строке
double GetMessageCode(message &mes) {
    double mes_code = 0;
    for (int i = 0; i < mes.text.length(); ++i) {
        mes_code += (int)mes.text[i];
    }
    return mes_code / mes.text.length();
}



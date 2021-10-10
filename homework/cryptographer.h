#ifndef __cryptographer__
#define __cryptographer__


struct message {
    std::string text;
    // Массивы попарного шифрования
    char symb[62] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g',
                   'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
                   'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w',
                   'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char crypt[62] = {'R', 'r', '2', '3', 'S', 's', 'T', 'u', 'U', 't', 'V', 'W', 'v', 'w',
                    '0', 'b', 'B', '9', 'c', 'y', 'z', 'C', 'X', 'Y', 'Z', 'x', 'F', 'f', 'I', 'i',
                    'A', 'G', 'g', 'a', 'P', 'q', 'p', 'Q', 'j', 'k', 'K', 'J', 'L', 'M', 'N', 'n',
                    'l', 'm', 'D', 'd', 'E', 'e', '5', '4', '1', 'O', '6', '7', 'o', 'H', 'h', '8'};
};

// Ввод текста через файл
void Enter(message &mes, std::ifstream &in);

// Ввод случайного сообщения
void RndEnter(message &mes);

// Вывод полученного сообщения
void Withdraw(message &mes, std::ofstream &out);

// Шифрует каждую букву с индексом i в соответствие с парой с индексом i
std::string PairCrypt(message &mes);

// Шифрует строку по сдвигу кода каждого символа на значение shift
std::string ShiftCrypt(message &mes);

// Заменяет каждый символ строки на код символа
std::string NumericCrypt(message &mes);

// Получает код текста как значение каждго символа строки деленное, на кол-во символов в строке
double GetMessageCode(message &mes);

#endif

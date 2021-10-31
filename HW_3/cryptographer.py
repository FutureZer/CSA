import random
import string


class Crypter:
    # symb и crypt списки для шифрования подменой одного символа на другой
    symb = ['A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g',
            'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
            'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w',
            'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
    crypt = ['R', 'r', '2', '3', 'S', 's', 'T', 'u', 'U', 't', 'V', 'W', 'v', 'w',
             '0', 'b', 'B', '9', 'c', 'y', 'z', 'C', 'X', 'Y', 'Z', 'x', 'F', 'f', 'I', 'i',
             'A', 'G', 'g', 'a', 'P', 'q', 'p', 'Q', 'j', 'k', 'K', 'J', 'L', 'M', 'N', 'n',
             'l', 'm', 'D', 'd', 'E', 'e', '5', '4', '1', 'O', '6', '7', 'o', 'H', 'h', '8']
    rand = random.Random()

    # Конструктор используется при инициализации через файл
    def __init__(self):
        self.message = []

    # Метод используется при инициализации через файл
    def file_init(self, mes):
        self.message = mes

    # Метод используется при инициализации сообщения случайным
    def rnd_init(self):
        self.message = ""
        length = Crypter.rand.randint(3, 200)
        for i in range(length):
            if Crypter.rand.randint(0, 8) == 8 and i != 0:
                self.message += ' '
            else:
                self.message += Crypter.symb[Crypter.rand.randint(0, 61)]

    # Шифрует подменой одного символа на другой
    def pair_crypt(self):
        crypted = ""
        for symbol in self.message:
            for index in range(len(Crypter.symb)):
                if symbol == ' ':
                    crypted += ' '
                    break
                elif Crypter.symb[index] == symbol:
                    crypted += Crypter.crypt[index]
                    break
        return crypted

    # Шифрует сдвигом кода символа на небольшую случайную величину
    def shift_crypt(self):
        crypted = ""
        shift = Crypter.rand.randint(-5, 5)
        if shift == 0:
            shift = 1
        for symbol in self.message:
            crypted += chr(ord(symbol) + shift)
        return crypted

    # Шифрует заменой символа на его код
    def numeric_crypt(self):
        crypt = ""
        for symbol in self.message:
            crypt += str(ord(symbol))
        return crypt

    # Возвращает код строки (среднее кодов всех символов)
    def get_message_code(self):
        total = 0
        for symbol in self.message:
            total += ord(symbol)
        return int(total / len(self.message))

    # Записывает информацию о сообщении в файл
    def write(self, outstream):
        outstream.write(" Message text: {}\n".format(self.message))
        outstream.write(" Message code: {}\n".format(self.get_message_code()))
        outstream.write("   Pair crypt: {}\n".format(self.pair_crypt()))
        outstream.write("  Shift crypt: {}\n".format(self.shift_crypt()))
        outstream.write("Numeric crypt: {}\n".format(self.numeric_crypt()))
        pass

    # Отображает информацию о сообщении в консоли
    def print_info(self):
        print(" Message text: {}\n".format(self.message))
        print(" Message code: {}\n".format(self.get_message_code()))
        print("   Pair crypt: {}\n".format(self.pair_crypt()))
        print("  Shift crypt: {}\n".format(self.shift_crypt()))
        print("Numeric crypt: {}\n".format(self.numeric_crypt()))
        pass

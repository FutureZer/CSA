import string
from cryptographer import *


class Container:
    def __init__(self):
        self.messages = []

    # При инициализации контейнера информацией из файла
    def file_init(self, messages):
        for index in range(len(messages)):
            cr = Crypter()
            cr.file_init(messages[index])
            self.messages.append(cr)

    # При инициализации контейнера случайными сообщениями
    def rnd_init(self, length):
        for index in range(length):
            cr = Crypter()
            cr.rnd_init()
            self.messages.append(cr)

    # Печатает всю информации о сообщениях в контейнере в файл
    def write(self, outstream):
        outstream.write("======================================================================\n")
        for message in self.messages:
            message.write(outstream)
            outstream.write("======================================================================\n")
        pass

    # Выводит всю информации о сообщениях в контейнере в консоль
    def print_info(self):
        print("======================================================================\n")
        for message in self.messages:
            print(message.print_info())
            print("======================================================================\n")
        pass

    # Находит среднее значение кода сообщения
    def average(self):
        total = 0
        for mes in self.messages:
            total += mes.get_message_code()
        return total / len(self.messages)

    # Удаляет все сообщения контейнера, значение кода которых меньше среднего
    def average_only(self):
        aver = []
        for mes in self.messages:
            if mes.get_message_code() >= self.average():
                aver.append(mes)
        self.messages = aver
        pass

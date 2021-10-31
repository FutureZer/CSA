import sys
from container import *


if __name__ == '__main__':
    # Проверка на корректность введенных данных
    if len(sys.argv) != 5:
        print("Incorrect format. You must write:\n"
              "python main <input type (-f or -n)> <(-f)inputFileName or (-n)number> "
              "<outputFile1> <outputFile1>")
        exit(1)

    # Определение типа ввода информации
    is_file_input = False
    if sys.argv[1] == "-f":
        is_file_input = True
    elif sys.argv[1] == "-n":
        is_file_input = False
    else:
        print("Incorrect second argument. It should be \"-f\" or \"-n\"")
        exit(2)

    # Создание контейнера и его инициализация
    cont = Container()
    if is_file_input:
        try:
            instream = open(sys.argv[2])
            text = instream.read()
            cont.file_init(text.split('\n'))
            instream.close()
        except Exception:
            print("Incorrect third argument (input file path)")
            exit(3)
    else:
        try:
            cont.rnd_init(int(sys.argv[2]))
        except Exception:
            print("Incorrect third argument. It should be integer number")
            exit(4)

    # Вывод всей обработанной информации из контейнера
    try:
        outstream = open(sys.argv[3], 'w')
        cont.write(outstream)
        outstream.close()
    except ZeroDivisionError:
        print("Your file contains empty string: \\n\\n repeated twice")
        exit(5)
    except Exception:
        print("Incorrect fourth argument (output file path)")
        exit(5)

    # Вывод сообщений, значение кода которых не меньше среднего
    cont.average_only()
    try:
        outstream = open(sys.argv[4], 'w')
        cont.write(outstream)
        outstream.close()
    except Exception:
        print("Incorrect fifth argument (output file path)")
        exit(6)
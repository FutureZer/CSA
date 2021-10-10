#include <fstream>
#include <string>
#include "cryptographer.cpp"
#include "container.cpp"
#include "stdio.h"

void ErrMessage1() {
    printf("incorrect command line!\nWaited:\ncommand -f infile outfile01 outfile02\n"
           "Or:\ncommand -n number outfile01 outfile02\n");
}

void ErrMessage2() {
    printf("incorrect qualifier value!\nWaited:\ncommand -f infile outfile01 outfile02\n"
           "Or:\ncommand -n number outfile01 outfile02\n");
}

int main(int argc, char *argv[]) {
    clock_t start_time =  clock();
    if (argc != 5) {
        ErrMessage1();
        return 1;
    }
    // Выбор ввода
    container cont;
    int size = 100;
    bool isFile;
    if (!strcmp(argv[1], "-f")) {
        isFile = true;
    } else if (!strcmp(argv[1], "-n")) {
        isFile = false;
        size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of text = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
    } else {
        ErrMessage2();
        return 2;
    }

    // Заполнение контейнера
    if (isFile) {
        Initialization(cont);
        std::ifstream in;
        in.open(argv[2]);
        Enter(cont, in);
        in.close();
    } else {
        Initialization(cont, size);
        srand(static_cast<unsigned int>(time(0)));
        RndEnter(cont, size);
    }

    // Вывод результатов задания
    std::ofstream out;
    out.open(argv[3]);
    Withdraw(cont, out);
    out.close();

    // Доп задание
    std::ofstream aver_out;
    aver_out.open(argv[4]);
    AverageRemove(cont);
    Withdraw(cont, aver_out);
    aver_out.close();
    Clear(cont);
    printf("Everything worked successfully. Check out files for results\n");
    clock_t end_time = clock();
    double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Spended time: %f", search_time);
    return 0;
}




#include "stdio.h"
#include "container.cpp"

void ErrMessage1() {
    printf("incorrect command line!\nWaited:\ncommand -f infile outfile01 outfile02\n"
           "Or:\ncommand -n number outfile01 outfile02\n");
}

void ErrMessage2() {
    printf("incorrect qualifier value!\nWaited:\ncommand -f infile outfile01 outfile02\n"
           "Or:\ncommand -n number outfile01 outfile02\n");
}

int main(int argc, char *argv[]) {
    clock_t start_time = clock();
    if (argc != 5) {
        ErrMessage1();
        return 1;
    }

    // Выбор ввода
    Container* cont;
    int size = 100;
    bool isFile;
    if (!strcmp(argv[1], "-f")) {
        isFile = true;
    } else if (!strcmp(argv[1], "-n")) {
        isFile = false;
        size = atoi(argv[2]);
        if ((size < 1) || (size > 2000)) {
            printf("incorrect number of text = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
    } else {
        ErrMessage2();
        return 2;
    }

    // Заполнение контейнера
    if (isFile) {
        FILE *input = fopen(argv[2], "r");
        cont = new Container(input);
        fclose(input);
    } else {
        cont = new Container(size);
    }

    // Вывод результатов задания
    FILE* out = fopen(argv[3], "w");
    cont->FileWrite(out);
    fclose(out);

    // Доп функция
    FILE* aver = fopen(argv[4], "w");
    cont->AverageRemove();
    cont->FileWrite(aver);
    fclose(aver);
    cont->Clear();
    printf("Everything worked successfully. Check out files for results\n");
    clock_t end_time = clock();
    double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Spended time: %f", search_time);
    return 0;
}

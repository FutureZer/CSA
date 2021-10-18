#include "container.h"
#include "stdio.h"
#include "crypter.cpp"

Container::Container(FILE *fp) {
    int symbol = fgetc(fp);
    int symb_index = 0;
    char text[max_len];
    while (symbol != EOF) {
        if (symbol == '\n') {
            text[symb_index++] = 0;
            messages[curr_index++] = new Crypter(text);
            symb_index = 0;
        } else {
            text[symb_index++] = symbol;
        }
        symbol = fgetc(fp);
    }
    text[symb_index++] = 0;
    messages[curr_index++] = new Crypter(text);
}

Container::Container(int size) {
    for (int i = 0; i < size; ++i) {
        messages[curr_index++] = new Crypter();
    }
}

void Container::FileWrite(FILE *fp) {
    for (int i = 0; i < curr_index; ++i) {
        fprintf(fp, "======================================================================\n");
        messages[i]->FileWrite(fp);
    }

    fprintf(fp, "======================================================================\n");
}

double Container::AverageCode() {
    double sum = 0;
    for (int i = 0; i < curr_index; ++i) {
        sum += messages[i]->GetTextCode();
    }
    return sum / curr_index;
}

void Container::AverageRemove() {
    Crypter **new_mes = new Crypter *[max_len];
    int new_index = 0;
    for (int i = 0; i < curr_index; ++i) {
        if (messages[i]->GetTextCode() >= AverageCode()) {
            new_mes[new_index++] = messages[i];
        }
    }
    delete[] messages;
    curr_index = new_index;
    messages = new_mes;
}

// Освобождает ресурсы
void Container::Clear() {
    delete[] messages;
}

#include <iostream>
#include <thread>
#include <queue>
#include <cstdlib>
#include <vector>
#include <mutex>
#include "customer.cpp"
#include "merchant.cpp"

// Генерация покупателей, которые будут заходить в течении рабочего для
std::vector<Customer> *generateCustomers(int customer_number) {
    srand(static_cast<unsigned int>(time(nullptr)));
    auto *customers = new std::vector<Customer>();
    std::vector<int> nums = std::vector<int>();
    for (int i = 0; i < customer_number; ++i) {
        int generated_time = rand() % 491;
        while (std::find(nums.begin(), nums.end(), generated_time) != nums.end() ||
               generated_time < 5) {
            generated_time = (generated_time + 1) % 491;
        }
        customers->push_back(Customer(generated_time, i + 1, rand() % 3));
    }
    customers->push_back(Customer(5, 100, 1));
    return customers;
}

int main(int argc, char *argv[]) {
    // Проверка на количество введенных аргументов
    if (argc != 2) {
        std::cout << "Incorrect number of arguments in command line."
                     "You should enter one argument - number of customers (from 1 to 400)";
        return 0;
    }

    // Проверка на корректность второго аргумента
    int customer_number;
    try {
        customer_number = std::stoi(argv[1]);
    } catch (std::exception ex) {
        std::cout << "Second argument should be a number from 1 to 400";
        return 0;
    }
    if (customer_number < 1 || customer_number > 400) {
        std::cout << "The number of customer should be from 1 to 400";
        return 0;
    }

    std::mutex mt;

    // Продавец, который работает в магазине
    Merchant m = Merchant();

    // Подготовка покупателей, которые будут заходить в магазин
    std::cout << "Preparing shop...\n";
    auto *customers = generateCustomers(customer_number);

    // Очереди в которых стоят покупатели к первой, второй и третьей кассах соответсвенно
    auto queue1 = std::queue<Customer>();
    auto queue2 = std::queue<Customer>();
    auto queue3 = std::queue<Customer>();

    // Поток продавца -> обслуживает покупателей, либо бегает по кассам
    std::thread merch([&]() {
        int i = 0;
        while (i < 500) {
            m.goToAnotherCashbox();
            m.displayStatus();
            if (m.getCashId() == 0) {
                while (!queue1.empty()) {
                    m.serveCustomer(queue1.front());
                    queue1.pop();
                    ++i;
                }
            } else if (m.getCashId() == 1) {
                while (!queue2.empty()) {
                    m.serveCustomer(queue2.front());
                    queue2.pop();
                    ++i;
                }
            } else {
                while (!queue3.empty()) {
                    m.serveCustomer(queue3.front());
                    queue3.pop();
                    ++i;
                }
            }
            ++i;
        }
    });

    // Поток покупателей -> встает в очередь в соответствии со временем прихода в магазин
    std::thread customer_process([&]() {
        int i = 0;
        while (i < 500) {
            auto entered_customer = Customer::enterShop(customers, i);
            if (entered_customer) {
                mt.lock();
                if (entered_customer->getCashId() == 0) {
                    queue1.push(*entered_customer);
                } else if (entered_customer->getCashId() == 1) {
                    queue2.push(*entered_customer);
                } else {
                    queue3.push(*entered_customer);
                }
                mt.unlock();
            }
            ++i;
        }
    });
    customer_process.join();
    merch.join();
    return 0;
}

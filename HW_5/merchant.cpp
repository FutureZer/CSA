#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include "merchant.h"

Merchant::Merchant() {
    cashbox_id_ = 0;
}

void Merchant::goToAnotherCashbox() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cashbox_id_ = (cashbox_id_ + 1) % 3;
}

int Merchant::getCashId() const {
    return cashbox_id_;
}

void Merchant::serveCustomer(Customer customer) const {
    int sleep_time = rand() % 3 + 2;
    std::cout << "[Merchant thread]: Merchant works on " << cashbox_id_ + 1
              << " cashbox with " << customer.getId() << " customer...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time * 1000));
    std::cout << "[Merchant thread]: Customer " << customer.getId() << " was served successfully\n";
}

void Merchant::displayStatus() const {
    std::cout << "[Merchant thread]: Merchant working with " << cashbox_id_ + 1 << " cashbox\n";
}
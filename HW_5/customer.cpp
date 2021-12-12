#include "customer.h"
#include <vector>
#include <iostream>


Customer::Customer(int wait, int id, int cash_id) {
    wait_time_ = wait;
    id_ = id;
    cash_id_ = cash_id;
}

int Customer::getId() const {
    return id_;
}

int Customer::getCashId() const {
    return cash_id_;
}

Customer *Customer::enterShop(std::vector<Customer> *timetable, int elapsed) {
    if (elapsed == 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1600));
    } else {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
    for (auto & i : *timetable) {
        if (i.wait_time_ == elapsed) {
            std::cout << "[Customer thread]: Customer " << i.id_ << " arrived to cashbox " <<
                      i.cash_id_ + 1 << "\n";
            return &i;
        }
    }
    return nullptr;
}

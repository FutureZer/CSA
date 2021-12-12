#ifndef HW_5_CUSTOMER_H
#define HW_5_CUSTOMER_H

class Customer {
private:
    // Время по прошествии которого придет
    int wait_time_;
    int id_;
    int cash_id_;
public:
    Customer(int wait, int id, int cash_id);

    // Возвращает id пользователя
    int getId() const;

    // Возвращает id кассы пользователя
    int getCashId() const;

    // Находит в списке сгенерированных покупателей того, кто именно сейчас должен прийти
    // Если таких нет, то null
    static Customer *enterShop(std::vector<Customer> *timetable, int elapsed);
};

#endif //HW_5_CUSTOMER_H

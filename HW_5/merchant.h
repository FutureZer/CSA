#ifndef HW_5_MERCHANT_H
#define HW_5_MERCHANT_H


class Merchant {
private:
    int cashbox_id_;

public:
    Merchant();

    // Возращает id кассы, с кторой сейчас работает продавец
    int getCashId() const;

    // Иллюстрирует процесс обслуживания покупателя
    void serveCustomer(Customer cus) const;

    // Перемещает поток продовца на следующую кассу
    void goToAnotherCashbox();

    // Выводит кассу, с которой работает продавец на данный момент
    void displayStatus() const;
};


#endif //HW_5_MERCHANT_H

#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include <QKeyEvent>

#ifdef __cplusplus
extern "C" {
#endif
    #include "../SmartCalc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_pushButton_res_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_take_clicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H

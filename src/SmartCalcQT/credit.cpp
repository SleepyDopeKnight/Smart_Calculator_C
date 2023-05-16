#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);

  setWindowTitle("Credit Calculator");
}

Credit::~Credit() { delete ui; }

void Credit::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
    ui->pushButton_res->click();
  } else if (event->key() == Qt::Key_F1) {
    ui->radioButton_type1->click();
  } else if (event->key() == Qt::Key_F2) {
    ui->radioButton_type2->click();
  }
}

void Credit::on_pushButton_res_clicked() {
  credit creditqt = {0, 0, 0, 0, 0, 0, 0};
  creditqt.sum_credit = ui->ui_sum_credit->text().toDouble();
  creditqt.time_credit = ui->ui_time_credit->text().toInt();
  creditqt.procent = ui->ui_procent->text().toDouble();
  if (ui->radioButton_type1->isChecked()) {
    creditqt.type = 1;
  } else if (ui->radioButton_type2->isChecked()) {
    creditqt.type = 2;
  }
  if (CreditCalc(&creditqt) == 0) {
    ui->err->setText("");
    ui->ui_sum_pay->setText(QString::number(creditqt.sum_pay, 'g', 15));
    ui->ui_over_pay->setText(QString::number(creditqt.over_pay, 'g', 15));
    ui->ui_month_pay->setText(QString::number(creditqt.month_pay, 'g', 15));
  } else {
    ui->err->setText("Invalid input");
    ui->ui_sum_pay->setText("0");
    ui->ui_over_pay->setText("0");
    ui->ui_month_pay->setText("0");
  }
}

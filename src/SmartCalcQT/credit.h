#ifndef CREDIT_H
#define CREDIT_H

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
class Credit;
}

class Credit : public QDialog
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_pushButton_res_clicked();

private:
    Ui::Credit *ui;
};

#endif // CREDIT_H

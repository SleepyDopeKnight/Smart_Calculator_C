#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QtMath>

#include "credit.h"
#include "deposit.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../SmartCalc.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
  void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

 private slots:
  void digits_numbers();
  void ariph_numbers();
  void trigonomy_numbers();
  void on_pushButton_dot_clicked();
  void on_pushButton_unar_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_backspace_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_deposit_clicked();

 private:
  double xBegin, xEnd, h, X, xy_1, xy_2, result_1, result_2;
  int N;

  QVector<double> x, y;

  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H

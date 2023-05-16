#include "SmartCalcQT.h"

#include "ui_SmartCalcQT.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setWindowTitle("Smart Calculator");
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(trigonomy_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(ariph_numbers()));
  connect(ui->pushButton_lbracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_rbracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_0) {
    ui->pushButton_0->click();
    ui->pushButton_0->setDown(true);
  } else if (event->key() == Qt::Key_1) {
    ui->pushButton_1->click();
    ui->pushButton_1->setDown(true);
  } else if (event->key() == Qt::Key_2) {
    ui->pushButton_2->click();
    ui->pushButton_2->setDown(true);
  } else if (event->key() == Qt::Key_3) {
    ui->pushButton_3->click();
    ui->pushButton_3->setDown(true);
  } else if (event->key() == Qt::Key_4) {
    ui->pushButton_4->click();
    ui->pushButton_4->setDown(true);
  } else if (event->key() == Qt::Key_5) {
    ui->pushButton_5->click();
    ui->pushButton_5->setDown(true);
  } else if (event->key() == Qt::Key_6) {
    ui->pushButton_6->click();
    ui->pushButton_6->setDown(true);
  } else if (event->key() == Qt::Key_7) {
    ui->pushButton_7->click();
    ui->pushButton_7->setDown(true);
  } else if (event->key() == Qt::Key_8) {
    ui->pushButton_8->click();
    ui->pushButton_8->setDown(true);
  } else if (event->key() == Qt::Key_9) {
    ui->pushButton_9->click();
    ui->pushButton_9->setDown(true);
  } else if (event->key() == Qt::Key_Plus) {
    ui->pushButton_plus->click();
    ui->pushButton_plus->setDown(true);
  } else if (event->key() == Qt::Key_Minus) {
    ui->pushButton_minus->click();
    ui->pushButton_minus->setDown(true);
  } else if (event->key() == Qt::Key_Slash) {
    ui->pushButton_del->click();
    ui->pushButton_del->setDown(true);
  } else if (event->key() == Qt::Key_Asterisk) {
    ui->pushButton_mul->click();
    ui->pushButton_mul->setDown(true);
  } else if (event->key() == Qt::Key_Period) {
    ui->pushButton_dot->click();
    ui->pushButton_dot->setDown(true);
  } else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
    ui->pushButton_eq->click();
    ui->pushButton_eq->setDown(true);
  } else if (event->key() == Qt::Key_ParenLeft) {
    ui->pushButton_lbracket->click();
    ui->pushButton_lbracket->setDown(true);
  } else if (event->key() == Qt::Key_ParenRight) {
    ui->pushButton_rbracket->click();
    ui->pushButton_rbracket->setDown(true);
  } else if (event->key() == (Qt::Key_Delete)) {
    ui->pushButton_AC->click();
    ui->pushButton_AC->setDown(true);
  } else if (event->key() == Qt::Key_Backspace) {
    ui->pushButton_backspace->click();
    ui->pushButton_backspace->setDown(true);
  } else if (event->key() == Qt::Key_AsciiCircum) {
    ui->pushButton_pow->click();
    ui->pushButton_pow->setDown(true);
  } else if (event->key() == Qt::Key_X) {
    ui->pushButton_x->click();
    ui->pushButton_x->setDown(true);
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_0) {
    ui->pushButton_0->setDown(false);
  } else if (event->key() == Qt::Key_1) {
    ui->pushButton_1->setDown(false);
  } else if (event->key() == Qt::Key_2) {
    ui->pushButton_2->setDown(false);
  } else if (event->key() == Qt::Key_3) {
    ui->pushButton_3->setDown(false);
  } else if (event->key() == Qt::Key_4) {
    ui->pushButton_4->setDown(false);
  } else if (event->key() == Qt::Key_5) {
    ui->pushButton_5->setDown(false);
  } else if (event->key() == Qt::Key_6) {
    ui->pushButton_6->setDown(false);
  } else if (event->key() == Qt::Key_7) {
    ui->pushButton_7->setDown(false);
  } else if (event->key() == Qt::Key_8) {
    ui->pushButton_8->setDown(false);
  } else if (event->key() == Qt::Key_9) {
    ui->pushButton_9->setDown(false);
  } else if (event->key() == Qt::Key_Plus) {
    ui->pushButton_plus->setDown(false);
  } else if (event->key() == Qt::Key_Minus) {
    ui->pushButton_minus->setDown(false);
  } else if (event->key() == Qt::Key_Slash) {
    ui->pushButton_del->setDown(false);
  } else if (event->key() == Qt::Key_Asterisk) {
    ui->pushButton_mul->setDown(false);
  } else if (event->key() == Qt::Key_Period) {
    ui->pushButton_dot->setDown(false);
  } else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
    ui->pushButton_eq->setDown(false);
  } else if (event->key() == Qt::Key_ParenLeft) {
    ui->pushButton_lbracket->setDown(false);
  } else if (event->key() == Qt::Key_ParenRight) {
    ui->pushButton_rbracket->setDown(false);
  } else if (event->key() == (Qt::Key_Delete)) {
    ui->pushButton_AC->setDown(false);
  } else if (event->key() == Qt::Key_Backspace) {
    ui->pushButton_backspace->setDown(false);
  } else if (event->key() == Qt::Key_AsciiCircum) {
    ui->pushButton_pow->setDown(false);
  } else if (event->key() == Qt::Key_X) {
    ui->pushButton_x->setDown(false);
  }
}

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString all_nums;
  if ((ui->result->text() == '0') || (ui->result->text() == "Invalid input"))
    ui->result->setText("");
  all_nums = (ui->result->text() + button->text());
  ui->result->setText(all_nums);
}

void MainWindow::ariph_numbers() {
  QPushButton *button = (QPushButton *)sender();
  if ((ui->result->text() == '0') || (ui->result->text() == "Invalid input"))
    ui->result->setText("");
  ui->result->setText(ui->result->text() + button->text());
}

void MainWindow::trigonomy_numbers() {
  QPushButton *button = (QPushButton *)sender();
  if ((ui->result->text() == '0') || (ui->result->text() == "Invalid input"))
    ui->result->setText("");
  ui->result->setText(ui->result->text() + button->text() + '(');
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->result->setText(ui->result->text() + ".");
}

void MainWindow::on_pushButton_unar_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  double all_nums;
  if (button->text() == "+/-") {
    all_nums = (ui->result->text()).toDouble();
    all_nums = all_nums * -1;
    new_label = QString::number(all_nums, 'g', 15);
    ui->result->setText(new_label);
  }
}

void MainWindow::on_pushButton_AC_clicked() { ui->result->setText("0"); }

void MainWindow::on_pushButton_eq_clicked() {
  double x = 0;
  char str[10000] = {0};
  QByteArray ba = ui->result->text().toLatin1();
  strlcpy(str, ba, ui->result->text().length() + 1);
  if (ui->value_x->text() != "") x = (ui->value_x->text().toDouble());
  if (valid_str(str) == 1) {
    ui->result->setText("Invalid input");
  } else {
    QString new_res = QString::number(terminal(str, x), 'g', 60);
    ui->result->setText(new_res);
  }
}

void MainWindow::on_pushButton_backspace_clicked() {
  QString text = ui->result->text();
  text.chop(1);
  if (text.isEmpty()) text = "0";
  ui->result->setText(text);
}
void MainWindow::on_pushButton_graph_clicked() {
  QString send = ui->result->text();
  QByteArray ba = send.toLocal8Bit();
  char *buf = ba.data();
  ui->widget->clearGraphs();
  x.clear();
  y.clear();
  result_1 = 0;
  result_2 = 0;
  xBegin = 0;
  xEnd = 0;
  h = 0.1;

  double Y = ui->value_x->text().toDouble();
  double X = 0;
  if (Y == 0) Y = 1;

  xy_1 = ui->x1->text().toDouble();
  xy_2 = ui->x2->text().toDouble();
  result_1 = ui->y1->text().toInt();
  result_2 = ui->y2->text().toInt();

  xBegin = result_2;
  xEnd = result_1 + h;

  ui->widget->xAxis->setRange(xy_2, xy_1);
  ui->widget->yAxis->setRange(result_2, result_1);
  N = (xEnd - xBegin) / h + 2;

  for (X = xBegin; X <= xEnd; X += h) {
    x.push_back(X);
    y.push_back(terminal(buf, Y * X));
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}

void MainWindow::on_pushButton_credit_clicked() {
  Credit window;
  window.setModal(true);
  window.exec();
}

void MainWindow::on_pushButton_deposit_clicked() {
  Deposit window;
  window.setModal(true);
  window.exec();
}

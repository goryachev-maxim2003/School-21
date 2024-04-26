#include "mainwindow.h"

#include "../s21_GUI_functions.h"
#include "../s21_calculate.h"
#include "../s21_validation.h"
#include "creditcalc.h"
#include "depositcalc.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(on_push_binary_operator()));
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(on_push_symbol()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(on_push_symbol()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(on_push_symbol()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(on_push_binary_operator()));
  connect(ui->pushButton_multiplication, SIGNAL(clicked()), this,
          SLOT(on_push_binary_operator()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(on_push_binary_operator()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(on_push_binary_operator()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(on_push_symbol()));

  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(on_push_function()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(on_push_function()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(on_push_binary_operator()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_push_symbol() {
  // error
  QString text = ui->result->text();
  std::string std_str = text.toStdString();
  const char* str = std_str.c_str();
  if (is_error(str)) ui->result->setText("");
  //вставка символа
  QPushButton* button = (QPushButton*)sender();
  ui->result->setText(ui->result->text() + button->text());
}

void MainWindow::on_push_function() {
  // error
  QString text = ui->result->text();
  std::string std_str = text.toStdString();
  const char* str = std_str.c_str();
  if (is_error(str)) ui->result->setText("");
  //вставка функции
  QPushButton* button = (QPushButton*)sender();
  ui->result->setText(ui->result->text() + button->text() + "(");
}

void MainWindow::on_push_binary_operator() {
  // error
  QString text = ui->result->text();
  std::string std_str = text.toStdString();
  const char* str = std_str.c_str();
  if (is_error(str)) ui->result->setText("");
  //вставка оператора
  QPushButton* button = (QPushButton*)sender();
  ui->result->setText(ui->result->text() + " " + button->text() + " ");
}

void MainWindow::on_pushButton_backspace_clicked() {
  //Вычислить сколько нужно удалить
  QString text = ui->result->text();

  std::string std_str = text.toStdString();
  const char* str = std_str.c_str();
  text.resize(text.size() - get_last_item_len(str));
  ui->result->setText(text);
}

void MainWindow::on_pushButton_c_clicked() { ui->result->setText(""); }

void MainWindow::on_pushButton_equal_clicked() {
  // result
  std::string std_str = ui->result->text().toStdString();
  const char* str = std_str.c_str();
  // x
  std::string std_str_x = ui->x_value->text().toStdString();
  const char* str_x = std_str_x.c_str();
  double x = 0;
  if (validation(str) == 1 || get_x(str_x, &x) == 0) {
    ui->result->setText(ERR_TEXT);
  } else {
    double d = calculate(str, x);
    ui->result->setText(QString::number(d));
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  ui->widget->clearGraphs();
  double min_x = 0, max_x = 0, min_y = 0, max_y = 0;
  // result
  std::string std_str = ui->result->text().toStdString();
  const char* str = std_str.c_str();
  // x
  std::string std_str_min_x = ui->min_x->text().toStdString();
  const char* str_min_x = std_str_min_x.c_str();
  std::string std_str_max_x = ui->max_x->text().toStdString();
  const char* str_max_x = std_str_max_x.c_str();
  std::string std_str_min_y = ui->min_y->text().toStdString();
  const char* str_min_y = std_str_min_y.c_str();
  std::string std_str_max_y = ui->max_y->text().toStdString();
  const char* str_max_y = std_str_max_y.c_str();
  // ui->result->setText(QString::number(!validation(str))+
  // QString::number(get_x(str_min_x, &min_x)) +
  // QString::number(get_x(str_max_x, &max_x)) +
  // QString::number(get_x(str_min_y, &min_y)) +
  // QString::number(get_x(str_max_y, &max_y)) + " minx
  // "+QString::number(min_x)+" maxx "+QString::number(max_x)+" miny
  // "+QString::number(min_y)+" maxy "+QString::number(max_y));
  //  if (get_x(str_min_x, &min_x))
  //    ui->result->setText(QString::number(min_x));

  if (!validation(str) && get_x(str_min_x, &min_x) &&
      get_x(str_max_x, &max_x) && get_x(str_min_y, &min_y) &&
      get_x(str_max_y, &max_y)) {
    ui->widget->xAxis->setRange(min_x, max_x);
    ui->widget->yAxis->setRange(min_y, max_y);
    QVector<double> x, y;
    double h = (max_x - min_x) / 100000;
    for (double i = min_x; i < max_x; i += h) {
      x.push_back(i);
      y.push_back(calculate(str, i));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    // ui->result->setText("minx "+QString::number(min_x)+" maxx
    // "+QString::number(max_x)+" miny "+QString::number(min_y)+" maxy
    // "+QString::number(max_y));
  } else {
    ui->result->setText("GRAPH_ERROR");
  }
}

void MainWindow::on_ToCreditCalc_clicked() {
  CreditCalc crediWin;
  crediWin.setModal(true);
  crediWin.exec();
}

void MainWindow::on_ToDepositCalc_clicked() {
  depositcalc depWin;
  depWin.setModal(true);
  depWin.exec();
}

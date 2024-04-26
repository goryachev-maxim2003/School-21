#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//Подлючение файлов си
#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_GUI_functions.h"
#include "../s21_calculate.h"
#include "../s21_validation.h"

#ifdef __cplusplus
}
#endif

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

 private slots:
  void on_push_symbol();
  void on_push_function();
  void on_push_binary_operator();
  void on_pushButton_backspace_clicked();
  void on_pushButton_c_clicked();
  void on_pushButton_equal_clicked();
  void on_pushButton_graph_clicked();
  void on_ToCreditCalc_clicked();
  void on_ToDepositCalc_clicked();
};
#endif  // MAINWINDOW_H

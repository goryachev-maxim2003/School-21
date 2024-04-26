#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QDialog>

namespace Ui {
class CreditCalc;
}

//Подлючение файлов си
#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_GUI_functions.h"
#include "../s21_creditCalc.h"

#ifdef __cplusplus
}
#endif

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_pushButton_clicked();

  void on_clear_clicked();

 private:
  Ui::CreditCalc *ui;
};

#endif  // CREDITCALC_H

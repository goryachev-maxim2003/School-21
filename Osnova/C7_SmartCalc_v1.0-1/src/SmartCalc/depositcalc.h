#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QDialog>

namespace Ui {
class depositcalc;
}

//Подлючение файлов си
#ifdef __cplusplus

extern "C" {
#endif

#include "../s21_GUI_functions.h"
#include "../s21_depositCalc.h"

#ifdef __cplusplus
}
#endif

class depositcalc : public QDialog {
  Q_OBJECT

 public:
  explicit depositcalc(QWidget *parent = nullptr);
  ~depositcalc();

 private slots:
  void on_clear_clicked();

  void on_calculate_clicked();

  void on_period_editingFinished();

  void on_add_or_rm_button_clicked();

  void on_period_textChanged(const QString &arg1);

 private:
  Ui::depositcalc *ui;
};

#endif  // DEPOSITCALC_H

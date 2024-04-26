#include "creditcalc.h"

#include "../s21_GUI_functions.h"
#include "../s21_creditCalc.h"
#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget* parent)
    : QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_clicked() {
  ui->error->setText("");
  double credit_sum = 0, interest_rate = 0, monthly_payment_min = 0,
         monthly_payment_max = 0, overpayment = 0, total_payout = 0;
  int period = 0;
  std::string std_str_credit_sum = ui->credit_sum->text().toStdString();
  const char* str_credit_sum = std_str_credit_sum.c_str();
  std::string std_str_period = ui->period->text().toStdString();
  const char* str_period = std_str_period.c_str();
  std::string std_str_interest_rate = ui->interest_rate->text().toStdString();
  const char* str_interest_rate = std_str_interest_rate.c_str();
  // if (get_x(str_credit_sum, &credit_sum) && get_x(str_period, &period) &&
  // get_x(str_interest_rate, &interest_rate)){
  //   ui->monthly_payment->setText("credit_sum:
  //   "+QString::number(credit_sum)+"period:
  //   "+QString::number(period)+"interest_rate:
  //   "+QString::number(interest_rate));
  // }
  if (!get_x(str_credit_sum, &credit_sum)) {
    ui->error->setText("Некорректное заполнение поля сумма кредита");
  } else if (!get_int(str_period, &period) || period <= 0) {
    ui->error->setText("Некорректное заполнение поля срок");
  } else if (!get_x(str_interest_rate, &interest_rate)) {
    ui->error->setText("Некорректное заполнение поля процентная ставка");
  } else if (!(ui->type_ann->isChecked() || ui->type_dif->isChecked())) {
    ui->error->setText("Не выбран тип платежа");
  } else {
    int type = ui->type_ann->isChecked() ? ANNUITY : DIFFERENTIATED;
    creditCalc(credit_sum, period, interest_rate, type, &monthly_payment_min,
               &monthly_payment_max, &overpayment, &total_payout);
    if (monthly_payment_min == monthly_payment_max) {
      ui->monthly_payment->setText(QString::number(monthly_payment_min));
    } else {
      ui->monthly_payment->setText(QString::number(monthly_payment_max) +
                                   " ... " +
                                   QString::number(monthly_payment_min));
    }
    ui->overpayment->setText(QString::number(overpayment));
    ui->total_payout->setText(QString::number(total_payout));
  }
}

void CreditCalc::on_clear_clicked() {
  ui->credit_sum->setText("");
  ui->period->setText("");
  ui->interest_rate->setText("");
  ui->monthly_payment->setText("0");
  ui->overpayment->setText("0");
  ui->total_payout->setText("0");
  ui->error->setText("");
}

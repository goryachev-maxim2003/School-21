#include "depositcalc.h"

#include "../s21_GUI_functions.h"
#include "../s21_depositCalc.h"
#include "ui_depositcalc.h"

depositcalc::depositcalc(QWidget* parent)
    : QDialog(parent), ui(new Ui::depositcalc) {
  ui->setupUi(this);
}

depositcalc::~depositcalc() { delete ui; }

void depositcalc::on_clear_clicked() {
  ui->deposit_sum->setText("");
  ui->period->setText("");
  ui->interest_rate->setText("");
  ui->tax_rate->setText("");
  ui->periodicity->setCurrentIndex(0);
  ui->interest_charges->setText("0");
  ui->tax_sum->setText("0");
  ui->end_sum->setText("0");
  ui->capitalization->setCheckState(Qt::Unchecked);
  ui->error->setText("");
  ui->add_or_rm_sum->setText("");
  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(0);
}

void depositcalc::on_calculate_clicked() {
  ui->error->setText("");

  double deposit_sum = 0, interest_rate = 0, tax_rate = 0, interest_charges = 0,
         tax_sum = 0, end_sum = 0;
  int period = 0;
  PeriodType periodicity = static_cast<enumPeriodType>(
      ui->periodicity->currentIndex());  // int в enum
  int capitalization = ui->capitalization->isChecked();
  int rowCount = ui->tableWidget->rowCount();
  addSum* arr = (addSum*)calloc(rowCount, sizeof(addSum));
  //Снятие и пополнение
  std::string std_str_deposit_sum = ui->deposit_sum->text().toStdString();
  const char* str_deposit_sum = std_str_deposit_sum.c_str();
  std::string std_str_period = ui->period->text().toStdString();
  const char* str_period = std_str_period.c_str();
  std::string std_str_interest_rate = ui->interest_rate->text().toStdString();
  const char* str_interest_rate = std_str_interest_rate.c_str();
  std::string std_str_tax_rate = ui->tax_rate->text().toStdString();
  const char* str_tax_rate = std_str_tax_rate.c_str();
  // if (get_x(str_deposit_sum, &deposit_sum) && get_int(str_period, &period) &&
  // get_x(str_interest_rate, &interest_rate) && get_x(str_tax_rate,
  // &tax_rate)){
  //   ui->error->setText("deposit_sum: "+QString::number(deposit_sum)+"period:
  //   "+QString::number(period)+"interest_rate:
  //   "+QString::number(interest_rate)
  //                      +"tax_rate: "+QString::number(tax_rate) +
  //                      "periodicity: " + QString::number(periodicity) +
  //                      "capitalization: " + QString::number(capitalization));
  // }
  if (!get_x(str_deposit_sum, &deposit_sum)) {
    ui->error->setText("Некорректное заполнение поля сумма депозита");
  } else if (!get_int(str_period, &period)) {
    ui->error->setText("Некорректное заполнение поля срок");
  } else if (!get_x(str_interest_rate, &interest_rate)) {
    ui->error->setText("Некорректное заполнение поля процентная ставка");
  } else if (!get_x(str_tax_rate, &tax_rate)) {
    ui->error->setText("Некорректное заполнение поля налоговая ставка");
  } else {
    for (int i = 0; i < rowCount; i++) {
      int month = ui->tableWidget->item(i, 0)->text().toInt();
      double sum = ui->tableWidget->item(i, 1)->text().toDouble();
      int day_number = ui->tableWidget->item(i, 2)->text().toInt();
      addSum item = {month, sum, day_number};
      arr[i] = item;
    }

    depositCalc(deposit_sum, period, interest_rate, tax_rate, periodicity,
                capitalization, &interest_charges, &tax_sum, &end_sum, arr,
                rowCount);
    ui->interest_charges->setText(QString::number(interest_charges));
    ui->tax_sum->setText(QString::number(tax_sum));
    ui->end_sum->setText(QString::number(end_sum));
  }
  free(arr);
}

void depositcalc::on_period_editingFinished()  //Для добавления пополнения
                                               //предлагаем только месяцы, в
                                               //течечение который лежит вклад
{
  std::string std_str_period = ui->period->text().toStdString();
  const char* str_period = std_str_period.c_str();
  int period = 0;
  if (!get_int(str_period, &period) || period <= 0) {
    ui->error->setText("Некорректное заполнение поля срок");
    ui->month_number->clear();
  } else {
    ui->month_number->clear();
    for (int i = 0; i < period; i++) {
      //В один и тот же месяц может быть несколько пополнений
      ui->month_number->addItem(QString::number(i + 1));
    }
  }
}

void depositcalc::on_add_or_rm_button_clicked() {
  std::string std_str_add_or_rm_sum = ui->add_or_rm_sum->text().toStdString();
  const char* str_add_or_rm_sum = std_str_add_or_rm_sum.c_str();
  std::string std_str_day_number = ui->day_number->text().toStdString();
  const char* str_day_number = std_str_day_number.c_str();
  double add_or_rm_sum = 0;
  int day_number = 0;
  if (!get_x(str_add_or_rm_sum, &add_or_rm_sum))
    ui->error->setText(
        "Некорректное заполнение поля Сумма пополнения / снятия");
  else if (ui->month_number->currentIndex() == -1)
    ui->error->setText("Заполните поле срок для добавления!");
  else if (!get_int(str_day_number, &day_number) || day_number <= 0)
    ui->error->setText(
        "Заполните корректно поле номер дня в месяце для добавления!");
  else {
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(
        ui->tableWidget->rowCount() - 1, 0,
        new QTableWidgetItem(ui->month_number->currentText()));
    ui->tableWidget->setItem(
        ui->tableWidget->rowCount() - 1, 1,
        new QTableWidgetItem(QString::number(add_or_rm_sum)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2,
                             new QTableWidgetItem(QString::number(day_number)));

    //Проверка
    // ui->error->setText(ui->tableWidget->item(0,0)->text() + " " +
    // ui->tableWidget->item(0,1)->text() );
  }
}

void depositcalc::on_period_textChanged(const QString& arg1) {
  //Когда меняем срок, в таблице могут остаться пополнения/снятия не входящие в
  //срок Отчищаем пополнения/снятия при каждом ихзменении срока
  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(0);
}

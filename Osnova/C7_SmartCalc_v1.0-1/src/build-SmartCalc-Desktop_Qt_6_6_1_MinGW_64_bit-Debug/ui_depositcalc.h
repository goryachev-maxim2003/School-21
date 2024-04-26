/********************************************************************************
** Form generated from reading UI file 'depositcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITCALC_H
#define UI_DEPOSITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_depositcalc {
 public:
  QLabel *label;
  QLabel *label_2;
  QLabel *label_3;
  QLabel *label_4;
  QLabel *label_5;
  QLineEdit *deposit_sum;
  QLineEdit *period;
  QLineEdit *interest_rate;
  QLineEdit *tax_rate;
  QCheckBox *capitalization;
  QLabel *label_6;
  QPushButton *add_or_rm_button;
  QLabel *label_7;
  QLabel *label_8;
  QLabel *label_9;
  QLabel *interest_charges;
  QLabel *tax_sum;
  QLabel *end_sum;
  QPushButton *clear;
  QPushButton *calculate;
  QLabel *error;
  QComboBox *periodicity;
  QLineEdit *add_or_rm_sum;
  QLabel *label_10;
  QTableWidget *tableWidget;
  QComboBox *month_number;
  QLineEdit *day_number;
  QLabel *label_11;

  void setupUi(QDialog *depositcalc) {
    if (depositcalc->objectName().isEmpty())
      depositcalc->setObjectName("depositcalc");
    depositcalc->resize(1039, 499);
    label = new QLabel(depositcalc);
    label->setObjectName("label");
    label->setGeometry(QRect(20, 10, 101, 20));
    label_2 = new QLabel(depositcalc);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(20, 50, 101, 20));
    label_3 = new QLabel(depositcalc);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(20, 90, 171, 20));
    label_4 = new QLabel(depositcalc);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(20, 130, 161, 20));
    label_5 = new QLabel(depositcalc);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(20, 170, 191, 20));
    deposit_sum = new QLineEdit(depositcalc);
    deposit_sum->setObjectName("deposit_sum");
    deposit_sum->setGeometry(QRect(190, 10, 131, 21));
    period = new QLineEdit(depositcalc);
    period->setObjectName("period");
    period->setGeometry(QRect(190, 50, 131, 21));
    period->setMaxLength(3);
    interest_rate = new QLineEdit(depositcalc);
    interest_rate->setObjectName("interest_rate");
    interest_rate->setGeometry(QRect(190, 90, 131, 21));
    tax_rate = new QLineEdit(depositcalc);
    tax_rate->setObjectName("tax_rate");
    tax_rate->setGeometry(QRect(190, 130, 131, 21));
    capitalization = new QCheckBox(depositcalc);
    capitalization->setObjectName("capitalization");
    capitalization->setGeometry(QRect(20, 200, 131, 24));
    label_6 = new QLabel(depositcalc);
    label_6->setObjectName("label_6");
    label_6->setGeometry(QRect(20, 270, 271, 20));
    add_or_rm_button = new QPushButton(depositcalc);
    add_or_rm_button->setObjectName("add_or_rm_button");
    add_or_rm_button->setGeometry(QRect(290, 370, 101, 31));
    label_7 = new QLabel(depositcalc);
    label_7->setObjectName("label_7");
    label_7->setGeometry(QRect(440, 10, 171, 20));
    label_8 = new QLabel(depositcalc);
    label_8->setObjectName("label_8");
    label_8->setGeometry(QRect(440, 50, 171, 20));
    label_9 = new QLabel(depositcalc);
    label_9->setObjectName("label_9");
    label_9->setGeometry(QRect(440, 90, 231, 20));
    interest_charges = new QLabel(depositcalc);
    interest_charges->setObjectName("interest_charges");
    interest_charges->setGeometry(QRect(700, 10, 91, 20));
    tax_sum = new QLabel(depositcalc);
    tax_sum->setObjectName("tax_sum");
    tax_sum->setGeometry(QRect(700, 50, 91, 20));
    end_sum = new QLabel(depositcalc);
    end_sum->setObjectName("end_sum");
    end_sum->setGeometry(QRect(700, 90, 91, 20));
    clear = new QPushButton(depositcalc);
    clear->setObjectName("clear");
    clear->setGeometry(QRect(560, 150, 91, 31));
    calculate = new QPushButton(depositcalc);
    calculate->setObjectName("calculate");
    calculate->setGeometry(QRect(440, 150, 91, 31));
    error = new QLabel(depositcalc);
    error->setObjectName("error");
    error->setGeometry(QRect(440, 200, 591, 20));
    periodicity = new QComboBox(depositcalc);
    periodicity->addItem(QString());
    periodicity->addItem(QString());
    periodicity->addItem(QString());
    periodicity->addItem(QString());
    periodicity->addItem(QString());
    periodicity->addItem(QString());
    periodicity->setObjectName("periodicity");
    periodicity->setGeometry(QRect(190, 170, 131, 26));
    add_or_rm_sum = new QLineEdit(depositcalc);
    add_or_rm_sum->setObjectName("add_or_rm_sum");
    add_or_rm_sum->setGeometry(QRect(290, 270, 131, 21));
    label_10 = new QLabel(depositcalc);
    label_10->setObjectName("label_10");
    label_10->setGeometry(QRect(180, 340, 111, 20));
    tableWidget = new QTableWidget(depositcalc);
    if (tableWidget->columnCount() < 3) tableWidget->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
    QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
    tableWidget->setObjectName("tableWidget");
    tableWidget->setGeometry(QRect(440, 260, 571, 211));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
    tableWidget->setSizePolicy(sizePolicy);
    month_number = new QComboBox(depositcalc);
    month_number->setObjectName("month_number");
    month_number->setGeometry(QRect(290, 340, 131, 26));
    day_number = new QLineEdit(depositcalc);
    day_number->setObjectName("day_number");
    day_number->setGeometry(QRect(290, 300, 131, 21));
    label_11 = new QLabel(depositcalc);
    label_11->setObjectName("label_11");
    label_11->setGeometry(QRect(70, 300, 221, 20));

    retranslateUi(depositcalc);

    QMetaObject::connectSlotsByName(depositcalc);
  }  // setupUi

  void retranslateUi(QDialog *depositcalc) {
    depositcalc->setWindowTitle(
        QCoreApplication::translate("depositcalc", "Dialog", nullptr));
    label->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\241\321\203\320\274\320\274\320\260 "
        "\320\262\320\272\320\273\320\260\320\264\320\260",
        nullptr));
    label_2->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\241\321\200\320\276\320\272 (\320\234\320\265\321\201.)",
        nullptr));
    label_3->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320"
        "\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 (%)",
        nullptr));
    label_4->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\235\320\276\320\273\320\276\320\263\320\276\320\262\320\260\321"
        "\217 \321\201\321\202\320\260\320\262\320\272\320\260 (%)",
        nullptr));
    label_5->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320"
        "\275\320\276\321\201\321\202\321\214 "
        "\320\262\321\213\320\277\320\273\320\260\321\202",
        nullptr));
    capitalization->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320"
        "\267\320\260\321\206\320\270\321\217",
        nullptr));
    label_6->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\241\321\203\320\274\320\274\320\260 "
        "\320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320"
        "\270\321\217 (>0) / \321\201\320\275\321\217\321\202\320\270\321\217 "
        "(<0) ",
        nullptr));
    add_or_rm_button->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214",
        nullptr));
    label_7->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\275\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320"
        "\275\321\213\320\265 "
        "\320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213",
        nullptr));
    label_8->setText(QCoreApplication::translate(
        "depositcalc",
        "\321\201\321\203\320\274\320\274\320\260 "
        "\320\275\320\260\320\273\320\276\320\263\320\260",
        nullptr));
    label_9->setText(QCoreApplication::translate(
        "depositcalc",
        "\321\201\321\203\320\274\320\274\320\260 \320\275\320\260 "
        "\320\262\320\272\320\273\320\260\320\264\320\265 \320\272 "
        "\320\272\320\276\320\275\321\206\321\203 "
        "\321\201\321\200\320\276\320\272\320\260",
        nullptr));
    interest_charges->setText(
        QCoreApplication::translate("depositcalc", "0", nullptr));
    tax_sum->setText(QCoreApplication::translate("depositcalc", "0", nullptr));
    end_sum->setText(QCoreApplication::translate("depositcalc", "0", nullptr));
    clear->setText(
        QCoreApplication::translate("depositcalc",
                                    "\320\236\321\202\321\207\320\270\321\201"
                                    "\321\202\320\270\321\202\321\214",
                                    nullptr));
    calculate->setText(
        QCoreApplication::translate("depositcalc",
                                    "\320\240\320\260\321\201\321\201\321\207"
                                    "\320\270\321\202\320\260\321\202\321\214",
                                    nullptr));
    error->setText(QString());
    periodicity->setItemText(0, QCoreApplication::translate(
                                    "depositcalc",
                                    "\321\200\320\260\320\267 \320\262 "
                                    "\320\274\320\265\321\201\321\217\321\206",
                                    nullptr));
    periodicity->setItemText(
        1, QCoreApplication::translate(
               "depositcalc",
               "\321\200\320\260\320\267 \320\262 2 "
               "\320\274\320\265\321\201\321\217\321\206\320\260",
               nullptr));
    periodicity->setItemText(
        2, QCoreApplication::translate(
               "depositcalc",
               "\321\200\320\260\320\267 \320\262 "
               "\320\272\320\262\320\260\321\200\321\202\320\260\320\273",
               nullptr));
    periodicity->setItemText(
        3, QCoreApplication::translate(
               "depositcalc",
               "\321\200\320\260\320\267 \320\262 4 "
               "\320\274\320\265\321\201\321\217\321\206\320\260",
               nullptr));
    periodicity->setItemText(
        4, QCoreApplication::translate(
               "depositcalc",
               "\321\200\320\260\320\267 \320\262 "
               "\320\277\320\276\320\273\320\263\320\276\320\264\320\260",
               nullptr));
    periodicity->setItemText(
        5, QCoreApplication::translate(
               "depositcalc",
               "\321\200\320\260\320\267 \320\262 \320\263\320\276\320\264",
               nullptr));

    label_10->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\235\320\276\320\274\320\265\321\200 "
        "\320\274\320\265\321\201\321\217\321\206\320\260",
        nullptr));
    QTableWidgetItem *___qtablewidgetitem =
        tableWidget->horizontalHeaderItem(0);
    ___qtablewidgetitem->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\235\320\276\320\274\320\265\321\200 "
        "\320\274\320\265\321\201\321\217\321\206\320\260",
        nullptr));
    QTableWidgetItem *___qtablewidgetitem1 =
        tableWidget->horizontalHeaderItem(1);
    ___qtablewidgetitem1->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320"
        "\270\320\265 / C\320\275\321\217\321\202\320\270\320\265",
        nullptr));
    QTableWidgetItem *___qtablewidgetitem2 =
        tableWidget->horizontalHeaderItem(2);
    ___qtablewidgetitem2->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\235\320\276\320\274\320\265\321\200 \320\264\320\275\321\217 "
        "\320\262 \320\274\320\265\321\201\321\217\321\206\320\265",
        nullptr));
    label_11->setText(QCoreApplication::translate(
        "depositcalc",
        "\320\235\320\276\320\274\320\265\321\200 \320\264\320\275\321\217 "
        "\320\262 \320\277\320\265\321\200\320\270\320\276\320\264\320\265 "
        "\320\262\321\213\320\277\320\273\320\260\321\202",
        nullptr));
  }  // retranslateUi
};

namespace Ui {
class depositcalc : public Ui_depositcalc {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_DEPOSITCALC_H

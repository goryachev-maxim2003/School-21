/********************************************************************************
** Form generated from reading UI file 'creditcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITCALC_H
#define UI_CREDITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CreditCalc {
 public:
  QLabel *label;
  QLabel *label_2;
  QLabel *label_3;
  QLabel *label_4;
  QLabel *label_5;
  QLabel *label_6;
  QLabel *label_7;
  QRadioButton *type_ann;
  QRadioButton *type_dif;
  QPushButton *pushButton;
  QLineEdit *credit_sum;
  QLineEdit *period;
  QLineEdit *interest_rate;
  QLabel *monthly_payment;
  QLabel *overpayment;
  QLabel *total_payout;
  QLabel *error;
  QPushButton *clear;

  void setupUi(QDialog *CreditCalc) {
    if (CreditCalc->objectName().isEmpty())
      CreditCalc->setObjectName("CreditCalc");
    CreditCalc->resize(1229, 294);
    label = new QLabel(CreditCalc);
    label->setObjectName("label");
    label->setGeometry(QRect(30, 20, 111, 20));
    label_2 = new QLabel(CreditCalc);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(30, 70, 121, 20));
    label_3 = new QLabel(CreditCalc);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(30, 120, 171, 20));
    label_4 = new QLabel(CreditCalc);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(30, 170, 91, 20));
    label_5 = new QLabel(CreditCalc);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(350, 20, 161, 20));
    label_6 = new QLabel(CreditCalc);
    label_6->setObjectName("label_6");
    label_6->setGeometry(QRect(350, 70, 161, 20));
    label_7 = new QLabel(CreditCalc);
    label_7->setObjectName("label_7");
    label_7->setGeometry(QRect(350, 120, 161, 20));
    type_ann = new QRadioButton(CreditCalc);
    type_ann->setObjectName("type_ann");
    type_ann->setGeometry(QRect(30, 200, 131, 24));
    type_dif = new QRadioButton(CreditCalc);
    type_dif->setObjectName("type_dif");
    type_dif->setGeometry(QRect(30, 230, 191, 24));
    pushButton = new QPushButton(CreditCalc);
    pushButton->setObjectName("pushButton");
    pushButton->setGeometry(QRect(240, 230, 171, 29));
    credit_sum = new QLineEdit(CreditCalc);
    credit_sum->setObjectName("credit_sum");
    credit_sum->setGeometry(QRect(210, 20, 113, 26));
    period = new QLineEdit(CreditCalc);
    period->setObjectName("period");
    period->setGeometry(QRect(210, 70, 113, 26));
    period->setMaxLength(3);
    interest_rate = new QLineEdit(CreditCalc);
    interest_rate->setObjectName("interest_rate");
    interest_rate->setGeometry(QRect(210, 120, 113, 26));
    monthly_payment = new QLabel(CreditCalc);
    monthly_payment->setObjectName("monthly_payment");
    monthly_payment->setGeometry(QRect(520, 20, 491, 21));
    overpayment = new QLabel(CreditCalc);
    overpayment->setObjectName("overpayment");
    overpayment->setGeometry(QRect(520, 70, 491, 21));
    total_payout = new QLabel(CreditCalc);
    total_payout->setObjectName("total_payout");
    total_payout->setGeometry(QRect(520, 120, 491, 21));
    error = new QLabel(CreditCalc);
    error->setObjectName("error");
    error->setGeometry(QRect(210, 170, 331, 20));
    clear = new QPushButton(CreditCalc);
    clear->setObjectName("clear");
    clear->setGeometry(QRect(440, 230, 171, 29));

    retranslateUi(CreditCalc);

    QMetaObject::connectSlotsByName(CreditCalc);
  }  // setupUi

  void retranslateUi(QDialog *CreditCalc) {
    CreditCalc->setWindowTitle(
        QCoreApplication::translate("CreditCalc", "Dialog", nullptr));
    label->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\241\321\203\320\274\320\274\320\260 "
        "\320\272\321\200\320\265\320\264\320\270\321\202\320\260",
        nullptr));
    label_2->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\241\321\200\320\276\320\272 (\320\262 "
        "\320\274\320\265\321\201\321\217\321\206\320\260\321\205)",
        nullptr));
    label_3->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320"
        "\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 (%)",
        nullptr));
    label_4->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\242\320\270\320\277 "
        "\320\277\320\273\320\260\321\202\320\265\320\266\320\260:",
        nullptr));
    label_5->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320"
        "\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266",
        nullptr));
    label_6->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320"
        "\260 \320\277\320\276 "
        "\320\272\321\200\320\265\320\264\320\270\321\202\321\203",
        nullptr));
    label_7->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\236\320\261\321\211\320\260\321\217 "
        "\320\262\321\213\320\277\320\273\320\260\321\202\320\260",
        nullptr));
    type_ann->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\260\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320"
        "\275\321\213\320\271",
        nullptr));
    type_dif->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\264\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321"
        "\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213"
        "\320\271",
        nullptr));
    pushButton->setText(
        QCoreApplication::translate("CreditCalc",
                                    "\320\240\320\260\321\201\321\201\321\207"
                                    "\320\270\321\202\320\260\321\202\321\214",
                                    nullptr));
    interest_rate->setText(QString());
    monthly_payment->setText(
        QCoreApplication::translate("CreditCalc", "0", nullptr));
    overpayment->setText(
        QCoreApplication::translate("CreditCalc", "0", nullptr));
    total_payout->setText(
        QCoreApplication::translate("CreditCalc", "0", nullptr));
    error->setText(QString());
    clear->setText(
        QCoreApplication::translate("CreditCalc",
                                    "\320\236\321\202\321\207\320\270\321\201"
                                    "\321\202\320\270\321\202\321\214",
                                    nullptr));
  }  // retranslateUi
};

namespace Ui {
class CreditCalc : public Ui_CreditCalc {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_CREDITCALC_H

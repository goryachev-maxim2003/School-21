/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QWidget *gridLayoutWidget;
  QGridLayout *gridLayout;
  QPushButton *pushButton_mod;
  QPushButton *pushButton_asin;
  QPushButton *pushButton_6;
  QPushButton *pushButton_backspace;
  QPushButton *pushButton_plus;
  QPushButton *pushButton_div;
  QPushButton *pushButton_pow;
  QPushButton *pushButton_x;
  QPushButton *pushButton_0;
  QPushButton *pushButton_3;
  QPushButton *pushButton_1;
  QPushButton *pushButton_acos;
  QPushButton *pushButton_5;
  QPushButton *pushButton_atan;
  QPushButton *pushButton_c;
  QPushButton *pushButton_ln;
  QPushButton *pushButton_7;
  QPushButton *pushButton_sqrt;
  QPushButton *pushButton_8;
  QPushButton *pushButton_dot;
  QPushButton *pushButton_graph;
  QPushButton *pushButton_4;
  QPushButton *pushButton_2;
  QPushButton *pushButton_9;
  QPushButton *pushButton_minus;
  QPushButton *pushButton_tan;
  QPushButton *pushButton_log;
  QPushButton *pushButton_cos;
  QPushButton *pushButton_sin;
  QPushButton *pushButton_equal;
  QPushButton *pushButton_right_bracket;
  QPushButton *pushButton_left_bracket;
  QPushButton *pushButton_multiplication;
  QLabel *result;
  QLineEdit *x_value;
  QLabel *label;
  QLabel *label_2;
  QLabel *label_3;
  QLineEdit *min_x;
  QLineEdit *max_x;
  QLineEdit *min_y;
  QLineEdit *max_y;
  QCustomPlot *widget;
  QPushButton *ToCreditCalc;
  QPushButton *ToDepositCalc;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName("MainWindow");
    MainWindow->resize(1323, 649);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    gridLayoutWidget = new QWidget(centralwidget);
    gridLayoutWidget->setObjectName("gridLayoutWidget");
    gridLayoutWidget->setGeometry(QRect(50, 110, 571, 321));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName("gridLayout");
    gridLayout->setHorizontalSpacing(2);
    gridLayout->setVerticalSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    pushButton_mod = new QPushButton(gridLayoutWidget);
    pushButton_mod->setObjectName("pushButton_mod");
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(
        pushButton_mod->sizePolicy().hasHeightForWidth());
    pushButton_mod->setSizePolicy(sizePolicy);
    pushButton_mod->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_mod, 1, 3, 1, 1);

    pushButton_asin = new QPushButton(gridLayoutWidget);
    pushButton_asin->setObjectName("pushButton_asin");
    sizePolicy.setHeightForWidth(
        pushButton_asin->sizePolicy().hasHeightForWidth());
    pushButton_asin->setSizePolicy(sizePolicy);
    pushButton_asin->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_asin, 1, 0, 1, 1);

    pushButton_6 = new QPushButton(gridLayoutWidget);
    pushButton_6->setObjectName("pushButton_6");
    sizePolicy.setHeightForWidth(
        pushButton_6->sizePolicy().hasHeightForWidth());
    pushButton_6->setSizePolicy(sizePolicy);
    pushButton_6->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_6, 3, 3, 1, 1);

    pushButton_backspace = new QPushButton(gridLayoutWidget);
    pushButton_backspace->setObjectName("pushButton_backspace");
    sizePolicy.setHeightForWidth(
        pushButton_backspace->sizePolicy().hasHeightForWidth());
    pushButton_backspace->setSizePolicy(sizePolicy);
    pushButton_backspace->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_backspace, 1, 2, 1, 1);

    pushButton_plus = new QPushButton(gridLayoutWidget);
    pushButton_plus->setObjectName("pushButton_plus");
    sizePolicy.setHeightForWidth(
        pushButton_plus->sizePolicy().hasHeightForWidth());
    pushButton_plus->setSizePolicy(sizePolicy);
    pushButton_plus->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_plus, 4, 4, 1, 1);

    pushButton_div = new QPushButton(gridLayoutWidget);
    pushButton_div->setObjectName("pushButton_div");
    sizePolicy.setHeightForWidth(
        pushButton_div->sizePolicy().hasHeightForWidth());
    pushButton_div->setSizePolicy(sizePolicy);
    pushButton_div->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_div, 1, 4, 1, 1);

    pushButton_pow = new QPushButton(gridLayoutWidget);
    pushButton_pow->setObjectName("pushButton_pow");
    sizePolicy.setHeightForWidth(
        pushButton_pow->sizePolicy().hasHeightForWidth());
    pushButton_pow->setSizePolicy(sizePolicy);
    pushButton_pow->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_pow, 0, 2, 1, 1);

    pushButton_x = new QPushButton(gridLayoutWidget);
    pushButton_x->setObjectName("pushButton_x");
    sizePolicy.setHeightForWidth(
        pushButton_x->sizePolicy().hasHeightForWidth());
    pushButton_x->setSizePolicy(sizePolicy);
    pushButton_x->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_x, 5, 1, 1, 1);

    pushButton_0 = new QPushButton(gridLayoutWidget);
    pushButton_0->setObjectName("pushButton_0");
    sizePolicy.setHeightForWidth(
        pushButton_0->sizePolicy().hasHeightForWidth());
    pushButton_0->setSizePolicy(sizePolicy);
    pushButton_0->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_0, 5, 2, 1, 1);

    pushButton_3 = new QPushButton(gridLayoutWidget);
    pushButton_3->setObjectName("pushButton_3");
    sizePolicy.setHeightForWidth(
        pushButton_3->sizePolicy().hasHeightForWidth());
    pushButton_3->setSizePolicy(sizePolicy);
    pushButton_3->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_3, 4, 3, 1, 1);

    pushButton_1 = new QPushButton(gridLayoutWidget);
    pushButton_1->setObjectName("pushButton_1");
    sizePolicy.setHeightForWidth(
        pushButton_1->sizePolicy().hasHeightForWidth());
    pushButton_1->setSizePolicy(sizePolicy);
    pushButton_1->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_1, 4, 1, 1, 1);

    pushButton_acos = new QPushButton(gridLayoutWidget);
    pushButton_acos->setObjectName("pushButton_acos");
    sizePolicy.setHeightForWidth(
        pushButton_acos->sizePolicy().hasHeightForWidth());
    pushButton_acos->setSizePolicy(sizePolicy);
    pushButton_acos->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_acos, 2, 0, 1, 1);

    pushButton_5 = new QPushButton(gridLayoutWidget);
    pushButton_5->setObjectName("pushButton_5");
    sizePolicy.setHeightForWidth(
        pushButton_5->sizePolicy().hasHeightForWidth());
    pushButton_5->setSizePolicy(sizePolicy);
    pushButton_5->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_5, 3, 2, 1, 1);

    pushButton_atan = new QPushButton(gridLayoutWidget);
    pushButton_atan->setObjectName("pushButton_atan");
    sizePolicy.setHeightForWidth(
        pushButton_atan->sizePolicy().hasHeightForWidth());
    pushButton_atan->setSizePolicy(sizePolicy);
    pushButton_atan->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_atan, 0, 0, 1, 1);

    pushButton_c = new QPushButton(gridLayoutWidget);
    pushButton_c->setObjectName("pushButton_c");
    sizePolicy.setHeightForWidth(
        pushButton_c->sizePolicy().hasHeightForWidth());
    pushButton_c->setSizePolicy(sizePolicy);
    pushButton_c->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_c, 1, 1, 1, 1);

    pushButton_ln = new QPushButton(gridLayoutWidget);
    pushButton_ln->setObjectName("pushButton_ln");
    sizePolicy.setHeightForWidth(
        pushButton_ln->sizePolicy().hasHeightForWidth());
    pushButton_ln->setSizePolicy(sizePolicy);
    pushButton_ln->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_ln, 1, 5, 1, 1);

    pushButton_7 = new QPushButton(gridLayoutWidget);
    pushButton_7->setObjectName("pushButton_7");
    sizePolicy.setHeightForWidth(
        pushButton_7->sizePolicy().hasHeightForWidth());
    pushButton_7->setSizePolicy(sizePolicy);
    pushButton_7->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_7, 2, 1, 1, 1);

    pushButton_sqrt = new QPushButton(gridLayoutWidget);
    pushButton_sqrt->setObjectName("pushButton_sqrt");
    sizePolicy.setHeightForWidth(
        pushButton_sqrt->sizePolicy().hasHeightForWidth());
    pushButton_sqrt->setSizePolicy(sizePolicy);
    pushButton_sqrt->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_sqrt, 0, 1, 1, 1);

    pushButton_8 = new QPushButton(gridLayoutWidget);
    pushButton_8->setObjectName("pushButton_8");
    sizePolicy.setHeightForWidth(
        pushButton_8->sizePolicy().hasHeightForWidth());
    pushButton_8->setSizePolicy(sizePolicy);
    pushButton_8->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_8, 2, 2, 1, 1);

    pushButton_dot = new QPushButton(gridLayoutWidget);
    pushButton_dot->setObjectName("pushButton_dot");
    sizePolicy.setHeightForWidth(
        pushButton_dot->sizePolicy().hasHeightForWidth());
    pushButton_dot->setSizePolicy(sizePolicy);
    pushButton_dot->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_dot, 5, 3, 1, 1);

    pushButton_graph = new QPushButton(gridLayoutWidget);
    pushButton_graph->setObjectName("pushButton_graph");
    sizePolicy.setHeightForWidth(
        pushButton_graph->sizePolicy().hasHeightForWidth());
    pushButton_graph->setSizePolicy(sizePolicy);
    pushButton_graph->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_graph, 2, 5, 1, 1);

    pushButton_4 = new QPushButton(gridLayoutWidget);
    pushButton_4->setObjectName("pushButton_4");
    sizePolicy.setHeightForWidth(
        pushButton_4->sizePolicy().hasHeightForWidth());
    pushButton_4->setSizePolicy(sizePolicy);
    pushButton_4->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);

    pushButton_2 = new QPushButton(gridLayoutWidget);
    pushButton_2->setObjectName("pushButton_2");
    sizePolicy.setHeightForWidth(
        pushButton_2->sizePolicy().hasHeightForWidth());
    pushButton_2->setSizePolicy(sizePolicy);
    pushButton_2->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_2, 4, 2, 1, 1);

    pushButton_9 = new QPushButton(gridLayoutWidget);
    pushButton_9->setObjectName("pushButton_9");
    sizePolicy.setHeightForWidth(
        pushButton_9->sizePolicy().hasHeightForWidth());
    pushButton_9->setSizePolicy(sizePolicy);
    pushButton_9->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_9, 2, 3, 1, 1);

    pushButton_minus = new QPushButton(gridLayoutWidget);
    pushButton_minus->setObjectName("pushButton_minus");
    sizePolicy.setHeightForWidth(
        pushButton_minus->sizePolicy().hasHeightForWidth());
    pushButton_minus->setSizePolicy(sizePolicy);
    pushButton_minus->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_minus, 3, 4, 1, 1);

    pushButton_tan = new QPushButton(gridLayoutWidget);
    pushButton_tan->setObjectName("pushButton_tan");
    sizePolicy.setHeightForWidth(
        pushButton_tan->sizePolicy().hasHeightForWidth());
    pushButton_tan->setSizePolicy(sizePolicy);
    pushButton_tan->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_tan, 3, 0, 1, 1);

    pushButton_log = new QPushButton(gridLayoutWidget);
    pushButton_log->setObjectName("pushButton_log");
    sizePolicy.setHeightForWidth(
        pushButton_log->sizePolicy().hasHeightForWidth());
    pushButton_log->setSizePolicy(sizePolicy);
    pushButton_log->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_log, 0, 5, 1, 1);

    pushButton_cos = new QPushButton(gridLayoutWidget);
    pushButton_cos->setObjectName("pushButton_cos");
    sizePolicy.setHeightForWidth(
        pushButton_cos->sizePolicy().hasHeightForWidth());
    pushButton_cos->setSizePolicy(sizePolicy);
    pushButton_cos->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_cos, 5, 0, 1, 1);

    pushButton_sin = new QPushButton(gridLayoutWidget);
    pushButton_sin->setObjectName("pushButton_sin");
    sizePolicy.setHeightForWidth(
        pushButton_sin->sizePolicy().hasHeightForWidth());
    pushButton_sin->setSizePolicy(sizePolicy);
    pushButton_sin->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_sin, 4, 0, 1, 1);

    pushButton_equal = new QPushButton(gridLayoutWidget);
    pushButton_equal->setObjectName("pushButton_equal");
    sizePolicy.setHeightForWidth(
        pushButton_equal->sizePolicy().hasHeightForWidth());
    pushButton_equal->setSizePolicy(sizePolicy);
    pushButton_equal->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_equal, 5, 4, 1, 1);

    pushButton_right_bracket = new QPushButton(gridLayoutWidget);
    pushButton_right_bracket->setObjectName("pushButton_right_bracket");
    sizePolicy.setHeightForWidth(
        pushButton_right_bracket->sizePolicy().hasHeightForWidth());
    pushButton_right_bracket->setSizePolicy(sizePolicy);
    pushButton_right_bracket->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_right_bracket, 0, 4, 1, 1);

    pushButton_left_bracket = new QPushButton(gridLayoutWidget);
    pushButton_left_bracket->setObjectName("pushButton_left_bracket");
    sizePolicy.setHeightForWidth(
        pushButton_left_bracket->sizePolicy().hasHeightForWidth());
    pushButton_left_bracket->setSizePolicy(sizePolicy);
    pushButton_left_bracket->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_left_bracket, 0, 3, 1, 1);

    pushButton_multiplication = new QPushButton(gridLayoutWidget);
    pushButton_multiplication->setObjectName("pushButton_multiplication");
    sizePolicy.setHeightForWidth(
        pushButton_multiplication->sizePolicy().hasHeightForWidth());
    pushButton_multiplication->setSizePolicy(sizePolicy);
    pushButton_multiplication->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_multiplication, 2, 4, 1, 1);

    result = new QLabel(centralwidget);
    result->setObjectName("result");
    result->setGeometry(QRect(50, 30, 661, 61));
    QFont font;
    font.setPointSize(16);
    result->setFont(font);
    result->setStyleSheet(QString::fromUtf8(
        "QLabel {\n"
        "	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
        "	border: 1px solid gray;\n"
        "}\n"
        "\n"
        "background-color: white;"));
    x_value = new QLineEdit(centralwidget);
    x_value->setObjectName("x_value");
    x_value->setGeometry(QRect(140, 440, 231, 31));
    label = new QLabel(centralwidget);
    label->setObjectName("label");
    label->setGeometry(QRect(90, 440, 21, 31));
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(640, 110, 91, 20));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(640, 160, 91, 20));
    min_x = new QLineEdit(centralwidget);
    min_x->setObjectName("min_x");
    min_x->setGeometry(QRect(740, 110, 71, 26));
    min_x->setMaxLength(8);
    max_x = new QLineEdit(centralwidget);
    max_x->setObjectName("max_x");
    max_x->setGeometry(QRect(830, 110, 71, 26));
    max_x->setMaxLength(8);
    min_y = new QLineEdit(centralwidget);
    min_y->setObjectName("min_y");
    min_y->setGeometry(QRect(740, 160, 71, 26));
    min_y->setMaxLength(8);
    max_y = new QLineEdit(centralwidget);
    max_y->setObjectName("max_y");
    max_y->setGeometry(QRect(830, 160, 71, 26));
    max_y->setMaxLength(8);
    widget = new QCustomPlot(centralwidget);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(640, 200, 401, 221));
    ToCreditCalc = new QPushButton(centralwidget);
    ToCreditCalc->setObjectName("ToCreditCalc");
    ToCreditCalc->setGeometry(QRect(50, 500, 191, 29));
    ToDepositCalc = new QPushButton(centralwidget);
    ToDepositCalc->setObjectName("ToDepositCalc");
    ToDepositCalc->setGeometry(QRect(260, 500, 191, 29));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 1323, 26));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName("statusbar");
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    pushButton_mod->setText(
        QCoreApplication::translate("MainWindow", "mod", nullptr));
    pushButton_asin->setText(
        QCoreApplication::translate("MainWindow", "asin", nullptr));
    pushButton_6->setText(
        QCoreApplication::translate("MainWindow", "6", nullptr));
    pushButton_backspace->setText(
        QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
    pushButton_plus->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_div->setText(
        QCoreApplication::translate("MainWindow", "/", nullptr));
    pushButton_pow->setText(
        QCoreApplication::translate("MainWindow", "^", nullptr));
    pushButton_x->setText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    pushButton_0->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    pushButton_3->setText(
        QCoreApplication::translate("MainWindow", "3", nullptr));
    pushButton_1->setText(
        QCoreApplication::translate("MainWindow", "1", nullptr));
    pushButton_acos->setText(
        QCoreApplication::translate("MainWindow", "acos", nullptr));
    pushButton_5->setText(
        QCoreApplication::translate("MainWindow", "5", nullptr));
    pushButton_atan->setText(
        QCoreApplication::translate("MainWindow", "atan", nullptr));
    pushButton_c->setText(
        QCoreApplication::translate("MainWindow", "C", nullptr));
    pushButton_ln->setText(
        QCoreApplication::translate("MainWindow", "ln", nullptr));
    pushButton_7->setText(
        QCoreApplication::translate("MainWindow", "7", nullptr));
    pushButton_sqrt->setText(
        QCoreApplication::translate("MainWindow", "sqrt", nullptr));
    pushButton_8->setText(
        QCoreApplication::translate("MainWindow", "8", nullptr));
    pushButton_dot->setText(
        QCoreApplication::translate("MainWindow", ".", nullptr));
    pushButton_graph->setText(QCoreApplication::translate(
        "MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272",
        nullptr));
    pushButton_4->setText(
        QCoreApplication::translate("MainWindow", "4", nullptr));
    pushButton_2->setText(
        QCoreApplication::translate("MainWindow", "2", nullptr));
    pushButton_9->setText(
        QCoreApplication::translate("MainWindow", "9", nullptr));
    pushButton_minus->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_tan->setText(
        QCoreApplication::translate("MainWindow", "tan", nullptr));
    pushButton_log->setText(
        QCoreApplication::translate("MainWindow", "log", nullptr));
    pushButton_cos->setText(
        QCoreApplication::translate("MainWindow", "cos", nullptr));
    pushButton_sin->setText(
        QCoreApplication::translate("MainWindow", "sin", nullptr));
    pushButton_equal->setText(
        QCoreApplication::translate("MainWindow", "=", nullptr));
    pushButton_right_bracket->setText(
        QCoreApplication::translate("MainWindow", ")", nullptr));
    pushButton_left_bracket->setText(
        QCoreApplication::translate("MainWindow", "(", nullptr));
    pushButton_multiplication->setText(
        QCoreApplication::translate("MainWindow", "*", nullptr));
    result->setText(QString());
    x_value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_2->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 x",
        nullptr));
    label_3->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 y",
        nullptr));
    min_x->setText(QCoreApplication::translate("MainWindow", "-100", nullptr));
    max_x->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
    min_y->setText(QCoreApplication::translate("MainWindow", "-100", nullptr));
    max_y->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
    ToCreditCalc->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320"
        "\271 "
        "\320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321"
        "\202\320\276\321\200",
        nullptr));
    ToDepositCalc->setText(QCoreApplication::translate(
        "MainWindow",
        "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321"
        "\213\320\271 "
        "\320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321"
        "\202\320\276\321\200",
        nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H

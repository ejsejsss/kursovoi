// bmiwidget.h
#ifndef BMIWIDGET_H
#define BMIWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QTextStream>

class BMIWidget : public QWidget
{
    Q_OBJECT

public:
    BMIWidget(QWidget *parent = nullptr);

private slots:
    void calculateBMI();
    void saveReport();

private:

    QLineEdit *heightEdit;
    QLineEdit *weightEdit;
    QLabel *resultLabel;
};

#endif // BMIWIDGET_H

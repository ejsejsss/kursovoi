// bmiwidget.cpp
#include "bmiwidget.h"
#include <QVBoxLayout>

BMIWidget::BMIWidget(QWidget *parent)
    : QWidget(parent)
{
    heightEdit = new QLineEdit(this);
    heightEdit->setPlaceholderText("Введите рост (в метрах)");

    weightEdit = new QLineEdit(this);
    weightEdit->setPlaceholderText("Введите вес (в килограммах)");

    QPushButton *calculateButton = new QPushButton("Рассчитать", this);
    connect(calculateButton, &QPushButton::clicked, this, &BMIWidget::calculateBMI);

    QPushButton *saveButton = new QPushButton("Сохранить отчет", this);
    connect(saveButton, &QPushButton::clicked, this, &BMIWidget::saveReport);

    resultLabel = new QLabel("Результат расчета: ", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(heightEdit);
    layout->addWidget(weightEdit);
    layout->addWidget(calculateButton);
    layout->addWidget(saveButton);
    layout->addWidget(resultLabel);
}

void BMIWidget::calculateBMI()
{
    QString heightStr = heightEdit->text();
    QString weightStr = weightEdit->text();

    bool ok;
    float height = heightStr.toFloat(&ok);
    if (!ok || height <= 0.0)
    {
        resultLabel->setText("Некорректный ввод роста");
        resultLabel->setStyleSheet("color: red;");
        return;
    }

    float weight = weightStr.toFloat(&ok);
    if (!ok || weight <= 0.0)
    {
        resultLabel->setText("Некорректный ввод веса");
        resultLabel->setStyleSheet("color: red;");
        return;
    }

    float bmi = weight / (height * height);

    QString status;
    QString color;
    if (bmi < 18.5){
        status = "Недостаточная масса тела";
        color = "blue";}
    else if (bmi < 24.9){
        status = "Норма";
        color = "green";}
    else if (bmi < 29.9){
        status = "Избыточная масса тела (предожирение)";
        color = "yellow";}
    else if (bmi < 34.9){
        status = "Ожирение I степени";
        color = "orange";}
    else if (bmi < 39.9){
        status = "Ожирение II степени";
        color = "red";}
    else{
        status = "Ожирение III степени";
        color = "darkred";}

    resultLabel->setText(QString("Индекс массы тела: %1%").arg(bmi).arg(status));
    resultLabel->setStyleSheet(QString("QLabel { color: %1; }").arg(color));

}

void BMIWidget::saveReport()
{
    QString filename = "bmi_report.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << resultLabel->text();
        file.close();
        resultLabel->setText(resultLabel->text() + "\nОтчет сохранен в файл: " + filename);
    }
    else
    {
        resultLabel->setText("Ошибка при сохранении отчета");
        resultLabel->setStyleSheet("color: red;");
    }
}

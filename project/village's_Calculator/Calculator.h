#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
class Widget : public QWidget
{
    Q_OBJECT
public slots:
    //按键捕捉
    void num_pushed(){
        QPushButton *digit = static_cast<QPushButton *>(sender());
        qDebug() << digit->text();
        QString data = le->text();
        le->setText(data + digit->text());
    }
    //操作捕捉
    void ope_pushed(){
        QPushButton * op = static_cast<QPushButton *>(sender());
        qDebug() << op->text();
        Operate = op->text();
        QString data = le->text();
        data1 = data.toDouble();
        le->setText(data+op->text());
    }
    // 小数点
    void dot(){
        QPushButton *dots = static_cast<QPushButton *>(sender());
        qDebug() <<dots->text();
        QString data = le->text();
        le->setText(data+dots->text());
    }
    //等号
    void cal(){
        QPushButton *den = static_cast<QPushButton *>(sender());
        qDebug() << den->text();
        QString  data = le->text();
        int start,length;
        for(int k1 = 0;k1<data.length();k1++){
            if (data[k1] != '.' && !isdigit(data[k1].toLatin1())){
                start = k1;break;
            }
        }
        length = data.length()-1;
        QString result = data.mid(start,length);
        data2 = result.toDouble();
        double sum;
        switch (Operate.toStdString().c_str()[0]){
            case '+': sum = data1 + data2; break;
            case '-': sum = data1 - data2; break;
            case '/': sum = data1 / data2; break;
            case '*': sum = data1 * data2; break;
        }
        le->clear();
        le->setText(QString::number(sum));
    }
    //退位
    void tuiwei(){
        QPushButton *den = static_cast<QPushButton *>(sender());
        qDebug() << den->text();
        QString  data = le->text();
        data.chop(1);
        le->setText(data);
    }
    // 清除
    void Clear(){
        QPushButton *C = static_cast<QPushButton *>(sender());
        qDebug() << C->text();
        le->clear();
    }
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *numbt[10];
    QPushButton *addbt,*subbt,*mulbt,*debt,*dotbt,*calbt,*delbt,*clearbt;
    QLineEdit *le;
    QString Operate;
    double data1,data2;
};

#endif // WIDGET_H
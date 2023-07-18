#include "Calculator.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 控件部分
    le = new QLineEdit;
    le->setAlignment(Qt::AlignRight);
    delbt = new QPushButton("<");
    addbt = new QPushButton("+");
    subbt = new QPushButton("-");
    mulbt = new QPushButton("*");
    debt = new QPushButton("/");
    dotbt = new QPushButton(".");
    calbt = new QPushButton("=");
    calbt->setMinimumHeight(63);
    clearbt = new QPushButton("C");
    for(int k1 = 0;k1<10;k1++){
        numbt[k1] = new QPushButton(QString::number(k1));
    }
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(le);
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(numbt[7],0,0,1,1);
    grid->addWidget(numbt[8],0,1,1,1);
    grid->addWidget(numbt[9],0,2,1,1);
    grid->addWidget(debt,0,3,1,1);
    grid->addWidget(clearbt,0,4,1,1);
    grid->addWidget(numbt[4],1,0,1,1);
    grid->addWidget(numbt[5],1,1,1,1);
    grid->addWidget(numbt[6],1,2,1,1);
    grid->addWidget(mulbt,1,3,1,1);
    grid->addWidget(delbt,1,4,1,1);
    grid->addWidget(numbt[1],2,0,1,1);
    grid->addWidget(numbt[2],2,1,1,1);
    grid->addWidget(numbt[3],2,2,1,1);
    grid->addWidget(subbt,2,3,1,1);
    grid->addWidget(calbt,2,4,2,1);
    grid->addWidget(numbt[0],3,0,1,1);
    grid->addWidget(dotbt,3,1,1,2);
    grid->addWidget(addbt,3,3,1,1);
    QVBoxLayout *mainbox = new QVBoxLayout;
    mainbox->addLayout(hbox);
    mainbox->addLayout(grid);
    setLayout(mainbox);
    connect(delbt, SIGNAL(clicked(bool)), this, SLOT(tuiwei()));
    for(int k1 = 0;k1<10;k1++){
        connect(numbt[k1],SIGNAL(clicked(bool)),this,SLOT(num_pushed()));
    }
    connect(addbt,SIGNAL(clicked(bool)),this,SLOT(ope_pushed()));
    connect(subbt,SIGNAL(clicked(bool)),this,SLOT(ope_pushed()));
    connect(mulbt,SIGNAL(clicked(bool)),this,SLOT(ope_pushed()));
    connect(debt,SIGNAL(clicked(bool)),this,SLOT(ope_pushed()));
    connect(dotbt,SIGNAL(clicked(bool)),this,SLOT(dot()));
    connect(calbt,SIGNAL(clicked(bool)),this,SLOT(cal()));
    connect(clearbt,SIGNAL(clicked(bool)),this,SLOT(Clear()));

}

Widget::~Widget()
{

}

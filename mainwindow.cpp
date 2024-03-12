#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interpritator.cpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //<Ввод символов с виртуальных клавиш>
    connect(ui->num1, SIGNAL(clicked()), this, SLOT(input_1()));
    connect(ui->num2, SIGNAL(clicked()), this, SLOT(input_2()));
    connect(ui->num3, SIGNAL(clicked()), this, SLOT(input_3()));
    connect(ui->num4, SIGNAL(clicked()), this, SLOT(input_4()));
    connect(ui->num5, SIGNAL(clicked()), this, SLOT(input_5()));
    connect(ui->num6, SIGNAL(clicked()), this, SLOT(input_6()));
    connect(ui->num7, SIGNAL(clicked()), this, SLOT(input_7()));
    connect(ui->num8, SIGNAL(clicked()), this, SLOT(input_8()));
    connect(ui->num9, SIGNAL(clicked()), this, SLOT(input_9()));
    connect(ui->num0, SIGNAL(clicked()), this, SLOT(input_0()));
    connect(ui->butplus, SIGNAL(clicked()), this, SLOT(input_plus()));
    connect(ui->butmin, SIGNAL(clicked()), this, SLOT(input_minus()));
    connect(ui->butumnoj, SIGNAL(clicked()), this, SLOT(input_umnojenie()));
    connect(ui->butdelit, SIGNAL(clicked()), this, SLOT(input_delenie()));
    connect(ui->butlscob, SIGNAL(clicked()), this, SLOT(input_lscob()));
    connect(ui->butrscob, SIGNAL(clicked()), this, SLOT(input_rscob()));
    connect(ui->buttochka, SIGNAL(clicked()), this, SLOT(input_tochka()));
    connect(ui->step, SIGNAL(clicked()), this, SLOT(input_stepen()));
    connect(ui->kor, SIGNAL(clicked()), this, SLOT(input_koren()));

    connect(ui->butravno, SIGNAL(clicked()), this, SLOT(ravno()));
    connect(ui->butback, SIGNAL(clicked()), this, SLOT(back()));
    connect(ui->butclear, SIGNAL(clicked()), this, SLOT(clear()));
    //</Ввод символов с виртуальных клавиш>

    ui->num1->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num2->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num3->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num4->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num5->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num6->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num7->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num8->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num9->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->num0->setStyleSheet("background-color: rgb(0, 255, 255);");
    ui->butplus->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->butmin->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->butumnoj->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->butdelit->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->butlscob->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->butrscob->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->buttochka->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->step->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->kor->setStyleSheet("background-color: rgb(255, 255, 0);");
    ui->butravno->setStyleSheet("background-color: rgb(0, 255, 0);");
    ui->butback->setStyleSheet("background-color: rgb(255, 100, 100);");
    ui->butclear->setStyleSheet("background-color: rgb(255, 100, 100);");

    TEReg = new QRegularExpression( "([0-9]|\\)|\\(|\\.|\\*|\\/|\\+|\\-|v|\\^){0,}"); // регулярное выражение 0-9 ( ) . * / + -
    RegVal = new QRegularExpressionValidator(*TEReg);
    ui->lineEdit->setValidator(RegVal);
}



MainWindow::~MainWindow()
{
    delete ui;
}

//<Ввод символов с виртуальных клавиш> Слоты ввода
void MainWindow::input_1()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"1"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_2()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"2"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_3()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"3"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_4()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"4"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_5()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"5"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_6()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"6"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_7()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"7"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_8()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"8"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_9()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"9"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_0()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"0"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_lscob()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"("));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_rscob()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,")"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_plus()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"+"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_minus()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"-"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_umnojenie()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"*"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_delenie()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"/"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}
void MainWindow::input_tochka()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"."));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}

void MainWindow::input_stepen()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"^"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}

void MainWindow::input_koren()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.insert(pos,"v"));
    ui->lineEdit->setCursorPosition(pos+1);
    emit ui->lineEdit->setFocus();
}

void MainWindow::ravno()
{
    text = ui->lineEdit->text();
    ui->textEdit->append("-----------------------------");
    ui->textEdit->append(interprit(text));
    }
void MainWindow::back()
{
    text = ui->lineEdit->text();
    pos = ui->lineEdit->cursorPosition();
    ui->lineEdit->setText(text.remove(ui->lineEdit->cursorPosition()-1, 1));
    ui->lineEdit->setCursorPosition(pos-1);
    if(pos>0) pos = pos - 2;
    emit ui->lineEdit->setFocus();

}
void MainWindow::clear()
{
    ui->lineEdit->setText("");
}
//</Ввод символов с виртуальных клавиш>


//<Обработчик событий>
bool MainWindow::event(QEvent * event_p)
{
 //<Масштабирование элементов интерфейск относительно размера окна>
    if(QEvent::Resize == event_p->type()){

        emit ui->lineEdit->setFocus();

        wi   =   this->geometry().width();  // длинна строки ввода
        he   =   this->geometry().height()/13; // высота строки ввода
        ui->lineEdit->resize(wi, he);

        fontsize(ui->lineEdit); // размер шрифта
        vert = ui->lineEdit->geometry().height()+ui->lineEdit->geometry().y();


        wi   =   this->geometry().width();   // длинна текстового поля
        he   =   this->geometry().height()/2.85;  // высота текстового поля
        vert = ui->lineEdit->geometry().height()+ui->lineEdit->geometry().y()+1;  //сдвиг по вертикали
        horis  = 0; // сдвиг по горизонтали
        ui->textEdit->resize(wi, he);
        ui->textEdit->move(horis ,vert);




         vert = he + vert;                        //сдвиг по вертикали
         he    = this->geometry().height()/8.7;     //высота кнопок
         wi    = (wi)/5;                          //длинна кнопок
         //   horis  = 10;                        // сдвиг по горизонтали


         //кнопка             3 место     0 ряд
        ui->butback->resize   (wi*4,      he         ); // двойная кнопка
        ui->butback->move     (horis+wi,  vert       );
        fontsize(ui->butback);

        //кнопка              0 место     0 ряд
        ui->butclear->resize  (wi,        he         );
        ui->butclear->move    (horis,     vert       );
        fontsize(ui->butclear);

         //кнопка              0 место     1 ряд
        ui->num7->resize      (wi,        he         );
        ui->num7->move        (horis,     vert+he    );
        fontsize(ui->num7);

        //кнопка              1 место     1 ряд
        ui->num8->resize      (wi,        he         );
        ui->num8->move        (horis+wi,  vert+he    );
        fontsize(ui->num8);

        //кнопка              2 место     1 ряд
        ui->num9->resize      (wi,        he         );
        ui->num9->move        (horis+wi*2,vert+he    );
        fontsize(ui->num9);

         //кнопка             3 место     1 ряд
        ui->step->resize      (wi,        he         );
        ui->step->move        (horis+wi*3,vert+he    );
        fontsize(ui->step);

        //кнопка              4 место     1 ряд
        ui->kor->resize       (wi,        he         );
        ui->kor->move         (horis+wi*4,vert+he    );
        fontsize(ui->kor);

        //кнопка              0 место     2 ряд
        ui->num4->resize      (wi,        he         );
        ui->num4->move        (horis,     vert+he*2  );
        fontsize(ui->num4);

        //кнопка              1 место     2 ряд
        ui->num5->resize      (wi,        he         );
        ui->num5->move        (horis+wi,  vert+he*2  );
        fontsize(ui->num5);

        //кнопка              2 место     2 ряд
        ui->num6->resize      (wi,        he         );
        ui->num6->move        (horis+wi*2,vert+he*2  );
        fontsize(ui->num6);

        //кнопка              3 место     2 ряд
        ui->butumnoj->resize  (wi,        he         );
        ui->butumnoj->move    (horis+wi*3,vert+he*2  );
        fontsize(ui->butumnoj);

        //кнопка              4 место     2 ряд
        ui->butdelit->resize  (wi,        he         );
        ui->butdelit->move    (horis+wi*4,vert+he*2  );
        fontsize(ui->butdelit);

        //кнопка              0 место     3 ряд
        ui->num1->resize      (wi,        he         );
        ui->num1->move        (horis,     vert+he*3  );
        fontsize(ui->num1);

        //кнопка              1 место     3 ряд
        ui->num2->resize      (wi,        he         );
        ui->num2->move        (horis+wi,  vert+he*3  );
        fontsize(ui->num2);

        //кнопка              2 место     3 ряд
        ui->num3->resize      (wi,        he         );
        ui->num3->move        (horis+wi*2,vert+he*3  );
        fontsize(ui->num3);

        //кнопка              3 место     3 ряд
        ui->butplus->resize   (wi,        he         );
        ui->butplus->move     (horis+wi*3,vert+he*3  );
        fontsize(ui->butplus);

        //кнопка              4 место     3 ряд
        ui->butmin->resize    (wi,        he         );
        ui->butmin->move      (horis+wi*4,vert+he*3  );
        fontsize(ui->butmin);

        //кнопка              0 место     4 ряд
        ui->butlscob->resize  (wi,        he         );
        ui->butlscob->move    (horis,     vert+he*4  );
        fontsize(ui->butlscob);

        //кнопка              1 место     4 ряд
        ui->num0->resize      (wi,        he         );
        ui->num0->move        (horis+wi,  vert+he*4  );
        fontsize(ui->num0);

        //кнопка              2 место     4 ряд
        ui->butrscob->resize  (wi,        he         );
        ui->butrscob->move    (horis+wi*2,vert+he*4  );
        fontsize(ui->butrscob);

        //кнопка              3 место     4 ряд
        ui->buttochka->resize (wi,        he         );
        ui->buttochka->move   (horis+wi*3,vert+he*4  );
        fontsize(ui->buttochka);

        //кнопка              4 место     4 ряд
        ui->butravno->resize  (wi,        he         );
        ui->butravno->move    (horis+wi*4,vert+he*4  );
        fontsize(ui->butravno);


    } //</Масштабирование элементов интерфейск относительно размера окна>
    return QMainWindow::event(event_p);
}
//</Обработчик событий>

void MainWindow::fontsize(QWidget* obj) // функция изменения размеров шрифта
{
    obj->font();                    // Изменение
    fon.setPixelSize(he/1.5);       //       размера
    obj->setFont(fon);              //           шрифта
};


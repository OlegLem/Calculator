#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool event(QEvent * event_p) override; //обработчик событий


private:
    Ui::MainWindow *ui;
    QString text;    //Текст в поле ввода
    QString curstext; //Текст сдвига курсора
    int wi,    // длинна
        he,    // высота
        vert,  // сдвиг по вертикали
        horis, // сдвиг по горизонтали
        pos; // номер позиции редактирования textedit
        QRegularExpression *TEReg; // регулярное выражение ограничивающее ввод букв и т.п.
        QValidator *RegVal;        // валидатор ограничитель ввода
    QFont fon; // шрифт
    void fontsize(QWidget*); // функция изменения размеров шрифта
public slots:
    //Слоты ввода
    void input_1();
    void input_2();
    void input_3();
    void input_4();
    void input_5();
    void input_6();
    void input_7();
    void input_8();
    void input_9();
    void input_0();
    void input_lscob();
    void input_rscob();
    void input_plus();
    void input_minus();
    void input_umnojenie();
    void input_tochka();
    void input_delenie();

    void ravno();
    void back();
    void clear();



};
#endif // MAINWINDOW_H

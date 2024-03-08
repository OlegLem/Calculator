#include <QApplication>
#include <QRegularExpression>
#include <string>
#include <iostream>
#include <sstream>

//test-222

QString interprit(QString str);

class Interpritator {
public:
    Interpritator(QString &str);
    ~Interpritator();
    QString *OutStr;
    const char *str1;
    QByteArray ba;
    char *a_str;
    char *b_str;
    char *c_str;
    char *scobL;
    char *scobR;

    char *str2;
    char *strprefix;
    char *strpostfix;
    char *strprefix_c;
    char *strpostfix_c;
    char *pref;
    char *postf;
    int sch;


    qreal  n1, n2;      // используется числовой тип данный подлиннее с точкой от Qt


    int Scob();
    int Arifm();
    void SimplArifm(int &size);
    void ArifmStrUpdate(bool vivod);

    QRegularExpression *rx;
    QRegularExpression *nu;
    QRegularExpression *nu_and_scob_l;
    QRegularExpression *nu_and_scob_r;
    QRegularExpression *zn;
    QRegularExpression *zn_and_scob_l;
    QRegularExpression *zn_and_scob_r;
    QRegularExpression *tchk;
    QRegularExpression *minus;
    QRegularExpression *zn_bez_minusa;
    QRegularExpression *zn_bez_minusa_i_tochki;
    QString a;
    QString b;
};

Interpritator::Interpritator(QString &str){
    OutStr = &str;
    ba = str.toLocal8Bit();
    Scob();                          // при создании объекта данного класса из конструктора сразу же начинается вычиление
}

Interpritator::~Interpritator(){
  /*     delete[] a_str;         // убераем за собой
       delete[] b_str;
       delete[] c_str;

       delete rx;
       delete nu;
       delete zn;
       delete[] pref;
       delete[] postf;
       delete[] str2;
       delete[] strprefix;
       delete[] strpostfix;
       delete[] strprefix_c;
       delete[] strpostfix_c;
       delete[] zn_and_scob_l;
       delete[] zn_and_scob_r;
       delete[] nu_and_scob_r;
       delete[] nu_and_scob_l;
       delete[] tchk;
       delete[] minus;
       delete[] zn_bez_minusa;*/
}


int Interpritator::Scob() {                              // основное тело данного интерпритатора

    str1 = new const char();
    str1 = ba.data();
    int len = strlen(str1) * 2;
    a_str = new char[len];
    b_str = new char[len];
    c_str = new char[len];
    rx = new QRegularExpression( "[0-9]|\\.");            // регулярное выражение 0-9 и .
    nu = new QRegularExpression( "[0-9]");                // регулярное выражение 0-9
    nu_and_scob_l = new QRegularExpression( "[0-9]|\\(|\\-");     // регулярное выражение 0-9 ( -
    nu_and_scob_r = new QRegularExpression( "[0-9]|\\)");     // регулярное выражение 0-9
    zn = new QRegularExpression( "\\+|\\-|\\*|\\/|\\.");      // регулярное выражение + - * / .
    zn_and_scob_l = new QRegularExpression( "\\+|\\-|\\*|\\/|\\(");      // регулярное выражение + - * / (
    zn_and_scob_r = new QRegularExpression( "\\+|\\-|\\*|\\/|\\)");      // регулярное выражение + - * / )
    tchk = new QRegularExpression( "\\."); // .
    minus = new QRegularExpression( "\\-"); // -
    zn_bez_minusa = new QRegularExpression( "\\+|\\*|\\/|\\.");      // регулярное выражение + * / .
    zn_bez_minusa_i_tochki = new QRegularExpression( "\\+|\\*|\\/");      // регулярное выражение + * /

    for(int x=0; str1[x] != '\0'; x++ ){         // перевод из const char в char
      a_str[x] = str1[x];
      a_str[x+1] = '\0';
    }

    sch=0;
    for(int x=0; a_str[x] != '\0'; x++ ){        // проверка на правильное соотношение открывающих и закрывающих скобок
        if(a_str[x] == '(')
            sch++;
        if(a_str[x] == ')')
            sch--;
        if (sch < 0){
            *OutStr = "Не хватает открывающей скобки.";
            return 0;
        }
    }
    if (sch > 0){
        *OutStr = "Нехватает закрывающей скобки.";
        return 0;
        }

    for(int x=1; a_str[x] != '\0'; x++ ){        // проверка на знаки, раставленные подряд
        a = a_str[x-1];
        b = a_str[x];
        if(zn->match(a).hasMatch() && zn->match(b).hasMatch()){
             if (!(zn_bez_minusa_i_tochki->match(a).hasMatch() && minus->match(b).hasMatch())){

                 c_str[0] = a_str[x-1];
                 c_str[1] = a_str[x];
                 c_str[2] = '\0';
                 *OutStr = "Что это?: ";
                 *OutStr = *OutStr + c_str;
                 return 0;
          }
    }
    }

    for(int x=0; a_str[x] != '\0'; x++ ){        // проверка на некорректную расстановку скобок относительно знаков, чисел и друг друга
        if(a_str[x] == '('){
            if(x>0 && a_str[x+1]!='\0'){
               a = a_str[x-1];
               if(!zn_and_scob_l->match(a).hasMatch()){
                   c_str[0] = a_str[x-1];
                   c_str[1] = a_str[x];
                   c_str[2] = '\0';
                   *OutStr = "Что это?: ";
                   *OutStr = *OutStr + c_str;
                   return 0;
               }
               a = a_str[x+1];
               if(!nu_and_scob_l->match(a).hasMatch()){
                   c_str[0] = a_str[x];
                   c_str[1] = a_str[x+1];
                   c_str[2] = '\0';
                   *OutStr = "Что это?: ";
                   *OutStr = *OutStr + c_str;
                   return 0;
               }
            }
        }
        if(a_str[x] == ')'){
            if(x>0 && a_str[x+1]!='\0'){
               a = a_str[x-1];
               if(!nu_and_scob_r->match(a).hasMatch()){
                   c_str[0] = a_str[x-1];
                   c_str[1] = a_str[x];
                   c_str[2] = '\0';
                   *OutStr = "Что это?: ";
                   *OutStr = *OutStr + c_str;
                   return 0;
               }
               a = a_str[x+1];
               if(!zn_and_scob_r->match(a).hasMatch()){
                   c_str[0] = a_str[x];
                   c_str[1] = a_str[x+1];
                   c_str[2] = '\0';
                   *OutStr = "Что это?: ";
                   *OutStr = *OutStr + c_str;
                   return 0;
               }
            }
        }

    }
    a = a_str[strlen(a_str)-1];                           // если вдруг кто то начал или закончил ввод выражения знаком
    if(zn->match(a).hasMatch()){
        *OutStr = "Выражение не должно заканчиваться знаком";
        return 0;
    }
    a = a_str[0];
    if(zn_bez_minusa->match(a).hasMatch()){
        *OutStr = "Выражение не должно начинаться со знака";
        return 0;
    }

    for(int x=1; a_str[x] != '\0'; x++ ){        // проверка на недописанную десятичную дробь
        a = a_str[x];
        if(tchk->match(a).hasMatch()){
            a = a_str[x-1];
            b = a_str[x+1];
            if (!nu->match(a).hasMatch()||!nu->match(b).hasMatch()){
                   c_str[0] = a_str[x-1];
                   c_str[1] = a_str[x];
                   c_str[2] = a_str[x+1];
                   c_str[3] = '\0';
                   *OutStr = "Что это?: ";
                   *OutStr = *OutStr + c_str;
                   return 0;
            }
        }
    }




    int z = 0;                         // всё это нужно
    char s[2];
    s[0] = '(';
    s[1] = '\0';
    pref = new char[len];
    postf = new char[len];
    str2 = new char[len];
    strprefix = new char[len];
    strpostfix = new char[len];
    strprefix_c = new char[len];
    strpostfix_c = new char[len];
    strprefix[0] = '\0';
    strpostfix[0] = '\0';
    strprefix_c[0] = '\0';
    strpostfix_c[0] = '\0';
    postf[0] = '\0';
    pref[0] = '\0';

    for(int x=0, y=0; a_str[x-1] != '\0'; x++, y++ ){   // вычисление выражений в скобках (таким образом достигается запись выражения без скобок)
        b_str[y] = a_str[x];
        if(a_str[x] == '('){            
            b_str[y] = '\0';
            if(z)
               strcat(pref, s);
            z++;                 //счётчик открытых скобок
            strcat(pref, b_str);   //сохраняем всё что до скобок
            y = -1;
        }
        if(a_str[x] == ')'){
            b_str[y] = '\0';
            strcpy(postf, a_str+x+1); //сохраняем всё что после скобок
            while(Arifm());    // вычесляем выражение в скобках записанное в b_str, восстанавливаем первоначальный вид выражения с учётом уже решённой части. Если данное выражение некорректно, выполнение функции завершиться.
            pref[0] = '\0';
            postf[0] = '\0';
            x=-1;                    // начинаем заново проверять скобки
            y=-1;
            z=0;
            strcpy(a_str, c_str);
        }
    }
    while(Arifm());    // если скобок не осталось или их и не было

 return 0;
}

int Interpritator::Arifm(){                                // собственно вычисление
    n1 = 0; n2 = 0;

    for(int size = 1; size<strlen(b_str);  size++) {       // сначала * и /
        switch(b_str[size]) {
        case '*': {
             SimplArifm(size);   // выполняем интерпритацию из строки в готовый для вычилсления значения
             n1 *= n2;
             ArifmStrUpdate(1);   // выполняем составление вывода с учётом уже решённого
             size = 1;
             return 1;
             }
        case '/': {
            SimplArifm(size);
            n1 /= n2;
            ArifmStrUpdate(1);
            size = 1;
            return 1;
            }
         }
      }
    for(int size = 1; size<strlen(b_str);  size++) {       // потом + и -
        switch(b_str[size]) {
        case '+': {
             SimplArifm(size);
             n1 += n2;
             ArifmStrUpdate(1);
             size = 1;
             return 1;
             }
        case '-': {
            SimplArifm(size);
            n1 += n2;  // отрицательный знак учитывается в функции SimplArifm()
            ArifmStrUpdate(1);
             size = 1;
             return 1;
            }
       }
     }
    n1 = atof(b_str);
    ArifmStrUpdate(0);
    strcpy(b_str, c_str);
    return 0;
  }






void Interpritator::SimplArifm(int &size){    // интерпритация значений для вычиления
    size--;            // size указывает на математический оператор в строке
    a = b_str[size];
    int kolnum = 0;
    for(kolnum = size; rx->match(a).hasMatch(); kolnum--){   // используя регулярное выражение, безошибочно определяем значение перед оператором
        a = b_str[kolnum];
        if(rx->match(a).hasMatch() && kolnum >= 0){
            n1 = atof(&b_str[kolnum]);             //переводим значение во float
            a = b_str[kolnum-1];
            if(minus->match(a).hasMatch()){
                n1 *= -1;
            }
        }
     }

    if(n1>=0) {
        strprefix[kolnum+1] = '\0';            // сохраняем на потом всё что записано до интересуемого выражения
        for(int pref=kolnum; pref>-1; pref--)
        {
        strprefix[pref] = b_str[pref];
        }
    }
    else{
        strprefix[kolnum] = '\0';            // сохраняем на потом всё что записано до интересуемого выражения
        for(int pref=kolnum-1; pref>-1; pref--)
        {
        strprefix[pref] = b_str[pref];
        }
    }



    a = b_str[size+1];
    while(!rx->match(a).hasMatch()){       // определяем и переводим во float значение после оператора
        size++;
        a = b_str[size];

    }
    n2 = atof(&b_str[size]);

    a = b_str[size-1];
    if(minus->match(a).hasMatch()){
        n2 *= -1;
        size++;
    }


    a = b_str[size];
    while(rx->match(a).hasMatch()){       // сохраняем на потом всё что записано после интересуемого выражения
        size++;
        a = b_str[size];
    }

    strcpy(strpostfix, &b_str[size]);


    if(!(strpostfix[0] == '\0' && strprefix[0] == '\0')){   // если вдруг выражение в скобках, полученное из функции Scob(), состоит из нескольких математических операций, то необходимо при подстановке в итоговое упрощённое выражение, заключить его в скобки
        if(!( pref[0] == '\0' && postf[0] == '\0')){
          c_str[1] = '\0';
          c_str[0] = '(';
          strcat(c_str, strprefix);
          strcpy(strprefix_c, c_str);
          c_str[0] = ')';
          c_str[1] = '\0';
          strcpy(strpostfix_c, strpostfix);
          strcat(strpostfix_c, c_str);
        }
        else {                                    // но если получилась одно значение без операторов, то в скобки заключать не надо естественно
          strcpy(strprefix_c, strprefix);
          strcpy(strpostfix_c, strpostfix);
        }
    }
    else {
      strcpy(strprefix_c, strprefix);
      strcpy(strpostfix_c, strpostfix);
    }

}








void Interpritator::ArifmStrUpdate(bool vivod){    // перобразование исхдного выражение в упрощённое на одну операцию

    if (n1<0)                              // минус на минус даёт плюс
    {
        int h;
        for(h=0; pref[h] != '\0'; h++ );
        a = pref[h-1];

       if (minus->match(a).hasMatch()){
         n1 *= -1;
         if(h>1){
            a = pref[h-2];
            if(zn->match(a).hasMatch()){
               pref[h-1] = '\0';
               }
            else{
               pref[h-1] = '+';
               }
            }
           }

       }


    std::stringstream buffer;
    buffer << n1;                       //переводим float в строку


    for(int x=0; buffer.str().c_str()[x] != '\0'; x++ ){
      str2[x] = buffer.str().c_str()[x];
      str2[x+1] = '\0';
    }



    strcpy(b_str, strprefix);    // лепим строку для дальнейшего вычисления в функции Arifm()
    strcat(b_str, str2);
    strcat(b_str, strpostfix);


    strcpy(c_str, pref);         // лепим строку для вывода в окошко
    strcat(c_str, strprefix_c);
    strcat(c_str, str2);
    strcat(c_str, strpostfix_c);
    strcat(c_str, postf);

    strprefix[0] = '\0';
    strpostfix[0] = '\0';
    strprefix_c[0] = '\0';
    strpostfix_c[0] = '\0';

    if (vivod) *OutStr = *OutStr + " = \n" + c_str;  // добавляем к потенциальному выводу новую строку с упрощённым на одну операцию выражением
}                                                    // и так пока не останется одно значение

QString interprit(QString str){
  Interpritator a(str);          // фунция создания оъекта класса
  return str;
}

#ifndef PARTENARIAT_H
#define PARTENARIAT_H
#include"partenaire.h"
#include <QDialog>


namespace Ui {
class partenariat;
}

class partenariat : public QDialog
{
    Q_OBJECT

public:
    explicit partenariat(QWidget *parent = nullptr);
    ~partenariat();

private slots:
    void on_pushButton_ajouter_clicked();


     void on_tabWidget_currentChanged(int index);

     void on_pushButton_supp_2_clicked();

     void on_pushButton_modifier_2_clicked();

private:
    Ui::partenariat *ui;
    partenaire tmppartenaire ;
};

#endif // PARTENARIAT_H

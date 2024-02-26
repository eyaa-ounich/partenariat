#include "partenariat.h"
#include "ui_partenariat.h"
#include "partenaire.h"
#include"QMessageBox"
#include"QDate"

partenariat::partenariat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partenariat)
{
    ui->setupUi(this);
    ui->tableView_lister_2->setModel(tmppartenaire.afficher()) ;
}

partenariat::~partenariat()
{
    delete ui;
}

void partenariat::on_pushButton_ajouter_clicked()
{
    {
        // Retrieve data from UI elements
        int id = ui->lineEdit_ajouter_id->text().toInt();
        QString nom = ui->lineEdit_ajouter_nom->text();
        QString adresse = ui->lineEdit_ajouter_adresse->text();
        QString telephone = ui->lineEdit_ajouter_telephone->text();
        QString produit = ui->lineEdit_ajouter_produit->text();
        QString montant = ui->lineEdit_ajouter_montant->text();
        QDate datedebut = ui->dateEdit_ajouter_datedebut->date();
        QDate datefin = ui->dateEdit_ajouter_datefin->date();

        // Validate data before proceeding (optional)
        // For example, you may want to check if id, montant, or dates are valid

        // Create a partenaire object
        partenaire e(id, nom, adresse, telephone, produit, datedebut, datefin, montant);

        // Try to add the data to the database
        if (e.ajouter())
        {
            // If successful, show an information message
            QMessageBox::information(nullptr, QObject::tr("Ajout réussi"),
                                     QObject::tr("Les données ont été ajoutées avec succès."),
                                     QMessageBox::Cancel);
        }
        else
        {
            // If adding failed, show an error message
            QMessageBox::critical(nullptr, QObject::tr("Erreur lors de l'ajout"),
                                  QObject::tr("Impossible d'ajouter les données."),
                                  QMessageBox::Cancel);
        }
    }
}



/*void partenariat::on_tabWidget_currentChanged(int index)
{
      ui->tableView_lister->setModel(tmppartenaire.afficher()) ;
}*/


void partenariat::on_tabWidget_currentChanged(int index)
{
     ui->tableView_lister_2->setModel(tmppartenaire.afficher()) ;
}

void partenariat::on_pushButton_supp_2_clicked()
{
    int id =ui->lineEdit_sup_id_2->text().toUInt() ;
    bool test =tmppartenaire.supprimer(id) ;
    if (test)
    {
        ui->tableView_lister->setModel(tmppartenaire.afficher()) ;//refresh


        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                    QObject::tr("supprimer successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("matfasa5ch"),
                    QObject::tr("matfasa5ch.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void partenariat::on_pushButton_modifier_2_clicked()
{

        QString nom = ui->lineEdit_modifier_nom->text();
        QString adresse = ui->lineEdit_modifier_adresse->text();
        QString telephone = ui->lineEdit_modifier_telephone->text();
        QString produit = ui->lineEdit_modifier_produit->text();
        QString montant = ui->lineEdit_modifier_montant->text();


        QDate datedebut = ui->dateEdit_modifier_datedebut->date();
        QString date_naissance_str = datedebut.toString("yyyy-MM-dd");

        QDate datefin = ui->dateEdit_modifier_datefin->date();
        QString datefin2 = datefin.toString("yyyy-MM-dd");


        int id = ui->lineEdit_modifier_id_2->text().toUInt();

        // Display a confirmation dialog
           QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to modify?",
                                         QMessageBox::Yes|QMessageBox::No);
           if (reply == QMessageBox::Yes) {
               // User confirmed the modification, proceed with modification
               partenaire p;
               bool test = p.modifier(id, nom, adresse,  telephone, produit, montant, datedebut,datefin);

               if (test) {
                   QMessageBox::information(nullptr, QObject::tr("Modifier Success"),
                                            QObject::tr("Modification successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
               }
               else {
                   QMessageBox::critical(nullptr, QObject::tr("Error"),
                                         QObject::tr("Modification failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
               }
           }
           else {
               // User chose not to proceed with the modification
               QMessageBox::information(nullptr, QObject::tr("Modification Cancelled"),
                                        QObject::tr("Modification cancelled.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
           }

}


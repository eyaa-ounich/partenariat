#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>

class partenaire
{
public:
    partenaire();

   partenaire(int,QString,QString,QString,QString,QDate,QDate,QString);
    // les fonction get
    int get_id() ;
    QString get_nom() ;
    QString get_adresse() ;
    QString get_telephone() ;
    QString get_produit() ;
    QDate get_datedebut() ;
    QDate get_datefin() ;
    QString get_montant() ;
    //fonction crud
    bool ajouter() ;
     QSqlQueryModel * afficher() ;
     bool supprimer(int);
      bool modifier(int id, QString nom, QString adresse,QString telephone ,QString produit ,QString montant,QDate datedebut,QDate datefin);
private:
    QString  nom, adresse ,telephone, produit, montant ;
    QDate datedebut ,datefin ;
    int id  ;
};

#endif // PARTENAIRE_H

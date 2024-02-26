#include "partenaire.h"
#include <QDebug>
partenaire::partenaire()
{
    id=0 ;
    nom="" ;
    adresse="" ;
    telephone="";
    produit="";
    montant="";
    datedebut=QDate();
     datefin=QDate();
}
partenaire::partenaire(int id,QString nom,QString adresse,QString telephone, QString produit ,QDate datedebut,QDate datefin,QString montant)
{
  this->id  =id ;
  this->nom =nom ;
  this->adresse = adresse ;
     this->telephone = telephone ;
     this->produit = produit;
     this->montant = montant ;
     this->datedebut = datedebut ;
    this->datefin = datefin ;
}
QString partenaire::get_nom()
{
    return  nom ;
}
QString partenaire::get_adresse()
{
    return  adresse ;
}
QString partenaire::get_telephone()
{
    return  telephone ;
}
QString partenaire::get_produit()
{
    return  produit ;
}
QString partenaire::get_montant()
{
    return  montant ;
}
QDate partenaire:: get_datedebut()
{return  datedebut ; }
QDate   partenaire:: get_datefin()
{return  datefin ; }
bool partenaire::ajouter()
{
  QSqlQuery query ;

  query.prepare("INSERT INTO partenaire (id, nom, adresse,telephone, produit, datedebut, datefin, montant ) VALUES (:id, :nom, :adresse, :telephone, :produit, :datedebut, :datefin, :montant)");


  // lier des valeurs à des paramètres dans une requête SQL préparée.
  query.bindValue(":id", id);
  query.bindValue(":nom", nom);
  query.bindValue(":adresse", adresse);
  query.bindValue(":telephone",telephone);
  query.bindValue(":produit", produit);
  query.bindValue(":datedebut", datedebut);
  query.bindValue(":datefin", datefin);
  query.bindValue(":montant", montant);


  return query.exec() ;
}
QSqlQueryModel *partenaire::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Set the query to select data from the 'partenaire' table

    model->setQuery("select *from partenaire") ;

    // Set header data for each column
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("produit"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("datefin"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("montant"));

    return model;
}
bool partenaire::supprimer(int idd)
{
 QSqlQuery query ;
 QString res = QString::number(idd) ;

 query.prepare("Delete from partenaire where ID=:id") ;
 query.bindValue(":id",res) ;
 return query.exec() ;
}
bool partenaire:: modifier(int id, QString nom, QString adresse,QString telephone ,QString produit ,QString montant,QDate datedebut,QDate datefin)
 {


     QSqlQuery query;
     query.prepare("UPDATE partenaire SET nom = :nom, adresee = :adresse, telephone = :telephone, produit = :produit, montant = :montant, datedebut = :datedebut, datefin = :datefin WHERE id = :id");
     query.bindValue(":nom", nom);
     query.bindValue(":adresse", adresse);
     query.bindValue(":telephone", telephone);
     query.bindValue(":produit", produit);
     query.bindValue(":montant", montant);
     query.bindValue(":datedebut", datedebut);
     query.bindValue(":datefin", datefin);

     query.bindValue(":id", id);

     return query.exec();


 }

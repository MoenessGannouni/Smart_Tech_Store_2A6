#include "produit.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
produit::produit()
{
    nom="";
    id=0;
    prix=0;
    quantite=0;
    categorie="";
    datee="";
}
produit::produit( QString nom ,int id ,int prix,int quantite,QString categorie ,QString datee)
{
        this->nom=nom;
        this->id=id;
        this->prix=prix;
        this->quantite=quantite;
        this->categorie=categorie;
        this->datee=datee;
}

bool produit::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO produit (id,nom,prix,quantite,categorie,datee) VALUES (:id,:nom,:prix,:quantite,:categorie,:datee)");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);
    query.bindValue(":categorie",categorie);
    query.bindValue(":datee",datee);

    return query.exec();
}

QSqlQueryModel* produit::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM produit ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("catégorie"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("date"));

    return model;
}


bool produit::modifier(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Update produit set id = :id , nom = :nom , prix = :prix , quantite = :quantite , categorie = :categorie  where id = :id ");

query.bindValue(":id",id);
query.bindValue(":nom",nom);
query.bindValue(":prix",prix);
query.bindValue(":quantite",quantite);
query.bindValue(":categorie",categorie);



return    query.exec();
}

bool produit::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from produit where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}


QSqlQueryModel* produit::tri_prix()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM produit order by prix  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("date"));

    return model;
}


QSqlQueryModel* produit::tri_id()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM produit order by id  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("date"));

    return model;
}


QSqlQueryModel* produit::recherche_id(QString categorie )
{


    QSqlQueryModel * model= new QSqlQueryModel();
        QString qry="select * from produit where categorie like '%"+categorie+"%' ";
        qDebug()<<qry;
        model->setQuery(qry);
        return model;



}




QSqlQueryModel *produit::Product_type_pro_list()
{

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT categorie FROM produit");


        return model;


}





QGraphicsScene *produit::StatPromo_Product_type()
{


    //Calculer la récurcivité de chaque type de produit
   produit tmpproduit;
   QString test;

  int max=0;
  int informatique=0;
  int telephone=0;
  int electromenager=0;
  int gaming=0;



    QSqlQueryModel * model=tmpproduit.Product_type_pro_list();


    max=model->rowCount();

    for (int i=0;i<model->rowCount();i++)
    {
        test=model->record(i).value(0).toString();





        if(test=="informatique")
        {
            informatique++;
        }
        else if(test=="telephone")
        {
            telephone++;

        }
        else if(test=="electromenager")
        {
            electromenager++;

        }
        else if(test=="gaming")
        {
            gaming++;
        }


  }





//Génrer la Statistique sur La QGraphiqueView


    QGraphicsScene *  scene = new QGraphicsScene();

    QGraphicsEllipseItem *ellipse1;
    QGraphicsEllipseItem *ellipse2;
    QGraphicsEllipseItem *ellipse3;
    QGraphicsEllipseItem *ellipse4;





    QGraphicsTextItem *tex1;
    QGraphicsTextItem *tex2;
    QGraphicsTextItem *tex3;
    QGraphicsTextItem *tex4;


    QGraphicsRectItem *rec1;
    QGraphicsRectItem *rec2;
    QGraphicsRectItem *rec3;
    QGraphicsRectItem *rec4;




    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    QBrush yellowBrush(Qt::yellow);
    QBrush bleuBrush(Qt::blue);
    QBrush grayBrush(Qt::gray);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    int x=200;
    int y=100;
    int w=250;
    int h=250;


    ellipse1 = scene->addEllipse(x, y, w, h);
    ellipse1->setBrush(greenBrush);
    ellipse1->setStartAngle(((informatique*360)/max)*16);




    ellipse2 = scene->addEllipse(x, y, w, h);
    ellipse2->setBrush(redBrush);
    ellipse1->setStartAngle(((informatique*360)/max)*16);
    ellipse2->setSpanAngle(((telephone*360)/max)*16);


    ellipse3 = scene->addEllipse(x, y, w, h);
    ellipse3->setBrush(yellowBrush);
    ellipse3->setStartAngle((((informatique+telephone)*360)/max)*16);
    ellipse3->setSpanAngle(((electromenager*360)/max)*16);



    ellipse4 = scene->addEllipse(x, y, w, h);
    ellipse4->setBrush(grayBrush);
    ellipse4->setStartAngle((((informatique+telephone+electromenager)*360)/max)*16);
    ellipse4->setSpanAngle(((gaming*360)/max)*16);





    float informatique_pourcentage=((((informatique*360)/max))*100)/360;
    float telephone_pourcentage=((((telephone*360)/max))*100)/360;
    float electromenager_pourcentage=((((electromenager*360)/max))*100)/360;
    float gaming_pourcentage=((((gaming*360)/max))*100)/360;







    QString informatique_convert=QString::number( informatique_pourcentage);
    QString telephone_convert=QString::number(telephone_pourcentage);
    QString electromenager_convert=QString::number(electromenager_pourcentage);
    QString gaming_convert=QString::number(gaming_pourcentage);


    rec1 = scene->addRect(-20, 2, 20, 20, outlinePen, greenBrush);
    rec2 = scene->addRect(-20, 42, 20, 20, outlinePen, redBrush);
    rec3 = scene->addRect(-20, 80, 20, 20, outlinePen, yellowBrush);
    rec4 = scene->addRect(-20, 140, 20, 20, outlinePen, grayBrush);


    tex1 = scene->addText("informatique : "+informatique_convert+"%", QFont("Arial", 12));
    tex2 = scene->addText("\n\n telephone: "+telephone_convert+"%", QFont("Arial", 12) );
    tex3 = scene->addText("\n\n\n\n electromenager: "+electromenager_convert+"%", QFont("Arial", 12) );
    tex4 = scene->addText("\n\n\n\n\n\n gaming: "+gaming_convert+"%", QFont("Arial", 12) );



    return scene;


}

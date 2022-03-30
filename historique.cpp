#include "historique.h"

#include<QMessageBox>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString id,QString heureo,QString heuref)
{    QFile file ("C:/Users/21621/Desktop");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id+"\n"+heureo << "\n" +heuref << "\n";


}

QString Historique::load()
{   tmp="";
    QFile file("C:/Users/21621/Desktop");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         qDebug()<<"erreur";
      tmp="";

    QTextStream in(&file);

  while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }

   return tmp;
}


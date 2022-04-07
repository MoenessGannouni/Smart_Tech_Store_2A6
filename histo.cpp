#include "histo.h"

histo::histo()
{

}
void histo::save(QString cin,QString nom, QString prenom, QString adresse, QString adresse_mail)
{    QFile file ("C:/Users/MOEµNESS/Desktop/QT/Tache clients/tache_clients/historique.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
      out <<"\n" " Vous avez ajoutee : " "\n";
     out << cin+"\n"+nom << "\n"+prenom << "\n"+adresse << "\n"+adresse_mail << "\n" "-------------" "\n";
}
void histo::save1(QString,QString cin)
{    QFile file ("C:/Users/MOEµNESS/Desktop/QT/Tache clients/tache_clients/historique.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out <<"\n" " Vous avez supprimee : " "\n";
     out << cin+"\n" "\n" "---------" "\n";
}
void histo::save2(QString,QString cin,QString nom, QString prenom, QString adresse, QString adresse_mail)
{    QFile file ("C:/Users/MOEµNESS/Desktop/QT/Tache clients/tache_clients/historique.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out <<"\n" " Vous avez modifiee : " "\n";
     out << cin+"\n"+nom << "\n"+prenom << "\n"+adresse << "\n"+adresse_mail << "\n" "-------------" "\n";


}
QString histo::load()
{   tmp="";
    QFile file("C:/Users/MOEµNESS/Desktop/QT/Tache clients/tache_clients/historique.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}

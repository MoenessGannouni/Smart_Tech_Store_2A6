#ifndef HISTO_H
#define HISTO_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class histo
{
    QString tmp;
  public:
      histo();
      void save(QString,QString,QString,QString,QString);
      void save1(QString,QString);
      void save2(QString,QString,QString,QString,QString,QString);
      QString load();
};

#endif // HISTO_H

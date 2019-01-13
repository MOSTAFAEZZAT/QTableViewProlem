#ifndef DELGATE
#define DELGATE
#include <QtGui>
#include <QModelIndex>
#include <QObject>
#include <QSqlTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPushButton>
#include <QTableView>
class MyDelegate : public QWidget
{
    Q_OBJECT

public:
     MyDelegate(QObject *parent = 0);
    QSqlTableModel * model ;
    QTableView * view ;
    void qtable() ;

};

#endif // DELGATE

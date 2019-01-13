#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <QDialog>
#include <QSqlTableModel>
#include <QTableView>
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDriver>
#include <QAbstractItemView>
#include <QPushButton>
#include <iostream>
#include <QStandardItemModel>
#include "profile.h"
#include "showingdata.h"
#include "delgate.h"
  namespace Ui {
    class MainProcess;
}



   class MainProcess : public QDialog
{
    Q_OBJECT

public:
    explicit MainProcess(QWidget *parent = nullptr);
    MyDelegate del ;

    ~MainProcess() ;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_Search_clicked();


private:
    Ui::MainProcess *ui;
    Profile * profile ;
    QSqlTableModel * model  ;
    QTableView * view ;
};
        
    


#endif // MAINPROCESS_H

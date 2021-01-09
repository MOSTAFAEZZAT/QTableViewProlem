
#include "delgate.h"

MyDelegate::MyDelegate(QObject *parent)
 {



}
void MyDelegate:: qtable(){

    QSqlDatabase  Databasee =   QSqlDatabase::addDatabase("QMYSQL" , "thirdConnection");
    Databasee.setHostName("localhost") ;
    Databasee.setUserName("root");
    Databasee.setPassword("mostafa");
    Databasee.setDatabaseName("Clinic_Database");

// Pls Notice that 'QSqlTableModel' doesn't work without making sure that database connected

    if(Databasee.open()){
      QMessageBox::about(this,"res","databaseopen") ;


    }else {
        QMessageBox::about(this,"res","database not open") ;
        qDebug() <<  Databasee.lastError();
    }

   model = new QSqlTableModel(this,  Databasee);
   model->setTable("PatientsInfo");
   model->setEditStrategy(QSqlTableModel::OnManualSubmit);
   model->select();
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("PatientsName"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age")) ;
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("BloodPrint"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("PhoneNum"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DiagnosisDisease"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("consultant"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("ViewProfile"));

  view = new QTableView;
   view->setModel(model);

    QSignalMapper *signalMapper = new QSignalMapper(this);
     //   profile = new Profile(this) ;
        QPushButton *ViewProfile ;

   for( int i=0; i<7; i++ ) { //replace rows.length with your list or vector which consists of the data for your rows.
        //do something with your data for normal cells...
        auto item = model->index(i, 6);
     //   model->setData(item, QVariant::fromValue(model->getSpecificInformation()));
        //make new button for this row
        item = model->index(i, 6);
   ViewProfile = new QPushButton("ViewProfile");
        view->setIndexWidget(item, ViewProfile);
        signalMapper->setMapping(ViewProfile, i);

       // connect(ViewProfile, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
   }
//   connect(signalMapper, QOverload<QWidget *>::of(&QSignalMapper::mapped),
     //  [=](QWidget *widget){ /* ... */ });

    // connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(profile->show()));

   view->show();



}



#include "mainprocess.h"
#include "ui_mainprocess.h"
#include <QDebug>
MainProcess::MainProcess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainProcess)
{
    ui->setupUi(this);
    ui->lineEdit_Search->hide();
    ui->pushButton_5_Search->hide();
/*
    static QString PatientName1 = ui->lineEdit_Patirntname->text() ;
  static   QString Age1 = ui->lineEdit_2_Age->text() ;
   static  QString PhoneNum1 = ui->lineEdit_3_PhoeNum->text() ;
   static  QString BloodPrint1 = ui->comboBox->currentText() ;
   static   QString consultant1 = ui->lineEdit_2_consultant->text() ;
     QString Disease1 = ui->textEdit_Disease->toPlainText();
*/
    // void initializeModel(QSqlTableModel *model);



}

MainProcess::~MainProcess()
{
   delete ui;
}

 
   
   


void MainProcess::on_pushButton_2_clicked()
{


del.qtable();
    /*
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
        profile = new Profile(this) ;
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

        connect(ViewProfile, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
   }
//   connect(signalMapper, QOverload<QWidget *>::of(&QSignalMapper::mapped),
     //  [=](QWidget *widget){ /* ... */ // });

  //  profile->show();
  //  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(profile->show()));

  // view->show();


        /* for(int i=0;i<7;i++)
        {
         view->setIndexWidget(model->index(i,6),   new QPushButton("ViewProfile"));
        }*/

 //  QStandardItemModel   modell  (model->index(2,6));


/*
   MyDelegate  * delegate;
  view->setItemDelegate( delegate);

    view->horizontalHeader()->setStretchLastSection(true);
*/








}



 



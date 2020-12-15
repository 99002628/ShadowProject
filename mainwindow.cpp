#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(on_OkButtonClicked()));
    connect(ui->NextBtn,SIGNAL(clicked()),this,SLOT(on_NextBtnClicked()));
    connect(ui->BackBtn,SIGNAL(clicked()),this,SLOT(on_BackBtnClicked()));
     connect(ui->LoadBtn,SIGNAL(clicked()),this,SLOT(on_LoadBtnClicked()));
  //   connect(ui->DisplayBtn,SIGNAL(clicked(),this,SLOT(on_DisplayBtnClicked()));
     connect(ui->ClearBtn,SIGNAL(clicked()),ui->X_cor,SLOT(clear()));
    connect(ui->ClearBtn,SIGNAL(clicked()),ui->Y_cor,SLOT(clear()));
    connect(ui->ClearBtn,SIGNAL(clicked()),ui->Z_cor,SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OkButtonClicked()
{
    QString X = ui->X_cor->text();
    QString Y = ui->Y_cor->text();
    QString Z = ui->Z_cor->text();
    int x_cor_i=X.toInt();
    int y_cor_i=Y.toInt();
    int z_cor_i=Z.toInt();

    if((x_cor_i >500 || x_cor_i <0)  &&( y_cor_i >600 || y_cor_i <0 ) && (z_cor_i >600 ||z_cor_i <0) )
        messageBox->warning(this,"Invalid Input","Boundary condition not satisfied!");

    if(ui->X_cor->text()==NULL || ui->Y_cor->text()==NULL || ui->Z_cor->text()==NULL)
        messageBox->warning(this,"Invalid Input","Fields cannot be Empty!!");

    else
    {
        QRegExp re("\\d*");  // To check height is numeric or not
        if (!re.exactMatch(ui->X_cor->text()) || !re.exactMatch(ui->Y_cor->text())  || !re.exactMatch(ui->Z_cor->text()) )
            messageBox->warning(this,"Invalid Input","Fields contains only Numbers");

        else
        {
            QString filename="Data.txt";
            QFile file( filename );
            if ( file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append) )
            {
                QTextStream stream( &file );
                stream << ui->X_cor->text()<<"\t"<<ui->Y_cor->text()<<"\t"<<ui->Z_cor->text()<<"\n";
                messageBox->information(this,"Successfull","Data is written into filename: "+filename);
            }
        }

    }
}

void MainWindow::on_NextBtnClicked()
{

    if(ui->X_cor->text()==NULL || ui->Y_cor->text()==NULL || ui->Z_cor->text()==NULL)
        messageBox->warning(this,"Invalid Input","Fields cannot be Empty!!");

    else
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_BackBtnClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_LoadBtnClicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Text files (*.txt)"));
}

void MainWindow::on_DisplayBtnClicked()
{

}



#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);

    //connect button to signal and slot
    connect(ui->CalculateButton,SIGNAL(clicked()),SLOT(on_CalculateButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_single_clicked()
{
    ui->label_7->setEnabled(false);
    ui->spinBox_Threads->setEnabled(false);
}

void MainWindow::on_radioButton_parallel_clicked()
{
    ui->label_7->setEnabled(true);
    ui->spinBox_Threads->setEnabled(true);
}


void MainWindow::on_CalculateButton_clicked()
{
    //get all values
    int l = ui->spinBox_l->value();
    double delta_t = ui->doubleSpinBox_delta_t->value();
    double delta_x = ui->doubleSpinBox_delta_x->value();
    double lambda =  ui->doubleSpinBox_lambda->value();
    int ro = ui->spinBox_c->value();
    int c = ui->spinBox_c->value();
    int threads = ui->spinBox_Threads->value();
    bool parallel = ui->radioButton_parallel->isChecked();
    int N = ui->spinBox_LimitsElements->value();
    //call method
    PrepareCalc(l,delta_t,delta_x,lambda,ro,c,threads,N,parallel);
}

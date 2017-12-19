#include "mainwindow.h"
#include "main.h"
#include "math.h"
#include <QApplication>

#define _USE_MATH_DEFINES

void Calculations(double *temprature_arr[],int lenght_arr, int l, int lambda, int ro, int c, double delta_t, double delta_x){
    //Initial value
    int a = 0;
    int K = 0;
    for(int i=0;i<lenght_arr;i++){
        *temprature_arr[i] = 5.0*sin((M_PI*i)/l);
    }
    //Calc limits
    *temprature_arr[0]=0.0;
    *temprature_arr[lenght_arr-1]=10.0;
    //Calc k+1
    a = sqrt(lambda/(ro*c));
    K = (2*(a*a)*delta_t)/(delta_x*delta_x);

    for(int i=1;i<lenght_arr-1;i++)    {
        *temprature_arr[i]=K/2*(*temprature_arr[i-1])+(1+K)*(*temprature_arr[i])+K/2*(*temprature_arr[i+1]);
    }
}
void DrawTempreture(double *temprature_arr[], int count){
    QtCharts *charts = new QtCharts();
    QLineSeries *series = new QLineSeries();
    charts->addSeries(series);
    charts->setTitle("Temperature graph");
    //add axis
    QDateTimeAxis *axisX = new QDateTimeAxis;

    axisX->setTitleText("Temperature");
    charts->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Y");
    charts->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(charts);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}
void CleanMemory(double *arr[]){
    delete[] arr;
    arr=NULL;
}
void MainWindow::PrepareCalc(int ui_l, double ui_delta_t, double ui_delta_x, double ui_lambda, int ui_ro, int ui_c, int ui_threads, int ui_items_count, bool ui_parallel){
    //get consts values
    int l = ui_l;
    double delta_t=ui_delta_t;
    double delta_x=ui_delta_x;
    double lambda=ui_lambda;
    int ro=ui_ro;
    int c = ui_c;
    int threads = ui_threads;
    int N = ui_items_count;
    //prepare operabel values
    double* temprature = new double[N];
    //if(!ui_parallel) Calculations(&temprature);
    Calculations(&temprature, N, l, lambda, ro, c, delta_t, delta_x);
    DrawTempreture(&temprature, N);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

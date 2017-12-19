#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void PrepareCalc(int ui_l, double ui_delta_t, double ui_delta_x, double ui_lambda, int ui_ro, int ui_c, int ui_threads, int ui_items_count, bool ui_parallel);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_radioButton_single_clicked();

    void on_radioButton_parallel_clicked();

    void on_CalculateButton_clicked();

private:
    Ui::MainWindow *ui;
    QDoubleSpinBox *delta_t_SpinBox;
    QSpinBox *spinBox_l_SpinBox;
    QPushButton *calculate_button;
};

#endif // MAINWINDOW_H

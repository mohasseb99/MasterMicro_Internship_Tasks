#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "tinyexpr.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbPlot_clicked()
{
    QMessageBox::information(this, "Plot", "wait for processing");

    /* take Minimum value from text edit and convert to int */
    QString STRmnm = ui->TEmnm ->toPlainText();
    double mnm = STRmnm.toDouble();

    /* take step value from text edit and convert to int */
    QString STRmxm = ui->TEmxm->toPlainText();
    double mxm = STRmxm.toDouble();

    if(mxm <= mnm){
        QMessageBox::critical(this, "Plot", "Maximum should be more than minimum");
        return;
     }

    double x;
    te_variable vars[] = {"x", &x};

    int err;
    string eqn = ui->TEeqn->toPlainText().toStdString() ;

    /* Compile the expression with variables. */
    te_expr *expr = te_compile(eqn.c_str(), vars, 1, &err);

    QVector<double> yPlot;
    QVector<double> xPlot;

    if (expr) {
        for(double i = mnm; i <= (int)mxm; i+=0.2) xPlot.push_back(i);

        for(int i = 0; i < xPlot.size(); i++){
            x = xPlot[i];
            double y = te_eval(expr);
            yPlot.push_back(y);
        }

        te_free(expr);
    } else {
        QString errMsg = "Parse error at " + QString::fromStdString(to_string(err-1));
        QMessageBox::critical(this, "Plot", errMsg);
        return;
    }

    makePlot(xPlot, yPlot);
}

void MainWindow::makePlot(QVector<double> &x, QVector<double> &y){
    ui->wPlot->addGraph();
    // give the axes some labels:
    ui->wPlot->graph(0)->setPen(QPen(Qt::darkMagenta));
    ui->wPlot->xAxis->setLabel("x");
    ui->wPlot->yAxis->setLabel("y");
    ui->wPlot->graph(0)->setData(x, y);
    // set axes ranges, so we see all data:
    ui->wPlot->graph(0)->rescaleAxes(true);
    ui->wPlot->replot();
}

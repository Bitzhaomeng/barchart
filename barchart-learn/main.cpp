#include "dialog.h"
#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QHorizontalBarSeries>
#include<QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//QBarSet类表示条形图中的一组条
        QBarSet *set0 = new QBarSet("1km");
        QBarSet *set1 = new QBarSet("2km");
        QBarSet *set2 = new QBarSet("3km");
        QBarSet *set3 = new QBarSet("4km");
        QBarSet *set4 = new QBarSet("水平速度");
        QBarSet *set5 = new QBarSet("垂直速度");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;
        *set5 << -2 << 0<< 1 << -3 << 2 << -2;
    //![1]

    //![2]
       //QBarSeries类提供了一系列按类别分组的垂直条
        //QHorizontalBarSeries （用于创建水平柱状图）
//        QBarSeries *series = new QBarSeries();
        QHorizontalBarSeries *series=new QHorizontalBarSeries();
//        series->append(set0);
//        series->append(set1);
//        series->append(set2);
//        series->append(set3);
        series->append(set4);
        series->append(set5);

    //![2]

    //![3]

        //QChart类管理图表的系列、图例和坐标轴的图形表示
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);  //动作选项
    //![3]

    //![4]
       //QStringList类提供了一个字符串列表。
        QStringList categories;
        categories << "1km" << "2km" << "3km" << "4km" << "5km" << "6km";
        //QBarCategoryAxis类将类别添加到图表的坐标轴上
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();//根据已经添加到图表中的系列来创建图表的坐标轴。之前添加到图表中的任何坐标轴都将被删除。
       chart->setAxisY(axis, series);
        QValueAxis *axisX = new QValueAxis;
//         axisX->setRange(-5, 10);
//          axisX->setTickCount(16);
         axisX->setMinorTickCount(10);
          axisX->setLabelFormat("%.2f");
         chart->setAxisX(axisX, series);
         axisX->applyNiceNumbers();
    //![4]
//chart->setTheme(QChart::ChartThemeHighContrast);

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);//图例是如何与图表对齐的
    //![5]

    //![6]
    //(构建 QChartView，并设置抗锯齿、标题、大小)
        //QChartView是一个独立的小部件，可以显示图表。
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);//边缘平滑抗锯齿
//        chartView->rotate(90);  //顺时针旋转90°
    //![6]

    //![7]
//        QMainWindow window;
//        window.setCentralWidget(chartView);
//        window.resize(420, 300);
//        window.show();
    //![7]

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(2*420, 2*300);
    window.show();

    return a.exec();
}

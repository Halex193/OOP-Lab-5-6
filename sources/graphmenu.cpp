#include <headers/mainwindow.h>
#include "headers/graphmenu.h"
#include "ui_graphmenu.h"

GraphMenu::GraphMenu(Controller &controller, QWidget *parent) :
    QMainWindow(parent),
    controller{controller},
    ui(new Ui::GraphMenu)
{
    ui->setupUi(this);

    auto customPlot = ui->graphWidget;
    auto data = controller.getGraphData();

    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->setBackground(QBrush(gradient));

// create empty bar chart objects:
    QCPBars *count = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    count->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    count->setStackingGap(1);
// set names and colors:
    count->setName("Count");
    count->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    count->setBrush(QColor(0, 168, 140));

// prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> countData;
    int i = 1;
    for (auto &entry : data)
    {
        labels <<entry.first.c_str();
        ticks << i++;
        countData << entry.second;
    }
    count->setData(ticks, countData);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

// prepare y axis:
    customPlot->yAxis->setRange(0, 4);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Number of tutorials");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


// setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

GraphMenu::~GraphMenu()
{
    delete ui;
}

void GraphMenu::closeEvent(QCloseEvent *event)
{
    this->close();
    (new MainWindow{controller})->show();
}

#include "RadialFunViewer.h"

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtCore/QDebug>
#include <QtCharts/QLegend>
#include <QtWidgets/QFormLayout>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QLineSeries>
#include <QtCharts/QXYLegendMarker>
#include <QtCore/QtMath>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE


RadialFunViewer::RadialFunViewer(QWidget *parent) :  QWidget(parent)
{
     this->setWindowTitle("Radial Functions");

    // QLineSeries *series = new QLineSeries();

    // Create chart view with the chart
    m_chart = new QChart();
    m_chartView = new QChartView(m_chart, this);

    // Create layout for grid and detached legend
    m_mainLayout = new QGridLayout();
    m_mainLayout->addWidget(m_chartView, 0, 1, 3, 1);
    setLayout(m_mainLayout);

    connectMarkers();

    // Set the title and show legend
    m_chart->setTitle("R, R2 and RDF");
    m_chart->legend()->setVisible(true);
    m_chart->legend()->setAlignment(Qt::AlignBottom);

    m_chartView->setRenderHint(QPainter::Antialiasing);

    xmin=-10,ymin=-1, xmax=200,ymax=20;


    isRvisible=isR2visible=isRDFvisible=true;
}


void RadialFunViewer::renderMol(HMol * mol)
{
    if (!mol) return;
    if (mol==nullptr) return;

    if (mol->NAtoms()<0 ) return;

    removeSeries();


    // each orbital
    for (uint k =0; k<mol->NOrbitals();k++)
    {
        if (! mol->getObtial(k)->isVisible())
            continue;

        if (isRvisible)    addSeriesR(mol->getObtial(k));
        if (isRDFvisible)  addSeriesRDF(mol->getObtial(k));
        if (isR2visible)   addSeriesR2(mol->getObtial(k));

        refreshAxis();
    }

}


void RadialFunViewer::addSeriesRDF(HMO * mo)
{
    QLineSeries * series = new QLineSeries();
    m_series.append(series);

    QString name="RDF-" + mo->OrbitalName;
    series->setName(name);

    series->append(mo->RDFData);
    m_chart->addSeries(series);

    if (m_series.count() == 1)
        m_chart->createDefaultAxes();
    refreshAxis();
}


void RadialFunViewer::addSeriesR(HMO * mo)
{
    QLineSeries * series = new QLineSeries();
    m_series.append(series);

    QString name="R-" + mo->OrbitalName;
    series->setName(name);

    series->append(mo->RData);
    m_chart->addSeries(series);

    if (m_series.count() == 1)
        m_chart->createDefaultAxes();
    refreshAxis();
}

void RadialFunViewer::addSeriesR2(HMO * mo)
{
    QLineSeries * series = new QLineSeries();
    m_series.append(series);

    QString name="R2-" + mo->OrbitalName;
    series->setName(name);

    series->append(mo->R2Data);
    m_chart->addSeries(series);

    if (m_series.count() == 1)
        m_chart->createDefaultAxes();
    refreshAxis();
}

void RadialFunViewer::removeSeries()
{
    // Remove all series from chart
    while (m_series.count() > 0) {
        QLineSeries *series = m_series.last();
        m_chart->removeSeries(series);
        m_series.removeLast();
        delete series;
    }

}

void RadialFunViewer::connectMarkers()
{

    // Connect all markers to handler
    const auto markers = m_chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        // Disconnect possible existing connection to avoid multiple connections
        QObject::disconnect(marker, &QLegendMarker::clicked,
                            this, &RadialFunViewer::handleMarkerClicked);
        QObject::connect(marker, &QLegendMarker::clicked, this, &RadialFunViewer::handleMarkerClicked);
    }

}

void RadialFunViewer::disconnectMarkers()
{
    const auto markers = m_chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        QObject::disconnect(marker, &QLegendMarker::clicked,
                            this, &RadialFunViewer::handleMarkerClicked);
    }

}


void RadialFunViewer::handleMarkerClicked()
{

    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
    Q_ASSERT(marker);

    switch (marker->type())
    {
        case QLegendMarker::LegendMarkerTypeXY:
        {

        // Toggle visibility of series
        marker->series()->setVisible(!marker->series()->isVisible());

        // Turn legend marker back to visible, since hiding series also hides the marker
        // and we don't want it to happen now.
        marker->setVisible(true);

        // Dim the marker, if series is not visible
        qreal alpha = 1.0;

        if (!marker->series()->isVisible())
            alpha = 0.5;

        QColor color;
        QBrush brush = marker->labelBrush();
        color = brush.color();
        color.setAlphaF(alpha);
        brush.setColor(color);
        marker->setLabelBrush(brush);

        brush = marker->brush();
        color = brush.color();
        color.setAlphaF(alpha);
        brush.setColor(color);
        marker->setBrush(brush);

        QPen pen = marker->pen();
        color = pen.color();
        color.setAlphaF(alpha);
        pen.setColor(color);
        marker->setPen(pen);
        break;
        }
    }
}

void RadialFunViewer::refreshAxis()
{
    //m_chart->axisX()->setRange(xmin,xmax);
    //m_chart->axisY()->setRange(ymin,ymax);

    //m_chart->axisY()->setRange(-0.1,2.0);

}

void RadialFunViewer::setXRange(int min, int max)
{
   xmin=min, xmax=max;
   refreshAxis();
}

void RadialFunViewer::setYRange(int min, int max)
{
   ymin=min, ymax=max;
   refreshAxis();
}


void RadialFunViewer::setR2visible(bool v)
{
    isR2visible=v;

}

void RadialFunViewer::setRDFvisible(bool v)
{
    isRDFvisible=v;
}

void RadialFunViewer::setRvisible(bool v)
{
    isRvisible=v;
}





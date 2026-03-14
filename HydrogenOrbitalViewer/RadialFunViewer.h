#ifndef RPSIVIEWER_H
#define RPSIVIEWER_H

#include <QObject>
#include <QWidget>

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>

#include "HAtomOrb.h"
#include "HMol.h"


QT_CHARTS_USE_NAMESPACE


class MainWindow;
class RadialFunViewer : public QWidget
{
    Q_OBJECT
public:
    explicit RadialFunViewer(QWidget *parent = nullptr);
    MainWindow * parent;

    void setXRange(int , int );
    void setYRange(int , int );


public slots:
    void renderMol(HMol * );
    void addSeriesR(HMO * mo);
    void addSeriesR2(HMO * mo);
    void addSeriesRDF(HMO * mo);

    void removeSeries();
    void connectMarkers();
    void disconnectMarkers();

    void handleMarkerClicked();

    void setR2visible(bool v);
    void setRDFvisible(bool v);
    void setRvisible(bool v);
    void  refreshAxis();
private:

    QChart * m_chart;
    QList <QLineSeries *> m_series;
    QLineSeries * series_R;
    QLineSeries * series_R2;
    QLineSeries * series_RDF;

    QChartView *m_chartView;
    QGridLayout *m_mainLayout;
    QGridLayout *m_fontLayout;

    QList<QPointF> Rdata;
    QList<QPointF> RDFdata;

    bool isRvisible,isR2visible,isRDFvisible;

    int xmin,ymin, xmax,ymax;

};

#endif // RPSIVIEWER_H


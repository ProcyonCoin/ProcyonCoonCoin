// Copyright (c) 2011-2015 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Ravencoin Core developpers
//Copyright (c) 2022-Present The Procyon Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PROCYON_QT_TRAFFICGRAPHWIDGET_H
#define PROCYON_QT_TRAFFICGRAPHWIDGET_H

#include <QWidget>
#include <QQueue>

class ClientModel;

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QTimer;
QT_END_NAMESPACE

class TrafficGraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrafficGraphWidget(QWidget *parent = 0);
    void setClientModel(ClientModel *model);
    int getGraphRangeMins() const;

protected:
    void paintEvent(QPaintEvent *);

public Q_SLOTS:
    void updateRates();
    void setGraphRangeMins(int mins);
    void clear();

private:
    void paintPath(QPainterPath &path, QQueue<float> &samples);

    QTimer *timer;
    float fMax;
    int nMins;
    QQueue<float> vSamplesIn;
    QQueue<float> vSamplesOut;
    quint64 nLastBytesIn;
    quint64 nLastBytesOut;
    ClientModel *clientModel;
};

#endif // PROCYON_QT_TRAFFICGRAPHWIDGET_H

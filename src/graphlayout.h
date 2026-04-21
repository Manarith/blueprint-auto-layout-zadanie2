#ifndef GRAPHLAYOUT_H
#define GRAPHLAYOUT_H

#include <QString>
#include <QVector>
#include <QMap>

struct Node {
    int id;
    QString name;
    int x = 0;
    int y = 0;
};

struct Edge {
    int from;
    int to;
};

class GraphLayout {
public:
    void load(const QString &file);
    void layout();

    QVector<Node> nodes;
    QVector<Edge> edges;

private:
    QMap<int, QVector<int>> adj;
    QMap<int, int> indegree;
    QMap<int, int> level;

    void buildGraph();
};

#endif // GRAPHLAYOUT_H

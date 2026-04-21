#include "graphlayout.h"

#include "graphlayout.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QQueue>

void GraphLayout::load(const QString &file)
{
    QFile f(file);
    f.open(QIODevice::ReadOnly);

    auto doc = QJsonDocument::fromJson(f.readAll());
    auto obj = doc.object();

    nodes.clear();
    edges.clear();

    for (auto n : obj["nodes"].toArray()) {
        auto o = n.toObject();
        nodes.push_back({o["id"].toInt(), o["name"].toString()});
    }

    for (auto e : obj["edges"].toArray()) {
        auto o = e.toObject();
        edges.push_back({o["from"].toInt(), o["to"].toInt()});
    }

    buildGraph();
}

void GraphLayout::buildGraph()
{
    adj.clear();
    indegree.clear();

    for (auto &e : edges) {
        adj[e.from].push_back(e.to);
        indegree[e.to]++;
    }

    for (auto &n : nodes)
        indegree[n.id];
}

void GraphLayout::layout()
{
    level.clear();
    QQueue<int> q;

    for (auto &n : nodes) {
        if (indegree[n.id] == 0) {
            q.enqueue(n.id);
            level[n.id] = 0;
        }
    }

    while (!q.isEmpty()) {
        int u = q.head(); q.dequeue();

        for (int v : adj[u]) {
            level[v] = std::max(level[v], level[u] + 1);

            if (--indegree[v] == 0)
                q.enqueue(v);
        }
    }

    QMap<int, QVector<int>> layers;

    for (auto &n : nodes)
        layers[level[n.id]].push_back(n.id);

    int X = 250;
    int Y = 120;

    for (auto it = layers.begin(); it != layers.end(); ++it) {
        int layer = it.key();

        for (int i = 0; i < it.value().size(); i++) {
            int id = it.value()[i];

            for (auto &n : nodes) {
                if (n.id == id) {
                    n.x = layer * X + 50;
                    n.y = i * Y + 50;
                }
            }
        }
    }
}

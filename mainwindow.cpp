#include "mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);

    auto *view = new QGraphicsView(scene);
    setCentralWidget(view);

    graph.load("graph.json");
    graph.layout();

    draw();
}

void MainWindow::draw()
{
    scene->clear();

    QMap<int, Node> map;
    for (auto &n : graph.nodes)
        map[n.id] = n;

    // edges
    for (auto &e : graph.edges) {
        auto a = map[e.from];
        auto b = map[e.to];

        scene->addLine(a.x + 60, a.y + 25,
                       b.x + 60, b.y + 25);
    }

    // nodes
    for (auto &n : graph.nodes) {
        scene->addRect(n.x, n.y, 120, 50);

        auto text = scene->addText(n.name);
        text->setPos(n.x + 5, n.y + 10);
    }
}

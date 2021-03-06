#ifndef MESSAGENODE_H
#define MESSAGENODE_H

#include <QRect>
#include <QString>
#include <QPainter>
#include <QObject>
#include <QListView>
#include <QStyledItemDelegate>
#include <QGridLayout>

namespace Ui {
    class MessageNode;
}

class MessageNode : public QStyledItemDelegate {
    Q_OBJECT
public:
    MessageNode(QObject* parent = nullptr);
    MessageNode(QString message, QObject* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;
private:
    int m_widthoftextbox;
    QString m_message;
};

#endif // MESSAGENODE_H

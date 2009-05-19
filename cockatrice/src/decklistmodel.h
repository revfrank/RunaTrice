#ifndef DECKLISTMODEL_H
#define DECKLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "decklist.h"

class CardDatabase;

class DeckListModel : public QAbstractListModel {
	Q_OBJECT
public:
	DeckListModel(CardDatabase *_db, QObject *parent = 0);
	~DeckListModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	DecklistRow *getRow(int row) const;
	void cleanList();
	DeckList *getDeckList() const { return deckList; }
	bool loadFromFile(const QString &fileName, DeckList::FileFormat fmt);
	bool saveToFile(const QString &fileName, DeckList::FileFormat fmt);
private:
	CardDatabase *db;
	DeckList *deckList;
};

#endif

#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <QAbstractListModel>
#include <QObject>
#include <QHash>
#include <QDebug>
#include "../model/task.hpp"
#include "../db/taskdatabase.hpp"

class TaskManager : public QAbstractListModel
{
	Q_OBJECT
private:
	TaskDatabase &m_db;
	QVector<Task *> m_tasks;

public:
    enum TaskRoles {
        TitleRole = Qt::UserRole + 1,
        DescriptionRole,
        CompletedRole
    };
	
	explicit TaskManager(TaskDatabase &db, QAbstractListModel *parent = nullptr);

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role) const override;
	QHash<int, QByteArray> roleNames() const override;

	Q_INVOKABLE void addTask(const Task &);
	Q_INVOKABLE void editTask(const Task &);
	Q_INVOKABLE void removeTask(unsigned int row);

	Q_INVOKABLE QVector<QObject *> tasks() const;

signals:
	void tasksChanged();
};

#endif

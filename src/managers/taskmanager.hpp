#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <QObject>
#include <QVector>
#include <QDebug>
#include "../model/task.hpp"
#include "../db/taskdatabase.hpp"

class TaskManager : public QObject
{
    Q_OBJECT
	Q_PROPERTY(QVector<QObject*> tasks READ tasks NOTIFY tasksChanged)
private:
    TaskDatabase& m_db;
    QVector<QObject*> m_tasks;
	
public:
	explicit TaskManager(TaskDatabase& db, QObject* parent = nullptr);

    Q_INVOKABLE void addTask(const Task&);
    Q_INVOKABLE void removeTask(unsigned int id);

    Q_INVOKABLE QVector<QObject*> tasks() const;

signals:
    void tasksChanged();
};

#endif

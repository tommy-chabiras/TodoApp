#include "taskmanager.hpp"

TaskManager::TaskManager(TaskDatabase &db, QObject *parent) : m_db(db), QObject(parent) {}

Q_INVOKABLE void TaskManager::addTask(const Task &task)
{
	m_db.addTask(task);
}

Q_INVOKABLE void TaskManager::removeTask(unsigned int id)
{
	m_db.deleteTask(id);
}

QVector<QObject*> TaskManager::tasks() const
{
    QVector<QObject*> tasks;
    for (Task* t : m_db.loadTasks()) {
        tasks.append(t);
    }
    return tasks;
}
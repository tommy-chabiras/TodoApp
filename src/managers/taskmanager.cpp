#include "taskmanager.hpp"

TaskManager::TaskManager(TaskDatabase &db, QAbstractListModel *parent)
	: QAbstractListModel(parent), m_db(db)
{
	m_tasks = m_db.loadTasks();
}

int TaskManager::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent)
	return m_tasks.size();
}

QVariant TaskManager::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || index.row() < 0 || index.row() >= m_tasks.size())
		return QVariant();

	Task *task = m_tasks[index.row()];
	switch (role)
	{
	case TitleRole:
		return task->getTitle();
	case DescriptionRole:
		return task->getDescription();
	case CompletedRole:
		return task->isCompleted();
	default:
		return QVariant();
	}
}

QHash<int, QByteArray> TaskManager::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[TitleRole] = "title";
	roles[DescriptionRole] = "description";
	roles[CompletedRole] = "completed";
	return roles;
}

Q_INVOKABLE void TaskManager::addTask(const Task &task)
{
	m_tasks.append(new Task(task.getTitle(), task.getDescription(), task.isCompleted(), this));
	m_db.addTask(task);
	emit tasksChanged();
}

Q_INVOKABLE void TaskManager::editTask(const Task &task)
{
	m_db.updateTask(task);
	emit tasksChanged();
}

void TaskManager::removeTask(unsigned int row)
{
    if (row < 0 || row >= m_tasks.size()) return;

    beginRemoveRows(QModelIndex(), row, row);
    Task *task = m_tasks.takeAt(row);
    m_db.deleteTask(task->getId());
    task->deleteLater();
    endRemoveRows();
	emit tasksChanged();
}

QVector<QObject *> TaskManager::tasks() const
{
	QVector<QObject *> tasks;
	for (Task *t : m_db.loadTasks())
	{
		tasks.append(t);
	}
	return tasks;
}
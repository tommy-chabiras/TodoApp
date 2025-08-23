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
	case IdRole:
		return task->getId();
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
	roles[IdRole] = "id";
	roles[TitleRole] = "title";
	roles[DescriptionRole] = "description";
	roles[CompletedRole] = "completed";
	return roles;
}

Q_INVOKABLE void TaskManager::addTask(const Task &task)
{
	m_db.addTask(const_cast<Task &>(task));

	Task *newTask = task.clone();
	
	beginInsertRows(QModelIndex(), m_tasks.size(), m_tasks.size());
	m_tasks.append(newTask);
	endInsertRows();
}

Q_INVOKABLE void TaskManager::editTask(const Task &task)
{
	m_db.updateTask(task);
	emit tasksChanged();
}

Q_INVOKABLE void TaskManager::removeTask(unsigned int id)
{
	for (int row = 0; row < m_tasks.size(); ++row)
	{
		Task *task = m_tasks.at(row);
		if (task->getId() == id)
		{
			beginRemoveRows(QModelIndex(), row, row);

			m_tasks.removeAt(row);
			m_db.deleteTask(id);
			task->deleteLater();

			endRemoveRows();
			emit tasksChanged();
			return;
		}
	}
}

Q_INVOKABLE void TaskManager::removeTask(const QList<unsigned int> &ids)
{
	for (int row = 0; row < m_tasks.size(); ++row)
	{
		Task *task = m_tasks.at(row);
		if (ids.contains(task->getId()))
		{
			beginRemoveRows(QModelIndex(), row, row);

			m_tasks.removeAt(row);
			m_db.deleteTask(task->getId());
			task->deleteLater();

			endRemoveRows();
		}
	}
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
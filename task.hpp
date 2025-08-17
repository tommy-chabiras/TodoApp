#ifndef TASK_HPP
#define TASK_HPP

#include <QString>
#include <QDateTime>
#include "taskdatabase.hpp"

class Task
{
	struct TaskUpdate
	{
		std::optional<QString> title;
		std::optional<QString> description;
		std::optional<QDateTime> startedAt;
	};
	const unsigned int id{TaskDatabase::generateId()};
	QString title{};
	QString description{};
	bool completed{};
	const QDateTime createdAt{QDateTime::currentDateTime()};
	QDateTime startedAt{QDateTime::currentDateTime()};
	QDateTime completedAt{};

public:
	Task(const QString &t, const QString &d, bool c = false)
		: title(t), description(d), completed(c) {};

	const QString &getTitle() const;
	const QString &getDescription() const;
	unsigned int getId() const;
	bool isCompleted() const;

	QDateTime taskCompleted();

	Task &updateTask(const TaskUpdate &upd);
};

#endif
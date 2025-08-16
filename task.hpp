#ifndef TODO_HPP
#define TODO_HPP

#include <QString>
#include <QDateTime>
class Task
{
	struct TaskUpdate
	{
		std::optional<QString> title;
		std::optional<QString> description;
		std::optional<QDateTime> startedAt;
	};

	QString title{};
	QString description{};
	bool isCompleted{};
	const QDateTime createdAt {QDateTime::currentDateTime()};
	QDateTime startedAt {QDateTime::currentDateTime()};
	QDateTime completedAt{};

public:
	Task(const QString &t, const QString &d, bool c = false) : title(t), description(d), isCompleted(c) {}


	const QString& getTitle() const
	{
		return title;
	}
	const QString& getDescription() const
	{
		return description;
	}

	QDateTime completed()
	{
		completedAt = QDateTime::currentDateTime();
		isCompleted = true;
		return completedAt;
	}

	Task &updateTask(const TaskUpdate &upd)
	{
		if (upd.title)
			title = *upd.title;
		if (upd.description)
			description = *upd.description;
		if (upd.startedAt)
			startedAt = *upd.startedAt;

		return *this;
	}
};

#endif
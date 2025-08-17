#include "task.hpp"


	const QString& Task::getTitle() const
	{
		return title;
	}
	const QString& Task::getDescription() const
	{
		return description;
	}

	QDateTime Task::completed()
	{
		completedAt = QDateTime::currentDateTime();
		isCompleted = true;
		return completedAt;
	}

	Task& Task::updateTask(const TaskUpdate &upd)
	{
		if (upd.title)
			title = *upd.title;
		if (upd.description)
			description = *upd.description;
		if (upd.startedAt)
			startedAt = *upd.startedAt;

		return *this;
	}
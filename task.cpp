#include "task.hpp"


	const QString& Task::getTitle() const
	{
		return title;
	}
	
	const QString& Task::getDescription() const
	{
		return description;
	}

	unsigned int Task::getId() const
	{
		return id;
	}

	bool Task::isCompleted() const
	{
		return completed;
	}

	QDateTime Task::taskCompleted()
	{
		completedAt = QDateTime::currentDateTime();
		completed = true;
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
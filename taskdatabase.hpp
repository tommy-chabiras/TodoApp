#ifndef TASKDATA_HPP
#define TASKDATA_HPP


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
#include "task.hpp"


class TaskDatabase
{
	QSqlDatabase db;

public:
	TaskDatabase(const QString& dbName = "tasks.db");
	~TaskDatabase();

	std::vector<Task> getTasks();
	void addTask(Task &task);
};

#endif
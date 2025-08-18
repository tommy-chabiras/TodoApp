#ifndef TASKDATABASE_HPP
#define TASKDATABASE_HPP


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
#include "task.hpp"

class Task;

class TaskDatabase
{
	static QSqlDatabase db;

public:
	TaskDatabase(const QString& dbName = "tasks.db");
	~TaskDatabase();

	static unsigned int generateId();
	std::vector<Task> loadTasks();
	void addTask(const Task &task);
	void updateTask(const Task &task);
	static void deleteTask(unsigned int id);
};

#endif
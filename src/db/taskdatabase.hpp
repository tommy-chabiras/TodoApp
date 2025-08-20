#ifndef TASKDATABASE_HPP
#define TASKDATABASE_HPP


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
#include "../model/task.hpp"

class Task;

class TaskDatabase
{
	static QSqlDatabase db;

public:
	TaskDatabase(const QString& dbName = "tasks.db");
	~TaskDatabase();

	static unsigned int generateId();
	QVector<Task*> loadTasks();
	void addTask(const Task &task);
	void updateTask(const Task &task);
	static void deleteTask(unsigned int id);
};

#endif
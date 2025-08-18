
#include "taskdatabase.hpp"

QSqlDatabase TaskDatabase::db;

TaskDatabase::TaskDatabase(const QString &dbName)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Failed to connect to the database!";
    }


	QSqlQuery query;
	query.exec("CREATE TABLE IF NOT EXISTS tasks ("
			   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
			   "title TEXT NOT NULL,"
			   "description TEXT,"
			   "completed INTEGER NOT NULL DEFAULT 0,"
			   "createdAt TEXT,"
			   "startedAt TEXT,"
			   "completedAt TEXT"
			   ")");
}

TaskDatabase::~TaskDatabase()
{
	if (db.isOpen())
		db.close();
}

unsigned int TaskDatabase::generateId()
{
	QSqlQuery query("SELECT IFNULL(MAX(id), 0) + 1 FROM tasks");

	if (query.next())
	{
		return query.value(0).toUInt();
	}
	return 1;
}

std::vector<Task> TaskDatabase::loadTasks()
{
	std::vector<Task> tasks;

	QSqlQuery query("SELECT id, title, description, completed FROM tasks");

	while (query.next())
	{
		unsigned int id = query.value(0).toUInt();
		QString title = query.value(1).toString();
		QString description = query.value(2).toString();
		bool completed = query.value(3).toInt();

		tasks.emplace_back(id, title, description, completed);
	}

	return tasks;
}

void TaskDatabase::addTask(const Task &task)
{
	QSqlQuery query;
	query.prepare("INSERT INTO tasks (title, description, completed) "
				  "VALUES (:title, :description, :completed)");
	query.bindValue(":title", task.getTitle());
	query.bindValue(":description", task.getDescription());
	query.bindValue(":completed", task.isCompleted() ? 1 : 0);

	if (!query.exec())
	{
		qDebug() << "Add task failed:" << query.lastError().text();
	}
}

void TaskDatabase::updateTask(const Task &task)
{
	QSqlQuery query;
	query.prepare("UPDATE tasks SET description = :description, completed = :completed "
				  "WHERE title = :title");
	query.bindValue(":title", task.getTitle());
	query.bindValue(":description", task.getDescription());
	query.bindValue(":completed", task.isCompleted() ? 1 : 0);

	if (!query.exec())
	{
		qDebug() << "Update task failed:" << query.lastError().text();
	}
}

void TaskDatabase::deleteTask(const QString &title)
{
	QSqlQuery query;
	query.prepare("DELETE FROM tasks WHERE title = :title");
	query.bindValue(":title", title);

	if (!query.exec())
	{
		qDebug() << "Delete task failed:" << query.lastError().text();
	}
}
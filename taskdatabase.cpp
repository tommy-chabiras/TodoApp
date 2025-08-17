
#include "taskdatabase.hpp"

TaskDatabase::TaskDatabase(const QString &dbName)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

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
	if (db.isOpen()) db.close();
}

std::vector<Task> TaskDatabase::getTasks()
{
	return std::vector<Task>();
}

void TaskDatabase::addTask(Task &task)
{
}

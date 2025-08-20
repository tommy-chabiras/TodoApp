#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "model/task.hpp"
#include "db/taskdatabase.hpp"
#include "managers/taskmanager.hpp"


int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	TaskDatabase db("tasks.db");

	QVector<Task*> tasks = db.loadTasks();

	db.addTask(Task("Sample Task", "This is a test task"));


	QQmlApplicationEngine engine;

	engine.rootContext()->setContextProperty("tasksList", QVariant::fromValue(tasks));

	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}

// void displayTasks(QVBoxLayout *mainLayout, const std::vector<std::unique_ptr<Task>> &tasks)
// {
// 	for (const auto &task : tasks)
// 	{
// 		QHBoxLayout *row = new QHBoxLayout;
// 		QLabel *title = new QLabel(task->getTitle());
// 		QLabel *desc = new QLabel(task->getDescription());
// 		row->addWidget(title);
// 		row->addWidget(desc);

// 		mainLayout->addLayout(row);
// 	}
// }

// void deleteTasks(std::vector<std::unique_ptr<Task>> &tasks, const std::unordered_set<int> &ids)
// {

// 	auto it = tasks.begin();
// 	while (it != tasks.end())
// 	{
// 		int id = (*it)->getId();
// 		if (ids.count(id))
// 		{
// 			TaskDatabase::deleteTask(id);
// 			it = tasks.erase(it);
// 		}
// 		else
// 		{
// 			++it;
// 		}
// 	}
// }
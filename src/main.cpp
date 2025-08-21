#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QFileSystemWatcher>
#include <QDebug>

#include "model/task.hpp"
#include "db/taskdatabase.hpp"
#include "managers/taskmanager.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	TaskDatabase db("tasks.db");
	TaskManager taskManager(db);

	engine.rootContext()->setContextProperty("taskManager", &taskManager);

	#ifdef DEV
		QString qmlPath = QDir(QCoreApplication::applicationDirPath())
							.absoluteFilePath("../resources/qml/main.qml");

		engine.load(QUrl::fromLocalFile(qmlPath));

		QFileSystemWatcher watcher;
		watcher.addPath(qmlPath);

		QObject::connect(&watcher, &QFileSystemWatcher::fileChanged,
						[&engine, qmlPath](const QString &)
						{
							qDebug() << "QML file changed. Reloading...";
							for (QObject *obj : engine.rootObjects())
							{
								delete obj;
							}
							engine.clearComponentCache();
							engine.load(QUrl::fromLocalFile(qmlPath));
						});
	#else
		engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	#endif

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
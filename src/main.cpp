#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>

#include <algorithm>
#include <iostream>
#include "task.hpp"
#include "taskdatabase.hpp"

void displayTasks(QVBoxLayout *mainLayout, const std::vector<std::unique_ptr<Task>> &tasks);
void deleteTasks(std::vector<std::unique_ptr<Task>> &tasks, const std::unordered_set<int> &ids);

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget window;
	window.setWindowTitle("TodoApp");

	window.resize(300, 200);

	QVBoxLayout *mainLayout = new QVBoxLayout(&window);

	QLabel *label = new QLabel("text");
	QPushButton *button = new QPushButton("Add Task");

	// button.resize(200, 50);
	// button.show();

	mainLayout->addWidget(label);

	// std::vector<Task> tasks = {
	// 	Task("task 1", "task 1 desc", false),
	// 	Task("task 2", "task 2 desc", false)

	// };

	TaskDatabase db("tasks.db");

	db.addTask(Task("task 1", "task 1 desc"));

	std::vector<std::unique_ptr<Task>> tasks;

	for (auto &t : db.loadTasks())
	{
		tasks.push_back(std::make_unique<Task>(t)); // copy into unique_ptr
	}

	std::cout << tasks[0]->getTitle().toStdString();
	displayTasks(mainLayout, tasks);

	std::unordered_set<int> allTaskIds;
	for (const auto &task : tasks)
	{
		allTaskIds.insert(task->getId());
	}

	deleteTasks(tasks, allTaskIds);

	mainLayout->addWidget(button);

	window.setLayout(mainLayout);
	window.show();

	// qDebug() << "Hello World!";

	// QLabel label("Hello, This is a GUI app");

	return app.exec();
}

void displayTasks(QVBoxLayout *mainLayout, const std::vector<std::unique_ptr<Task>> &tasks)
{
	for (const auto &task : tasks)
	{
		QHBoxLayout *row = new QHBoxLayout;
		QLabel *title = new QLabel(task->getTitle());
		QLabel *desc = new QLabel(task->getDescription());
		row->addWidget(title);
		row->addWidget(desc);

		mainLayout->addLayout(row);
	}
}

void deleteTasks(std::vector<std::unique_ptr<Task>> &tasks, const std::unordered_set<int> &ids)
{

	auto it = tasks.begin();
	while (it != tasks.end())
	{
		int id = (*it)->getId();
		if (ids.count(id))
		{
			TaskDatabase::deleteTask(id);
			it = tasks.erase(it);
		}
		else
		{
			++it;
		}
	}
}
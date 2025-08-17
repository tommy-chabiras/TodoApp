#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "task.hpp"
#include "taskdatabase.hpp"

void displayTasks(QVBoxLayout *layout, const std::vector<Task> &tasks);

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget window;
	window.setWindowTitle("TodoApp");

	window.resize(300, 200);

	QVBoxLayout* mainLayout = new QVBoxLayout(&window);

	QLabel *label = new QLabel("text");
	QPushButton *button = new QPushButton("Add Task");

	// button.resize(200, 50);
	// button.show();

	mainLayout->addWidget(label);


	// std::vector<Task> tasks = {
	// 	Task("task 1", "task 1 desc", false),
	// 	Task("task 2", "task 2 desc", false)

	// };
	TaskDatabase db = TaskDatabase();
	db.addTask(Task("task 1", "task 1 desc", false));
	displayTasks(mainLayout, db.loadTasks());

	mainLayout->addWidget(button);

	window.setLayout(mainLayout);
	window.show();

	// qDebug() << "Hello World!";

	// QLabel label("Hello, This is a GUI app");

	return app.exec();
}

void displayTasks(QVBoxLayout *mainLayout, const std::vector<Task> &tasks)
{
	for (const auto &task : tasks)
	{
		QHBoxLayout* row = new QHBoxLayout;
		QLabel *title = new QLabel(task.getTitle());
		QLabel *desc = new QLabel(task.getDescription());
		row->addWidget(title);
		row->addWidget(desc);

		mainLayout->addLayout(row);
	}
}
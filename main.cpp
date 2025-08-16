#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "task.hpp"

void addTasks(QVBoxLayout *layout, std::vector<Task> &tasks);

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget window;
	window.setWindowTitle("TodoApp");

	window.resize(300, 200);

	auto *layout = new QVBoxLayout(&window);

	QLabel *label = new QLabel("text");
	QPushButton *button = new QPushButton("Add Task");

	// button.resize(200, 50);
	// button.show();

	layout->addWidget(label);
	layout->addWidget(button);

	std::vector<Task> tasks = {
		Task("task 1", "task 1 desc", false),
		Task("task 2", "task 2 desc", false)

	};
	addTasks(layout, tasks);

	window.setLayout(layout);
	window.show();

	// qDebug() << "Hello World!";

	// QLabel label("Hello, This is a GUI app");

	return app.exec();
}

void addTasks(QVBoxLayout *layout, std::vector<Task> &tasks)
{
	for (const auto &task : tasks)
	{
		QLabel *label = new QLabel(task.getTitle());
		layout->addWidget(label);
	}
}
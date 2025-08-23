#ifndef TESTHELPER_HPP
#define TESTHELPER_HPP
#include <QObject>
#include "../managers/taskmanager.hpp"
#include "../model/task.hpp"

class TestHelper : public QObject
{
	Q_OBJECT

private:
	TaskManager *m_taskManager;

public:
	explicit TestHelper(TaskManager *manager, QObject *parent = nullptr)
		: QObject(parent), m_taskManager(manager) {}

	Q_INVOKABLE void createTestTask()
	{
		Task t;
		t.setTitle("Temporary"); 
		t.setDescription("This is a test task");

		m_taskManager->addTask(t);
	}
};

#endif